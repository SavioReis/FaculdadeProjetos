#include "arquivo.h"

Arquivo::Arquivo(): matriculas(0), nomes(0), departamentos(0), titulacoes(0), tpcs(0), tamanho_vetor(0) {}

Arquivo::Arquivo(QString *newMatriculas, QString *newNomes, QString *newDepartamentos, QString *newTitulacoes, QString *newTpcs, int tamanho_vetor) :
    matriculas(newMatriculas),
    nomes(newNomes),
    departamentos(newDepartamentos),
    titulacoes(newTitulacoes),
    tpcs(newTpcs),
    tamanho_vetor(tamanho_vetor)
{
    if (!matriculas || !nomes || !departamentos || !titulacoes || !tpcs)
        throw QString("Arrays não criados");
}

bool Arquivo::elemento_existe(const int& matricula)
{
    if (!matriculas)
        throw QString("Arrays não existem");
    if (matricula >= tamanho_vetor || matricula < 0)
        throw QString("Número de matrícula inválido (deve estar entre 0 e " + QString::number(tamanho_vetor - 1) + ")");

    return !nomes[matricula].isEmpty();
}

void Arquivo::abrir()
{
    if (!matriculas)
        throw QString("Arrays não existem");

    QString endereco_arquivo = "D:/Faculdade/ED2-12/Arquivo/DocentesEscola.csv";
    QFile arquivo(endereco_arquivo);
    if (!arquivo.open(QIODevice::ReadOnly))
        throw QString("Não foi possível abrir o arquivo");
    QTextStream in(&arquivo);
    carregar_elementos(in);
    arquivo.close();
}

void Arquivo::carregar_elementos(QTextStream &in)
{
    if (!matriculas)
        throw QString("Arrays não existem");

    while (!in.atEnd()) {
        QString linha = in.readLine();
        QStringList parts = linha.split(";");
        int matricula = parts[0].toInt();

        if (matricula >= tamanho_vetor || matricula < 0)
            throw QString("Matrícula fora do intervalo válido");

        matriculas[matricula] = parts[0];
        nomes[matricula] = parts[1];
        departamentos[matricula] = parts[2];
        titulacoes[matricula] = parts[3];
        tpcs[matricula] = parts[4];
    }
}
