#ifndef GRADUADO_H
#define GRADUADO_H
#include "estudante.h"

namespace ce{
class Graduado: public Estudante
{
protected:
    QString anoDaConclusao;
    QString anoDaColacaoDeGrau;
    QString numeroDoDiploma;
public:
    Graduado();
    Graduado(QString nome, QString endereco, QString telefone, QString email, QString matricula, QString curso, QString campus, QString anoDaConclusao, QString anoDaColacaoDeGrau, QString numeroDoDiploma);
    QString toString()const;
    QString getAnoDaConclusao() const;
    void setAnoDaConclusao(const QString &newAnoDaConclusao);
    QString getAnoDaColacaoDeGrau() const;
    void setAnoDaColacaoDeGrau(const QString &newAnoDaColacaoDeGrau);
    QString getNumeroDoDiploma() const;
    void setNumeroDoDiploma(const QString &newNumeroDoDiploma);
};
}
#endif // GRADUADO_H
