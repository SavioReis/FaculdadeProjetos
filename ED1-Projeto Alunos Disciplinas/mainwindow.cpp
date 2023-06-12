#include "mainwindow.h"
#include "alunodao.h"
#include "aluno.h"
#include "dialogcombobox.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <disciplinaturma.h>
#include<fstream>

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

void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        std::fstream arquivo;

        // Buscando o arquivo no disco
        QString nomeDoArquivo = QFileDialog::getOpenFileName(this, "Abrir Arquivo", QDir::currentPath(), "Arquivos Textos (*.csv *.txt)");
        if (nomeDoArquivo.isEmpty()) {
            throw QString("Arquivo não foi selecionado");
        }

        // Abrindo um arquivo de entrada
        arquivo.open(nomeDoArquivo.toStdString().c_str());

        // Verificando erro de abertura do arquivo de entrada
        if (!arquivo.is_open()) {
            throw QString("ERRO: Arquivo não pode ser aberto");
        }

        ui->lineEditArquivo->setText(nomeDoArquivo);

        ui->lineEditArquivo->setEnabled(false);
    } catch (...) {
        QMessageBox::about(this,"Erro","não foi possivel concluir sua tarefa");
    }

}

void MainWindow::onValueSelected(const QString& value)
{
    try {
        QString comboBOX = ui->comboBox->currentText(); // pegar texto da combobox

        if (comboBOX == "Listar Turma"){
            AlunoDAO AlunoPRO;

            QStringList partes = value.split("-");
            // Verificar se a string foi dividida corretamente em duas partes
            QString nomeDoArquivo = ui->lineEditArquivo->text();
            QString disciplina = ""; // CMP1044
            QString turma = ""; // C02
            if (partes.size() == 2) {
                disciplina = partes.at(0); // CMP1044
                turma = partes.at(1); // C02

            } else {
                qDebug() << "Formato inválido da string.";
            }

            std::list<Aluno> listaDeAlunos = AlunoPRO.listagemPorDisciplinaTurma(nomeDoArquivo,disciplina,turma);

            qDebug() << "Número de alunos lidos: " << listaDeAlunos.size();

            // Limpar a grid
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);

            // Definir as colunas da tabela (apenas matrícula e nome)
            ui->tableWidget->setColumnCount(2);
            QStringList headers;
            headers << "Matrícula" << "Nome";
            ui->tableWidget->setHorizontalHeaderLabels(headers);

            for (const auto& aluno : listaDeAlunos) {
                QTableWidgetItem* itemMatricula = new QTableWidgetItem(aluno.getMatricula());
                QTableWidgetItem* itemNome = new QTableWidgetItem(aluno.getAluno());

                int linha = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(linha);
                ui->tableWidget->setItem(linha, 0, itemMatricula);
                ui->tableWidget->setItem(linha, 1, itemNome);
            }

            // Ajustar ao conteúdo
           // ui->tableWidget->resizeColumnsToContents();
        }else if (comboBOX == "Listar Disciplina"){
            AlunoDAO AlunoPRO;

            QString nomeDoArquivo = ui->lineEditArquivo->text();
            QString disciplina = value; // CMP1044

            std::list<Aluno> listaDeAlunos = AlunoPRO.listagemPorDisciplina(nomeDoArquivo,disciplina);
            qDebug() << "Número de alunos lidos: " << listaDeAlunos.size();

            // Limpar a grid
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);

            // Definir as colunas da tabela (apenas matrícula e nome)
            ui->tableWidget->setColumnCount(2);
            QStringList headers;
            headers << "Matrícula" << "Nome";
            ui->tableWidget->setHorizontalHeaderLabels(headers);

            for (const auto& aluno : listaDeAlunos) {
                QTableWidgetItem* itemMatricula = new QTableWidgetItem(aluno.getMatricula());
                QTableWidgetItem* itemNome = new QTableWidgetItem(aluno.getAluno());

                int linha = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(linha);
                ui->tableWidget->setItem(linha, 0, itemMatricula);
                ui->tableWidget->setItem(linha, 1, itemNome);
            }

            // Ajustar ao conteúdo
            //ui->tableWidget->resizeColumnsToContents();

        }else if (comboBOX == "Listar Curso"){
            AlunoDAO AlunoPRO;

            QStringList partes = value.split("-");
            // Verificar se a string foi dividida corretamente em duas partes
            QString nomeDoArquivo = ui->lineEditArquivo->text();
            QString disciplina = ""; // CMP1044
            QString turma = ""; // C02
            QString curso = value;
            if (partes.size() == 2) {
                disciplina = partes.at(0); // CMP1044
                turma = partes.at(1); // C02

            } else {
                qDebug() << "Formato inválido da string.";
            }

            std::list<Aluno> listaDeAlunos = AlunoPRO.listagemPorCurso(nomeDoArquivo,curso);
            qDebug() << "Número de alunos lidos: " << listaDeAlunos.size();

            // Limpar a grid
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);

            // Definir as colunas da tabela (apenas matrícula e nome)
            ui->tableWidget->setColumnCount(2);
            QStringList headers;
            headers << "Matrícula" << "Nome";
            ui->tableWidget->setHorizontalHeaderLabels(headers);

            for (const auto& aluno : listaDeAlunos) {
                QTableWidgetItem* itemMatricula = new QTableWidgetItem(aluno.getMatricula());
                QTableWidgetItem* itemNome = new QTableWidgetItem(aluno.getAluno());

                int linha = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(linha);
                ui->tableWidget->setItem(linha, 0, itemMatricula);
                ui->tableWidget->setItem(linha, 1, itemNome);
            }

            // Ajustar ao conteúdo
           // ui->tableWidget->resizeColumnsToContents();

        }else {
            QString nomeDoArquivo = ui->lineEditArquivo->text();
            AlunoDAO alunoPRO;
            std::list<Aluno> listaDeAlunos = alunoPRO.listagemPorAluno(nomeDoArquivo,value);
            qDebug() << "Número de alunos lidos: " << listaDeAlunos.size();
            // Limpar a tabela antes de adicionar os novos dados
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);

            // Configurar as colunas na tabela
            ui->tableWidget->setColumnCount(4);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Matrícula" << "Nome" << "Disciplina" << "Turma");

            // Percorrer a lista de alunos e adicionar os dados na tabela
            int row = 0;
            for (const auto& aluno : listaDeAlunos) {
                // Adicionar uma nova linha na tabela
                ui->tableWidget->insertRow(row);

                // Adicionar a matrícula
                QTableWidgetItem* itemMatricula = new QTableWidgetItem(aluno.getMatricula());
                ui->tableWidget->setItem(row, 0, itemMatricula);

                // Adicionar o nome
                QTableWidgetItem* itemNome = new QTableWidgetItem(aluno.getAluno());
                ui->tableWidget->setItem(row, 1, itemNome);

                // Adicionar as disciplinas e turmas
                QString disciplinas;
                QString turmas;

                for (const auto& disciplina : aluno.getDisciplinas()) {
                    disciplinas += disciplina.getCodDisciplina() + "\n";
                    turmas += disciplina.getTurma() + "\n";
                }

                QTableWidgetItem* itemDisciplinas = new QTableWidgetItem(disciplinas.trimmed());
                QTableWidgetItem* itemTurmas = new QTableWidgetItem(turmas.trimmed());

                ui->tableWidget->setItem(row, 2, itemDisciplinas);
                ui->tableWidget->setItem(row, 3, itemTurmas);

                row++;
            }

        }

    } catch (...) {
        QMessageBox::about(this,"Erro","não foi possivel concluir sua tarefa");
    }

}


void MainWindow::on_pushButton_clicked()
{
    QString arquivo = ui->lineEditArquivo->text();
    QString tipo = ui->comboBox->currentText();

    DialogComboBox dialog(this,arquivo,tipo);
    connect(&dialog, &DialogComboBox::valueSelected, this, &MainWindow::onValueSelected);

    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::about(this,"ola ","deu certo");
    }

}

