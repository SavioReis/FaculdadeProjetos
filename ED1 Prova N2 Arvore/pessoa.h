#ifndef PESSOA_H
#define PESSOA_H

#include <string>

namespace ED1 {
class Pessoa {
public:
    int matricula;
    std::string nome;

    Pessoa(int matricula, const std::string& nome);
};
}

#endif  // PESSOA_H
