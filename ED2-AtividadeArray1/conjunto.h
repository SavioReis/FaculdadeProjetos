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
};
}
#endif // CONJUNTO_H
