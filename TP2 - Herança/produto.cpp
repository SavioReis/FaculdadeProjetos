#include "produto.h"

Produto::Produto()
{

}

const QString &Produto::getCodigo() const
{
    return codigo;
}

void Produto::setCodigo(const QString &newCodigo)
{
    codigo = newCodigo;
}

const QString &Produto::getDescricao() const
{
    return descricao;
}

void Produto::setDescricao(const QString &newDescricao)
{
    descricao = newDescricao;
}

int Produto::getPreco() const
{
    return preco;
}

void Produto::setPreco(int newPreco)
{
    preco = newPreco;
}

const QString &Produto::getTipo() const
{
    return tipo;
}

void Produto::setTipo(const QString &newTipo)
{
    tipo = newTipo;
}
