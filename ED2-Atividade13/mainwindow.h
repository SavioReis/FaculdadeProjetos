#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arquivo.h"
#include "tabela.h"
#include <QMessageBox>

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
    void on_pushButton_consultar_clicked();

    void on_pushButton_inserir_clicked();

    void on_pushButton_alterar_clicked();

    void on_pushButton_remover_clicked();

private:
    Ui::MainWindow *ui;
    Tabela *tabela;
};
#endif // MAINWINDOW_H
