#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <conjunto.h>

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
    void on_pushButton_clicked();

    void on_pushButtonApagar_clicked();

    void habilitarBotao(const QString &texto);
    void on_pushButton_2_clicked();

    void on_pushButtonBuscar_clicked();

    void on_pushButtonApagarSequencial_clicked();

    void on_pushButtonApagarOrdenado_clicked();

    void on_pushButtonBuscarBinario_clicked();

    void on_pushButtonApagarBinaria_clicked();

    void handlelineEditElementosTextChanged(const QString &text);

    void handleLineEditValorBinariaTextChanged(const QString &text);

    void handlelineEditValorTextChanged(const QString &text);
private:
    Ui::MainWindow *ui;
    srlg::Conjunto *vetor;
};
#endif // MAINWINDOW_H
