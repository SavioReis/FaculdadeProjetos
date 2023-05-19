#include "iexe5.h"
#include "ui_iexe5.h"
#include "mainwindow.h"

Iexe5::Iexe5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Iexe5)
{
    ui->setupUi(this);
}

Iexe5::~Iexe5()
{
    delete ui;
}

void Iexe5::on_pushButtonrecursivo_clicked()
{
    // Calcular o valor de pi usando recursividade
    double piRecursivo = srlg::exercicio5::calcularPiRecursivo(1000); // Defina o valor máximo de termo desejado

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Valor de pi usando recursão: " + QString::number(piRecursivo, 'f', 4);
    ui->textEdit->setText(resultado);
}


void Iexe5::on_pushButtonrepeticao_clicked()
{
    // Calcular o valor de pi usando o loop for
    double piFor = srlg::exercicio5::calcularPiFor();

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Valor de pi usando o loop for: " + QString::number(piFor, 'f', 4);
    ui->textEdit->setText(resultado);
}


void Iexe5::on_pushButtonVoltar_clicked()
{
    MainWindow *w2 = new MainWindow;
    w2->show();
    this->hide();
}

