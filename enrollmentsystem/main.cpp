#include "aluno.hpp"
#include<iostream>
#include<algorithm>
#include <iomanip>

int main(){
    std::vector<Aluno> alunos;

    while (true) {
        std::string nome;
        getline(std::cin, nome);
        if (nome == "END") {
            break;
        }
    
    int matricula;
    std::cin >> matricula;
    std::cin.ignore();
    std::vector<int> notas;
    int nota;
    while (std::cin >> nota && nota != -1) {
        notas.push_back(nota);
    }
    std::cin.ignore();
    alunos.push_back(Aluno(nome, matricula, notas));
    }
    
    std::sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
        return a.getNome() < b.getNome();
    });

    for (size_t i = 0; i < alunos.size(); i++) {
        Aluno aluno = alunos[i];
        std::cout << aluno.getMatricula() << " " << aluno.getNome() << " ";
        std::vector<int> notas = aluno.getNotas();
        for (int nota : notas){
            std::cout << nota << " ";
        }
        std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << aluno.calcularmedia() << " " << aluno.notamax() << " " << aluno.notamin() << std::endl;
    }
    
    
}