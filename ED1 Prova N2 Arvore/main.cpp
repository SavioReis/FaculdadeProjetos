#include <QCoreApplication>
#include <iostream>
#include "arvorebinaria.h"

int main(int argc, char *argv[])
{
    ED1::ArvoreBinaria arvore;

    // Exemplo de inserção de pessoas na árvore
    arvore.inserirPessoa(1001, "Joao");
    arvore.inserirPessoa(1005, "Maria");
    arvore.inserirPessoa(1003, "Pedro");
    arvore.inserirPessoa(1002, "Ana");

    // Exemplo de impressão em ordem (decrescente)
    std::cout << "Impressao em ordem (decrescente):" << std::endl;
    arvore.imprimirEmOrdem();

    // Exemplo de busca de pessoa na árvore
    ED1::Pessoa pessoaEncontrada(0, "");
    if (arvore.buscarPessoa(1001, pessoaEncontrada)) {
        std::cout << "Pessoa encontrada: Matricula: " << pessoaEncontrada.matricula << ", Nome: " << pessoaEncontrada.nome << std::endl;
    } else {
        std::cout << "Pessoa não encontrada!" << std::endl;
    }

    QCoreApplication a(argc, argv);

    return a.exec();
}
