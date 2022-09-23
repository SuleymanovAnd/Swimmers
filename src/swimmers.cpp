#include "swimmers.h"
#include <iostream>


    Swimmer::Swimmer () {
        std::string inName;
        std::cout << "Enter name of swimmer: ";
        std::cin >> inName;
        int inSpeed;
        std::cout << "Enter speed of swimmer (M/s) : ";
        std::cin >> inSpeed;
        setName(inName);
        setSpeedOfSwim(inSpeed);
    }


    std::string Swimmer:: getName(){
        return swimmerName;
    }

    void Swimmer::setTotalTime (int total){
        totalTime = total;
    }

    int Swimmer::getTotalTime (){
        return totalTime;
    }

    int Swimmer::getCurrentPosition (){
        return currentPosition;
    }

    bool Swimmer::swimmerFinish (){
        return currentPosition == 100;
    }

    void Swimmer::setCurrentPosition (int currenTime){
        if(currentPosition <=100) currentPosition = currenTime *speedOfSwim;
        if(currentPosition >100) currentPosition = 100;
    }

    void Swimmer::setName (std::string inName){
        swimmerName = inName;
    }

    void Swimmer::setSpeedOfSwim (int inSpeed){
        speedOfSwim = inSpeed;
    }

