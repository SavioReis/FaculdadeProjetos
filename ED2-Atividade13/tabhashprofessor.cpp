#include "tabhashprofessor.h"

TabHashProfessor::TabHashProfessor() : TabHash<Professor>()
{
}

TabHashProfessor::TabHashProfessor(const int& tamanhoTabela, const int& colisao) : TabHash<Professor>(tamanhoTabela, colisao)
{
}

int TabHashProfessor::getChave(const Professor& entrada) const
{
    return entrada.getMatricula();
}
