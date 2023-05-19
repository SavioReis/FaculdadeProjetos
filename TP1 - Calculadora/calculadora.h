#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QString>
#include <math.h>

namespace srlg{
    class Calculadora
    {
    private:
        double primeiroTermo;
        double segundoTermo;
    public:
        Calculadora();
        Calculadora(double primeiroTermo, double segundoTermo);

        double calcularAdcao()const;
        double calcularSubtracao()const;
        double calcularMultiplicacao()const;
        double calcularDivisao()const;
        double calcularPotenciacao()const;
        double calcularRadiciacao()const;
        double calcularPorcentagem()const;

        double getPrimeiroTermo() const;
        void setPrimeiroTermo(double newPrimeiroTermo);
        double getSegundoTermo() const;
        void setSegundoTermo(double newSegundoTermo);
    };
}
#endif // CALCULADORA_H
