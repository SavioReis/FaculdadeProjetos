#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iexe1.h"
#include "iexe2.h"
#include "iexe3.h"
#include "iexe4.h"
#include "iexe5.h"
#include "iexe6.h"

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


void MainWindow::on_pushButton_clicked()
{
    Iexe1 *w1 = new Iexe1;
    w1->show();
    this->hide();
}


void MainWindow::on_pushButtonexercicio2_clicked()
{
    Iexe2 *w2 = new Iexe2;
    w2->show();
    this->hide();
}


void MainWindow::on_pushButtonExercicio3_clicked()
{
    Iexe3 *w3 = new Iexe3;
    w3->show();
    this->hide();
}


void MainWindow::on_pushButtonExercicio4_clicked()
{
    Iexe4 *w4 = new Iexe4;
    w4->show();
    this->hide();
}

void MainWindow::on_pushButtonExercicio5_clicked()
{
    Iexe5 *w5 = new Iexe5;
    w5->show();
    this->hide();
}

void MainWindow::on_pushButtonExercicio6_clicked()
{
    Iexe6 *w5 = new Iexe6;
    w5->show();
    this->hide();
}

