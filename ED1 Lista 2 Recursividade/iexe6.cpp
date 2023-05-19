#include "iexe6.h"
#include "ui_iexe6.h"

iexe6::iexe6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iexe6)
{
    ui->setupUi(this);
}

iexe6::~iexe6()
{
    delete ui;
}

void iexe6::on_pushButtonMultiplicarRecursivo_clicked()
{
    // Obter os valores de N1 e N2 a partir dos QLineEdits
    QString n1Str = ui->lineEditN1->text();
    QString n2Str = ui->lineEditN2->text();
    bool ok;
    int n1 = n1Str.toInt(&ok);
    int n2 = n2Str.toInt(&ok);

    // Calcular a multiplicação recursiva
    srlg::lista2 lista;
    int resultado = lista.multiplicarRecursivo(n1, n2);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultadoStr = "Recursivo : O resultado da multiplicação é: " + QString::number(resultado);
    ui->textEdit->setText(resultadoStr);
}
void iexe6::on_pushButtonVoltar_clicked()
{
    MainWindow *w1 = new MainWindow;
    w1->show();
    this->hide();
}


void iexe6::on_pushButtonMultiplicarFor_clicked()
{
    // Obter os valores de N1 e N2 a partir dos QLineEdits
    QString n1Str = ui->lineEditN1->text();
    QString n2Str = ui->lineEditN2->text();
    bool ok;
    int n1 = n1Str.toInt(&ok);
    int n2 = n2Str.toInt(&ok);

    // Calcular a multiplicação usando o loop for
    srlg::lista2 lista;
    int resultado = lista.multiplicarFor(n1, n2);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado na QTextEdit
    QString resultadoStr = "Imperativo : O resultado da multiplicação é: " + QString::number(resultado);
    ui->textEdit->setText(resultadoStr);
}

