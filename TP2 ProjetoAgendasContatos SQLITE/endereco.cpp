#include "endereco.h"
namespace srlg{


Endereco::Endereco():
    logradouro(""),
    numero(""),
    cep(0)
{

}
Endereco::Endereco(QString logradouro, QString numero, int cep):
    logradouro(logradouro),
    numero(numero),
    cep(cep)
{

}
const QString &Endereco::getLogradouro() const
{
    return logradouro;
}

void Endereco::setLogradouro(const QString &newLogradouro)
{
    logradouro = newLogradouro;
}

int Endereco::getCep() const
{
    return cep;
}

void Endereco::setCep(int newCep)
{
    cep = newCep;
}
QString Endereco::getNumero() const
{
    return numero;
}

void Endereco::setNumero(const QString &newNumero)
{
    numero = newNumero;
}

QString Endereco::conseguirEndereco()const{
    QString saida = logradouro;
    saida += ", ";
    saida += numero;
    saida += ", ";
    QString cepString = QString::number(cep);
    cepString = cepString.insert(5,"-");
    saida += cepString;
    return saida;
}
QString Endereco::toString()const{
    QString saida = logradouro;
    saida += ";";
    saida += numero;
    saida += ";";
    saida += QString::number(cep);
    return saida;
}
}
