#ifndef NO_H
#define NO_H

#include <QString>

namespace srlg{
    class No
    {
    private:
        int dado;
        No* enderecoProximo;
    public:
        No();
        No(int dado);

        int getDado() const;
        void setDado(int newDado);
        No *getEnderecoProximo() const;
        void setEnderecoProximo(No *newEnderecoProximo);
    };
}
#endif // NO_H
