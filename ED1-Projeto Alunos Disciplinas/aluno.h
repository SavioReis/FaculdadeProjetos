#ifndef ALUNO_H
#define ALUNO_H
#include "disciplinaturma.h"
#include <qstring.h>
#include <list>
class Aluno
{
private:
    QString matricula;
    QString aluno;
    std::list <DisciplinaTurma> disciplinas;
public:
    Aluno();

    void setAluno(const QString &newAluno);
    QString getAluno() const;

    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);
    std::list<DisciplinaTurma> getDisciplinas() const;
    void setDisciplinas(const std::list<DisciplinaTurma> &newDisciplinas);
};

#endif // ALUNO_H
