#include "arvorebinaria.h"

namespace ED1 {
ArvoreBinaria::ArvoreBinaria() : raiz(nullptr) {}

ArvoreBinaria::~ArvoreBinaria() {
    if (raiz != nullptr) {
        delete raiz;
    }
}

void ArvoreBinaria::inserirRecursivo(No*& no, Pessoa pessoa) {
    if (no == nullptr) {
        no = new No(pessoa);
    } else if (pessoa.matricula < no->pessoa.matricula) {
        inserirRecursivo(no->esquerda, pessoa);
    } else {
        inserirRecursivo(no->direita, pessoa);
    }
}

bool ArvoreBinaria::buscarRecursivo(No* no, int matricula, Pessoa& pessoaEncontrada) {
    if (no == nullptr) {
        return false;  // Não encontrou a pessoa na árvore
    }

    if (matricula == no->pessoa.matricula) {
        pessoaEncontrada = no->pessoa;
        return true;  // Encontrou a pessoa na árvore
    }

    if (matricula < no->pessoa.matricula) {
        return buscarRecursivo(no->esquerda, matricula, pessoaEncontrada);
    } else {
        return buscarRecursivo(no->direita, matricula, pessoaEncontrada);
    }
}

void ArvoreBinaria::imprimirRecursivo(No* no) {
    if (no != nullptr) {
        imprimirRecursivo(no->direita);
        std::cout << "Matricula: " << no->pessoa.matricula << ", Nome: " << no->pessoa.nome << std::endl;
        imprimirRecursivo(no->esquerda);
    }
}

void ArvoreBinaria::inserirPessoa(int matricula, const std::string& nome) {
    Pessoa pessoa(matricula, nome);
    inserirRecursivo(raiz, pessoa);
}

bool ArvoreBinaria::buscarPessoa(int matricula, Pessoa& pessoaEncontrada) {
    return buscarRecursivo(raiz, matricula, pessoaEncontrada);
}

void ArvoreBinaria::imprimirEmOrdem() {
    imprimirRecursivo(raiz);
}
}
