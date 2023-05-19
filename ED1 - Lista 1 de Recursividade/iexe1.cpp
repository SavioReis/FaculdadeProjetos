#include "iexe1.h"
#include "ui_iexe1.h"
#include <QIntValidator>
#include "mainwindow.h"

Iexe1::Iexe1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Iexe1)
{
    ui->setupUi(this);
    QIntValidator* validator = new QIntValidator(1, INT_MAX, this);
    ui->lineEdit->setValidator(validator);
}

Iexe1::~Iexe1()
{
    delete ui;
}

void Iexe1::on_pushButtonrecursivo_clicked()
{
    QString nStr = ui->lineEdit->text();
    bool ok;
    int n = nStr.toInt(&ok);

    if (!ok || n == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número diferente de zero.");
        return;
    }

    QString resultadoRecursivo;
    srlg::exercicio1::imprimirNumerosRecursivo(n, resultadoRecursivo);
    QString resultado = "Resultado usando recursão:\n" + resultadoRecursivo;

    ui->textEdit->setText(resultado);
}


void Iexe1::on_pushButtonrepeticao_clicked()
{
    QString nStr = ui->lineEdit->text();
    bool ok;
    int n = nStr.toInt(&ok);

    if (!ok || n == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número diferente de zero.");
        return;
    }

    QString resultadoFor;
    srlg::exercicio1::imprimirNumerosFor(n, resultadoFor);
    QString resultado = "Resultado usando for:\n" + resultadoFor + "\n\n";
    ui->textEdit->setText(resultado);
}


void Iexe1::on_pushButtonVoltar_clicked()
{
    MainWindow *w2 = new MainWindow;
    w2->show();
    this->hide();
}

