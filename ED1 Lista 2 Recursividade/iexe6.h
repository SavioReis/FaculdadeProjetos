#ifndef IEXE6_H
#define IEXE6_H

#include <QWidget>
#include "QString"
#include "lista2.h"
#include "mainwindow.h"

namespace Ui {
class iexe6;
}

class iexe6 : public QWidget
{
    Q_OBJECT

public:
    explicit iexe6(QWidget *parent = nullptr);
    ~iexe6();

private slots:
    void on_pushButtonMultiplicarRecursivo_clicked();

    void on_pushButtonVoltar_clicked();

    void on_pushButtonMultiplicarFor_clicked();

private:
    Ui::iexe6 *ui;
};

#endif // IEXE6_H
