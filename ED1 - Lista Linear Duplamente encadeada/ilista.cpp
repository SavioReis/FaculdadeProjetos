#include "ilista.h"
#include "ui_ilista.h"

Ilista::Ilista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ilista)
{
    ui->setupUi(this);

    msgBoxIncluir.setWindowTitle("ERRO");
    msgBoxIncluir.setText("Insira apenas inteiros!");
    msgBoxIncluir.setIcon(QMessageBox::Warning);
    ui->comboBox->setDisabled(true);
    ui->lineEditQE->setEnabled(false);
    ui->textEditSaida->setEnabled(false);
    if (ui->comboBox->findText("Original") == -1) {
        ui->comboBox->addItem("Original");
    }
    if (ui->comboBox->findText("Crescente") == -1) {
        ui->comboBox->addItem("Crescente");
    }
    if (ui->comboBox->findText("Decrescente") == -1) {
        ui->comboBox->addItem("Decrescente");
    }
    if (ui->comboBox->findText("Alternado") == -1) {
        ui->comboBox->addItem("Alternado");
    }
}

Ilista::~Ilista()
{
    delete ui;
}

void Ilista::on_pushButtonInserirInicio_clicked()
{
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
        lista.inserirInicio(valor);
        ui->lineEditValor->clear();
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }

    } catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}


void Ilista::on_pushButtonAcessarInicio_clicked()
{
    try
    {
        if(lista.estaVazia()) throw QString("A lista está vazia!");
        QString saida = QString::number(lista.acessarInicio());
        ui->lineEditValor->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}

void Ilista::on_pushButtonRetirarInicio_clicked()
{

    try
    {
        if(lista.estaVazia()) throw QString("A lista já esta vazia!");
        QString saida = QString::number(lista.retirarInicio());
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void Ilista::on_pushButtonAcessarFim_clicked()
{
    try
    {
        QString saida = QString::number(lista.acessarFim());
        ui->lineEditValor->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}


void Ilista::on_pushButtonInserirFim_clicked()
{
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
        lista.inserirFim(valor);
        ui->lineEditValor->clear();
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }

    } catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA", erro);
    }
}


void Ilista::on_pushButtonRetirarFim_clicked()
{
    try
    {
        QString saida = QString::number(lista.retirarFim());
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void Ilista::on_pushButtonInerirPosicao_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        if(lista.estaVazia()) throw QString("A lista esta vazia!");
        QString saida = QString::number(lista.acessarPosicao(posicao));
        ui->lineEditValor->setText(saida);

    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

}


void Ilista::on_pushButtonPosicaoInicial_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok)
        {
            lista.inserirPosicao(valor, posicao);
            ui->lineEditValor->clear();
            ui->textEditSaida->setText(lista.obterLista());
            ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
        }
        else
        {
            ui->lineEditValor->clear();
        }
        int QE = lista.getquantidadeDeBagulho();
        ui->spinBox->setMaximum(QE);

    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

}


void Ilista::on_pushButtonRetirarPosicao_clicked()
{
    int posicao = ui->spinBox->value();
    try {
        if(lista.estaVazia()) throw QString("A lista já esta vazia!");
        QString saida = QString::number(lista.retirarPosicao(posicao));

        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));

        int QE = lista.getquantidadeDeBagulho();
        ui->spinBox->setMaximum(QE);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}


void Ilista::on_pushButtonOrdenar_clicked()
{
    ui->comboBox->setEnabled(true);
    QString order = ui->comboBox->currentText();
    if (order == "Original") {
        ui->lineEditValor->clear();
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
    }
    else if (order == "Crescente") {
        // faça algo quando a opção "crescente" é selecionada
        lista. inserirOrdenadoCrescente();
        ui->lineEditValor->clear();
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
    } else if (order == "Decrescente") {
        lista. inserirOrdenadoDecrescente();
        ui->lineEditValor->clear();
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
    }
    else if (order == "Alternado") {
        ui->lineEditValor->clear();
        ui->textEditSaida->setText(lista.obterListaOrdenada());
        ui->lineEditQE->setText(QString::number(lista.getquantidadeDeBagulho()));
    }
}
