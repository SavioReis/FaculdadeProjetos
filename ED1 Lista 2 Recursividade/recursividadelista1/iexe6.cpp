#include "iexe6.h"
#include "ui_iexe6.h"
#include "mainwindow.h"

Iexe6::Iexe6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Iexe6)
{
    ui->setupUi(this);
}

Iexe6::~Iexe6()
{
    delete ui;
}

void Iexe6::on_pushButtonrecursivo_clicked()
{
    // Calcular o valor aproximado de pi usando recursividade
    double piRecursivo = srlg::exercicio6::calcularPiRecursivo(51);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Valor aproximado de pi usando recursão: " + QString::number(piRecursivo, 'f', 10);
    ui->textEdit->setText(resultado);
}


void Iexe6::on_pushButtonrepeticao_clicked()
{
    // Calcular o valor aproximado de pi usando o loop for
    double piFor = srlg::exercicio6::calcularPiFor();

    // Limpar a QTextEdit
    ui->textEdit->clear();

     // Exibir o resultado no QTextEdit
     QString resultado = "Valor aproximado de pi usando o loop for: " + QString::number(piFor, 'f', 10);
     ui->textEdit->setText(resultado);
}


void Iexe6::on_pushButtonVoltar_clicked()
{
    MainWindow *w2 = new MainWindow;
    w2->show();
    this->hide();
}

