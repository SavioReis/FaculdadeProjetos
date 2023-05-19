#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
//Biblioteca de manipulacao dos diretorios do disco
#include <QFileDialog>
#include <manipulararquivo.h>
#include <piloto.h>

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
    void on_pushButtonBuscar_clicked();

    void on_pushButtonMostrarResultado_clicked();

    void on_pushButtonCriador_clicked();

private:
    Ui::MainWindow *ui;
    QString nomeDoArquivoNabiblioteca;
};
#endif // MAINWINDOW_H
