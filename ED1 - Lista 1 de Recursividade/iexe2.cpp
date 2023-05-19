#include "iexe2.h"
#include "ui_iexe2.h"
#include <QIntValidator>
#include "mainwindow.h"

Iexe2::Iexe2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Iexe2)
{
    ui->setupUi(this);
    QIntValidator* validator = new QIntValidator(1, INT_MAX, this);
    ui->lineEdit->setValidator(validator);
}

Iexe2::~Iexe2()
{
    delete ui;
}

void Iexe2::on_pushButtonrepeticao_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
    bool ok;
    int n = nStr.toInt(&ok);

    if (!ok || n % 2 != 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número par válido.");
        return;
    }

    if (!ok || n == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número diferente de zero.");
        return;
    }

    // Chamar a função e obter o resultado
    QString resultadoParesFor;
    srlg::exercicio2::imprimirNumerosParesFor(n, resultadoParesFor);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Números pares de 1 a " + QString::number(n) + " (For):\n" + resultadoParesFor;
    ui->textEdit->setText(resultado);
}


void Iexe2::on_pushButtonrecursivo_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
   bool ok;
    int n = nStr.toInt(&ok);

    if (!ok || n % 2 != 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número par válido.");
        return;
    }

    if (!ok || n == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número diferente de zero.");
        return;
    }

    // Chamar a função e obter o resultado
    QString resultadoParesRecursivo;
    srlg::exercicio2::imprimirNumerosParesRecursivo(n, resultadoParesRecursivo);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Números pares de 1 a " + QString::number(n) + " (Recursão):\n" + resultadoParesRecursivo;
    ui->textEdit->setText(resultado);
}


void Iexe2::on_pushButtonVoltar_clicked()
{
    MainWindow *w2 = new MainWindow;
    w2->show();
    this->hide();
}

