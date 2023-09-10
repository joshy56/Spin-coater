#ifndef CoatingProcess_h
#define CoatingProcess_h

#include <Arduino.h>

class CoatingProcess
{
public:
    void reset();
    unsigned long time();
    void time(const unsigned long time);
    byte speedPercentage();
    void speedPercentage(const byte percentage);

private:
    unsigned long _time;
    byte _speedPercentage;
};

#endif