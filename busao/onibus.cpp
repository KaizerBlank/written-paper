#include "onibus.hpp"
#include<iostream>

onibus::onibus(std::string placa, int capmax)
{
    _placa = placa;
    _capmax = capmax;
    _lotatual = 0;
}

int onibus::subir_passageiros(int pas)
{
    if (_lotatual + pas > _capmax)
    {
        return -1;
    }
    
    _lotatual += pas;
    return _lotatual;
}

int onibus::descer_passageiros(int des)
{
    if (_lotatual - des < 0)
    {
        return - 1;
    }
    
    _lotatual -= des;
    return _lotatual;
}

void onibus::transfere_passageiros(onibus &outro, int trans)
{
    outro._lotatual += trans;
}

void onibus::imprimir_estado()
{
    std::cout << _placa << " (" << _lotatual << "/" << _capmax << ")" << std::endl;
}