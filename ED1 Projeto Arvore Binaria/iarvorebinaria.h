#ifndef IARVOREBINARIA_H
#define IARVOREBINARIA_H
namespace ED1{
class IArvoreBinaria{
    virtual void inserir(int elemento) = 0;
    virtual void imprimir() = 0;
    virtual void remover(int elemento) = 0;
};
}
#endif // IARVOREBINARIA_H
