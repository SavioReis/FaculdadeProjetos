#ifndef NO_H
#define NO_H

#include <QString>

template <class L>
class NO
{
private:
    L dado;
    NO *proximo;
    NO *anterior;

public:
    NO() : dado(),
        proximo(0),
        anterior(0)
    {
    }

    NO(const L &newDado) : dado(newDado),
        proximo(0),
        anterior(0)
    {
    }

    L getDado() const
    {
        return dado;
    }

    void setDado(const L &newDado)
    {
        dado = newDado;
    }

    NO *getProximo() const
    {
        return proximo;
    }

    void setProximo(NO *newProximo)
    {
        proximo = newProximo;
    }

    NO *getAnterior() const
    {
        return anterior;
    }

    void setAnterior(NO *newAnterior)
    {
        anterior = newAnterior;
    }
};

#endif // NO_H
