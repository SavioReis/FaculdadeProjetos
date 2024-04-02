#include "conjunto.h"
namespace srlg{

Conjunto::Conjunto(int tamanho):
    tamanho(0),
    numExec(0),
    numOrdenSelectionSort(0),
    numOrdenInsertionSort(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser negativo nem 0");
    try {
        array = new int[tamanho];
        arraySelectionSort = new int[tamanho];
        arrayInsertionSort = new int[tamanho];
        this->tamanho=tamanho;
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::srand(seed);
        for(int i=0;i<tamanho;i++){
            int numeroAleatorio = std::rand() %1000 +1;
            array[i] = numeroAleatorio;
            arraySelectionSort[i] = numeroAleatorio;
            arrayInsertionSort[i] = numeroAleatorio;
        }
    } catch (std::bad_alloc &erro) {
        throw QString ("Erro ao gerar número aleatório");
    }
}
Conjunto::~Conjunto(){
    delete[] array;
}

int Conjunto::getTamanho() const
{
    return tamanho;
}
QString Conjunto::TooString(){
    QString saida = "";
    bool vermelho = true;

    for(int i = 0; i < tamanho; i++){
        if (vermelho) {
            saida += "<font color=\"red\">[ " + QString::number(array[i]) + " ]</font><font color=\"red\">,</font> ";
        } else {
            saida += "<font color=\"black\">[ " + QString::number(array[i]) + " ]</font><font color=\"black\">,</font> ";
        }

        vermelho = !vermelho;
    }

    if (!saida.isEmpty()) {
        saida.chop(12);
    }
    return saida;
}
QString Conjunto::TooStringOrdenado(){
    selectionSort();
    QString saida = "";
    bool vermelho = true;

    for(int i = 0; i < tamanho; i++){
        if (vermelho) {
            saida += "<font color=\"red\">[ " + QString::number(arraySelectionSort[i]) + " ]</font><font color=\"red\">,</font> ";
        } else {
            saida += "<font color=\"black\">[ " + QString::number(arraySelectionSort[i]) + " ]</font><font color=\"black\">,</font> ";
        }

        vermelho = !vermelho;
    }

    if (!saida.isEmpty()) {
        saida.chop(12);
    }
    return saida;
}
QString Conjunto::TooStringInsertionSort(){
    insertionSort();
    QString saida = "";
    bool vermelho = true;

    for(int i = 0; i < tamanho; i++){
        if (vermelho) {
            saida += "<font color=\"red\">[ " + QString::number(arrayInsertionSort[i]) + " ]</font><font color=\"red\">,</font> ";
        } else {
            saida += "<font color=\"black\">[ " + QString::number(arrayInsertionSort[i]) + " ]</font><font color=\"black\">,</font> ";
        }

        vermelho = !vermelho;
    }

    if (!saida.isEmpty()) {
        saida.chop(12);
    }
    return saida;
}

void Conjunto::selectionSort(){
    this->numOrdenSelectionSort=0;
    for(int step = 0; step < getTamanho() -1; step++){
        int num_min = step;
        for(int i = step + 1; i < getTamanho(); i++){
            numOrdenSelectionSort++;
            if(arraySelectionSort[i] < arraySelectionSort[num_min]){
                num_min = i;
                numOrdenSelectionSort++;
            }
        }
        int temp = arraySelectionSort[step];
        arraySelectionSort[step] = arraySelectionSort[num_min];
        arraySelectionSort[num_min] = temp;
    }
}
void Conjunto::insertionSort() {
    this->numOrdenInsertionSort=0;
    for (int step = 1; step < getTamanho(); step++) {
        int key = arrayInsertionSort[step];
        int j = step - 1;
        numOrdenInsertionSort++;
        while (key < arrayInsertionSort[j] && j >= 0) {
            arrayInsertionSort[j + 1] = arrayInsertionSort[j];
            --j;
            numOrdenInsertionSort++;
        }
        arrayInsertionSort[j + 1] = key;
    }
}

int Conjunto::getNumExec() const
{
    return numExec;
}

int Conjunto::getNumOrdenSelectionSort() const
{
    return numOrdenSelectionSort;
}

int Conjunto::getNumOrdenInsertionSort() const
{
    return numOrdenInsertionSort;
}

}
