#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpressionValidator *validatorNumeros = new QRegularExpressionValidator(this);
    validatorNumeros->setRegularExpression(QRegularExpression("^\\d+$"));
    ui->lineEditTamanho->setValidator(validatorNumeros);
    ui->textEdit->isReadOnly();
    ui->textEditOrdenadoInsertion->isReadOnly();
    ui->textEditOrdenadoSelection->isReadOnly();
    ui->lineEditTamanho->setFocus();
    //aparecer na tela a mensagem de de por favor
    QLineEdit *lineEditTamanho = ui->lineEditTamanho;
    lineEditTamanho->setPlaceholderText("Por favor, insira um valor");
    connect(ui->lineEditTamanho, &QLineEdit::textChanged, this, &MainWindow::handleTextChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//aparecer na tela a mensagem de de por favor
void MainWindow::handleTextChanged(const QString &text) {
    if (text.isEmpty()) {
        ui->lineEditTamanho->setStyleSheet("border: 2px solid red; border-radius: 5px; color: black;");
    } else {
        ui->lineEditTamanho->setStyleSheet("border: 2px solid red; border-radius: 5px; color: red;");
    }
}

void MainWindow::on_pushButtonGerar_clicked()
{
    try {

        if(ui->lineEditTamanho->text().isEmpty()) {
            ui->lineEditTamanho->setFocus();
            throw QString ("Digite um tamanho para o vetor");
        }

        vetor = new srlg::Conjunto (ui->lineEditTamanho->text().toInt());
        ui->textEdit->setText(vetor->TooString());

        clock_t tempoInicioSelection = clock();
        ui->textEditOrdenadoSelection->setText(vetor->TooStringOrdenado());
        clock_t tempoFinalSelection = clock();
        double tempoDeRespostaSelection = (tempoFinalSelection - tempoInicioSelection) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoSS->setText(QString::number(tempoDeRespostaSelection) + " Ms");

        clock_t tempoInicialInsertion = clock();
        ui->textEditOrdenadoInsertion->setText(vetor->TooStringInsertionSort());
        clock_t tempoFinalInsertion = clock();
        double tempoDeRespostaInsertion = (tempoFinalInsertion - tempoInicialInsertion) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoIS->setText(QString::number(tempoDeRespostaInsertion) + " Ms");

        clock_t tempoInicialbBubble = clock();
        ui->textEditOrdenadoBubble->setText(vetor->TooStringBubbleSort());
        clock_t tempoFinalBubble = clock();
        double tempoDeRespostaBubble = (tempoFinalBubble - tempoInicialbBubble) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoBBS->setText(QString::number(tempoDeRespostaBubble) + " Ms");

        clock_t tempoInicialMerge = clock();
        ui->textEditOrdenadoMerge->setText(vetor->TooStringMergeSort());
        clock_t tempoFinalMerge = clock();
        double tempoDeRespostaMerge = ((tempoFinalMerge - tempoInicialMerge) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
        ui->textEditTempoMGS->setText(QString::number(tempoDeRespostaMerge) + " Ms");

        clock_t tempoInicialHeap = clock();
        ui->textEditOrdenadoHeap->setText(vetor->TooStringHeapSort());
        clock_t tempoFinalHeap = clock();
        double tempoDeRespostaHeap = ((tempoFinalHeap - tempoInicialHeap) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
        ui->textEditTempoHS->setText(QString::number(tempoDeRespostaHeap) + " Ms");


        ui->textEditExecOrdenSelection->setText(QString::number(vetor->getNumOrdenSelectionSort()));
        ui->textEditExecOrdenInsertion->setText(QString::number(vetor->getNumOrdenInsertionSort()));
        ui->textEditExecOrdenBubble->setText(QString::number(vetor->getNumOrdenBubleSort()));
        ui->textEditExecOrdenMerge->setText(QString::number(vetor->getNumOrdenMergeSort()));


    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }

}


void MainWindow::on_pushButtonApagarQtElementos_clicked()
{
    try {
        ui->lineEditTamanho->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}


void MainWindow::on_pushButtonApagarSelection_clicked()
{
    try {
        ui->textEditOrdenadoSelection->clear();
        ui->textEditExecOrdenSelection->clear();
        ui->textEditTempoSS->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}


void MainWindow::on_pushButtonApagarInsertion_clicked()
{
    try {
        ui->textEditOrdenadoInsertion->clear();
        ui->textEditExecOrdenInsertion->clear();
        ui->textEditTempoIS->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}


void MainWindow::on_pushButtonApagarDadosGerados_clicked()
{
    try {
        ui->textEdit->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}


void MainWindow::on_pushButtonApagarBubble_clicked()
{
    try {
        ui->textEditOrdenadoBubble->clear();
        ui->textEditExecOrdenBubble->clear();
        ui->textEditTempoBBS->clear();
    }catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}

