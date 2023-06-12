#include "aluno.h"
Aluno::Aluno()
{

}
void Aluno::setAluno(const QString &newAluno)
{
    aluno = newAluno;
}

QString Aluno::getAluno() const
{
    return aluno;
}

QString Aluno::getMatricula() const
{
    return matricula;
}

void Aluno::setMatricula(const QString &newMatricula)
{
    matricula = newMatricula;
}

std::list<DisciplinaTurma> Aluno::getDisciplinas() const
{
    return disciplinas;
}

void Aluno::setDisciplinas(const std::list<DisciplinaTurma> &newDisciplinas)
{
    disciplinas = newDisciplinas;
}
