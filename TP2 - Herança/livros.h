#ifndef LIVROS_H
#define LIVROS_H
#include "produto.h"


class Livros: public Produto
{
protected:
     QString autor;
     QString tradutor;
     QString editora;
     QString ano_de_publicação;
public:
     Livros();
     const QString &getAutor() const;
     void setAutor(const QString &newAutor);
     const QString &getTradutor() const;
     void setTradutor(const QString &newTradutor);
     const QString &getEditora() const;
     void setEditora(const QString &newEditora);
     const QString &getAno_de_publicação() const;
     void setAno_de_publicação(const QString &newAno_de_publicação);
};

#endif // LIVROS_H
