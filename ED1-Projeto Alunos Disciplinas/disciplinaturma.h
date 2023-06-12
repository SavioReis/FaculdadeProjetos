#ifndef DISCIPLINATURMA_H
#define DISCIPLINATURMA_H
#include <QString>
class DisciplinaTurma
{
private:
    QString codDisciplina;
    QString turma;
public:
    DisciplinaTurma();

    QString getCodDisciplina() const;
    void setCodDisciplina(const QString &newCodDisciplina);

    QString getTurma() const;
    void setTurma(const QString &newTurma);
};

#endif // DISCIPLINATURMA_H
