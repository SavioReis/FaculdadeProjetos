#include "llde.h"
#include <vector>

namespace srlg{

int LLDE::getquantidadeDeBagulho() const
{
    return quantidadeDeBagulho;
}

LLDE::LLDE():
    quantidadeDeBagulho(0),
    inicio(0),
    fim(0)
{

}

bool LLDE::estaVazia()const
{
    return (quantidadeDeBagulho == 0);
}

void LLDE::inserirInicio(int elemento)
{
    try
    {
        No *aux = new No(elemento);
        if(estaVazia())
        {
            inicio = fim = aux;
            quantidadeDeBagulho++;
            return;
        }
        aux->setEnderecoProximo(inicio);
        inicio->setEnderecoAnterior(aux);
        inicio = aux;
        quantidadeDeBagulho++;

    } catch (std::bad_alloc &erro)
    {
        throw QString("Nó não foi criado!");
    }
}

int LLDE::acessarInicio()const
{
    if(estaVazia()) throw QString("A lista está vazia");
    return inicio->getDado();
}

int LLDE::retirarInicio()
{
    if(estaVazia()) throw QString("A lista está vazia");
    if(quantidadeDeBagulho==1)
    {
        int valor = inicio->getDado();
        quantidadeDeBagulho--;
        delete inicio;
        fim = inicio = 0;
        return valor;
    }
    int valor = inicio->getDado();
    inicio = inicio->getEnderecoProximo();
    delete inicio->getEnderecoAnterior();
    inicio->setEnderecoAnterior(0);
    quantidadeDeBagulho--;
    return valor;
}

void LLDE::inserirFim(int elemento)
{
    try {
        No* aux = new No(elemento);
        if(estaVazia())
        {
            quantidadeDeBagulho++;
            inicio = fim = aux;
            return;
        }
        fim->setEnderecoProximo(aux);
        aux->setEnderecoAnterior(fim);
        quantidadeDeBagulho++;
        fim = aux;
    } catch (std::bad_alloc &erro)
    {
        throw QString ("Nó não foi criado!");
    }
}

int LLDE::acessarFim() const
{
    if(estaVazia()) throw QString("A lista está vazia");
    return fim->getDado();
}

int LLDE::retirarFim()
{
    if(estaVazia()) throw QString("A lista está vaizia");
    if(quantidadeDeBagulho == 1)
    {
       int valor = fim->getDado();
       quantidadeDeBagulho--;
       delete fim;
       fim = inicio = 0;
       return valor;
    }

    int valor = fim->getDado();
    fim = fim->getEnderecoAnterior();
    delete fim->getEnderecoProximo();
    fim->setEnderecoProximo(0);
    quantidadeDeBagulho--;
    return valor;
}

void LLDE::inserirOrdenadoCrescente(){
    if(estaVazia()) return;

    bool trocou;
    No* atual;
    No* anterior = 0;

    do {
        trocou = false;
        atual = inicio;

        while(atual->getEnderecoProximo() != anterior) {
            No* proximo = atual->getEnderecoProximo();
            if(atual->getDado() > proximo->getDado()) {
                // Troca os valores dos nós
                int temp = atual->getDado();
                atual->setDado(proximo->getDado());
                proximo->setDado(temp);
                trocou = true;
            }
            atual = atual->getEnderecoProximo();
        }
        anterior = atual;
    } while(trocou);
}

void LLDE::inserirPos(int pos, int elemento){
    if(pos < 0 || pos > quantidadeDeBagulho) throw QString("Posicao fora do parametro - IQ");
    if(pos == quantidadeDeBagulho){
        inserirFim(elemento);
        return;
    }
    if(pos == 0 || quantidadeDeBagulho == 0){
        inserirInicio(elemento);
        return;
    }
    else {
        try {
            No *pAux = inicio;
            No *novo = new No(elemento);

            int cont = 0;

            while(cont < pos - 1){
                pAux = pAux->getEnderecoProximo();
                cont ++;
            }

            pAux->getEnderecoProximo()->setEnderecoAnterior(novo);
            novo->setEnderecoProximo(pAux->getEnderecoProximo());
            pAux->setEnderecoProximo(novo);
            novo->setEnderecoAnterior(pAux);
            quantidadeDeBagulho ++;

        }  catch (std::bad_alloc&) {
            throw QString("Memoria insuficiente");
        }
   }
}

void LLDE::inserirOrdenadoDecrescente(){
    if(estaVazia()) return;

    bool trocou;
    No* atual;
    No* anterior = 0;

    do {
        trocou = false;
        atual = inicio;

        while(atual->getEnderecoProximo() != anterior) {
            No* proximo = atual->getEnderecoProximo();
            if(atual->getDado() < proximo->getDado()) {
                // Troca os valores dos nós
                int temp = atual->getDado();
                atual->setDado(proximo->getDado());
                proximo->setDado(temp);
                trocou = true;
            }
            atual = atual->getEnderecoProximo();
        }
        anterior = atual;
    } while(trocou);
}

void LLDE::inserirPosicao(int elemento, int posicao)
{
    try {
        if(posicao < 0 || posicao >quantidadeDeBagulho) throw QString("A posição desejada não existe");
        if(posicao == 0) return inserirInicio(elemento);
        if(posicao == quantidadeDeBagulho) return inserirFim(elemento);

        No *aux = new No(elemento);
        No *anterior = inicio;

        for(int pos = 0 ; pos < posicao - 0; pos++)
        {
            anterior = anterior->getEnderecoProximo();
        }

        aux-> setEnderecoProximo(anterior->getEnderecoProximo());
        anterior-> setEnderecoProximo(aux);
        quantidadeDeBagulho++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nó não foi criado!");
    }

}

int LLDE::retirarPosicao(int posicao)
{
    if(estaVazia()) throw QString("A lista está vazia!");
    if(posicao < 0 || posicao >= quantidadeDeBagulho) throw QString("A posição desejada não existe");
    if(posicao == 0) return retirarInicio();
    if(posicao == quantidadeDeBagulho - 1) return retirarFim();

    No *aux = inicio;
    No *anterior = nullptr;

    for(int pos = 0; pos < posicao; pos++)
    {
        anterior = aux;
        aux = aux->getEnderecoProximo();
    }
    anterior-> setEnderecoProximo(aux->getEnderecoProximo());
    int valor = aux->getDado();
    delete aux;
   quantidadeDeBagulho--;

    return valor;
}

int LLDE::acessarPosicao(int posicao)const
{
    if(estaVazia()) throw QString("A lista está vazia!");
    if(posicao < 0 || posicao >= quantidadeDeBagulho) throw QString("A posição desejada não existe");
    if(posicao == 0) return acessarInicio();
    if(posicao == quantidadeDeBagulho - 1) return acessarFim();
    No *aux = inicio;
    for(int pos = 0; pos < posicao; pos++)
    {
        aux = aux->getEnderecoProximo();
    }
    return aux->getDado();
}

QString LLDE::obterLista()const
{
    if(estaVazia()) throw QString("Lista esta Vazia - obterDadosLLDE");
    No* auxiliar = inicio;
    bool vermelho = true;
    QString saida = "";
       for (int pos = 0; pos < quantidadeDeBagulho; pos++){
        saida += "|" + QString::number(auxiliar->getDado()) + "|";
        auxiliar = auxiliar->getEnderecoProximo();
        if(pos<quantidadeDeBagulho-1) saida += " -> ";
        if(vermelho){
            saida = "<font color='red'>" + saida + "</font>";
        }else {
            saida = "<font color='black'>" + saida + "</font>";
        }
        vermelho = !vermelho;
    }
    return saida;
}
QString LLDE::obterListaOrdenada() const {
    if (estaVazia()) {
        throw QString("Lista está vazia - obterListaOrdenada");
    }

    QString saidaNormal = "";
    No* auxiliar = inicio;
    for (std::vector<int>::size_type pos = 0; pos < static_cast<std::vector<int>::size_type>(quantidadeDeBagulho); ++pos) {
        saidaNormal += "|" + QString::number(auxiliar->getDado()) + "|";
        auxiliar = auxiliar->getEnderecoProximo();
        if (pos < static_cast<std::vector<int>::size_type>(quantidadeDeBagulho) - 1) {
            saidaNormal += " -> ";
        }
    }

    std::vector<int> dados;
    auxiliar = inicio;
    for (std::vector<int>::size_type pos = 0; pos < static_cast<std::vector<int>::size_type>(quantidadeDeBagulho); ++pos) {
        dados.push_back(auxiliar->getDado());
        auxiliar = auxiliar->getEnderecoProximo();
    }

    std::sort(dados.begin(), dados.end());

    QString saidaCrescente = "";
    for (std::vector<int>::size_type i = 0; i < dados.size(); ++i) {
        saidaCrescente += "|" + QString::number(dados[i]) + "|";
        if (i < dados.size() - 1) {
            saidaCrescente += " -> ";
        }
    }

    std::sort(dados.begin(), dados.end(), std::greater<int>());

    QString saidaDecrescente = "";
    for (std::vector<int>::size_type i = 0; i < dados.size(); ++i) {
        saidaDecrescente += "|" + QString::number(dados[i]) + "|";
        if (i < dados.size() - 1) {
            saidaDecrescente += " -> ";
        }
    }

    return "Original: " + saidaNormal + "\n\n" +
           "Crescente: " + saidaCrescente + "\n\n" +
           "Decrescente: " + saidaDecrescente;
}
}
