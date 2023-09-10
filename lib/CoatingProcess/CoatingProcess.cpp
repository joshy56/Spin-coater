#include "CoatingProcess.h"

void CoatingProcess::reset() {
    time(0);
    speedPercentage(0);
}

unsigned long CoatingProcess::time() {
    return _time;
}

void CoatingProcess::time(const unsigned long time) {
    _time = time;
}

byte CoatingProcess::speedPercentage() {
    return _speedPercentage;
}

void CoatingProcess::speedPercentage(const byte percentage) {
    if(percentage < 0) {
        _speedPercentage = 0;
        return;
    }
    if(percentage > 100) {
        _speedPercentage = 100;
        return;
    }
    _speedPercentage = percentage;
}