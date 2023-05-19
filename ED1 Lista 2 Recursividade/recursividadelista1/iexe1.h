#ifndef IEXE1_H
#define IEXE1_H
#include "exercicio1.h"
#include "QString"

#include <QWidget>
#include <QMessageBox>
#include <QValidator>

namespace Ui {
class Iexe1;
}

class Iexe1 : public QWidget
{
    Q_OBJECT

public:
    explicit Iexe1(QWidget *parent = nullptr);
    ~Iexe1();

private slots:
    void on_pushButtonrecursivo_clicked();

    void on_pushButtonrepeticao_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::Iexe1 *ui;
};

#endif // IEXE1_H
