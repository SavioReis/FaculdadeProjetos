#ifndef COMBOBOXWINDOW_H
#define COMBOBOXWINDOW_H

#include <QDialog>

namespace Ui {
class ComboBoxWindow;
}

class ComboBoxWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ComboBoxWindow(QWidget *parent = nullptr);
    ~ComboBoxWindow();

private slots:

private:
    Ui::ComboBoxWindow *ui;
};

#endif // COMBOBOXWINDOW_H
