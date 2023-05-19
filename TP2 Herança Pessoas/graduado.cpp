#include "graduado.h"

namespace ce{

Graduado::Graduado():
    Estudante(),
    anoDaConclusao(""),
    anoDaColacaoDeGrau(""),
    numeroDoDiploma("")
{

}

Graduado::Graduado(QString nome, QString endereco, QString telefone, QString email, QString matricula, QString curso, QString campus, QString anoDaConclusao, QString anoDaColacaoDeGrau, QString numeroDoDiploma):
    Estudante(nome, endereco, telefone, email, matricula, curso, campus),
    anoDaConclusao(anoDaConclusao),
    anoDaColacaoDeGrau(anoDaColacaoDeGrau),
    numeroDoDiploma(numeroDoDiploma)
{

}

QString Graduado::toString()const
{
    QString saida = Estudante::toString();
    saida += "Ano da Conclusão: " + anoDaConclusao + "\n";
    saida += "Ano da Colação de Grau: " + anoDaColacaoDeGrau + "\n";
    saida += "Numero do Diploma: " + numeroDoDiploma + "\n";
    return saida;
}
QString Graduado::getAnoDaConclusao() const
{
    return anoDaConclusao;
}

void Graduado::setAnoDaConclusao(const QString &newAnoDaConclusao)
{
    anoDaConclusao = newAnoDaConclusao;
}

QString Graduado::getAnoDaColacaoDeGrau() const
{
    return anoDaColacaoDeGrau;
}

void Graduado::setAnoDaColacaoDeGrau(const QString &newAnoDaColacaoDeGrau)
{
    anoDaColacaoDeGrau = newAnoDaColacaoDeGrau;
}

QString Graduado::getNumeroDoDiploma() const
{
    return numeroDoDiploma;
}

void Graduado::setNumeroDoDiploma(const QString &newNumeroDoDiploma)
{
    numeroDoDiploma = newNumeroDoDiploma;
}
}
