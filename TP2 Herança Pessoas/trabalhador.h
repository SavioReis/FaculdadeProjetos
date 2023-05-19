#ifndef TRABALHADOR_H
#define TRABALHADOR_H
#include "pessoa.h"

namespace ce{

class Trabalhador: public Pessoa
{
protected:
    QString funcao;
    QString departamento;
    QString salario;
public:
    Trabalhador();
    Trabalhador(QString nome, QString endereco, QString telefone, QString email, QString funcao, QString departamento, QString salario);
    QString toString()const;
    QString getFuncao() const;
    void setFuncao(const QString &newFuncao);
    QString getDepartamento() const;
    void setDepartamento(const QString &newDepartamento);
    QString getSalario() const;
    void setSalario(const QString &newSalario);
};
}
#endif // TRABALHADOR_H
