#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <QString>
#include "ctime"

namespace srlg{
class Conjunto
{
private:
    int tamanho;
    int *array;
public:
    Conjunto(int tamanho);
    ~Conjunto();
    int getTamanho() const;
    QString TooString();
    int buscarSequencial(int valor);
};
}
#endif // CONJUNTO_H
