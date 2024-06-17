#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QMessageBox>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
    , graph(new srlg::graph)
    , graphPaint(new srlg::GraphPaint(this))
{
    ui->setupUi(this);
    // Adicionar o GraphPaint widget ao widgetGrafo
    QVBoxLayout *layout = new QVBoxLayout(ui->widgetGrafo);
    layout->addWidget(graphPaint);

    connect(ui->pushButton_Criar, &QPushButton::clicked, this, &MainWindow::on_pushButton_Criar_clicked);
    connect(ui->pushButton_Add, &QPushButton::clicked, this, &MainWindow::on_pushButton_Add_clicked);
    connect(ui->pushButton_Alterar, &QPushButton::clicked, this, &MainWindow::on_pushButton_Alterar_clicked);
    connect(ui->pushButton_Remover, &QPushButton::clicked, this, &MainWindow::on_pushButton_Remover_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete graph;
    delete graphPaint;
}

void MainWindow::on_pushButton_Criar_clicked()
{
    graph->removerTodosVertices();
    int numVertices = ui->lineEditNumVertices->text().toInt();
    for (int i = 0; i < numVertices; ++i) {
        graph->adicionarVertice();
    }
    updateComboBoxes();
    drawGraph();
    ui->comboBox_AddVertice1->setEnabled(true);
    ui->comboBox_AddVertice2->setEnabled(true);
    ui->lineEdit_AddPeso->setEnabled(true);
    ui->pushButton_Add->setEnabled(true);
    ui->comboBox_AlterarVertice1->setEnabled(true);
    ui->comboBox_AlterarVertice2->setEnabled(true);
    ui->lineEdit_AlterarPeso->setEnabled(true);
    ui->pushButton_Alterar->setEnabled(true);
    ui->comboBox_RemoverVertice1->setEnabled(true);
    ui->pushButton_Remover->setEnabled(true);
    ui->comboBox_RemoverVertice2->setEnabled(true);

}

void MainWindow::on_pushButton_Add_clicked()
{
    int v1 = ui->comboBox_AddVertice1->currentText().toInt();
    int v2 = ui->comboBox_AddVertice2->currentText().toInt();
    int weight = ui->lineEdit_AddPeso->text().toInt();

    try {
        graph->adicionarAresta(v1, v2, weight);
        drawGraph(); // Redesenha o grafo após adicionar a aresta
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Erro", e.what());
    }
}

void MainWindow::on_pushButton_Alterar_clicked()
{
    int v1 = ui->comboBox_AlterarVertice1->currentText().toInt();
    int v2 = ui->comboBox_AlterarVertice2->currentText().toInt();
    int weight = ui->lineEdit_AlterarPeso->text().toInt();

    try {
        graph->alterarPesoAresta(v1, v2, weight);
        drawGraph(); // Redesenha o grafo após alterar o peso
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Erro", e.what());
    }
}

void MainWindow::on_pushButton_Remover_clicked()
{
    int v1 = ui->comboBox_RemoverVertice1->currentText().toInt();
    int v2 = ui->comboBox_RemoverVertice2->currentText().toInt();
    try {
        graph->removerAresta(v1, v2);
        drawGraph(); // Redesenhar o grafo
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Erro", e.what());
    }
}

void MainWindow::updateComboBoxes() {
    int size = graph->getsize();
    ui->comboBox_AddVertice1->clear();
    ui->comboBox_AddVertice2->clear();
    ui->comboBox_AlterarVertice1->clear();
    ui->comboBox_AlterarVertice2->clear();
    ui->comboBox_RemoverVertice1->clear();
    ui->comboBox_RemoverVertice2->clear();
    // Adiciona todos os vértices às comboBoxes
    for (int i = 0; i < size; ++i) {
        ui->comboBox_AddVertice1->addItem(QString::number(i));
        ui->comboBox_AddVertice2->addItem(QString::number(i));
        ui->comboBox_AlterarVertice1->addItem(QString::number(i));
        ui->comboBox_AlterarVertice2->addItem(QString::number(i));
        ui->comboBox_RemoverVertice1->addItem(QString::number(i));
        ui->comboBox_RemoverVertice2->addItem(QString::number(i));
    }
    // Adiciona apenas os vértices que têm ligações como opções selecionáveis
    for (int i = 0; i < size; ++i) {
        for (const auto& neighbor : graph->getAdjList()[i]) {
            int neighborVertex = neighbor.first;
            ui->comboBox_AddVertice1->addItem(QString::number(i));
            ui->comboBox_AlterarVertice1->addItem(QString::number(i));
            ui->comboBox_RemoverVertice1->addItem(QString::number(i));
            ui->comboBox_AddVertice2->addItem(QString::number(neighborVertex));
            ui->comboBox_AlterarVertice2->addItem(QString::number(neighborVertex));
            ui->comboBox_RemoverVertice2->addItem(QString::number(neighborVertex));
        }
    }
    // Remove duplicatas e ordena os itens nas comboBoxes
    QStringList comboBoxItems;
    for (int i = 0; i < ui->comboBox_AddVertice1->count(); ++i) {
        comboBoxItems << ui->comboBox_AddVertice1->itemText(i);
    }
    ui->comboBox_AddVertice1->clear();
    ui->comboBox_AddVertice1->addItems(comboBoxItems);
    ui->comboBox_AddVertice2->clear();
    ui->comboBox_AddVertice2->addItems(comboBoxItems);
    ui->comboBox_AlterarVertice1->clear();
    ui->comboBox_AlterarVertice1->addItems(comboBoxItems);
    ui->comboBox_AlterarVertice2->clear();
    ui->comboBox_AlterarVertice2->addItems(comboBoxItems);
    ui->comboBox_RemoverVertice1->clear();
    ui->comboBox_RemoverVertice1->addItems(comboBoxItems);
    ui->comboBox_RemoverVertice2->clear();
    ui->comboBox_RemoverVertice2->addItems(comboBoxItems);
}

void MainWindow::drawGraph() {
    graphPaint->setGraph(graph);
    graphPaint->update();
}
