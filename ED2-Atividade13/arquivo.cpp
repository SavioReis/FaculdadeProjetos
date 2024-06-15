#include "arquivo.h"

Arquivo::Arquivo() : vetor(0)
{
}

Arquivo::Arquivo(TabHashProfessor *entrada) : vetor(0)
{
    if (!entrada)
        throw QString("Vetor nao criado");
    vetor = entrada;
}

void Arquivo::abrir()
{
    if (!vetor)
        throw QString("Vetor nao existe");

    QString endereco_arquivo = "D:/Faculdade/Atividade13-EDII/dados/DocentesEscola.csv";
    QFile arquivo(endereco_arquivo);
    if (!arquivo.open(QIODevice::ReadOnly))
        throw QString("Nao foi possivel abrir o arquivo");
    QTextStream in(&arquivo);
    carregar_elementos(in);
    arquivo.close();
}

void Arquivo::carregar_elementos(QTextStream &in)
{
    if (!vetor)
        throw QString("vetor nao existe");

    while (!in.atEnd())
    {
        QString linha = in.readLine();
        QStringList parts = linha.split(";");
        int matricula = parts[0].toInt();
        QString nome = parts[1];
        QString departamento = parts[2];
        QString titulacao = parts[3];
        QString tipoContrato = parts[4];
        Professor professor(matricula, nome, departamento, titulacao, tipoContrato);
        vetor->IncluirDados(professor);
    }
}


