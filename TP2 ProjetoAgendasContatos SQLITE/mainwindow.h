#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <contatocontrole.h>
#include <QMainWindow>
#include <ICrudContato.h>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <contatopersistencia.h>
#include <list>
#include <contato.h>
#include <QRegularExpressionValidator>
#include <QEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    srlg::IContatoCRUD *agendaDeContatosControle;
    QRegularExpressionValidator *validatorNumeros;
    QRegularExpressionValidator *validatorLetras;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mostrarContatosNaGrid(std::list<srlg::Contato> *listaDeContatos);
    void limparGrid();
private slots:
    void on_pushButtonIncluir_clicked();
    void clicarCelula(int row);
    void on_pushButtonConsultar_clicked();
    void on_pushButtonLimpar_clicked();
    void on_pushButtonExcluir_clicked();
    void on_pushButtonAlterar_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
