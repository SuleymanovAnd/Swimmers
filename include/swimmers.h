#include <iostream>

class Swimmer {
    std::string swimmerName;
    int speedOfSwim;
    int currentPosition = 0;
    int totalTime = 0;

    void setName (){
        std::cout << "Enter name of swimmer: ";
        std::cin >> swimmerName;
    }

    void setSpeedOfSwim (){
        std::cout << "Enter speed of swimmer (M/s) : ";
        std::cin >> speedOfSwim;
    }
public:
    Swimmer () {
        setName();
        setSpeedOfSwim();
    }

    std::string getName(){
        return swimmerName;
    }

    void setTotalTime (int total){
        totalTime = total;
    }

    int getTotalTime (){
        return totalTime;
    }

    int getCurrentPosition (){
        return currentPosition;
    }
    bool swimmerFinish (){
        return currentPosition == 100;
    }

    void setCurrentPosition (int currenTime){
     if(currentPosition <=100) currentPosition = currenTime *speedOfSwim;
     if(currentPosition >100) currentPosition = 100;
    }

    ~Swimmer() = default;

};