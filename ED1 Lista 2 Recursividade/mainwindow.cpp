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

void MainWindow::on_pushButtonCalcularSomaCubosFor_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
    int n = nStr.toInt();

    // Calcular a soma dos primeiros n cubos usando recursividade
    int somaCubosin= srlg::lista2::calcularSomaCubosFor(n);

    // Limpar a QTextEdit
    ui->textEdit1->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Soma dos primeiros " + QString::number(n) + " cubos (Imperativo): " + QString::number(somaCubosin);
    ui->textEdit1->setText(resultado);
}


void MainWindow::on_pushButtonNumerosDecrescenteRecursivo_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
   bool ok;
    int n = nStr.toInt(&ok);

    // Chamar a função e obter o resultado
    QString resultado;
    srlg::lista2::imprimirNumerosDecrescenteRecursivo(n, resultado);

    // Limpar a QTextEdit
    ui->textEdit2->clear();

    // Exibir o resultado no QTextEdit
    QString resultadoq = "Números  Descrecente " + QString::number(n) + " (Recursivo) : " + resultado;
    ui->textEdit2->setText(resultadoq);
}

void MainWindow::on_pushButtonNumerosDecrescenteFor_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
   bool ok;
    int n = nStr.toInt(&ok);

    // Chamar a função e obter o resultado
    QString resultadofor;
    srlg::lista2::imprimirNumerosDecrescenteFor(n, resultadofor);

    // Limpar a QTextEdit
    ui->textEdit2->clear();

    // Exibir o resultado no QTextEdit
    QString resultadoq = "Números  Descrecente " + QString::number(n) + " (Imperativo) : " + resultadofor;
    ui->textEdit2->setText(resultadoq);
}


void MainWindow::on_pushButtonDecimalParaBinarioRecursivo_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
    bool ok;
    int n = nStr.toInt(&ok);

    // Chamar a função recursiva e obter o resultado em binário
    srlg::lista2 lista;
    std::string binarioRecursivo = lista.decimalParaBinarioRecursivo(n);

    // Limpar a QTextEdit
    ui->textEdit4->clear();

    // Exibir o resultado no QTextEdit
    QString resultadoRecursivo = "Número Decimal " + QString::number(n) + " (Recursivo) em Binário: " + QString::fromStdString(binarioRecursivo);
    ui->textEdit4->setText(resultadoRecursivo);
}


void MainWindow::on_pushButtonDecimalParaBinarioFor_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
    bool ok;
    int n = nStr.toInt(&ok);

    // Chamar a função com loop for e obter o resultado em binário
    srlg::lista2 lista;
    std::string binarioFor = lista.decimalParaBinarioFor(n);

    // Limpar a QTextEdit
    ui->textEdit4->clear();

    // Exibir o resultado no QTextEdit
    QString resultadoFor = "Número Decimal " + QString::number(n) + " (Imperativo) em Binário: " + QString::fromStdString(binarioFor);
    ui->textEdit4->setText(resultadoFor);
}

void MainWindow::on_pushButtonFindSmallestRecursive_clicked()
{
    // Obter o texto digitado no QLineEdit
    QString numbersStr = ui->lineEdit->text();

    // Separar os números por espaços em uma lista
    QStringList numbersList = numbersStr.split(" ");

    // Converter a lista de números em um vetor de double
    std::vector<double> numbers;
    for (const QString& numberStr : numbersList) {
        bool ok;
        double number = numberStr.toDouble(&ok);
        if (ok) {
            numbers.push_back(number);
        }
    }

    // Verificar se há pelo menos um número no vetor
    if (numbers.empty()) {
        // Se não houver números válidos, exibir uma mensagem de erro
        ui->textEdit3->setText("Nenhum número válido foi fornecido.");
        return;
    }

    // Criar uma instância da classe lista2
    srlg::lista2 lista;

    // Encontrar o menor elemento no vetor de forma recursiva
    double smallestRecursive = lista.findSmallestRecursive(numbers, 0, numbers[0]);

    // Limpar o QTextEdit
    ui->textEdit3->clear();

    // Exibir o resultado no QTextEdit
    QString resultRecursive = "Menor elemento (Recursivo): " + QString::number(smallestRecursive);
    ui->textEdit3->setText(resultRecursive);
}


void MainWindow::on_pushButtonpushButtonFindSmallestIterative_clicked()
{
    // Obter o vetor de números a partir do QLineEdit
    QString numbersStr = ui->lineEdit->text();
    QStringList numbersList = numbersStr.split(" ");
    std::vector<int> numbers;
    for (const QString& numberStr : numbersList) {
        bool ok;
        int number = numberStr.toInt(&ok);
        if (ok) {
            numbers.push_back(number);
        }
    }

    // Chamar a função iterativa e obter o menor elemento
    srlg::lista2 lista;
    int smallestIterative = lista.findSmallestIterative(numbers);

    // Limpar o QTextEdit
    ui->textEdit3->clear();

    // Exibir o resultado no QTextEdit
    QString resultIterative = "Menor elemento (Interativo): " + QString::number(smallestIterative);
    ui->textEdit3->setText(resultIterative);
}

void MainWindow::on_pushButtonmudartelaexe5_clicked()
{
    iexe5 *w1 = new iexe5;
    w1->show();
    this->hide();
}

void MainWindow::on_pushButtonpushButtonCalcularSomaCubosRecursivo_clicked()
{
    // Obter o valor de n a partir do QLineEdit
    QString nStr = ui->lineEdit->text();
    int n = nStr.toInt();

    // Calcular a soma dos primeiros n cubos usando recursividade
    int somaCubos = srlg::lista2::calcularSomaCubosRecursivo(n);

    // Limpar a QTextEdit
    ui->textEdit1->clear();

    // Exibir o resultado no QTextEdit
    QString resultado = "Soma dos primeiros " + QString::number(n) + " cubos (Recursivo): " + QString::number(somaCubos);
    ui->textEdit1->setText(resultado);
}


void MainWindow::on_pushButtonmudartelaexe6_clicked()
{
    iexe6 *w2 = new iexe6;
    w2->show();
    this->hide();
}


void MainWindow::on_pushButtonclear_clicked()
{
     ui->textEdit1->clear();
     ui->textEdit2->clear();
     ui->textEdit3->clear();
     ui->textEdit4->clear();
     ui->lineEdit->clear();
}
