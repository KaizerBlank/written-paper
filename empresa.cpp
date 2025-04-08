#include "empresa.hpp"
#include <iostream>

void empresa::adicionar_onibus(std:: string placa, int lotmax)
{
    for (int i = 0; i < _totalbus; i++)
    {
        if (placa == vetor[i]->_placa)
        {
            std::cout << "ERRO : onibus repetido" << std::endl;
            return;
        }
    }

    if (_totalbus < 20)
    {
        vetor[_totalbus] = new onibus(placa, lotmax);
        _totalbus++;
        std::cout << "novo onibus cadastrado" << std::endl;
    }
    else
    {
        std::cout << "ERRO : limite de onibus atingido" << std::endl;
    }
}

onibus* empresa::busca_onibus(std::string placa)
{
    for (int i = 0; i < 20; i++)
    {
        if (vetor[i]->_placa == placa)
        {
            return vetor[i];
        }
    }
    return nullptr;
}

void empresa::imprimir_estado()
{
    for (int i = 0; i < _totalbus; i++)
    {
        if (vetor[i] != nullptr)
        {
            vetor[i]->imprimir_estado();
        }
    }
}