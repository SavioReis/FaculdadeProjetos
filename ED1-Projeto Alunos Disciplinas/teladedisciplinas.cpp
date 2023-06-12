#include "teladedisciplinas.h"
#include "ui_teladedisciplinas.h"

TelaDeDisciplinas::TelaDeDisciplinas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaDeDisciplinas)
{
    ui->setupUi(this);
}

TelaDeDisciplinas::~TelaDeDisciplinas()
{
    delete ui;
}
