#ifndef ENDERECO_H
#define ENDERECO_H
#include <QString>
namespace srlg{
class Endereco
{
private:
    QString logradouro;
    QString numero;
    int cep;
public:
    Endereco();
    Endereco(QString logradouro, QString numero, int cep);
    const QString &getLogradouro() const;
    void setLogradouro(const QString &newLogradouro);
    int getCep() const;
    void setCep(int newCep);
    QString conseguirEndereco()const;
    QString toString()const;
    QString getNumero() const;
    void setNumero(const QString &newNumero);
};
}
#endif // ENDERECO_H
