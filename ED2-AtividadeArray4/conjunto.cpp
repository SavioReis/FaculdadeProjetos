#include "conjunto.h"
namespace srlg{

Conjunto::Conjunto(int tamanho):
    tamanho(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser negativo nem 0");
    try {
        array = new int[tamanho];
        arraySelectionSort = new int[tamanho];
        this->tamanho=tamanho;
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::srand(seed);
        for(int i=0;i<tamanho;i++){
            int numeroAleatorio = std::rand() %1001;
            array[i] = numeroAleatorio;
            arraySelectionSort[i] = numeroAleatorio;
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
int Conjunto::buscarSequencial(int valor){
    for(int pos=0;pos<tamanho;pos++){
        if(valor == array[pos]){
            return pos;
        }
    }
    throw QString("O número procurado não existe");
}
int Conjunto::buscarSequencialMelhorado(int aux){
    for(int i=0;i<tamanho;i++){
        if(aux == arraySelectionSort[i]){
            return i;
        }
        if(aux < arraySelectionSort[i]){
            throw QString("O número procurado não existe");
        }
    }
    throw QString("O número procurado não existe");
}
void Conjunto::selectionSort(){
    for(int step = 0; step < getTamanho() -1; step++){
        int num_min = step;
        for(int i = step + 1; i < getTamanho(); i++){
            if(arraySelectionSort[i] < arraySelectionSort[num_min]){
                num_min = i;
            }
        }
        int temp = arraySelectionSort[step];
        arraySelectionSort[step] = arraySelectionSort[num_min];
        arraySelectionSort[num_min] = temp;
    }
}
int Conjunto::buscarBinaria(int aux){
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (arraySelectionSort[meio] == aux)
            return meio;
        if (arraySelectionSort[meio] < aux)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    throw QString("O número procurado não existe");
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
}
