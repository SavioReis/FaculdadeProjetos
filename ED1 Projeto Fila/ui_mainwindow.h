/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelTitulo;
    QPushButton *pushButtonExecutar;
    QLabel *z;
    QTextEdit *textEditVetorOrdenado;
    QLabel *labelVetorOrdenado;
    QComboBox *comboBox;
    QLabel *labelRegra;
    QLabel *labelVetorOriginal;
    QTextEdit *textEditVetorOriginal;
    QLabel *labelQuantidadeElemento;
    QLineEdit *lineEditQuantidadeElementos;
    QPushButton *pushButtonCriar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setGeometry(QRect(150, 10, 401, 31));
        pushButtonExecutar = new QPushButton(centralwidget);
        pushButtonExecutar->setObjectName("pushButtonExecutar");
        pushButtonExecutar->setGeometry(QRect(600, 200, 81, 51));
        z = new QLabel(centralwidget);
        z->setObjectName("z");
        z->setGeometry(QRect(-2, -25, 811, 611));
        z->setPixmap(QPixmap(QString::fromUtf8("Arquivos/fila.jpg")));
        z->setScaledContents(true);
        textEditVetorOrdenado = new QTextEdit(centralwidget);
        textEditVetorOrdenado->setObjectName("textEditVetorOrdenado");
        textEditVetorOrdenado->setGeometry(QRect(220, 260, 409, 70));
        labelVetorOrdenado = new QLabel(centralwidget);
        labelVetorOrdenado->setObjectName("labelVetorOrdenado");
        labelVetorOrdenado->setGeometry(QRect(60, 250, 151, 70));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(130, 220, 93, 24));
        labelRegra = new QLabel(centralwidget);
        labelRegra->setObjectName("labelRegra");
        labelRegra->setGeometry(QRect(70, 220, 61, 26));
        labelVetorOriginal = new QLabel(centralwidget);
        labelVetorOriginal->setObjectName("labelVetorOriginal");
        labelVetorOriginal->setGeometry(QRect(70, 110, 131, 70));
        textEditVetorOriginal = new QTextEdit(centralwidget);
        textEditVetorOriginal->setObjectName("textEditVetorOriginal");
        textEditVetorOriginal->setGeometry(QRect(230, 120, 559, 70));
        labelQuantidadeElemento = new QLabel(centralwidget);
        labelQuantidadeElemento->setObjectName("labelQuantidadeElemento");
        labelQuantidadeElemento->setGeometry(QRect(70, 80, 227, 26));
        lineEditQuantidadeElementos = new QLineEdit(centralwidget);
        lineEditQuantidadeElementos->setObjectName("lineEditQuantidadeElementos");
        lineEditQuantidadeElementos->setGeometry(QRect(320, 80, 261, 24));
        pushButtonCriar = new QPushButton(centralwidget);
        pushButtonCriar->setObjectName("pushButtonCriar");
        pushButtonCriar->setGeometry(QRect(600, 60, 81, 51));
        MainWindow->setCentralWidget(centralwidget);
        z->raise();
        labelTitulo->raise();
        pushButtonExecutar->raise();
        textEditVetorOrdenado->raise();
        labelVetorOrdenado->raise();
        comboBox->raise();
        labelRegra->raise();
        labelVetorOriginal->raise();
        textEditVetorOriginal->raise();
        labelQuantidadeElemento->raise();
        lineEditQuantidadeElementos->raise();
        pushButtonCriar->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelTitulo->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Sistema de Ordena\303\247\303\243o Usando FIla</span></p></body></html>", nullptr));
        pushButtonExecutar->setText(QCoreApplication::translate("MainWindow", "Executar", nullptr));
        z->setText(QString());
        labelVetorOrdenado->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#ffffff;\">Vetor Ordenado</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Crescente", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Decrescente", nullptr));

        labelRegra->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#000000;\">Regra</span></p></body></html>", nullptr));
        labelVetorOriginal->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#000000;\">Vetor Original</span></p></body></html>", nullptr));
        labelQuantidadeElemento->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#000000;\">Quantidade de Elementos</span></p></body></html>", nullptr));
        pushButtonCriar->setText(QCoreApplication::translate("MainWindow", "Criar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
