#ifndef EMPRESA_H
#define EMPRESA_H
#include <string>
#include "onibus.hpp"
struct empresa
{
    int _totalbus;
    onibus* vetor[20];

    empresa()
    {
        _totalbus = 0;
        for (int i = 0; i < 20; i++)
        {
            vetor[i] = nullptr;
        }
    }
    void adicionar_onibus(std::string placa, int lotmax);
    onibus* busca_onibus(std::string placa);
    void imprimir_estado();
};
#endif