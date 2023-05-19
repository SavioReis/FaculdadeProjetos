#ifndef PILHA_H
#define PILHA_H
#include <QString>
namespace srlg {


class Pilha
{
private:
    int topo = -1;
    int *Vetor = nullptr;
    int tamanho;
public:

    int retirar();
    int acessar();
    bool estaCheio() const;
    bool estaVazio() const;
    void inserir(int elemento);
    Pilha(int MaxVetor);
    int Tamanho() const;
    QString mostrar();
    ~Pilha();
};
}
#endif // PILHA_H
