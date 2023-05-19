#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <llse.h>
#include <QInputDialog>
#include <QPixmap>

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
    void on_pushButtonIncluirInicio_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonRetiraInicio_clicked();

    void on_pushButtonIncluirFinal_clicked();

    void on_pushButtonAcessarFinal_clicked();

    void on_pushButtonRetiraFinal_clicked();

    void on_pushButtoninserirposicao_clicked();

    void on_pushButtonAcessarposicao_clicked();

    void on_pushButtonRetirarPosicao_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    srlg::LLSE lista1;
};
#endif // MAINWINDOW_H
