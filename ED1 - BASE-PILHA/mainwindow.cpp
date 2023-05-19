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
    delete ui;
}

void MainWindow::on_pushButtonCalcular_clicked()
{
    try {

        if (ui->LineNumeroBase->text().isEmpty()){
           throw QString("Line esta vazio\nDigite Line numero de Base 10");
        }
        nBase.SetBase(ui->comboBase->currentText().toInt());
        nBase.SetNumeroBase(ui->LineNumeroBase->text().toInt());
        QString txt = nBase.CalcularNumeroBase();
        ui->TextResultado->setText(txt);
    } catch (QString &erro) {
        QMessageBox::information(this,"Erro",erro);
    }
}
