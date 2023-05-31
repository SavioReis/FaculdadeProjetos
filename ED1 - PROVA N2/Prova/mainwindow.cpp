#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_executar1_clicked()
{
    // Obter os valores de N1 e N2 a partir dos QLineEdits
    QString xStr = ui->lineEditN->text();
    QString yStr = ui->lineEditM->text();
    bool ok;
    int x = xStr.toInt(&ok);
    int y = yStr.toInt(&ok);

    // Calcular a multiplicação recursiva
    srlg::recursivo lista;
    int resultador = lista.divisorcomum(x,y);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultadorStr = "" + QString::number(resultador);
    ui->textEdit->setText(resultadorStr);
}


void MainWindow::on_executar2_clicked()
{
    // Obter os valores de N1 e N2 a partir dos QLineEdits
    QString nStr = ui->lineEditN->text();
    QString kStr = ui->lineEditM->text();
    bool ok;
    int n = nStr.toInt(&ok);
    int k = kStr.toInt(&ok);

    // Calcular a multiplicação recursiva
    srlg::recursivo lista;
    int resultador = lista.countDigit(n,k);

    // Limpar a QTextEdit
    ui->textEdit2->clear();

    // Exibir o resultado no QTextEdit
    QString resultadorStr = "" + QString::number(resultador);
    ui->textEdit2->setText(resultadorStr);
}


void MainWindow::on_limpar_clicked()
{
    ui->textEdit->clear();
    ui->textEdit2->clear();
}

