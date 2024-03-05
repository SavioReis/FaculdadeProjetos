#include "conjunto.h"
namespace srlg{

Conjunto::Conjunto(int tamanho):
    tamanho(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser menor que 0");
    try {
        array = new int[tamanho];
        this->tamanho=tamanho;
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::srand(seed);
        for(int i=0;i<tamanho;i++){
            int numeroAleatorio = std::rand() %1001;
            array[i] = numeroAleatorio;
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
}
