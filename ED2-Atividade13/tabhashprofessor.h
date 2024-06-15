#ifndef TABHASHPROFESSOR_H
#define TABHASHPROFESSOR_H

#include "tabhash.h"
#include "professor.h"

class TabHashProfessor : public TabHash<Professor>
{
public:
    TabHashProfessor();
    TabHashProfessor(const int& tamanhoTabela, const int& colisao);
    int getChave(const Professor& entrada) const override;
};

#endif // TABHASHPROFESSOR_H
