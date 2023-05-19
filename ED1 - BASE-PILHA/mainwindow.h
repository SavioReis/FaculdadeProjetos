#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pilha.h>
#include <QMessageBox>
#include <numerobases.h>

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

    void on_pushButtonCalcular_clicked();

private:
    Ui::MainWindow *ui;
    NumeroBases nBase;
};
#endif // MAINWINDOW_H
