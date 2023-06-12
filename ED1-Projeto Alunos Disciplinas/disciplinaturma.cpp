#include "disciplinaturma.h"
DisciplinaTurma::DisciplinaTurma()
{

}

QString DisciplinaTurma::getCodDisciplina() const
{
    return codDisciplina;
}

void DisciplinaTurma::setCodDisciplina(const QString &newCodDisciplina)
{
    codDisciplina = newCodDisciplina;
}

QString DisciplinaTurma::getTurma() const
{
    return turma;
}

void DisciplinaTurma::setTurma(const QString &newTurma)
{
    turma = newTurma;
}
