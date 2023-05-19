#ifndef PILOTO_H
#define PILOTO_H
#include <QString>

namespace srlg{
class Piloto
{
private:
    int codigo;
    QString nome;
    QString pais;
    int idade;
    QString equipe;
    QString motor;
    int classificacao[7];
    int pontuacaoFinal;
public:
    Piloto();
    Piloto(int codigo,QString nome, QString pais, int idade, QString equipe,QString motor, int classificacao[7]);

    void calcularPontuacaoFinal();

    int getCodigo() const;
    void setCodigo(int newCodigo);
    const QString &getNome() const;
    void setNome(const QString &newNome);
    const QString &getPais() const;
    void setPais(const QString &newPais);
    int getIdade() const;
    void setIdade(int newIdade);
    const QString &getEquipe() const;
    void setEquipe(const QString &newEquipe);
    const QString &getMotor() const;
    void setMotor(const QString &newMotor);
    int getPontuacaoFinal() const;
    void setPontuacaoFinal(int newPontuacaoFinal);
    void setClassificacao(int array[7]);
    QString ToString()const;
};
}
#endif // PILOTO_H
