#ifndef TABELA_H
#define TABELA_H

#include "QTableWidget"
#include "QHeaderView"

class Tabela
{
private:
    QTableWidget *tabela;
    QString *matriculas;
    QString *nomes;
    QString *departamentos;
    QString *titulacoes;
    QString *tpcs;
    int tamanho_vetor;

public:
    Tabela();
    Tabela(QTableWidget *parent, int tamanho_vetor);
    ~Tabela();
    void start();
    void limpar();
    void atualizar();
    QString buscaElemento(const int& matricula);
    QString buscaElemento(const QString& nomeCompleto);
    void inserirElemento(int& matricula, QString& nomeCompleto, QString& departamento, QString& titulacao, QString& tpccs);
    void alterarElemento(int &matricula, QString &nomeCompleto, QString &departamento, QString &titulacao, QString &tpccs);
    void removerElemento(int& matricula);
    QString *getMatriculas() const;
    QString *getNomes() const;
    QString *getDepartamentos() const;
    QString *getTitulacoes() const;
    QString *getTpcs() const;
    int getTamanhoVetor() const;
};

#endif // TABELA_H
