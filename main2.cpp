#include "main2.hpp"

void Power::start()
{
    cout << "Motor Ligado!" << endl;
}

void Power::stop()
{
    cout << "Motor desligado!" << endl;
}

int Power::changeRpm(int rpm, bool is_increasing)
{
    if (rpm < 0)
    {
        cout << "RPM nao pode ser negativo!" << endl;
        return 0;
    }

    if (rpm > 10000)
    {
        cout << "RPM máximo atingido!" << endl;
        return 0;
    }

    if (is_increasing)
    {
        cout << "Aumentando RPM para " << rpm << endl;
        return 1;
    }

    cout << "Aumentando RPM para " << rpm << endl;
    return 1;
}

Power power_class;

void Car::startCar()
{
    if (!is_up) {
        power_class.start();
        is_up = true;

        return;
    }

    cout << "O carro já estava ligado" << endl;
};

void Car::stopCar()
{
    if (is_up)
    {
        power_class.stop();
        is_up = false;

        return;
    }

    cout << "O carro já estava desligado" << endl;
};

void Car::increaseRpmCar(int rpm)
{
    if (!is_up)
    {
        cout << "O motor precisa estar ligado!" << endl;
        return;
    }

    bool changed = power_class.changeRpm(rpm_real_time + rpm, true);

    if (changed) {
        rpm_real_time += rpm;
        register_rpm.push_back(rpm_real_time);
    }

};

void Car::decreaseRpmCar(int rpm)
{
    if (!is_up)
    {
        cout << "O motor precisa estar ligado!" << endl;
        return;
    }

    bool changed = power_class.changeRpm(rpm_real_time - rpm, false);

    if (changed) {
        rpm_real_time -= rpm;
        register_rpm.push_back(rpm_real_time);
    }
};

void Car::showRegisters()
{
    for (int i = 0; i < register_rpm.size(); i++)
    {        
        cout << "Registro " << i + 1 << ": " << register_rpm[i] << " RPM" << endl;
    }
};

int main()
{
    Car myCar;

    myCar.startCar();

    myCar.increaseRpmCar(12000);
    myCar.decreaseRpmCar(13000);
    myCar.increaseRpmCar(10000);
    myCar.decreaseRpmCar(2000);
    myCar.increaseRpmCar(8000);
    myCar.decreaseRpmCar(1000);
    myCar.decreaseRpmCar(4000);
    myCar.increaseRpmCar(8000);
    myCar.decreaseRpmCar(4000);

    myCar.stopCar();
    myCar.showRegisters();

    return 0;
}