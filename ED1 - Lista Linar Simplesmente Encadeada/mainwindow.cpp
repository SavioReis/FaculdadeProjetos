#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButtonAcessarInicio->setEnabled(false);
    ui->pushButtonRetiraInicio->setEnabled(false);
    ui->pushButtonAcessarFinal->setEnabled(false);
    ui->pushButtonRetiraFinal->setEnabled(false);
    ui->pushButtonIncluirFinal->setEnabled(false);

    ui->pushButtoninserirposicao->setEnabled(false);
    ui->pushButtonAcessarposicao->setEnabled(false);
    ui->pushButtonRetirarPosicao->setEnabled(false);

    ui->textEditSaidaQtdElementos->setEnabled(false);
    ui->textEditSaida->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonIncluirInicio_clicked()
{
//    int posicao = ui->lineEditValor->text().toInt();
    try{
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
           lista1.inserirInicio(valor);
            ui->lineEditValor->clear();
            ui->textEditSaida->setText(lista1.obterDadosLLSE());
            ui->textEditSaidaQtdElementos->setText(QString::number(lista1.getquantidadedeBagulho()));
        }
        else
        {
//            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }
        ui->textEditSaida->setText(lista1.obterDadosLLSE());
        ui->pushButtonAcessarInicio->setEnabled(true);
        ui->pushButtonRetiraInicio->setEnabled(true);
        ui->lineEditValor->clear();

        QString saida = QString::number(lista1.getquantidadedeBagulho());
        ui->textEditSaidaQtdElementos->setText(saida);

        ui->pushButtonIncluirFinal->setEnabled(true);
        ui->pushButtonAcessarFinal->setEnabled(true);
        ui->pushButtonRetiraFinal->setEnabled(true);

       ui->pushButtoninserirposicao->setEnabled(true);
       ui->pushButtonAcessarposicao->setEnabled(true);
       ui->pushButtonRetirarPosicao->setEnabled(true);


    } catch(QString &erro){
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try{
        int valor = lista1.acessarInicio();
        ui->lineEditValor->setText(QString::number(valor));
    } catch (QString &erro){
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonRetiraInicio_clicked()
{
    try{
        int valor = lista1.retirarInicio();
        ui->lineEditValor->setText(QString::number(valor));

        QString saida = QString::number(lista1.getquantidadedeBagulho());
        ui->textEditSaidaQtdElementos->setText(saida);

        ui->textEditSaida->clear();
        ui->textEditSaida->setText(lista1.obterDadosLLSE());
    } catch (QString &erro){
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonIncluirFinal_clicked()
{
    try {
        int valor = ui->lineEditValor->text().toInt();
        if(!valor) throw QString("INFORME UM NÚMERO INTEIRO - deve ser um inteiro");
        lista1.inserirFinal(valor);

        ui->textEditSaida->setText(lista1.obterDadosLLSE());
        ui->lineEditValor->clear();

        QString saida = QString::number(lista1.getquantidadedeBagulho());
        ui->textEditSaidaQtdElementos->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonAcessarFinal_clicked()
{
    try {
        int valor = lista1.acessarFinal();
        ui->lineEditValor->setText(QString::number(valor));
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonRetiraFinal_clicked()
{
    try {
        int valor = lista1.retirarFinal();
        ui->lineEditValor->setText(QString::number(valor));

        QString saida = QString::number(lista1.getquantidadedeBagulho());
        ui->textEditSaidaQtdElementos->setText(saida);

        ui->textEditSaida->clear();
        ui->textEditSaida->setText(lista1.obterDadosLLSE());
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtoninserirposicao_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
            lista1.inserirPosicao(valor, posicao);
            ui->lineEditValor->clear();
            ui->textEditSaida->setText(lista1.obterDadosLLSE());
            ui->textEditSaidaQtdElementos->setText(QString::number(lista1.getquantidadedeBagulho()));
        }
        else
        {
//            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }
        int QE = lista1.getquantidadedeBagulho();
        ui->spinBox->setMaximum(QE);

    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

}

void MainWindow::on_pushButtonAcessarposicao_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        if(lista1.estaVazia()) throw QString("A lista esta vazia!");
        QString saida = QString::number(lista1.acessarPosicao(posicao));
        ui->lineEditValor->setText(saida);

    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

}

void MainWindow::on_pushButtonRetirarPosicao_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        if(lista1.estaVazia()) throw QString("A lista já esta vazia!");
        QString saida = QString::number(lista1.retirarPosicao(posicao));

        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista1.obterDadosLLSE());
        ui->textEditSaidaQtdElementos->setText(QString::number(lista1.getquantidadedeBagulho()));

        int QE = lista1.getquantidadedeBagulho();
        ui->spinBox->setMaximum(QE);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}
