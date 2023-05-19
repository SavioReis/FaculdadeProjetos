#include "calculadora.h"

namespace srlg{
    double Calculadora::getPrimeiroTermo() const
    {
        return primeiroTermo;
    }

    void Calculadora::setPrimeiroTermo(double newPrimeiroTermo)
    {
        primeiroTermo = newPrimeiroTermo;
    }

    double Calculadora::getSegundoTermo() const
    {
        return segundoTermo;
    }

    void Calculadora::setSegundoTermo(double newSegundoTermo)
    {
        segundoTermo = newSegundoTermo;
    }

    Calculadora::Calculadora():
        primeiroTermo(0), segundoTermo(0)
        {}

    Calculadora::Calculadora(double primeiroTermo, double segundoTermo):
    primeiroTermo(0), segundoTermo(0)
    {
        this->primeiroTermo = primeiroTermo;
        this->segundoTermo = segundoTermo;
    }

    double Calculadora::calcularAdcao()const{
        return getPrimeiroTermo()+getSegundoTermo();
    }
    double Calculadora::calcularSubtracao()const{
        return primeiroTermo-segundoTermo;
    }
    double Calculadora::calcularMultiplicacao()const{
        return primeiroTermo*segundoTermo;
    }
    double Calculadora::calcularDivisao()const{
        if (segundoTermo != 0) return primeiroTermo/segundoTermo;
        throw QString("Para divisão o segundo termo deve ser diferente de 0");
    }
    double Calculadora::calcularPotenciacao()const{
        return pow(getPrimeiroTermo(), getSegundoTermo());

    }
    double Calculadora::calcularRadiciacao()const{
        int auxiliar;
        auxiliar = segundoTermo;
        if (auxiliar % 2 == 0 && primeiroTermo < 0) throw QString("Não existe raiz com radical par de número negativo");
        if (auxiliar % 2 == 1 && primeiroTermo < 0) return pow(getPrimeiroTermo()*(-1), (1/getSegundoTermo()));
        return pow(getPrimeiroTermo(), (1/getSegundoTermo()));

    }
    double Calculadora::calcularPorcentagem()const{
        return primeiroTermo*(segundoTermo/100);
    }
}
