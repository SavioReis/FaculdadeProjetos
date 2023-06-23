#include "no.h"

namespace ED1 {
No::No(int elemento) : pessoa(elemento, ""), esquerda(nullptr), direita(nullptr) {}

No::No(Pessoa pessoa) : pessoa(pessoa), esquerda(nullptr), direita(nullptr) {}
}
