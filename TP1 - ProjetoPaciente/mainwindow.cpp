#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEditSaida->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonExecutar_clicked()
{
    try {

        srlg::Paciente pessoa(ui->lineEditNomeDoPaciente->text(),
                              ui->lineEditPeso->text().toInt(),
                              ui->lineEditAltura->text().toFloat(),
                              ui->comboBoxSexo->currentText());

        QString saida =  "CLINICA GYN \n";
        saida += "DADOS DO PACIENTE \n";
        saida += "NOME COMPLETO: " + pessoa.getNomeCompleto() + "\n";
        saida += "PESO: " + QString::number(pessoa.getPeso()) + "\n";
        saida += "ALTURA: " + QString::number(pessoa.getAltura()) + "\n";
        saida += "SEXO: " + pessoa.getSexo() + "\n";
        saida += "IMC: "+ QString::number(pessoa.calcularIMC()) + "\n";
        saida += "PESO IDEAL: " + QString::number(pessoa.calcularPesoIdeal()) + "\n";
        saida += "FAIXA DE PESO ATUAL: " + pessoa.calcularFaixaDePeso();

        ui->textEditSaida->setText(saida);

        ui->lineEditNomeDoPaciente->clear();
        ui->lineEditPeso->clear();
        ui->lineEditAltura->clear();

    } catch (QString &erro) {
        QMessageBox::information(this/*cria vinculo entre a UI e a janela de erro*/,"ERRO DO SISTEMA",erro);
    }
}

