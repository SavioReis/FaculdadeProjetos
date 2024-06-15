#include "tabela.h"

Tabela::Tabela() : tabela(0),
    tabela_hash(0),
    tamanho_tabela(0)
{
}

Tabela::Tabela(QTableWidget *parent, const int &tamanho, const int &colisoes) : tabela(0),
    tabela_hash(0),
    tamanho_tabela(0)
{
    if (!parent)
        throw QString("Tabela não criada");
    if (tamanho <= 0)
        throw QString("Tamanho inválido");
    if (colisoes <= 0)
        throw QString("Número de colisões inválido");
    this->tabela = parent;
    try
    {
        tabela_hash = new TabHashProfessor(tamanho, colisoes);
        this->tamanho_tabela = tabela_hash->getTamanhoTabela();
    }
    catch (const std::bad_alloc &e)
    {
        throw QString("Não foi possível alocar memória");
    }
}

TabHashProfessor *Tabela::getVetor() const
{
    return tabela_hash;
}

int Tabela::getTamanhoTabela() const
{
    return tamanho_tabela;
}

Tabela::~Tabela()
{
    if (tabela_hash)
        delete tabela_hash;
}

void Tabela::start()
{
    if (!tabela)
        throw QString("Tabela não localizada {start}");
    tabela->setColumnCount(tabela_hash->getColisoes() + 4); // Adicionado +4 para os novos campos
    tabela->setColumnWidth(0, 10);
    for (int i = 1; i < tabela_hash->getColisoes() + 4; ++i) // Adicionado +4 para os novos campos
    {
        tabela->setColumnWidth(i, 100); // Ajuste do tamanho da coluna
    }
    tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabela->verticalHeader()->setVisible(false);
}

void Tabela::limpar()
{
    if (!tabela)
        throw QString("Tabela não localizada, {limpartabela}");

    tabela->setRowCount(0);
    tabela->clearContents();
    start();
}

void Tabela::atualizar()
{
    if (!tabela)
        throw QString("tabela nao localizada {atualizar}");

    if (!tabela_hash)
        throw QString("tabela_hash nao localizado {atualizar}");

    limpar();
    Lista<Professor> **vetor = tabela_hash->getVetor();
    for (int i = 0; i  < tamanho_tabela; ++i){
        tabela->insertRow(i);
        tabela->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        for (int j = 0; j < vetor[i]->getQuantidadeElementos(); ++j){
            Professor professor = vetor[i]->acessarPosicao(j);
            tabela->setItem(i, j + 1, new QTableWidgetItem(QString::number(professor.getMatricula()) + "; " + professor.getNome()+ ";" + professor.getDepartamento() + ";" + professor.getTitulacao() + ";" + professor.getTipoContrato()));
        }
    }
}

QString Tabela::buscaElemento(const int &matricula)
{
    if (matricula < 0)
        throw QString("Número inválido");

    if (!tabela_hash)
        throw QString("Tabela_hash não localizado {buscaelemento}");
    return tabela_hash->Consultar(matricula).getNome();
}

void Tabela::inserirElemento(const int &matricula, const QString &nomeCompleto, const QString &departamento, const QString &titulacao, const QString &tipoContrato)
{
    if (matricula < 0)
        throw QString("Número de matricula não condiz com os padrões {inserirElemento}");

    if (nomeCompleto.isEmpty())
        throw QString("Nome não pode estar vazio, se deseja remover use o botão 'remover' {inserirElemento}");

    if (!tabela_hash)
        throw QString("Tabela_hash não localizado {inserirElemento}");

    if (tabela_hash->Consultar(matricula).getNome() != "")
        throw QString("Este elemento já existe, se deseja alterar, use o botão 'alterar' {inserirElemento}");
    Professor professor(matricula, nomeCompleto.toUpper(), departamento, titulacao, tipoContrato);
    tabela_hash->IncluirDados(professor);
    atualizar();
}

void Tabela::alterarElemento(const int &matricula, const QString &nomeCompleto, const QString &departamento, const QString &titulacao, const QString &tipoContrato)
{
    if (matricula < 0)
        throw QString("Número de matricula não condiz com os padrões {alterarElemento}");

    if (nomeCompleto.isEmpty())
        throw QString("Nome não pode estar vazio, se deseja remover use o botão 'remover' {alterarElemento}");

    if (!tabela_hash)
        throw QString("Tabela_hash não localizado {alterarElemento}");

    if (tabela_hash->Consultar(matricula).getNome() == "")
    {
        throw QString("Elemento não existe, se deseja adicionar use o botão 'inserir' {alterarElemento}");
    }
    else
    {
        tabela_hash->ExcluirDados(matricula);
    }
    Professor professor(matricula, nomeCompleto.toUpper(), departamento, titulacao, tipoContrato);
    tabela_hash->IncluirDados(professor);
    atualizar();
}

void Tabela::removerElemento(const int &matricula) {
    if (!tabela_hash)
        throw QString("Tabela_hash não localizado {removerElemento}");
    if (matricula < 0)
        throw QString("Número de matrícula não condiz com os padrões {removerElemento}");

    if (tabela_hash->Consultar(matricula).getMatricula() == -1)
    {
        throw QString("Elemento não existe, se deseja adicionar use o botão 'inserir' {alterarElemento}");
    }

    tabela_hash->ExcluirDados(matricula);
    atualizar();
}
