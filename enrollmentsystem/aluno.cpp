#include "aluno.hpp"
#include <numeric>
#include <algorithm>

Aluno::Aluno(std::string nome, int nummatricula, std::vector<int> notas){
    this->_nome = nome;
    this->_nummatricula = nummatricula;
    this->_notas = notas;
}

Aluno::Aluno(){
    _nome = " ";
    _nummatricula = 0;
    _notas.push_back(0);
}

float Aluno::calcularmedia() {
    if (_notas.empty()) {
        return 0;
    }
    float soma = std::accumulate(_notas.begin(), _notas.end(), 0);
    return soma / _notas.size();
}

int Aluno::notamax() {
    return *std::max_element(_notas.begin(), _notas.end());
}

int Aluno::notamin() {
    return *std::min_element(_notas.begin(), _notas.end());
}

std::string Aluno::getNome() const {
    return _nome;
}

int Aluno::getMatricula() const {
    return _nummatricula;
}

std::vector<int> Aluno::getNotas() const {
    return _notas;
}
