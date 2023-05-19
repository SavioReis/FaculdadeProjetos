#include "cds.h"

const QString &CDS::getNome_do_album() const
{
    return nome_do_album;
}

void CDS::setNome_do_album(const QString &newNome_do_album)
{
    nome_do_album = newNome_do_album;
}

const QString &CDS::getBanda() const
{
    return banda;
}

void CDS::setBanda(const QString &newBanda)
{
    banda = newBanda;
}

const QString &CDS::getCantor() const
{
    return cantor;
}

void CDS::setCantor(const QString &newCantor)
{
    cantor = newCantor;
}

const QString &CDS::getGênero() const
{
    return gênero;
}

void CDS::setGênero(const QString &newGênero)
{
    gênero = newGênero;
}

CDS::CDS()
{

}
