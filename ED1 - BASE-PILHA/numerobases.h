#ifndef NUMEROBASES_H
#define NUMEROBASES_H
#include <QString>
#include <pilha.h>

class NumeroBases
{
private :
    int base;
    int numeroBase;
public:
    QString CalcularNumeroBase();
    void SetBase(int Base);
    void SetNumeroBase(int NumeroBase);
    NumeroBases();
    int GetNumeroBase();
};



#endif // NUMEROBASES_H
