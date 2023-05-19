#ifndef CDS_H
#define CDS_H
#include "produto.h"

class CDS:public Produto
{
protected:
    QString nome_do_album;
    QString banda;
    QString cantor;
    QString gênero;
public:
    CDS();
    const QString &getNome_do_album() const;
    void setNome_do_album(const QString &newNome_do_album);
    const QString &getBanda() const;
    void setBanda(const QString &newBanda);
    const QString &getCantor() const;
    void setCantor(const QString &newCantor);
    const QString &getGênero() const;
    void setGênero(const QString &newGênero);
};

#endif // CDS_H
