#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QColor>
#include <QIntValidator>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEditSaida->setReadOnly(true);
    QLineEdit *lineEditElementos = ui->lineEditElementos;
    connect(ui->lineEditElementos, &QLineEdit::textChanged, this, &MainWindow::habilitarBotao);
    habilitarBotao(ui->lineEditElementos->text());
    QRegularExpressionValidator *validatorNumeros = new QRegularExpressionValidator(this);
    validatorNumeros->setRegularExpression(QRegularExpression("^\\d+$"));
    ui->lineEditElementos->setValidator(validatorNumeros);
    ui->lineEditValor->setValidator(validatorNumeros);
    ui->textEditSaida->isReadOnly();
    ui->lineEditElementos->setFocus();
    lineEditElementos->setStyleSheet("border: 2px solid red; border-radius: 5px; color: red;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    try {

        if(ui->lineEditElementos->text().isEmpty()) {
            ui->lineEditElementos->setFocus();
            throw QString ("Digite um tamanho para o vetor");
        }
        vetor = new srlg::Conjunto (ui->lineEditElementos->text().toInt());
        ui->textEditSaida->setText(vetor->TooString());
        ui->lineEditValor->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonApagar_clicked()
{
    try {
    ui->textEditSaida->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

void MainWindow::habilitarBotao(const QString &texto)
{
    try {
    ui->pushButton->setEnabled(!texto.isEmpty());
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    try {
    ui->lineEditElementos->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}
void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        if(ui->lineEditValor->text().isEmpty()) throw QString ("Digite um valor para a busca");
        QString posicao = QString::number(vetor->buscarSequencial(ui->lineEditValor->text().toInt()));
        ui->lineEditResultado->setText("O número "+ ui->lineEditValor->text() + " está na posição " + posicao );
        ui->lineEditValor->setFocus();

    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }
}


void MainWindow::on_pushButtonApagarSequencial_clicked()
{
    try {
        ui->lineEditValor->clear();
        ui->lineEditResultado->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

