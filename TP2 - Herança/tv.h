#ifndef TV_H
#define TV_H
#include <produto.h>


class Tv
{
public:
    const QString &getModelo() const;
    void setModelo(const QString &newModelo);

    const QString &getMarca() const;
    void setMarca(const QString &newMarca);

    const QString &getSistema() const;
    void setSistema(const QString &newSistema);

    const QString &getTamanho() const;
    void setTamanho(const QString &newTamanho);

protected:
    QString modelo;
    QString marca;
    QString sistema;
    QString tamanho;

};

#endif // TV_H
