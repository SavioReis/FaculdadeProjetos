#ifndef TABELA_H
#define TABELA_H

#include "QTableWidget"
#include "QHeaderView"
#include "tabhashprofessor.h"

class Tabela
{
private:
    QTableWidget *tabela;
    TabHashProfessor *tabela_hash;
    int tamanho_tabela;

public:
    Tabela();
    Tabela(QTableWidget *parent, const int &tamanho, const int &colisoes);
    ~Tabela();
    void start();
    void limpar();
    void atualizar();
    QString buscaElemento(const int &matricula);
    void inserirElemento(const int &matricula, const QString &nomeCompleto, const QString &departamento, const QString &titulacao, const QString &tipoContrato);
    void alterarElemento(const int &matricula, const QString &nomeCompleto, const QString &departamento, const QString &titulacao, const QString &tipoContrato);
    void removerElemento(const int &matricula);
    TabHashProfessor *getVetor() const;
    int getTamanhoTabela() const;
};

#endif // TABELA_H
