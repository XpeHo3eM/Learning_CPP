#pragma once



class Swimmer
{
public:
    Swimmer (std::string& name, double speed);
    std::string getName ();
    double getSpeed ();
    void setFinish ();
    bool getFinish ();
    void setSwimTime (double time);
    double getSwimTime ();

private:
    std::string name = "unknown";
    double speed = 0;
    double time = 0.0;
    bool finish = false;
};



int compare (Swimmer* a, Swimmer* b);