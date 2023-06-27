#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete objetoArray;
   objetoArray = nullptr;
   delete ui;
}

void MainWindow::on_pushButtonCriar_clicked()
{
    try {
        objetoArray = new srlg::OrdenacaoVetor(ui->lineEditQuantidadeElementos->text().toInt());
        ui->textEditVetorOriginal->setText(objetoArray->mostrarResultado());
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonExecutar_clicked()
{
    try
       {
           if (ui->comboBox->currentText() == "Crescente")
           {
               objetoArray->ordenarCrescente();
           }
           else
           {
               objetoArray->ordenarDecrescente();
           }
           ui->textEditVetorOrdenado->setText(objetoArray->mostrarResultado());
       }
       catch (QString &erro)
       {
           QMessageBox::critical(this, "Erro ", erro);
       }
   }

