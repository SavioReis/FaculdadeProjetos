#include "livros.h"

const QString &Livros::getAutor() const
{
    return autor;
}

void Livros::setAutor(const QString &newAutor)
{
    autor = newAutor;
}

const QString &Livros::getTradutor() const
{
    return tradutor;
}

void Livros::setTradutor(const QString &newTradutor)
{
    tradutor = newTradutor;
}

const QString &Livros::getEditora() const
{
    return editora;
}

void Livros::setEditora(const QString &newEditora)
{
    editora = newEditora;
}

const QString &Livros::getAno_de_publicação() const
{
    return ano_de_publicação;
}

void Livros::setAno_de_publicação(const QString &newAno_de_publicação)
{
    ano_de_publicação = newAno_de_publicação;
}

Livros::Livros()
{

}
