#include "no.h"

namespace srlg{

int No::getDado() const
{
    return dado;
}

void No::setDado(int newDado)
{
    dado = newDado;
}

No *No::getEnderecoProximo() const
{
    return proximo;
}

void No::setEnderecoProximo(No *newProximo)
{
    proximo = newProximo;
}
No *No::getEnderecoAnterior() const
{
    return anterior;
}

void No::setEnderecoAnterior(No *newAnterior)
{
    anterior = newAnterior;
}

No::No():
    dado(0),
    proximo(0),
    anterior(0)
{
}
No::No(int dado):
    dado(dado),
    proximo(0),
    anterior(0)
{
}

}
