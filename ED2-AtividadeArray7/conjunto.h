#ifndef VETORALEATORIO_H
#define VETORALEATORIO_H
#include <QString>
#include <ctime>
#include <random>
namespace srlg{
class Conjunto
{
private:
    int tamanho;
    int *array;
    int *arraySelectionSort;
    int *arrayInsertionSort;
    int numExec;
    int numOrdenSelectionSort;
    int numOrdenInsertionSort;
public:
    Conjunto(int tamanho);
    ~Conjunto();
    int getTamanho() const;
    QString TooString();
    QString TooStringOrdenado();
    QString TooStringInsertionSort();
    void selectionSort();
    void insertionSort();
    int getNumExec() const;
    int getNumOrdenSelectionSort() const;
    int getNumOrdenInsertionSort() const;
};
}
#endif // VETORALEATORIO_H
