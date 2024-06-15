#ifndef TABHASHALUNO_H
#define TABHASHALUNO_H

#include "tabhash.h"
#include "professor.h"

class TabHashAluno : public TabHash<Professor>
{
public:
    TabHashAluno();
    TabHashAluno(const int& tamanhoTabela, const int& colisao);
    int getChave(const Professor& entrada) const override;
};

#endif // TABHASHALUNO_H
