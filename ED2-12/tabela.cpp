#include "tabela.h"

Tabela::Tabela() : tabela(0), matriculas(0), nomes(0), departamentos(0), titulacoes(0), tpcs(0), tamanho_vetor(0) {}

Tabela::Tabela(QTableWidget *parent, int tamanho_vetor) :
    tabela(0),
    matriculas(0),
    nomes(0),
    departamentos(0),
    titulacoes(0),
    tpcs(0),
    tamanho_vetor(0)
{
    if (!parent)
        throw QString("Tabela não criada");

    this->tabela = parent;
    if (tamanho_vetor <= 0)
        throw QString("Tamanho inválido, o valor precisa ser maior que 0");

    this->tamanho_vetor = tamanho_vetor;
    try {
        matriculas = new QString[tamanho_vetor];
        nomes = new QString[tamanho_vetor];
        departamentos = new QString[tamanho_vetor];
        titulacoes = new QString[tamanho_vetor];
        tpcs = new QString[tamanho_vetor];
    } catch(const std::bad_alloc& e) {
        throw QString("Não foi possível alocar memória");
    }
}

QString *Tabela::getMatriculas() const {
    return matriculas;
}

QString *Tabela::getNomes() const {
    return nomes;
}

QString *Tabela::getDepartamentos() const {
    return departamentos;
}

QString *Tabela::getTitulacoes() const {
    return titulacoes;
}

QString *Tabela::getTpcs() const {
    return tpcs;
}

int Tabela::getTamanhoVetor() const {
    return tamanho_vetor;
}

Tabela::~Tabela()
{
    if (matriculas)
        delete[] matriculas;
    if (nomes)
        delete[] nomes;
    if (departamentos)
        delete[] departamentos;
    if (titulacoes)
        delete[] titulacoes;
    if (tpcs)
        delete[] tpcs;
}

void Tabela::start()
{
    if (!tabela)
        throw QString("Tabela não localizada");

    tabela->setColumnCount(5);
    QStringList cabecalho = {"Matrícula", "Nome Completo", "Departamento", "Titulação", "TPC"};
    tabela->setHorizontalHeaderLabels(cabecalho);
    tabela->setColumnWidth(0, 100); // Matrícula
    tabela->setColumnWidth(1, 300); // Nome
    tabela->setColumnWidth(2, 100); // Departamento
    tabela->setColumnWidth(3, 100); // Titulação
    tabela->setColumnWidth(4, 150); // TPC
    tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabela->verticalHeader()->setVisible(false);
}

void Tabela::limpar()
{
    if (!tabela)
        throw QString("Tabela não localizada");

    tabela->setRowCount(0);
    tabela->clearContents();
    start();
}

void Tabela::atualizar()
{
    if (!tabela)
        throw QString("Tabela não localizada");

    if (!matriculas || !nomes || !departamentos || !titulacoes || !tpcs)
        throw QString("Arrays não localizados");

    limpar();

    for (int i = 0; i < tamanho_vetor; ++i) {
        tabela->insertRow(i);
        tabela->setItem(i, 0, new QTableWidgetItem(matriculas[i]));
        tabela->setItem(i, 1, new QTableWidgetItem(nomes[i]));
        tabela->setItem(i, 2, new QTableWidgetItem(departamentos[i]));
        tabela->setItem(i, 3, new QTableWidgetItem(titulacoes[i]));
        tabela->setItem(i, 4, new QTableWidgetItem(tpcs[i]));
    }
}

QString Tabela::buscaElemento(const int& matricula)
{
    if (matricula >= tamanho_vetor || matricula < 0)
        throw QString("Número inválido, deve estar entre 0 e " + QString::number(tamanho_vetor - 1));

    if (!nomes)
        throw QString("Arrays não localizados");

    if (nomes[matricula].isEmpty())
        return "Não encontrado";
    return nomes[matricula];
}

QString Tabela::buscaElemento(const QString &nomeCompleto)
{
    if (!nomes)
        throw QString("Arrays não localizados");

    for (int i = 0; i < tamanho_vetor; ++i) {
        if (nomes[i].compare(nomeCompleto, Qt::CaseInsensitive) == 0) {
            return "Matrícula: " + matriculas[i] + "\n\nNome Completo: " + nomes[i] + "\n\nDepartamento: " + departamentos[i] + "\n\nTitulação: " + titulacoes[i] + "\n\nTipo de Contrato: " + tpcs[i];
        }
    }
    return "Não encontrado";
}

void Tabela::inserirElemento(int& matricula, QString& nomeCompleto, QString& departamento, QString& titulacao, QString& tpccs)
{
    if (matricula < 0 || matricula >= tamanho_vetor)
        throw QString("Número de matrícula inválido");

    if (nomeCompleto.isEmpty())
        throw QString("Nome não pode estar vazio");

    if (departamento.isEmpty())
        throw QString("Departamento não pode estar vazio");

    if (titulacao.isEmpty())
        throw QString("Titulacao não pode estar vazio");

    if (tpccs.isEmpty())
        throw QString("Tipo de Contrato não pode estar vazio");

    if (!nomes)
        throw QString("Arrays não localizados");

    if (!nomes[matricula].isEmpty())
        throw QString("Este elemento já existe");

    matriculas[matricula] = QString::number(matricula);
    nomes[matricula] = nomeCompleto.toUpper();
    departamentos[matricula] = departamento;
    titulacoes[matricula] = titulacao;
    tpcs[matricula] = tpccs;
    atualizar();
}

void Tabela::alterarElemento(int &matricula, QString &nomeCompleto, QString &departamento, QString &titulacao, QString &tpccs)
{
    if (matricula < 0 || matricula >= tamanho_vetor)
        throw QString("Número de matrícula inválido");

    if (nomeCompleto.isEmpty())
        throw QString("Nome não pode estar vazio");

    if (!nomes)
        throw QString("Arrays não localizados");

    if (nomes[matricula].isEmpty())
        throw QString("Elemento não existe");

    nomes[matricula] = nomeCompleto.toUpper();
    departamentos[matricula] = departamento;
    titulacoes[matricula] = titulacao;
    tpcs[matricula] = tpccs;
    atualizar();
}


void Tabela::removerElemento(int &matricula)
{
    if (!nomes)
        throw QString("Arrays não localizados");

    if (matricula < 0 || matricula >= tamanho_vetor)
        throw QString("Número de matrícula inválido");

    if (nomes[matricula].isEmpty())
        throw QString("Elemento já foi removido");

    nomes[matricula].clear();
    departamentos[matricula].clear();
    titulacoes[matricula].clear();
    tpcs[matricula].clear();
    atualizar();
}
