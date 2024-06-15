#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try{
        tabela = new Tabela(ui->tableWidget_saida_dados, 1000, 3);
        tabela->start();
        Arquivo arquivo(tabela->getVetor());
        arquivo.abrir();
        tabela->atualizar();
        ui->tableWidget_saida_dados->setColumnWidth(0, 7);
        ui->tableWidget_saida_dados->setColumnWidth(1, 370);
        ui->tableWidget_saida_dados->setColumnWidth(2, 370);
        ui->tableWidget_saida_dados->setColumnWidth(3, 370);
        ui->tableWidget_saida_dados->setColumnWidth(4, 370);
        ui->tableWidget_saida_dados->setColumnWidth(5, 370);
        ui->tableWidget_saida_dados->setColumnWidth(6, 370);
        ui->tableWidget_saida_dados->setColumnWidth(7, 370);
    }catch(std::bad_alloc &e){
        QMessageBox::information(this, "ERRO", "Erro ao alocar memoria");
    }
    catch(QString &e){
        QMessageBox::information(this, "ERRO", e);
    }
    catch(...){
        QMessageBox::information(this, "ERRO", "Erro desconhecido");
    }
}

MainWindow::~MainWindow()
{
    if (tabela)
        delete tabela;
    delete ui;
}

void MainWindow::on_pushButton_inserir_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("Matrícula não pode estar vazia");

        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        QString departamento = ui->lineEdit_departamento->text();
        QString titulacao = ui->lineEdit_titulacao->text();
        QString tipoContrato = ui->lineEdit_tipoContrato->text();

        tabela->inserirElemento(matricula, nomeCompleto, departamento, titulacao, tipoContrato);        
        ui->tableWidget_saida_dados->setColumnWidth(0, 7);
        ui->tableWidget_saida_dados->setColumnWidth(1, 370);
        ui->tableWidget_saida_dados->setColumnWidth(2, 370);
        ui->tableWidget_saida_dados->setColumnWidth(3, 370);
        ui->tableWidget_saida_dados->setColumnWidth(4, 370);
        ui->tableWidget_saida_dados->setColumnWidth(5, 370);
        ui->tableWidget_saida_dados->setColumnWidth(6, 370);
        ui->tableWidget_saida_dados->setColumnWidth(7, 370);
        QMessageBox::about(this, "Concluído", "Elemento de matrícula: " + QString::number(matricula) + " alterado");
        // Encontrando a matrícula na tabela
        int numRows = ui->tableWidget_saida_dados->rowCount();
        int numCols = ui->tableWidget_saida_dados->columnCount();
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                QTableWidgetItem *item = ui->tableWidget_saida_dados->item(row, col);
                if (item && col != 0) { // Verifica se a coluna é diferente de 0
                    QStringList parts = item->text().split(';');
                    if (parts.size() > 0 && parts[0].toInt() == matricula) {
                        ui->tableWidget_saida_dados->setCurrentCell(row, col);
                        return;
                    }
                }
            }
        }
        QMessageBox::about(this, "Concluído", "Elemento de matrícula: " + QString::number(matricula) + "\nNome Completo: " + nomeCompleto + " inserido"+ "\nDepartamento: " + departamento + " inserido"+ "\nTitulação: " + titulacao + " inserido" + "\nTipo de Contrato: " + tipoContrato + " inserido");
    }
    catch(QString &e)
    {
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}

void MainWindow::on_pushButton_alterar_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("Número de matrícula não pode estar vazio");

        QString nomeCompleto = ui->lineEdit_nomeCompleto->text();
        QString departamento = ui->lineEdit_departamento->text();
        QString titulacao = ui->lineEdit_titulacao->text();
        QString tipoContrato = ui->lineEdit_tipoContrato->text();

        tabela->alterarElemento(matricula, nomeCompleto, departamento, titulacao, tipoContrato);

        ui->tableWidget_saida_dados->setColumnWidth(0, 7);
        ui->tableWidget_saida_dados->setColumnWidth(1, 370);
        ui->tableWidget_saida_dados->setColumnWidth(2, 370);
        ui->tableWidget_saida_dados->setColumnWidth(3, 370);
        ui->tableWidget_saida_dados->setColumnWidth(4, 370);
        ui->tableWidget_saida_dados->setColumnWidth(5, 370);
        ui->tableWidget_saida_dados->setColumnWidth(6, 370);
        ui->tableWidget_saida_dados->setColumnWidth(7, 370);

        QMessageBox::about(this, "Concluído", "Elemento de matrícula: " + QString::number(matricula) + " alterado");
        // Encontrando a matrícula na tabela
        int numRows = ui->tableWidget_saida_dados->rowCount();
        int numCols = ui->tableWidget_saida_dados->columnCount();
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                QTableWidgetItem *item = ui->tableWidget_saida_dados->item(row, col);
                if (item && col != 0) { // Verifica se a coluna é diferente de 0
                    QStringList parts = item->text().split(';');
                    if (parts.size() > 0 && parts[0].toInt() == matricula) {
                        ui->tableWidget_saida_dados->setCurrentCell(row, col);
                        return;
                    }
                }
            }
        }
    }
    catch(QString &e)
    {
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...)
    {
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}

void MainWindow::on_pushButton_remover_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("n° matricula nao pode estar vazio");
        tabela->removerElemento(matricula);

        ui->tableWidget_saida_dados->setColumnWidth(0, 7);
        ui->tableWidget_saida_dados->setColumnWidth(1, 370);
        ui->tableWidget_saida_dados->setColumnWidth(2, 370);
        ui->tableWidget_saida_dados->setColumnWidth(3, 370);
        ui->tableWidget_saida_dados->setColumnWidth(4, 370);
        ui->tableWidget_saida_dados->setColumnWidth(5, 370);
        ui->tableWidget_saida_dados->setColumnWidth(6, 370);
        ui->tableWidget_saida_dados->setColumnWidth(7, 370);

        QMessageBox::about(this, "Concluido", "Elemento de matricula: " + QString::number(matricula) + " removido");
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
    
}
void MainWindow::on_pushButton_consultar_clicked()
{
    try
    {
        bool ok;
        int matricula = ui->lineEdit_matricula->text().toInt(&ok);
        if (!ok)
            throw QString("Matrícula inválida");

        // Encontrando a matrícula na tabela
        int numRows = ui->tableWidget_saida_dados->rowCount();
        int numCols = ui->tableWidget_saida_dados->columnCount();
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                QTableWidgetItem *item = ui->tableWidget_saida_dados->item(row, col);
                if (item && col != 0) { // Verifica se a coluna é diferente de 0
                    QStringList parts = item->text().split(';');
                    if (parts.size() > 0 && parts[0].toInt() == matricula) {
                        ui->tableWidget_saida_dados->setCurrentCell(row, col);
                        return;
                    }
                }
            }
        }
        // Se não encontrarmos a matrícula, lançamos uma exceção
        throw QString("Matrícula não encontrada");
    }
    catch(QString &e){
        QMessageBox::critical(this, "Erro", e);
    }
    catch(...){
        QMessageBox::critical(this, "Erro", "Erro desconhecido");
    }
}

