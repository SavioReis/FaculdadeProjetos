#include "fila.h"
namespace srlg{
Fila::Fila(int tamanho):
    tamanho(0),
    array(0),
    inicio(-1),
    final(-1),
    quantidadeElementos(0)
{
    if (tamanho<=0)throw QString ("Tamanho não pode ser menor que 0");
    try {
        array = new int[tamanho];
        this->tamanho=tamanho;
    } catch (std::bad_alloc &erro) {
        throw QString ("Fila não pôde ser criada");
    }
}
Fila::~Fila(){
    if(array) delete []array;
}
bool Fila::estaCheia()const{
    return (quantidadeElementos==tamanho);
}
bool Fila::estaVazia()const{
    return (quantidadeElementos==0);
}
void Fila::inserir(int elemento){
    if (estaCheia())throw QString ("A fila está cheia");
    if (estaVazia())inicio=0;
    final++;
    if(final==tamanho)final=0;
    array[final]=elemento;
    quantidadeElementos++;
}
int Fila::retirar(){
    if (estaVazia())throw QString ("A fila está vazia");
    int aux=array[inicio];
    inicio++;
    if (inicio==tamanho)inicio=0;
    quantidadeElementos--;
    if (estaVazia())inicio=final=-1;
    return aux;
}
int Fila::acessar()const{
    if (estaVazia())throw QString ("Não há elementos para acessar");
    return array[inicio];
}
}
