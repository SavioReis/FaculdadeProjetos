#ifndef ILISTA_H
#define ILISTA_H

#include <QWidget>
#include <no.h>
#include <llde.h>

namespace Ui {
class Ilista;
}

class Ilista : public QWidget
{
    Q_OBJECT

public:
    explicit Ilista(QWidget *parent = nullptr);
    ~Ilista();

private slots:
    void on_pushButtonInserirInicio_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonAcessarFim_clicked();

    void on_pushButtonInserirFim_clicked();

    void on_pushButtonRetirarFim_clicked();

    void on_pushButtonInerirPosicao_clicked();

    void on_pushButtonPosicaoInicial_clicked();

    void on_pushButtonRetirarPosicao_clicked();

    void on_pushButtonOrdenar_clicked();

private:
    Ui::Ilista *ui;
    srlg::LLDE lista;
    QMessageBox msgBoxIncluir;
};

#endif // ILISTA_H
