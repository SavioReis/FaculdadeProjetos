#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , operar_tabela(nullptr)
    , arquivo(nullptr)
{
    ui->setupUi(this);
    try {
        operar_tabela = new Tabela(ui->tableWidget_saida_dados, 10000);
        operar_tabela->start();
        arquivo = new Arquivo(operar_tabela->getMatriculas(), operar_tabela->getNomes(), operar_tabela->getDepartamentos(), operar_tabela->getTitulacoes(), operar_tabela->getTpcs(), operar_tabela->getTamanhoVetor());
        arquivo->abrir();
        operar_tabela->atualizar();
    } catch (std::bad_alloc& e) {
        QMessageBox::critical(this, "Erro", "Não foi possível alocar memória para a criação da tabela");
    } catch (QString &e) {
        QMessageBox::critical(this, "Erro", e);
    } catch (...) {
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}

MainWindow::~MainWindow()
{
    delete operar_tabela;
    delete arquivo;
    delete ui;
}

void MainWindow::on_pushButton_consultar_clicked()
{
    try {
        bool ok;
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (ok)
            QMessageBox::about(this, "Concluído", "Matrícula: " + QString::number(matricula) + "\n\nNome Completo: " + operar_tabela->buscaElemento(matricula) + "\n\nDepartamento: " + operar_tabela->getDepartamentos()[matricula]  + "\n\nTitulação: " + operar_tabela->getTitulacoes()[matricula] + "\n\nTipo de Contrato: " + operar_tabela->getTpcs()[matricula]);
        else if (!nomeCompleto.isEmpty())
            QMessageBox::about(this, "Concluído", operar_tabela->buscaElemento(nomeCompleto));
        else
            operar_tabela->atualizar();
    } catch(QString &e) {
        QMessageBox::critical(this, "Erro", e);
    } catch(...) {
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}

void MainWindow::on_pushButton_inserir_clicked()
{
    try {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        QString departamento = ui->lineEdit_departamento->text();
        QString titulacao = ui->lineEdit_titulacao->text();
        QString tpcs = ui->lineEdit_tipodecontrato->text();

        if (!ok)
            throw QString("Matrícula não pode estar vazia");

        operar_tabela->inserirElemento(matricula, nomeCompleto, departamento, titulacao, tpcs);
         QMessageBox::about(this, "Concluído", "Matrícula: " + QString::number(matricula) + "\n\nNome Completo: " + operar_tabela->buscaElemento(matricula) + "\n\nDepartamento: " + operar_tabela->getDepartamentos()[matricula]  + "\n\nTitulação: " + operar_tabela->getTitulacoes()[matricula] + "\n\nTipo de Contrato: " + operar_tabela->getTpcs()[matricula]);
    } catch(QString &e) {
        QMessageBox::critical(this, "Erro", e);
    } catch(...) {
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}


void MainWindow::on_pushButton_alterar_clicked()
{
    try {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        QString departamento = ui->lineEdit_departamento->text();
        QString titulacao = ui->lineEdit_titulacao->text();
        QString tpcs = ui->lineEdit_tipodecontrato->text();

        if (!ok)
            throw QString("Número de matrícula não pode estar vazio");

        operar_tabela->alterarElemento(matricula, nomeCompleto, departamento, titulacao, tpcs);
        QMessageBox::about(this, "Concluído", "Elemento de matrícula: " + QString::number(matricula) + " alterado");
    } catch(QString &e) {
        QMessageBox::critical(this, "Erro", e);
    } catch(...) {
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}


void MainWindow::on_pushButton_remover_clicked()
{
    try {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("Número de matrícula não pode estar vazio");
        operar_tabela->removerElemento(matricula);
        QMessageBox::about(this, "Concluído", "Elemento de matrícula: " + QString::number(matricula) + " removido");
    } catch(QString &e) {
        QMessageBox::critical(this, "Erro", e);
    } catch(...) {
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}
