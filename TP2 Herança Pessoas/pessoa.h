#ifndef PESSOA_H
#define PESSOA_H
#include <QString>

namespace ce{

class Pessoa
{
protected:
    QString nome;
    QString endereco;
    QString telefone;
    QString email;
public:
    Pessoa();
    Pessoa(QString nome, QString endereco, QString telefone, QString email);
    QString toString()const;
    QString getNome() const;
    void setNome(const QString &newNome);
    QString getEndereco() const;
    void setEndereco(const QString &newEndereco);
    QString getTelefone() const;
    void setTelefone(const QString &newTelefone);
    QString getEmail() const;
    void setEmail(const QString &newEmail);
};
}
#endif // PESSOA_H
