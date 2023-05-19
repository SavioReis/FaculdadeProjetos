#ifndef IEXE5_H
#define IEXE5_H

#include <QWidget>
#include "exercicio5.h"
#include "QString"

namespace Ui {
class Iexe5;
}

class Iexe5 : public QWidget
{
    Q_OBJECT

public:
    explicit Iexe5(QWidget *parent = nullptr);
    ~Iexe5();

private slots:
    void on_pushButtonrecursivo_clicked();

    void on_pushButtonrepeticao_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::Iexe5 *ui;
};

#endif // IEXE5_H
