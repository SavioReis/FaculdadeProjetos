#ifndef IEXE3_H
#define IEXE3_H

#include <QWidget>
#include "exercicio3.h"
#include "QString"
#include <QMessageBox>
#include <QValidator>

namespace Ui {
class Iexe3;
}

class Iexe3 : public QWidget
{
    Q_OBJECT

public:
    explicit Iexe3(QWidget *parent = nullptr);
    ~Iexe3();

private slots:
    void on_pushButtonrecursivo_clicked();

    void on_pushButtonrepeticao_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::Iexe3 *ui;
};

#endif // IEXE3_H
