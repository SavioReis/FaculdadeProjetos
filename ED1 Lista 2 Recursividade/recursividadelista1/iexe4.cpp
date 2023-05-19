#include "iexe4.h"
#include "ui_iexe4.h"
#include "mainwindow.h"

Iexe4::Iexe4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Iexe4)
{
    ui->setupUi(this);
}

Iexe4::~Iexe4()
{
    delete ui;
}

void Iexe4::on_pushButtonrecursivo_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
    bool ok;
    int n = nStr.toInt(&ok);

    if (!ok || n == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número diferente de zero.");
        return;
    }

    // Calcular o somatório usando recursão
    int somatorioRecursivo = srlg::exercicio4::calcularSomatorioRecursivo(n);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Somatório de 1 a " + QString::number(n) + " (Recursão): " + QString::number(somatorioRecursivo);
    ui->textEdit->setText(resultado);
}


void Iexe4::on_pushButtonrepeticao_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
    bool ok;
    int n = nStr.toInt(&ok);

    if (!ok || n == 0) {
        // Exibir mensagem de erro
        QMessageBox::critical(this, "Erro", "Por favor, insira um número diferente de zero.");
        return;
    }

    // Calcular o somatório usando o loop for
    int somatorioFor = srlg::exercicio4::calcularSomatorioFor(n);

    // Limpar a QTextEdit
    ui->textEdit->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Somatório de 1 a " + QString::number(n) + " (For): " + QString::number(somatorioFor);
    ui->textEdit->setText(resultado);
}


void Iexe4::on_pushButtonVoltar_clicked()
{
    MainWindow *w2 = new MainWindow;
    w2->show();
    this->hide();
}

