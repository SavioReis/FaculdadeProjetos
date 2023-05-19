#include "estudante.h"

namespace ce{

Estudante::Estudante():
    Pessoa(),
    matricula(""),
    curso(""),
    campus("")
{

}
Estudante::Estudante(QString nome, QString endereco, QString telefone, QString email, QString matricula, QString curso, QString campus):
    Pessoa(nome, endereco, telefone, email),
    matricula(matricula),
    curso(curso),
    campus(campus)
{

}

QString Estudante::toString()const
{
    QString saida = Pessoa::toString();
    saida += "Matricula: " + matricula + "\n";
    saida += "Curso: " + curso + "\n";
    saida += "Campus: " + campus + "\n";
    return saida;
}

QString Estudante::getMatricula() const
{
    return matricula;
}

void Estudante::setMatricula(const QString &newMatricula)
{
    matricula = newMatricula;
}

QString Estudante::getCurso() const
{
    return curso;
}

void Estudante::setCurso(const QString &newCurso)
{
    curso = newCurso;
}

QString Estudante::getCampus() const
{
    return campus;
}

void Estudante::setCampus(const QString &newCampus)
{
    campus = newCampus;
}
}
