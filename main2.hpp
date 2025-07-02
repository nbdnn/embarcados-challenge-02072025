#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <vector>

using namespace std;
class Power
{
private:
public:
    void start();
    void stop();
    int changeRpm(int rpm, bool is_increasing);
};

class Car
{
private:
    bool is_up = false;
    int rpm_real_time = 0;
    vector<int> register_rpm;

public:
    void startCar();
    void stopCar();
    void increaseRpmCar(int rpm);
    void decreaseRpmCar(int rpm);
    void showRegisters();
};

#endif
