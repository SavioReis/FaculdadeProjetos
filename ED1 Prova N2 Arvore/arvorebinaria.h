#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <iostream>
#include "no.h"

namespace ED1 {
class ArvoreBinaria {
private:
    No* raiz;

    void inserirRecursivo(No*& no, Pessoa pessoa);
    bool buscarRecursivo(No* no, int matricula, Pessoa& pessoaEncontrada);
    void imprimirRecursivo(No* no);

public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void inserirPessoa(int matricula, const std::string& nome);
    bool buscarPessoa(int matricula, Pessoa& pessoaEncontrada);
    void imprimirEmOrdem();
};
}

#endif  // ARVORE_BINARIA_H
