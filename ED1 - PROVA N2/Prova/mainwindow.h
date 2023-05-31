#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "recursivo.h"
#include "QString"

#include <QMainWindow>

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
    void on_executar1_clicked();

    void on_executar2_clicked();

    void on_limpar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
