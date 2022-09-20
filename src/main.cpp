#include <iostream>
#include "swimmers.h"
#include <thread>


void swim (Swimmer& swmr) {
    int time = 1;
    while (!swmr.swimmerFinish()){
        std::this_thread::sleep_for (std::chrono::seconds (1));
        swmr.setCurrentPosition(time);
        if (swmr.getCurrentPosition() == 100) swmr.setTotalTime(time);
        std::cout << swmr.getName() << " swam " << swmr.getCurrentPosition() << " m." <<std::endl;
        time++;
    }
}


int main() {
    std::cout << "Swimmer 1." <<std::endl;
    Swimmer Sportsman1 = *new Swimmer (); std::cout << "Swimmer 2." <<std::endl;
    Swimmer Sportsman2 = *new Swimmer (); std::cout << "Swimmer 3." <<std::endl;
    Swimmer Sportsman3 = *new Swimmer (); std::cout << "Swimmer 4." <<std::endl;
    Swimmer Sportsman4 = *new Swimmer (); std::cout << "Swimmer 5." <<std::endl;
    Swimmer Sportsman5 = *new Swimmer (); std::cout << "Swimmer 6." <<std::endl;
    Swimmer Sportsman6 = *new Swimmer ();

    std::thread sportsmanSwim(swim, std::ref( Sportsman1));
    std::thread sportsmanSwim2(swim, std::ref (Sportsman2));
    std::thread sportsmanSwim3(swim, std::ref (Sportsman3));
    std::thread sportsmanSwim4(swim, std::ref (Sportsman4));
    std::thread sportsmanSwim5(swim, std::ref (Sportsman5));
    std::thread sportsmanSwim6(swim, std::ref (Sportsman6));

    sportsmanSwim.join ();
    sportsmanSwim2.join ();
    sportsmanSwim3.join ();
    sportsmanSwim4.join ();
    sportsmanSwim5.join ();
    sportsmanSwim6.join ();

    std::cout << Sportsman1.getName() << " total time : " <<Sportsman1.getTotalTime ()<< std::endl;
}
