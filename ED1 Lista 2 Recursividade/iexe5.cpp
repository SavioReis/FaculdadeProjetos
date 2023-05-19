#include "iexe5.h"
#include "ui_iexe5.h"

iexe5::iexe5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iexe5)
{
    ui->setupUi(this);
}

iexe5::~iexe5()
{
    delete ui;
}

void iexe5::on_pushButtonvoltar_clicked()
{
    MainWindow *w1 = new MainWindow;
    w1->show();
    this->hide();
}


void iexe5::on_pushButtonDecimalParaBinarioRecursivo_clicked()
{
    // Obter os valores de X e Y a partir dos QLineEdits
    QString xStr = ui->lineEditX->text();
    QString yStr = ui->lineEditY->text();
    bool ok;
    int X = xStr.toInt(&ok);
    int Y = yStr.toInt(&ok);

    // Calcular o valor de K = XY
    srlg::lista2 lista;
    int K = lista.calcularSomaCubosRecursivo(X, Y);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Recursividade : O valor de K  =  X^Y é: " + QString::number(K);
    ui->textEdit->setText(resultado);
}


void iexe5::on_pushButtonpushButtonDecimalParaBinarioFor_clicked()
{
    // Obter os valores de X e Y a partir dos QLineEdits
    QString xStr = ui->lineEditX->text();
    QString yStr = ui->lineEditY->text();
    bool ok;
    int X = xStr.toInt(&ok);
    int Y = yStr.toInt(&ok);

    // Calcular o valor de K = XY usando o loop for
    srlg::lista2 lista;
    int K = lista.calcularSomaCubosFor(X, Y);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Repetição : O valor de K = X^Y é : " + QString::number(K);
    ui->textEdit->setText(resultado);
}

