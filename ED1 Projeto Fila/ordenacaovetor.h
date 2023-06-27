#ifndef ORDENACAOVETOR_H
#define ORDENACAOVETOR_H
#include <ctime>
#include <fila.h>
namespace srlg{
class OrdenacaoVetor
{
private:
    int tamanho;
    int *array;
public:
    OrdenacaoVetor(int tamanho);
    ~OrdenacaoVetor();
    QString mostrarResultado()const;
    void ordenarCrescente();
    void ordenarDecrescente();
};
}
#endif // ORDENACAOVETOR_H
