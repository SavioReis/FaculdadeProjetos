#ifndef NO_H
#define NO_H
#include<iostream>
namespace ED1{
class No
{
private:
    int dado;
public:
    No *direita;
    No *esquerda;
public:
    No(int dado);
    ~No();
    int getDado()const{return dado;}
    void setDado(int dado){this->dado = dado;}
    No* getDireita(){return direita;}
    void setDireita(No* direita){this->direita = direita;}
    No* getEsquerda(){return esquerda;}
    void setEsquerda(No* esquerda){this->esquerda = esquerda;}
};
}
#endif // NO_H
