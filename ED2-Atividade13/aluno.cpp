#include "aluno.h"

Aluno::Aluno() : matricula(0),
    nome(""),
    departamento(""),
    titulacao(""),
    tipoContrato("")
{
}

Aluno::Aluno(const int &matricula, const QString &nome, const QString &departamento, const QString &titulacao, const QString &tipoContrato) : matricula(matricula),
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

int Aluno::getMatricula() const
{
    return matricula;
}

QString Aluno::getNome() const
{
    return nome;
}

QString Aluno::getDepartamento() const
{
    return departamento;
}

QString Aluno::getTitulacao() const
{
    return titulacao;
}

QString Aluno::getTipoContrato() const
{
    return tipoContrato;
}
