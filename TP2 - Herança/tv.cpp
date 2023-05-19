#include "tv.h"

Tv::Tv()
{

}

const QString &Tv::getModelo() const
{
    return modelo;
}

void Tv::setModelo(const QString &newModelo)
{
    modelo = newModelo;
}

const QString &Tv::getMarca() const
{
    return marca;
}

void Tv::setMarca(const QString &newMarca)
{
    marca = newMarca;
}

const QString &Tv::getSistema() const
{
    return sistema;
}

void Tv::setSistema(const QString &newSistema)
{
    sistema = newSistema;
}

const QString &Tv::getTamanho() const
{
    return tamanho;
}

void Tv::setTamanho(const QString &newTamanho)
{
    tamanho = newTamanho;
}
