#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ilista.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonDesbloqueio_clicked()
{
    Ilista *w2 = new Ilista;
    w2->show();
    this->hide();
}


void MainWindow::on_pushButtonCriador_clicked()
{
    QMessageBox::information(this,"Lista Duplamente Encadeada", "Trabalho de ED1 ");
}

