#include "ordenacaovetor.h"
namespace srlg{
OrdenacaoVetor::OrdenacaoVetor(int tamanho):
    tamanho(0),
    array(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser menor que 0");
    try {
        array=new int [tamanho];
        this->tamanho = tamanho;
        std::srand(std::time(0));
        for (int i = 0; i < tamanho; i++){
            array[i] = rand() % 101;
        }
    } catch (std::bad_alloc &erro) {
        throw QString ("Fila não pôde ser criada");
}
}
OrdenacaoVetor::~OrdenacaoVetor()
{
    delete[] array;
    array = nullptr;
}
    void OrdenacaoVetor::ordenarCrescente(){
        Fila f(tamanho);
        for (int i = 0; i < tamanho; i++)
            {
                f.inserir(array[i]);
            }

            for (int i = 0; i < tamanho; i++)
            {
                int valor = f.retirar();
                for (int j = 1; j < tamanho - i; j++)
                {
                    int aux = f.retirar();
                    if (aux < valor)
                    {
                        f.inserir(valor);
                        valor = aux;
                    }
                    else
                    {
                        f.inserir(aux);
                    }
                }
                array[i] = valor;
            }
        }
    void OrdenacaoVetor::ordenarDecrescente(){
        Fila f(tamanho);
        for (int i = 0; i < tamanho; i++)
            {
                f.inserir(array[i]);
            }

            for (int i = 0; i < tamanho; i++)
            {
                int valor = f.retirar();
                for (int j = 1; j < tamanho - i; j++)
                {
                    int aux = f.retirar();
                    if (aux > valor)
                    {
                        f.inserir(valor);
                        valor = aux;
                    }
                    else
                    {
                        f.inserir(aux);
                    }
                }
                array[i] = valor;
            }
        }
    QString OrdenacaoVetor::mostrarResultado()const{
        QString resultado;
           for(int i=0; i<tamanho; i++)
            {
               resultado += (QString::number(array[i])+ "\n");
            }
        return resultado;
    }

}


