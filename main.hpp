#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <vector>

using namespace std;
class Motor
{
private:
public:
    // int rpms_int;
    void ligar();
    void desligar();
    void aumentarRpm(int rpm_int);
    void diminuirRpm(int rpm_int);
};

class Carro
{
private:
    bool motorLigado_b = false;
    int rpmAtual_int = 0;
    vector<int> registrosRpm_int;

public:
    void ligarCarro();
    void desligarCarro();
    void aumentarRpmCarro(int rpm_int);
    void diminuirRpmCarro(int rpm_int);
    void exibirRegistros();
};

#endif
