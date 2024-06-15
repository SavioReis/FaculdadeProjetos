// tabhashaluno.cpp
#include "tabhashaluno.h"

TabHashAluno::TabHashAluno() : TabHash<Professor>()
{
}

TabHashAluno::TabHashAluno(const int& tamanhoTabela, const int& colisao) : TabHash<Professor>(tamanhoTabela, colisao)
{
}

int TabHashAluno::getChave(const Professor& entrada) const
{
    return entrada.getMatricula();
}
