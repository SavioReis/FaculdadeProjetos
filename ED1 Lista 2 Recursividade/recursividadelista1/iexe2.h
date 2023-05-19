#ifndef IEXE2_H
#define IEXE2_H
#include <QWidget>
#include "exercicio2.h"
#include "QString"
#include <QMessageBox>
#include <QValidator>

namespace Ui {
class Iexe2;
}

class Iexe2 : public QWidget
{
    Q_OBJECT

public:
    explicit Iexe2(QWidget *parent = nullptr);
    ~Iexe2();

private slots:
    void on_pushButtonrecursivo_clicked();

    void on_pushButtonrepeticao_clicked();

    void on_pushButtonVoltar_clicked();

private:
    Ui::Iexe2 *ui;
};

#endif // IEXE2_H
