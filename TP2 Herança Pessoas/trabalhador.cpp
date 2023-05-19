#include "trabalhador.h"

namespace ce{

Trabalhador::Trabalhador():
    Pessoa(),
    funcao(""),
    departamento(""),
    salario("")
{

}

Trabalhador::Trabalhador(QString nome, QString endereco, QString telefone, QString email, QString funcao, QString departamento, QString salario):
    Pessoa(nome, endereco, telefone, email),
    funcao(funcao),
    departamento(departamento),
    salario(salario)
{

}

QString Trabalhador::toString()const
{
    QString saida = Pessoa::toString();
    saida += "Função: " + funcao + "\n";
    saida += "Departamento: " + departamento + "\n";
    saida += "Salario " + salario + "\n";
    return saida;
}

QString Trabalhador::getFuncao() const
{
    return funcao;
}

void Trabalhador::setFuncao(const QString &newFuncao)
{
    funcao = newFuncao;
}

QString Trabalhador::getDepartamento() const
{
    return departamento;
}

void Trabalhador::setDepartamento(const QString &newDepartamento)
{
    departamento = newDepartamento;
}

QString Trabalhador::getSalario() const
{
    return salario;
}

void Trabalhador::setSalario(const QString &newSalario)
{
    salario = newSalario;
}
}
