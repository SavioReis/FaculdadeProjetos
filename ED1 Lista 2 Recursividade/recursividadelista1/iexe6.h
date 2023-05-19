#ifndef IEXE6_H
#define IEXE6_H

#include <QWidget>
#include "exercicio6.h"
#include "QString"

namespace Ui {
class Iexe6;
}

class Iexe6 : public QWidget
{
    Q_OBJECT

public:
    explicit Iexe6(QWidget *parent = nullptr);
    ~Iexe6();

private slots:
    void on_pushButtonrecursivo_clicked();

    void on_pushButtonrepeticao_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::Iexe6 *ui;
};

#endif // IEXE6_H
