#ifndef ALUNO_H
#define ALUNO_H

#include <QString>

class Aluno
{
private:
    int matricula;
    QString nome;
    QString departamento;
    QString titulacao;
    QString tipoContrato;

public:
    Aluno();
    Aluno(const int &matricula, const QString &nome, const QString &departamento, const QString &titulacao, const QString &tipoContrato);
    int getMatricula() const;
    QString getNome() const;
    QString getDepartamento() const;
    QString getTitulacao() const;
    QString getTipoContrato() const;
};

#endif // ALUNO_H
