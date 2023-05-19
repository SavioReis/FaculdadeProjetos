#include "mainwindow.h"
#include "qtablewidget.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      nomeDoArquivoNabiblioteca("")
{
    ui->setupUi(this);
    ui->lineEditNomeDoArquivo->setEnabled(false);
    ui->pushButtonMostrarResultado->setEnabled(false);
    ui->tableWidgetDados->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetDados->verticalHeader()->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        nomeDoArquivoNabiblioteca = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
          if(nomeDoArquivoNabiblioteca.isEmpty()) throw QString("Selecione o arquivo");
          ui->lineEditNomeDoArquivo->setText(nomeDoArquivoNabiblioteca);
      } catch (QString &erro) {
          QMessageBox::information(this,"ERRO DE SISTEMA",erro);
      }
    ui->pushButtonMostrarResultado->setEnabled(true);
}

void MainWindow::on_pushButtonMostrarResultado_clicked()
{
    try {
        srlg::ManipularArquivo objetoMA(nomeDoArquivoNabiblioteca);
        objetoMA.buscarDadosNaBiblioteca();
        srlg::Piloto p;
        std::vector<srlg::Piloto> const &listaDePilotos =  objetoMA.getlistaDePilotos();

            for(int j=0;j<(int)listaDePilotos.size();j++){
                QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(listaDePilotos[j].getCodigo()));
                ui->tableWidgetDados->setItem(j,0,item1);
                QTableWidgetItem *item2 = new QTableWidgetItem(listaDePilotos[j].getNome());
                ui->tableWidgetDados->setItem(j,1,item2);
                QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(listaDePilotos[j].getPontuacaoFinal()));
                ui->tableWidgetDados->setItem(j,2,item3);
                QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(j+1));
                ui->tableWidgetDados->setItem(j,3,item4);
         }

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DE SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonCriador_clicked()
{
    QMessageBox::information(this,"FÓRMUMA 1", "Trabalho de TP2 ");
}

