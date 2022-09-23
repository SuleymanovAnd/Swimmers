#include <iostream>

class Swimmer {
    std::string swimmerName;
    int speedOfSwim;
    int currentPosition = 0;
    int totalTime = 0;

    void setName (std::string inName);
    void setSpeedOfSwim (int inSpeed);
public:
    Swimmer ();

    std::string getName();
    void setTotalTime (int total);
    int getTotalTime ();
    int getCurrentPosition ();
    bool swimmerFinish ();
    void setCurrentPosition (int currenTime);

    ~Swimmer() = default;
};