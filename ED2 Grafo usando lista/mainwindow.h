#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "graphpaint.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Criar_clicked();
    void on_pushButton_Add_clicked();
    void on_pushButton_Alterar_clicked();
    void on_pushButton_Remover_clicked();
    void updateComboBoxes();
    void drawGraph();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    srlg::graph *graph;
    srlg::GraphPaint *graphPaint;
};

#endif // MAINWINDOW_H
