#ifndef ALUNO_H
#define ALUNO_H

#include<string>
#include<vector>

class Aluno {

    private:
    std::string _nome;
    int _nummatricula;
    std::vector<int> _notas;

    public:
    Aluno();
    Aluno(std::string nome, int nummatricula, std::vector<int> notas);
    float calcularmedia();
    int notamax();
    int notamin();

    
    std::string getNome() const;
    int getMatricula() const;
    std::vector<int> getNotas() const;
};
#endif