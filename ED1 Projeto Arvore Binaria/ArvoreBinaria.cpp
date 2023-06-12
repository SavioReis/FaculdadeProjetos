#include "ArvoreBinaria.h"

namespace ED1 {
    ArvoreBinaria::ArvoreBinaria() :
        raiz(nullptr)
    {
    }

    ArvoreBinaria::~ArvoreBinaria()
    {
        if (raiz != nullptr) {
            delete raiz;
        }
    }

    void ArvoreBinaria::inserirRecursivo(No** raiz, int elemento)
    {
        if (*raiz == nullptr) {
            *raiz = new No(elemento);
        }
        else if (elemento < (*raiz)->getDado()) {
            inserirRecursivo(&(*raiz)->esquerda, elemento);
        }
        else if (elemento > (*raiz)->getDado()) {
            inserirRecursivo(&(*raiz)->direita, elemento);
        }
        else {
            throw std::string("Elemento já existe na árvore");
        }
    }

    void ArvoreBinaria::emOrdem(No* raiz) const
    {
        if (raiz != nullptr) {
            emOrdem(raiz->getEsquerda());
            std::cout << raiz->getDado() << " ";
            emOrdem(raiz->getDireita());
        }
    }

    int ArvoreBinaria::retornar_Maior(No** raiz)
    {
        int valor;
        No* aux = nullptr;
        if ((*raiz)->direita != nullptr) {
            return retornar_Maior(&(*raiz)->direita);
        }
        else {
            aux = *raiz;
            valor = (*raiz)->getDado();
            *raiz = (*raiz)->esquerda;
            aux->esquerda = nullptr;
            aux->direita = nullptr;
            delete aux;
            return valor;
        }
    }

    void ArvoreBinaria::posFixadoEsquerda(No* raiz) const
    {
        if (raiz != nullptr) {
            posFixadoEsquerda(raiz->getEsquerda());
            posFixadoEsquerda(raiz->getDireita());
            std::cout << raiz->getDado() << " ";
        }
    }

    void ArvoreBinaria::centralEsquerda(No* raiz) const
    {
        if (raiz != nullptr) {
            centralEsquerda(raiz->getEsquerda());
            std::cout << raiz->getDado() << " ";
            centralEsquerda(raiz->getDireita());
        }
    }

    void ArvoreBinaria::preFixadoDireita(No* raiz) const
    {
        if (raiz != nullptr) {
            std::cout << raiz->getDado() << " ";
            preFixadoDireita(raiz->getDireita());
            preFixadoDireita(raiz->getEsquerda());
        }
    }

    void ArvoreBinaria::posFixadoDireita(No* raiz) const
    {
        if (raiz != nullptr) {
            posFixadoDireita(raiz->getDireita());
            posFixadoDireita(raiz->getEsquerda());
            std::cout << raiz->getDado() << " ";
        }
    }

    void ArvoreBinaria::imprimir()
    {
        std::cout << "Encaminhamento Central a Esquerda: ";
        emOrdem(raiz);
        std::cout << std::endl << "Encaminhamento Pós-Fixado à Esquerda: ";
        posFixadoEsquerda(raiz);
        std::cout << std::endl << "Encaminhamento Central à Esquerda: ";
        centralEsquerda(raiz);
        std::cout << std::endl << "Encaminhamento Pré-Fixado à Direita: ";
        preFixadoDireita(raiz);
        std::cout << std::endl << "Encaminhamento Pós-Fixado à Direita: ";
        posFixadoDireita(raiz);
        std::cout << std::endl;
    }

    void ArvoreBinaria::removerRecursivo(No** raiz, int elemento)
    {
        No* aux = nullptr;
        if (*raiz != nullptr) {
            if ((*raiz)->getDado() == elemento) {
                aux = *raiz;
                if ((*raiz)->esquerda == nullptr) {
                    *raiz = (*raiz)->direita;
                    aux->esquerda = nullptr;
                    aux->direita = nullptr;
                    delete aux;
                }
                else if ((*raiz)->direita == nullptr) {
                    *raiz = (*raiz)->esquerda;
                    aux->esquerda = nullptr;
                    aux->direita = nullptr;
                    delete aux;
                }
                else {
                    (*raiz)->setDado(this->retornar_Maior(&(*raiz)->esquerda));
                }
            }
            else {
                if ((*raiz)->getDado() < elemento) {
                    removerRecursivo(&(*raiz)->direita, elemento);
                }
                else if ((*raiz)->getDado() > elemento) {
                    removerRecursivo(&(*raiz)->esquerda, elemento);
                }
            }
        }
        else {
            throw std::string("Elemento não existe na árvore");
        }
    }
}


