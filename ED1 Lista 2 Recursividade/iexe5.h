#ifndef IEXE5_H
#define IEXE5_H

#include <QWidget>
#include "lista2.h"
#include "mainwindow.h"

namespace Ui {
class iexe5;
}

class iexe5 : public QWidget
{
    Q_OBJECT

public:
    explicit iexe5(QWidget *parent = nullptr);
    ~iexe5();

private slots:
    void on_pushButtonvoltar_clicked();

    void on_pushButtonDecimalParaBinarioRecursivo_clicked();

    void on_pushButtonpushButtonDecimalParaBinarioFor_clicked();

private:
    Ui::iexe5 *ui;
};

#endif // IEXE5_H
