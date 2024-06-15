#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <QString>

class Professor
{
private:
    int matricula;
    QString nome;
    QString departamento;
    QString titulacao;
    QString tipoContrato;

public:
    Professor();
    Professor(const int &matricula, const QString &nome, const QString &departamento, const QString &titulacao, const QString &tipoContrato);
    int getMatricula() const;
    QString getNome() const;
    QString getDepartamento() const;
    QString getTitulacao() const;
    QString getTipoContrato() const;
};

#endif // PROFESSOR_H
