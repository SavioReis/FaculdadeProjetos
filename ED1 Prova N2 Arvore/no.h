#ifndef NO_H
#define NO_H

#include "pessoa.h"

namespace ED1 {
class No {
public:
    Pessoa pessoa;
    No* esquerda;
    No* direita;

    No(int elemento);
    No(Pessoa pessoa);
};
}

#endif  // NO_H
