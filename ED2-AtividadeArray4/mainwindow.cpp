#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QColor>
#include <QIntValidator>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEditSaida->setReadOnly(true);
    QLineEdit *lineEditElementos = ui->lineEditElementos;
    connect(ui->lineEditElementos, &QLineEdit::textChanged, this, &MainWindow::habilitarBotao);
    habilitarBotao(ui->lineEditElementos->text());
    QRegularExpressionValidator *validatorNumeros = new QRegularExpressionValidator(this);
    validatorNumeros->setRegularExpression(QRegularExpression("^\\d+$"));
    ui->lineEditElementos->setValidator(validatorNumeros);
    ui->lineEditValor->setValidator(validatorNumeros);
    ui->textEditSaida->isReadOnly();
    ui->lineEditElementos->setFocus();
    //aparecer na tela a mensagem de de por favor
    lineEditElementos->setPlaceholderText("Por favor, insira um valor");
    connect(ui->lineEditElementos, &QLineEdit::textChanged, this, &MainWindow::handlelineEditElementosTextChanged);

    QLineEdit *lineEditValorBinaria = ui->lineEditValorBinaria;
    lineEditValorBinaria->setPlaceholderText("Por favor, insira um valor");
    connect(ui->lineEditValorBinaria, &QLineEdit::textChanged, this, &MainWindow::handleLineEditValorBinariaTextChanged);

    QLineEdit *lineEditValor = ui->lineEditValor;
    lineEditValor->setPlaceholderText("Por favor, insira um valor");
    connect(ui->lineEditValor, &QLineEdit::textChanged, this, &MainWindow::handlelineEditValorTextChanged);
}
MainWindow::~MainWindow()
{
    delete ui;
}

//aparecer na tela a mensagem de de por favor
void MainWindow::handlelineEditValorTextChanged(const QString &text) {
    if (text.isEmpty()) {
        ui->lineEditValor->setStyleSheet("border: 2px solid red; border-radius: 5px; color: black;");
    } else {
        ui->lineEditValor->setStyleSheet("border: 2px solid red; border-radius: 5px; color: red;");
    }
}

void MainWindow::handleLineEditValorBinariaTextChanged(const QString &text) {
    if (text.isEmpty()) {
        ui->lineEditValorBinaria->setStyleSheet("border: 2px solid red; border-radius: 5px; color: black;");
    } else {
        ui->lineEditValorBinaria->setStyleSheet("border: 2px solid red; border-radius: 5px; color: red;");
    }
}

void MainWindow::handlelineEditElementosTextChanged(const QString &text) {
    if (text.isEmpty()) {
        ui->lineEditElementos->setStyleSheet("border: 2px solid red; border-radius: 5px; color: black;");
    } else {
        ui->lineEditElementos->setStyleSheet("border: 2px solid red; border-radius: 5px; color: red;");
    }
}

//botão gerar
void MainWindow::on_pushButton_clicked()
try {

    if(ui->lineEditElementos->text().isEmpty()) {
        ui->lineEditElementos->setFocus();
        throw QString ("Digite um tamanho para o vetor");
    }
    vetor = new srlg::Conjunto (ui->lineEditElementos->text().toInt());
    ui->textEditSaida->setText(vetor->TooString());
    vetor->selectionSort();
    ui->textEditSaidaOrdenado->setText(vetor->TooStringOrdenado());
    ui->lineEditValor->setFocus();
} catch (QString &erro) {
    QMessageBox::critical(this, "ERRO", erro);
}

//lixeira de dados gerados
void MainWindow::on_pushButtonApagar_clicked()
{
    try {
    ui->textEditSaida->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

//função para bloquear o botão gerar
void MainWindow::habilitarBotao(const QString &texto)
{
    try {
    ui->pushButton->setEnabled(!texto.isEmpty());
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

//apagar quantidade de elementos
void MainWindow::on_pushButton_2_clicked()
{
    try {
    ui->lineEditElementos->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

//botão buscar sequencial
void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        if(ui->lineEditValor->text().isEmpty()) throw QString ("Digite um valor para a busca");
        QString posicao = QString::number(vetor->buscarSequencialMelhorado(ui->lineEditValor->text().toInt()));
        ui->lineEditResultado->setText("O número "+ ui->lineEditValor->text() + " existe na posição " + posicao );
        ui->lineEditValor->setFocus();

    } catch (QString &erro) {
        ui->lineEditResultado->setText("O número ' "+ ui->lineEditValor->text() + " ' procurado não existe");
    }
}

//apagar sequencial
void MainWindow::on_pushButtonApagarSequencial_clicked()
{
    try {
        ui->lineEditValor->clear();
        ui->lineEditResultado->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

//apagar ordenado
void MainWindow::on_pushButtonApagarOrdenado_clicked()
{
    try {
        ui->textEditSaidaOrdenado->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

//buscar binaria
void MainWindow::on_pushButtonBuscarBinario_clicked() {
    try {
        if(ui->lineEditValorBinaria->text().isEmpty())
            throw QString("Digite um valor para a busca");

        QString posicao = QString::number(vetor->buscarBinaria(ui->lineEditValorBinaria->text().toInt()));
        ui->lineEditResultadoBinaria->setText("O número " + ui->lineEditValorBinaria->text() + " existe na posição " + posicao);
        ui->lineEditValorBinaria->setFocus();

    } catch (QString &erro) {
        ui->lineEditResultadoBinaria->setText("O número ' "+ ui->lineEditValor->text() + " ' procurado não existe");
    }
}


//apagar binario
void MainWindow::on_pushButtonApagarBinaria_clicked()
{
    try {
        ui->lineEditValorBinaria->clear();
        ui->lineEditResultadoBinaria->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}
