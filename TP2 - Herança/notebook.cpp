#include "notebook.h"

const QString &Notebook::getMarca() const
{
    return marca;
}

void Notebook::setMarca(const QString &newMarca)
{
    marca = newMarca;
}

const QString &Notebook::getModelo() const
{
    return modelo;
}

void Notebook::setModelo(const QString &newModelo)
{
    modelo = newModelo;
}

const QString &Notebook::getMemória_RAM() const
{
    return memória_RAM;
}

void Notebook::setMemória_RAM(const QString &newMemória_RAM)
{
    memória_RAM = newMemória_RAM;
}

const QString &Notebook::getCapacidade_HD() const
{
    return capacidade_HD;
}

void Notebook::setCapacidade_HD(const QString &newCapacidade_HD)
{
    capacidade_HD = newCapacidade_HD;
}

const QString &Notebook::getProcessado() const
{
    return processado;
}

void Notebook::setProcessado(const QString &newProcessado)
{
    processado = newProcessado;
}

const QString &Notebook::getTamanho_tela() const
{
    return tamanho_tela;
}

void Notebook::setTamanho_tela(const QString &newTamanho_tela)
{
    tamanho_tela = newTamanho_tela;
}

const QString &Notebook::getSO() const
{
    return SO;
}

void Notebook::setSO(const QString &newSO)
{
    SO = newSO;
}

Notebook::Notebook()
{

}
