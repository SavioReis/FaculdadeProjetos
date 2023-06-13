#ifndef CONTATO_H
#define CONTATO_H
#include <QString>
#include <telefone.h>
#include <endereco.h>
namespace srlg{
class Contato
{
private:
    QString cpf;
    QString nome;
    QString email;
    Telefone fone;
    Endereco endereco;
public:
    Contato();
    Contato(QString &cpf, QString &nome, QString &email, Telefone &fone, Endereco &endereco);
    const QString &getNome() const;
    void setNomeCompleto(const QString &newNome);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    QString toString()const;
    const QString &getCpf() const;
    void setCpf(const QString &newCpf);
    Telefone getFone() const;
    void setFone(const Telefone &newFone);
    const Endereco &getEndereco() const;
    void setEndereco(const Endereco &newEndereco);
};
}
#endif // CONTATO_H
