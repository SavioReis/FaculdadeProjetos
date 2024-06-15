#include "professor.h"

Professor::Professor() : matricula(0),
    nome(""),
    departamento(""),
    titulacao(""),
    tipoContrato("")
{
}

Professor::Professor(const int &matricula, const QString &nome, const QString &departamento, const QString &titulacao, const QString &tipoContrato) : matricula(matricula),
    nome(nome),
    departamento(departamento),
    titulacao(titulacao),
    tipoContrato(tipoContrato)
{
    if (matricula < 0)
        throw QString("Matricula invalida");
    if (nome.isEmpty())
        throw QString("Nome vazio");
    if (departamento.isEmpty())
        throw QString("Departamento vazio");
    if (titulacao.isEmpty())
        throw QString("Titulacao vazia");
    if (tipoContrato.isEmpty())
        throw QString("Tipo de contrato vazio");
}

int Professor::getMatricula() const
{
    return matricula;
}

QString Professor::getNome() const
{
    return nome;
}

QString Professor::getDepartamento() const
{
    return departamento;
}

QString Professor::getTitulacao() const
{
    return titulacao;
}

QString Professor::getTipoContrato() const
{
    return tipoContrato;
}
