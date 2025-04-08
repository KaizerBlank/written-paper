#include "empresa.hpp"
#include "onibus.hpp"
#include<iostream>
#include<sstream>

int main()
{
    std:: string entry;
    empresa e;
    while (std::getline(std::cin, entry))
    {
        char type;
        std::string placa;
        int valor;
        std::istringstream iss(entry);
        iss >> type >> placa >> valor;

        if (type == 'C')
        {
            e.adicionar_onibus(placa, valor);
        }
        else if (type == 'S')
        {
            onibus* o = e.busca_onibus(placa);
            if (o == nullptr)
            {
                std::cout << "ERRO : onibus inexistente" << std::endl;
            }
            else
            {
                int resultado = o->subir_passageiros(valor);
                if (resultado == -1)
                {
                    std::cout << "ERRO : onibus lotado" << std::endl;
                }
                else
                {
                    std::cout << "passageiros subiram com sucesso";
                }
            }
        }
        else if (type == 'D')
        {
            onibus* o = e.busca_onibus(placa);
            if (o == nullptr)
            {
                std::cout << "ERRO : onibus inexistente" << std::endl;
            }
            else
            {
                int resultado = o->descer_passageiros(valor);
                if (resultado == -1)
                {
                    std::cout << "ERRO : faltam passageiros" << std::endl;
                }
                else
                {
                    std::cout << "passageiros desceram com sucesso" << std::endl;
                }
            }
        }
        else if (type == 'T')
        {

        }
        else if (type == 'I')
        {

        }
        else if (type == 'F')
        {
            return 0;
        }
        e.imprimir_estado();
    }
    
}