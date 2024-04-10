#include "conjunto.h"
namespace srlg{

Conjunto::Conjunto(int tamanho):
    tamanho(0),
    numExec(0),
    numOrdenSelectionSort(0),
    numOrdenInsertionSort(0),
    numOrdenBubleSort(0),
    numOrdenMergeSort(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser negativo nem 0");
    try {
        array = new int[tamanho];
        arraySelectionSort = new int[tamanho];
        arrayInsertionSort = new int[tamanho];
        arrayBubbleSort = new int[tamanho];
        arrayMergeSort = new int[tamanho];
        arrayHeapSort = new int[tamanho];
        this->tamanho=tamanho;
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::srand(seed);
        for(int i=0;i<tamanho;i++){
            int numeroAleatorio = std::rand() %10001;
            array[i] = numeroAleatorio;
            arraySelectionSort[i] = numeroAleatorio;
            arrayInsertionSort[i] = numeroAleatorio;
            arrayBubbleSort[i] = numeroAleatorio;
            arrayMergeSort[i] = numeroAleatorio;
            arrayHeapSort[i] = numeroAleatorio;
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

QString Conjunto::TooStringBubbleSort(){
    bublesort();
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

QString Conjunto::TooStringMergeSort(){
    mergeSort(arrayMergeSort,0,tamanho-1);
    QString saida = "";
    bool vermelho = true;

    for(int i = 0; i < tamanho; i++){
        if (vermelho) {
            saida += "<font color=\"red\">[ " + QString::number(arrayMergeSort[i]) + " ]</font><font color=\"red\">,</font> ";
        } else {
            saida += "<font color=\"black\">[ " + QString::number(arrayMergeSort[i]) + " ]</font><font color=\"black\">,</font> ";
        }

        vermelho = !vermelho;
    }

    if (!saida.isEmpty()) {
        saida.chop(12);
    }
    return saida;
}

QString Conjunto::TooStringHeapSort(){
    heapSort(arrayHeapSort, tamanho);
    QString saida = "";
    bool vermelho = true;

    for(int i = 0; i < tamanho; i++){
        if (vermelho) {
            saida += "<font color=\"red\">[ " + QString::number(arrayHeapSort[i]) + " ]</font><font color=\"red\">,</font> ";
        } else {
            saida += "<font color=\"black\">[ " + QString::number(arrayHeapSort[i]) + " ]</font><font color=\"black\">,</font> ";
        }

        vermelho = !vermelho;
    }

    if (!saida.isEmpty()) {
        saida.chop(12);
    }
    return saida;
}

void Conjunto::heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void Conjunto::heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}


void Conjunto::merge(int arr[], int p, int q, int r) {
    this->numOrdenMergeSort=0;
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
            numOrdenMergeSort += n1 - i;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Dividir merge
void Conjunto::mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
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

void Conjunto::bublesort(){
    this->numOrdenBubleSort=0;
    for (int step = 0; step < (getTamanho()-1); ++step) {

        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (getTamanho()-step-1); ++i) {

            if (arrayBubbleSort[i] > arrayBubbleSort[i + 1]) {

                int temp = arrayBubbleSort[i];
                arrayBubbleSort[i] = arrayBubbleSort[i + 1];
                arrayBubbleSort[i + 1] = temp;
                numOrdenBubleSort++;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
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

int Conjunto::getNumOrdenBubleSort() const
{
    return numOrdenBubleSort;
}
int Conjunto::getNumOrdenMergeSort() const
{
    return numOrdenMergeSort;
}

}
