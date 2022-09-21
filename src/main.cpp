#include <iostream>
#include "swimmers.h"
#include <thread>
#include <mutex>
#define fastest(a,b) (((a)<(b))?(a):(b))
void swim (Swimmer& swmr, std::mutex &mtx) {
    int time = 1;
    while (!swmr.swimmerFinish()){
        mtx.lock ();
        swmr.setCurrentPosition(time);
        if (swmr.swimmerFinish()) swmr.setTotalTime(time);
        std::cout << swmr.getName() << " swam " << swmr.getCurrentPosition() << " m." <<std::endl;
        mtx.unlock();

        std::this_thread::sleep_for (std::chrono::seconds (1));
        time++;
    }
}


int main() {

    std::mutex mtx;
    std::cout << "Swimmer 1." <<std::endl;
    Swimmer Sportsman1 = *new Swimmer (); std::cout << "Swimmer 2." <<std::endl;
    Swimmer Sportsman2 = *new Swimmer (); std::cout << "Swimmer 3." <<std::endl;
    Swimmer Sportsman3 = *new Swimmer (); std::cout << "Swimmer 4." <<std::endl;
    Swimmer Sportsman4 = *new Swimmer (); std::cout << "Swimmer 5." <<std::endl;
    Swimmer Sportsman5 = *new Swimmer (); std::cout << "Swimmer 6." <<std::endl;
    Swimmer Sportsman6 = *new Swimmer ();

    std::thread sportsmanSwim(swim, std::ref (Sportsman1),std::ref (mtx));
    std::thread sportsmanSwim2(swim, std::ref (Sportsman2),std::ref (mtx));
    std::thread sportsmanSwim3(swim, std::ref (Sportsman3),std::ref (mtx));
    std::thread sportsmanSwim4(swim, std::ref (Sportsman4),std::ref (mtx));
    std::thread sportsmanSwim5(swim, std::ref (Sportsman5),std::ref (mtx));
    std::thread sportsmanSwim6(swim, std::ref (Sportsman6),std::ref (mtx));

    sportsmanSwim.join ();
    sportsmanSwim2.join ();
    sportsmanSwim3.join ();
    sportsmanSwim4.join ();
    sportsmanSwim5.join ();
    sportsmanSwim6.join ();

    int FinishingOrder [6];
    std::string FinishingOrderName [6];

    for (int i = 0; i <6;i++){

            for (int j = 0; j <6 ; j++){
                if (j >6) break;
                int nextSportsmenTime = 0;
                switch (j){
                    case 0 : nextSportsmenTime = Sportsman1.getTotalTime();break;
                    case 1 : nextSportsmenTime = Sportsman2.getTotalTime();break;
                    case 2 : nextSportsmenTime = Sportsman3.getTotalTime();break;
                    case 3 : nextSportsmenTime = Sportsman4.getTotalTime();break;
                    case 4 : nextSportsmenTime = Sportsman5.getTotalTime();break;
                    case 5 : nextSportsmenTime = Sportsman6.getTotalTime();break;
                    default : break;
                }
                if (i == 0 && j == 1) { FinishingOrder[i] = fastest (Sportsman1.getTotalTime(), nextSportsmenTime);}
                else{ if (i >0) {
                        if ( fastest (FinishingOrder [i], nextSportsmenTime) != FinishingOrder [i-1] ) {
                            FinishingOrder[i] = fastest (FinishingOrder [i], nextSportsmenTime);
                        }
                     }else {FinishingOrder[i] = fastest (FinishingOrder [i], nextSportsmenTime);}
                }

            }

    }

        for (int i = 0; i < 6; i++){
            std::cout << " total time : " << FinishingOrder[i] << std::endl;
        }
    std::cout << Sportsman1.getName() << " total time : " <<Sportsman1.getTotalTime()<<std::endl;
    std::cout << Sportsman2.getName() << " total time : " <<Sportsman2.getTotalTime()<<std::endl;
    std::cout << Sportsman3.getName() << " total time : " <<Sportsman3.getTotalTime()<<std::endl;
    std::cout << Sportsman4.getName() << " total time : " <<Sportsman4.getTotalTime()<<std::endl;
    std::cout << Sportsman5.getName() << " total time : " <<Sportsman5.getTotalTime()<<std::endl;
    std::cout << Sportsman6.getName() << " total time : " <<Sportsman6.getTotalTime()<<std::endl;

}
