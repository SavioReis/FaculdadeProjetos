#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <conjunto.h>
#include <QRegularExpressionValidator>
#include <QMainWindow>
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
    void on_pushButtonGerar_clicked();

    void on_pushButtonApagarQtElementos_clicked();

    void on_pushButtonApagarSelection_clicked();

    void on_pushButtonApagarInsertion_clicked();

    void on_pushButtonApagarDadosGerados_clicked();

    void handleTextChanged(const QString &text);

    void on_pushButtonApagarBubble_clicked();

private:
    Ui::MainWindow *ui;
    srlg::Conjunto *vetor;
};
#endif // MAINWINDOW_H
