#ifndef PRODUTO_H
#define PRODUTO_H
#include <QString>

class Produto
{
public:
    Produto();

    const QString &getCodigo() const;
    void setCodigo(const QString &newCodigo);

    const QString &getDescricao() const;
    void setDescricao(const QString &newDescricao);

    int getPreco() const;
    void setPreco(int newPreco);

    const QString &getTipo() const;
    void setTipo(const QString &newTipo);

protected:
    QString codigo;
    QString descricao;
    int preco;
    QString tipo;


    };

#endif // PRODUTO_H
