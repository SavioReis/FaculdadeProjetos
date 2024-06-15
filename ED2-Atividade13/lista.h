#ifndef LISTA_H
#define LISTA_H

#include "no.h"
#include <iostream>
#include <QString>

template <class L>
class Lista
{
private:
    int quantidadeElementos;
    NO<L> *inicio;
    NO<L> *fim;

public:
    Lista() : quantidadeElementos(0),
              inicio(0),
              fim(0)
    {
    }

    ~Lista()
    {
        while (!estaVazia())
        {
            retirarInicio();
        }
    }

    bool estaVazia() const
    {
        return !((bool)quantidadeElementos);
    }

    void inserirInicio(const L &entrada)
    {
        try
        {
            NO<L> *newElemento = new NO<L>(entrada);
            if (estaVazia()){
                inicio = fim = newElemento;
                ++quantidadeElementos;
                return;
            }
            inicio->setAnterior(newElemento);
            newElemento->setProximo(inicio);
            inicio = newElemento;
            ++quantidadeElementos;
        }
        catch (std::bad_alloc &e)
        {
            throw QString("Erro ao inserir no inicio, nao foi possivel alocar memoria");
        }
    }

    NO<L> *acessarInicio() const
    {
        return inicio;
    }

    L retirarInicio()
    {
        if (estaVazia())
        {
            throw QString("Lista ja vazia, nao foi possivel retirar");
        }
        NO<L> *aux = inicio;
        L valor = inicio->getDado();
        if (quantidadeElementos == 1)
        {
            quantidadeElementos = 0;
            inicio = fim = 0;
            delete aux;
            return valor;
        }
        inicio = inicio->getProximo();
        inicio->setAnterior(0);
        delete aux;
        --quantidadeElementos;
        return valor;
    }

    void inserirFim(const L &entrada)
    {
        if (estaVazia())
        {
            return inserirInicio(entrada);
        }
        try
        {
            NO<L> *newElemento = new NO<L>(entrada);
            newElemento->setAnterior(fim);
            fim->setProximo(newElemento);
            fim = newElemento;
            ++quantidadeElementos;
        }
        catch (std::bad_alloc &e)
        {
            throw QString("Erro ao inserir no fim, nao foi possivel alocar memoria");
        }
    }

    NO<L> *acessarFim() const
    {
        return fim;
    }

    L retirarFim()
    {
        if (estaVazia())
        {
            throw QString("Lista ja vazia, nao foi possivel retirar");
        }
        if (quantidadeElementos == 1)
        {
            return retirarInicio();
        }
        NO<L> *aux = fim;
        L valor = fim->getDado();
        fim = fim->getAnterior();
        fim->setProximo(0);
        delete aux;
        --quantidadeElementos;
        return valor;
    }

    void inserirPosicao(const int &posicao, const L &entrada)
    {
        if (posicao < 0 || posicao > quantidadeElementos)
        {
            throw QString("Posicao invalida, nao pode ser menor que 0 ou maior que a quantidade de elementos");
        }
        if (posicao == 0)
        {
            return inserirInicio(entrada);
        }
        if (posicao == quantidadeElementos)
        {
            return inserirFim(entrada);
        }
        try
        {
            NO<L> *newElemento = new NO<L>(entrada);
            NO<L> *aux;
            if (posicao < quantidadeElementos / 2)
            {
                aux = inicio;
                for (int i = 0; i < posicao; ++i)
                {
                    aux = aux->getProximo();
                }
            }
            else
            {
                aux = fim;
                for (int i = quantidadeElementos - 1; i > posicao; --i)
                {
                    aux = aux->getAnterior();
                }
            }
            NO<L> *anterior = aux->getAnterior();
            anterior->setProximo(newElemento);
            newElemento->setProximo(aux);
            newElemento->setAnterior(anterior);
            aux->setAnterior(newElemento);
            ++quantidadeElementos;
        }
        catch (std::bad_alloc &e)
        {
            throw QString("Erro ao inserir no inicio, nao foi possivel alocar memoria");
        }
    }

    L acessarPosicao(const int &posicao) const
    {
        if (posicao < 0 || posicao >= quantidadeElementos)
        {
            throw QString("A posicao nao pode ser maior que a quantidade de elementos e nem menor que 0");
        }
        NO<L> *elemento;
        if (posicao < quantidadeElementos / 2)
        {
            elemento = inicio;
            for (int i = 0; i < posicao; ++i)
            {
                elemento = elemento->getProximo();
            }
        }
        else
        {
            elemento = fim;
            for (int i = quantidadeElementos - 1; i > posicao; --i)
            {
                elemento = elemento->getAnterior();
            }
        }
        return elemento->getDado();
    }

    L retirarPosicao(const int &posicao)
    {
        if (estaVazia())
        {
            throw QString("Lista ja vazia, nao foi possivel retirar");
        }
        if (posicao < 0 || posicao >= quantidadeElementos)
        {
            throw QString("Posicao invalida, nao pode ser menor que 0 ou maior igual que a quantidade de elementos");
        }
        if (posicao == 0)
        {
            return retirarInicio();
        }
        if (posicao == quantidadeElementos - 1)
        {
            return retirarFim();
        }
        NO<L> *aux;
        if (posicao < quantidadeElementos / 2)
        {
            aux = inicio;
            for (int i = 0; i < posicao; ++i)
            {
                aux = aux->getProximo();
            }
        }
        else
        {
            aux = fim;
            for (int i = quantidadeElementos - 1; i > posicao; --i)
            {
                aux = aux->getAnterior();
            }
        }
        NO<L> *anterior = aux->getAnterior();
        NO<L> *proximo = aux->getProximo();
        anterior->setProximo(proximo);
        proximo->setAnterior(anterior);
        L valor = aux->getDado();
        delete aux;
        --quantidadeElementos;
        return valor;
    }

    int getQuantidadeElementos() const
    {
        return quantidadeElementos;
    }
};

#endif // LISTA_H
