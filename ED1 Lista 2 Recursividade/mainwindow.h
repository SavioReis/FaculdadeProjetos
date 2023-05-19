#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"
#include "lista2.h"
#include <QDoubleValidator>
#include "iexe5.h"
#include "iexe6.h"

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
    void on_pushButtonCalcularSomaCubosFor_clicked();

    void on_pushButtonNumerosDecrescenteRecursivo_clicked();

    void on_pushButtonNumerosDecrescenteFor_clicked();

    void on_pushButtonDecimalParaBinarioRecursivo_clicked();

    void on_pushButtonDecimalParaBinarioFor_clicked();

    void on_pushButtonFindSmallestRecursive_clicked();

    void on_pushButtonpushButtonFindSmallestIterative_clicked();

    void on_pushButtonmudartelaexe5_clicked();

    void on_pushButtonpushButtonCalcularSomaCubosRecursivo_clicked();

    void on_pushButtonmudartelaexe6_clicked();

    void on_pushButtonclear_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
