#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <QString>
#include "ctime"
namespace srlg{
class Conjunto
{
private:
    int tamanho;
    int *array;
    int *arraySelectionSort;
public:
    //construtor
    Conjunto(int tamanho);

    //destrutor
    ~Conjunto();

    //funções
    int getTamanho() const;
    QString TooString();
    QString TooStringOrdenado();
    int buscarSequencial(int valor);
    int buscarSequencialMelhorado(int aux);
    void selectionSort();
    int buscarBinaria(int aux);
};
}
#endif // CONJUNTO_H
