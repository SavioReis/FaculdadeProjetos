#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include "No.h"
#include "IArvoreBinaria.h"
#include <string>
#include <iostream>

namespace ED1 {
    class ArvoreBinaria : public IArvoreBinaria {
    private:
        No* raiz;

    private:
        void inserirRecursivo(No** raiz, int elemento);
        void removerRecursivo(No** raiz, int elemento);
        void emOrdem(No* raiz) const;
        void posFixadoEsquerda(No* raiz) const;
        void centralEsquerda(No* raiz) const;
        void preFixadoDireita(No* raiz) const;
        void posFixadoDireita(No* raiz) const;
        int retornar_Maior(No** raiz);

    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void inserir(int elemento) { this->inserirRecursivo(&raiz, elemento); }
        void remover(int elemento) { this->removerRecursivo(&raiz, elemento); }
        void imprimir();
    };
}

#endif // ARVOREBINARIA_H
