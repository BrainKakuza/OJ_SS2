/*
Description

Motor is a kind of device which generate motion power by electrical power. We can design a type to measuring runnable time of a motor as followed:

class Motor {
    double energy, resistance, current;
public:
    Motor(double E, double R, double I): energy(E), resistance(R), current(I) {}
    double runnableTime() const {
        return energy / (resistance * current * current);
    }
};

Engine is a kind of device which convert heat moment to motion power. We can design a type to measuring runnable time of a engine as followed:

class Engine {
    double energy, performance;
public:
    Engine(double E, double P): energy(E), performance(P) {}
    double runnableTime() const {
        return energy / performance;
    }
};

A Hybrid engine is a new technique that we can generate motion power by both of above mechanics
. Please write a class namedHybridinherent both of above classes and redefinedrunnableTime(). 
Note that, our hybrid engine should active both of motor and engine, if any of them be down, then our engine will be stopped.


Input
NONE

Output
NONE

Sample Input 1 
NONE

Sample Output 1
NONE
*/

#include <iostream>

using namespace std;

class Motor
{
    double energy, resistance, current;

public:
    Motor(double E, double R, double I) : energy(E), resistance(R), current(I) {}
    double runnableTime() const
    {
        return energy / (resistance * current * current);
    }
};

class Engine
{
    double energy, performance;

public:
    Engine(double E, double P) : energy(E), performance(P) {}
    double runnableTime() const
    {
        return energy / performance;
    }
};

class Hybrid : public Motor, public Engine
{
private:
    double energy;
public:
    Hybrid(double ME, double MR, double MI, double EE, double EP) : Motor(ME, MR, MI), Engine(EE, EP), energy(ME)
    {
    }
    
    double runnableTime() const
    {
        double runtimeOne = Engine::runnableTime();
        double runtimeTwo = Motor::runnableTime();

        if((runtimeOne == 0 && runtimeTwo == 0) || (runtimeOne == 0 && runtimeTwo != 0) || (runtimeOne != 0 && runtimeTwo == 0))
        {
            return 0;
        }else if(runtimeOne > runtimeTwo)
        {
            return runtimeOne;
        }else if(runtimeTwo > runtimeOne)
        {
            return runtimeTwo;
        }else if(runtimeOne == runtimeTwo)
        {
            return runtimeOne;
        }


    }
};

int main(void)
{
    

    return 0;
}