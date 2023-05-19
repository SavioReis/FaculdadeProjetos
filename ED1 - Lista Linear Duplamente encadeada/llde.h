#ifndef LLDE_H
#define LLDE_H
#include <no.h>
#include <QString>
#include <QMessageBox>

namespace srlg{

class LLDE
{
private:
    int quantidadeDeBagulho;
    No* inicio;
    No* fim;
public:
    LLDE();

    QString obterLista()const;
    QString obterListaOrdenada()const;
    bool estaVazia()const;
    int getquantidadeDeBagulho() const;

    void inserirInicio(int elemento);
    int acessarInicio()const;
    int retirarInicio();

    void inserirFim(int elemento);
    int acessarFim()const;
    int retirarFim();

    int retirarPos(int pos);
    int operator[](int pos) const;
    void inserirPos(int pos, int elemento);

    void inserirPosicao(int elemento, int posicao);
    int acessarPosicao(int posicao)const;
    int retirarPosicao(int posicao);

    void inserirOrdenadoCrescente();
    void inserirOrdenadoDecrescente();
};
}
#endif // LLDE_H
