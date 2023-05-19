#ifndef IEXE4_H
#define IEXE4_H

#include <QWidget>
#include "exercicio4.h"
#include "QString"
#include <QMessageBox>
#include <QValidator>

namespace Ui {
class Iexe4;
}

class Iexe4 : public QWidget
{
    Q_OBJECT

public:
    explicit Iexe4(QWidget *parent = nullptr);
    ~Iexe4();

private slots:
    void on_pushButtonrecursivo_clicked();

    void on_pushButtonrepeticao_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::Iexe4 *ui;
};

#endif // IEXE4_H
