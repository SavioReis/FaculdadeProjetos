#ifndef LLSE_H
#define LLSE_H

#include <no.h>

namespace srlg{
    class LLSE
    {
    private:
        int quantidadedeBagulho;
        srlg::No *inicio;
    public:
        LLSE();
        int getquantidadedeBagulho() const;
        bool estaVazia()const;

        int insercaodeelementos()const;

        void inserirInicio(int elemento);
        int retirarInicio();
        int acessarInicio()const;

        void inserirFinal(int elemento);
        int retirarFinal();
        int acessarFinal()const;

        void inserirMeio(int elemento, int posicao);
        int retirarMeio();
        int acessarMeio(int posicao)const;

        void inserirPosicao(int elemento, int posicao);
        int acessarPosicao(int posicao)const;
        int retirarPosicao(int posicao);

        QString obterDadosLLSE()const;
    };
}

#endif // LLSE_H
