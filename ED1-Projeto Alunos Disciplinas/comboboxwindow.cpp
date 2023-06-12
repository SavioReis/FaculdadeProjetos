#include "ComboBoxWindow.h"
#include "ui_ComboBoxWindow.h"

ComboBoxWindow::ComboBoxWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComboBoxWindow)
{
    ui->setupUi(this);
}

ComboBoxWindow::~ComboBoxWindow()
{
    delete ui;
}

