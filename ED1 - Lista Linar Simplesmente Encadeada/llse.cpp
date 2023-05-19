#include "llse.h"

namespace srlg{
    int LLSE::getquantidadedeBagulho() const{
        return quantidadedeBagulho;
    }

    LLSE::LLSE():
        quantidadedeBagulho(0), inicio(0)
    {}
    bool LLSE::estaVazia() const{
        return (quantidadedeBagulho == 0);
    }

    void LLSE::inserirInicio(int elemento){
        try{
            No *auxiliar = new No(elemento);
            quantidadedeBagulho++;
            auxiliar->setEnderecoProximo(inicio);
            inicio = auxiliar;
        } catch (std::bad_alloc &erro){
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirInicio");
        }
    }

    int LLSE::retirarInicio(){
        if(estaVazia()) throw QString("Lista está vazia - retirarInicio");
        No* auxiliar = inicio;
        inicio = inicio->getEnderecoProximo();
        quantidadedeBagulho--;
        int valor = auxiliar->getDado();
        delete auxiliar;
        return valor;
    }

    int LLSE::acessarInicio()const{
        if(estaVazia()) throw QString("Lista está vazia - acessarInicio");
        return inicio->getDado();
    }

    void LLSE::inserirPosicao(int elemento, int posicao)
    {
        try {
            if(posicao < 0 || posicao > quantidadedeBagulho) throw QString("A posição desejada não existe");
            if(posicao == 0) return inserirInicio(elemento);
            if(posicao == quantidadedeBagulho) return inserirFinal(elemento);

            No *aux = new No(elemento);
            No *anterior = inicio;

            for(int pos = 0 ; pos < posicao - 0; pos++)
            {
                anterior = anterior->getEnderecoProximo();
            }

            aux-> setEnderecoProximo(anterior->getEnderecoProximo());
            anterior-> setEnderecoProximo(aux);
            quantidadedeBagulho++;
        }
        catch (std::bad_alloc &erro)
        {
            throw QString("Nó não foi criado!");
        }

    }

    int LLSE::retirarPosicao(int posicao)
    {
        if(estaVazia()) throw QString("A lista está vazia!");
        if(posicao < 0 || posicao >= quantidadedeBagulho) throw QString("A posição desejada não existe");
        if(posicao == 0) return retirarInicio();
        if(posicao == quantidadedeBagulho - 1) return retirarFinal();

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
        quantidadedeBagulho--;

        return valor;
    }

    int LLSE::acessarPosicao(int posicao)const
    {
        if(estaVazia()) throw QString("A lista está vazia!");
        if(posicao < 0 || posicao >= quantidadedeBagulho) throw QString("A posição desejada não existe");
        if(posicao == 0) return acessarInicio();
        if(posicao == quantidadedeBagulho - 1) return acessarFinal();
        No *aux = inicio;
        for(int pos = 0; pos < posicao; pos++)
        {
            aux = aux->getEnderecoProximo();
        }
        return aux->getDado();
    }

    QString LLSE::obterDadosLLSE()const{
        if(estaVazia()) throw QString("Lista esta Vazia - obterDadosLLSE");
        No* auxiliar = inicio;
        bool vermelho = true;
        QString saida = "";
        for(int i=0; i<quantidadedeBagulho; i++){
            saida += "|" + QString::number(auxiliar->getDado()) + "|";
            auxiliar = auxiliar->getEnderecoProximo();
            if(i<quantidadedeBagulho-1) saida += " -> ";
            if(vermelho){
                saida = "<font color='red'>" + saida + "</font>";
            }else {
                saida = "<font color='black'>" + saida + "</font>";
            }
            vermelho = !vermelho;
        }
        return saida;
    }

    void LLSE::inserirFinal(int elemento){
        try {
            No *auxiliar = new No(elemento);
            if(estaVazia()){
                inicio = auxiliar;
                quantidadedeBagulho++;
                return;
            }
            No* aux = inicio;
            for(int i=0; i<quantidadedeBagulho-1;i++){
                aux = aux->getEnderecoProximo();
            }
            aux->setEnderecoProximo(auxiliar);
            quantidadedeBagulho++;
        } catch (std::bad_alloc &erro) {
            throw QString("No não foi criado - ERRO DE MEMORIA - inserirFinal");
        }
    }

    int LLSE::acessarFinal()const{
        if(estaVazia()) throw QString("Lista está vazia - acessarFinal");
        No* aux = inicio;
        for(int i=0; i<quantidadedeBagulho-1;i++){
            aux = aux->getEnderecoProximo();
        }
        return aux->getDado();
    }

    int LLSE::retirarFinal()
    {
        if(estaVazia()) throw QString("A lissta está vazia!");
        if(quantidadedeBagulho == 1)
        {
            int valor = inicio->getDado();
            delete inicio;
            inicio = nullptr;
            return valor;
        }
        No *aux = inicio;
        while(aux->getEnderecoProximo()->getEnderecoProximo() != nullptr)
        {
            aux=aux->getEnderecoProximo();
        }
        int valor = aux->getEnderecoProximo()->getDado();
        delete aux->getEnderecoProximo();
        aux->setEnderecoProximo(nullptr);
        quantidadedeBagulho--;
        return valor;

        }
}
