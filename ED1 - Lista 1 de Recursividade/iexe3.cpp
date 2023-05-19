#include "iexe3.h"
#include "ui_iexe3.h"
#include "mainwindow.h"

Iexe3::Iexe3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Iexe3)
{
    ui->setupUi(this);
}

Iexe3::~Iexe3()
{
    delete ui;
}

void Iexe3::on_pushButtonrecursivo_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();

    bool ok;
    int n = nStr.toInt(&ok);

    if (!ok || n % 2 == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número ímpar válido.");
        return;
    }

    if (!ok || n == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número diferente de zero.");
        return;
    }

    // Chamar a função e obter o resultado
    QString resultadoImparesRecursivo;
    srlg::exercicio3::imprimirNumerosImparesRecursivo(n, resultadoImparesRecursivo);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Números ímpares de 1 a " + QString::number(n) + " (Recursão):\n" + resultadoImparesRecursivo;
    ui->textEdit->setText(resultado);
}


void Iexe3::on_pushButtonrepeticao_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
   bool ok;
    int n = nStr.toInt(&ok);

    if (!ok || n % 2 == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número ímpar válido.");
        return;
    }

    if (!ok || n == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número diferente de zero.");
        return;
    }

    // Chamar a função e obter o resultado
    QString resultadoImparesFor;
    srlg::exercicio3::imprimirNumerosImparesFor(n, resultadoImparesFor);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Números ímpares de 1 a " + QString::number(n) + " (For):\n" + resultadoImparesFor;
    ui->textEdit->setText(resultado);
}


void Iexe3::on_pushButtonVoltar_clicked()
{
    MainWindow *w2 = new MainWindow;
    w2->show();
    this->hide();
}

