#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("CALCULADORA");
    ui->textEditResultado->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

    void MainWindow::on_pushButtonAdcao_clicked()
    {
        srlg::Calculadora objeto(ui->lineEditPrimeiroTermo->text().toDouble(), ui->lineEditSegundoTermo->text().toDouble());
        ui->textEditResultado->setText(QString::number(objeto.calcularAdcao()));
    }

    void MainWindow::on_pushButtonSubtracao_clicked()
    {
        srlg::Calculadora objeto(ui->lineEditPrimeiroTermo->text().toDouble(), ui->lineEditSegundoTermo->text().toDouble());
        ui->textEditResultado->setText(QString::number(objeto.calcularSubtracao()));
    }

    void MainWindow::on_pushButtonMultiplicacao_clicked()
    {
        srlg::Calculadora objeto(ui->lineEditPrimeiroTermo->text().toDouble(), ui->lineEditSegundoTermo->text().toDouble());
        ui->textEditResultado->setText(QString::number(objeto.calcularMultiplicacao()));
    }

    void MainWindow::on_pushButtonDivisao_clicked()
    {
        try {
            srlg::Calculadora objeto(ui->lineEditPrimeiroTermo->text().toDouble(), ui->lineEditSegundoTermo->text().toDouble());
            ui->textEditResultado->setText(QString::number(objeto.calcularDivisao()));
        } catch (QString erro) {
            QMessageBox::information(this,"Erro de Sistema",erro);
        }

    }

    void MainWindow::on_pushButtonPotenciacao_clicked()
    {
        srlg::Calculadora objeto(ui->lineEditPrimeiroTermo->text().toDouble(), ui->lineEditSegundoTermo->text().toDouble());
        QString instrucao = "Indique o Primerio Termo como a BASE e o Segundo Termo como o EXPOENTE de sua potenciacao";
        QMessageBox::information(this,"Instruções de uso",instrucao);
        ui->textEditResultado->setText(QString::number(objeto.calcularPotenciacao(),'g',15));
    }

    void MainWindow::on_pushButtonRadiciacao_clicked()
    {
        try {
            srlg::Calculadora objeto(ui->lineEditPrimeiroTermo->text().toDouble(), ui->lineEditSegundoTermo->text().toDouble());
            QString instrucao = "Indique o Primeiro Termo como o RADICANDO e o Segundo Termo como o RADICAL de sua radiciacao";
            int auxiliar;
            auxiliar = objeto.getSegundoTermo();
            if (auxiliar % 2 == 1 && objeto.getPrimeiroTermo() < 0){
            QMessageBox::information(this, "Instruções de uso", instrucao);
            ui->textEditResultado->setText("-" + QString::number(objeto.calcularRadiciacao()));
            }
            else{
                QMessageBox::information(this,"Instruções de uso",instrucao);
                ui->textEditResultado->setText(QString::number(objeto.calcularRadiciacao()));
            }
        } catch (QString &erro) {
             QMessageBox::information(this,"Erro de Sistema",erro);
        }
    }

    void MainWindow::on_pushButtonPorcentagem_clicked()
    {
        srlg::Calculadora objeto(ui->lineEditPrimeiroTermo->text().toDouble(), ui->lineEditSegundoTermo->text().toDouble());
        QString instrucao = "Indique o Primeiro Termo como o TODO e o Segundo Termo como as PARTES";
        QMessageBox::information(this,"Instruções de uso",instrucao);
        QString saida = QString::number(objeto.getSegundoTermo()) + "% de " + QString::number(objeto.getPrimeiroTermo()) + " = ";
        ui->textEditResultado->setText(saida + QString::number(objeto.calcularPorcentagem()));
    }

void MainWindow::on_pushButtonAbout_clicked()
{
    QString about = "CALCULADORA 2.1\n";
    about += "Desenvolvido por Gabriel Teodoro e Gubio Garcia. \n";
    about += "Este programa foi desenvolvido para atendimento das demandas de calculos matematicos básicos da empresa GYN Engenharia.";
    QMessageBox::information(this,"About Calculadora",about);
}
