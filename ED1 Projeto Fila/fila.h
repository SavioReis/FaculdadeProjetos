#ifndef FILA_H
#define FILA_H
#include <QString>

namespace srlg{

class Fila
{
private:
    int tamanho;
    int *array;
    int inicio;
    int final;
    int quantidadeElementos;
public:
    Fila(int tamanho);
    ~Fila();
    int acessar()const;
    void inserir(int elemento);
    int retirar();
    bool estaVazia()const;
    bool estaCheia()const;
};
}
#endif // FILA_H
