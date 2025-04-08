#ifndef ONIBUS_H
#define ONIBUS_H
#include <string>

struct onibus
{
    std::string _placa;
    int _capmax, _lotatual;

    onibus(std::string, int);
    int subir_passageiros(int pas);
    int descer_passageiros(int des);
    void transfere_passageiros(onibus &outro, int trans);
    void imprimir_estado();
};
#endif