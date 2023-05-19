#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include "pessoa.h"

namespace ce{

class Estudante: public Pessoa
{
protected:
    QString matricula;
    QString curso;
    QString campus;
public:
    Estudante();
    Estudante(QString nome, QString endereco, QString telefone, QString email, QString matricula, QString curso, QString campus);
    QString toString()const;
    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);
    QString getCurso() const;
    void setCurso(const QString &newCurso);
    QString getCampus() const;
    void setCampus(const QString &newCampus);
};
}
#endif // ESTUDANTE_H
