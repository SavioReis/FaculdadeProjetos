#ifndef VETORALEATORIO_H
#define VETORALEATORIO_H
#include <QString>
#include <ctime>
#include <random>
#include <bits/stdc++.h> //todas bibliotecas
namespace srlg{
class Conjunto
{
private:
    int tamanho;
    int *array;
    int *arraySelectionSort;
    int *arrayInsertionSort;
    int *arrayBubbleSort;
    int *arrayMergeSort;
    int *arrayHeapSort;
    int numExec;
    int numOrdenSelectionSort;
    int numOrdenInsertionSort;
    int numOrdenBubleSort;
    int numOrdenMergeSort;
public:
    Conjunto(int tamanho);
    ~Conjunto();
    int getTamanho() const;
    QString TooString();
    QString TooStringOrdenado();
    QString TooStringInsertionSort();
    QString TooStringBubbleSort();
    QString TooStringMergeSort();
    QString TooStringHeapSort();
    void selectionSort();
    void insertionSort();
    void bublesort();
    void merge(int arr[], int p, int q, int r);
    void mergeSort(int arr[], int l, int r);
    void heapify(int arr[], int n, int i);
    void heapSort(int arr[], int n);
    int getNumExec() const;
    int getNumOrdenSelectionSort() const;
    int getNumOrdenInsertionSort() const;
    int getNumOrdenBubleSort() const;
    int getNumOrdenMergeSort() const;
};
}
#endif // VETORALEATORIO_H
