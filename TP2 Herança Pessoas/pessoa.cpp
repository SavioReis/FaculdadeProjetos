#include "pessoa.h"

namespace ce{

Pessoa::Pessoa():
    nome(""),
    endereco(""),
    telefone(""),
    email("")
{

}
Pessoa::Pessoa(QString nome, QString endereco, QString telefone, QString email):
    nome(nome),
    endereco(endereco),
    telefone(telefone),
    email(email)
{

}
QString Pessoa::toString()const
{
    QString saida = "DADOS: \n";
    saida += "Nome: " + nome + "\n";
    saida += "Endereço: " + endereco + "\n";
    saida += "Telefone: " + telefone + "\n";
    saida += "Email: " + email + "\n";
    return saida;
}

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &newNome)
{
    nome = newNome;
}

QString Pessoa::getEndereco() const
{
    return endereco;
}

void Pessoa::setEndereco(const QString &newEndereco)
{
    endereco = newEndereco;
}

QString Pessoa::getTelefone() const
{
    return telefone;
}

void Pessoa::setTelefone(const QString &newTelefone)
{
    telefone = newTelefone;
}

QString Pessoa::getEmail() const
{
    return email;
}

void Pessoa::setEmail(const QString &newEmail)
{
    email = newEmail;
}

}
