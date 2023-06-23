#ifndef TELEFONE_H
#define TELEFONE_H
#include <QString>
namespace srlg{
class Telefone
{
private:
    int ddi;
    int ddd;
    int numero;
public:
    Telefone();
    Telefone(int ddi, int ddd, int numero);
    int getDdi() const;
    void setDdi(int newDdi);
    int getDdd() const;
    void setDdd(int newDdd);
    int getNumero() const;
    void setNumero(int newNumero);
    QString toString()const;
    QString obterTelefone()const;
};
}
#endif // TELEFONE_H
