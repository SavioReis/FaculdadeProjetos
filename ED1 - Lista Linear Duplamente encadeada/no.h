#ifndef NO_H
#define NO_H

namespace srlg{
class No
{
private:
    int dado;
    No* proximo;
    No* anterior;
public:
    No();
    No(int dado);
    int getDado() const;
    void setDado(int newDado);
    No *getEnderecoProximo() const;
    void setEnderecoProximo(No *newProximo);
    No *getEnderecoAnterior() const;
    void setEnderecoAnterior(No *newAnterior);
};
}
#endif // NO_H
