#include "main.hpp"

void Motor::ligar()
{
    cout << "Motor Ligado!" << endl;
}

void Motor::desligar()
{
    cout << "Motor desligado!" << endl;
}

void Motor::aumentarRpm(int rpm_int)
{
    if (rpm_int < 0)
    {
        cout << "RPM nao pode ser negativo!" << endl;
    }
    else if (rpm_int > 10000) // erro no nome da variável
    {
        cout << "RPM máximo atingido!" << endl;
    }
    else
    {
        cout << "Aumentando RPM para " << rpm_int << endl;
    }
}

void Motor::diminuirRpm(int rpm_int)
{
    // if (rpm_int < -1000) // RPM nao pode ser negativo
    if (rpm_int < 0)
    {
        cout << "RPM nao pode ser negativo!" << endl;
        // while (1){};
        // Esse loop infinito vai fazer a aplicacao ficar presa aqui sem dar um erro
        return;
    }
    // else if (rpm_int > 100000)  // Que RPM alto
    else if (rpm_int > 10000)
    {
        cout << "RPM nao pode ser maior que 10000!" << endl;
    }
    else
    {

        cout << "Diminuindo RPM para " << rpm_int << endl;
    }
}

Motor motor_class;

void Carro::ligarCarro()
{
    // incluir uma verificação tambem para se o motor já estiver ligado. Pois não se
    // dá partida em um motor que já está ligado
    if (!motorLigado_b) {
        motor_class.ligar();
        motorLigado_b = true;

        return;
    }

    cout << "O carro já estava ligado" << endl; // adicionei uma linha para verificar se estamos tentando ligar um carro já ligado
    // motor_class.ligar();
    // motorLigado_b = !(motorLigado_b); // Se o motor já estiver ligado essa flag fica falsa
};

void Carro::desligarCarro()
{
    if (motorLigado_b)
    {
        motor_class.desligar();
        motorLigado_b = false;

        return;
    }

    cout << "O carro já estava desligado" << endl;
};

void Carro::aumentarRpmCarro(int rpm_int)
{
    if (!motorLigado_b)
    {
        cout << "O motor precisa estar ligado!" << endl;
        return;
    }

    if (rpmAtual_int + rpm_int > 10000) {
        cout << "RPM máximo atingido!" << endl;
        return;
    }

    rpmAtual_int += rpm_int;
    motor_class.aumentarRpm(rpmAtual_int);
    registrosRpm_int.push_back(rpmAtual_int);
};

void Carro::diminuirRpmCarro(int rpm_int)
{
    if (!motorLigado_b)
    {
        cout << "O motor precisa estar ligado!" << endl;
        return; // Faltou o return
    }

    if (rpmAtual_int - rpm_int < 0) {
        cout << "RPM nao pode ser negativo!" << endl;
        return;
    }

    rpmAtual_int -= rpm_int;
    motor_class.diminuirRpm(rpmAtual_int);
    registrosRpm_int.push_back(rpmAtual_int);
};

void Carro::exibirRegistros()
{
    for (int i = 0; i < registrosRpm_int.size(); i++)
    {
        // if (i < 4) // deve listar todas as mudanças
        // {
        // }
        
        cout << "Registro " << i + 1 << ": " << registrosRpm_int[i] << " RPM" << endl;
    }
};

int main()
{
    Carro meuCarro;

    meuCarro.ligarCarro();

    meuCarro.aumentarRpmCarro(12000);
    meuCarro.diminuirRpmCarro(13000);
    meuCarro.aumentarRpmCarro(10000);
    meuCarro.diminuirRpmCarro(2000);
    meuCarro.aumentarRpmCarro(8000);
    meuCarro.diminuirRpmCarro(1000);
    meuCarro.diminuirRpmCarro(4000);
    meuCarro.aumentarRpmCarro(8000);
    meuCarro.diminuirRpmCarro(4000);

    meuCarro.desligarCarro();
    meuCarro.exibirRegistros();

    return 0;
}