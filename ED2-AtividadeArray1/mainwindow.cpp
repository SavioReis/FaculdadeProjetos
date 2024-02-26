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
    QIntValidator *validator = new QIntValidator(0, 9999999, this);
    ui->lineEditElementos->setValidator(validator);
    lineEditElementos->setStyleSheet("border: 2px solid red; border-radius: 5px; color: red;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     try {
    srlg::Conjunto vetor(ui->lineEditElementos->text().toInt());
    ui->textEditSaida->setText(vetor.TooString());
     }catch (QString &erro) {
         QMessageBox::information(this, "ERRO" , erro);
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

