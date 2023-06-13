#include "contato.h"
namespace srlg{

Contato::Contato():
    cpf(""),
    nome(""),
    email(""),
    fone(),
    endereco()
{
}
Contato::Contato(QString &cpf, QString &nome, QString &email, Telefone &fone, Endereco &endereco):
    cpf(cpf),
    nome(nome),
    email(email),
    fone(fone),
    endereco(endereco)
{
}
const QString &Contato::getCpf() const
{
    return cpf;
}

void Contato::setCpf(const QString &newCpf)
{
    cpf = newCpf;
}
const QString &Contato::getNome() const
{
    return nome;
}

void Contato::setNomeCompleto(const QString &newNome)
{
    nome = newNome;
}

const QString &Contato::getEmail() const
{
    return email;
}

void Contato::setEmail(const QString &newEmail)
{
    email = newEmail;
}

Telefone Contato::getFone() const
{
    return fone;
}

void Contato::setFone(const Telefone &newFone)
{
    fone = newFone;
}
const Endereco &Contato::getEndereco() const
{
    return endereco;
}

void Contato::setEndereco(const Endereco &newEndereco)
{
    endereco = newEndereco;
}
QString Contato::toString()const{
    QString saida = cpf + ";";
    saida += nome + ";";
    saida += email + ";";
    saida += fone.toString() + ";";
    saida += endereco.toString();
    return saida;
}

}
