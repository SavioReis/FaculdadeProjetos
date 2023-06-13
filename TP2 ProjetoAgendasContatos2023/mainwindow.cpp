#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,  ui(new Ui::MainWindow)
    , agendaDeContatosControle(0)
{
    ui->setupUi(this);
    this->showFullScreen();
    agendaDeContatosControle = new srlg::ContatoControle();
    ui->tableWidgetListaDeContatos->setRowCount(0);
    ui->tableWidgetListaDeContatos->setColumnWidth(0,90);
    ui->tableWidgetListaDeContatos->setColumnWidth(1,220);
    ui->tableWidgetListaDeContatos->setColumnWidth(2,220);
    ui->tableWidgetListaDeContatos->setColumnWidth(3,160);
    ui->tableWidgetListaDeContatos->setColumnWidth(4,244);
    connect(ui->tableWidgetListaDeContatos->verticalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::clicarCelula);
    QRegularExpressionValidator *validatorNumeros = new QRegularExpressionValidator(this);
    QRegularExpressionValidator *validatorLetras = new QRegularExpressionValidator(this);
    validatorNumeros->setRegularExpression(QRegularExpression("^\\d+$"));
    validatorLetras->setRegularExpression(QRegularExpression("[^\\p{N}\\p{P}]+"));
    ui->lineEditCPF->setValidator(validatorNumeros);
    ui->lineEditNomeCompleto->setValidator(validatorLetras);
    ui->lineEditDDI->setValidator(validatorNumeros);
    ui->lineEditDDD->setValidator(validatorNumeros);
    ui->lineEditNumero->setValidator(validatorNumeros);
    ui->lineEdit_CEP->setValidator(validatorNumeros);
    try {
        std::list<srlg::Contato> *listaDeContatos = 0;
        listaDeContatos = agendaDeContatosControle->getListaDeContatos();
        mostrarContatosNaGrid(listaDeContatos);
    } catch (...) {
    }
}

MainWindow::~MainWindow()
{
    delete agendaDeContatosControle;
    delete ui;
}
void MainWindow::clicarCelula(int row) {
    if (row >= 0 && row < ui->tableWidgetListaDeContatos->rowCount()) {
        QTableWidgetItem *item = ui->tableWidgetListaDeContatos->item(row, 0);
        QString cpf = item->text();
        std::list<srlg::Contato>::iterator iterator;
        std::list<srlg::Contato> *listaDeContatos = agendaDeContatosControle->getListaDeContatos();
        for(iterator = listaDeContatos->begin(); iterator != listaDeContatos->end(); iterator++){
        if(cpf==iterator->getCpf()){
                ui->lineEditCPF->setText(iterator->getCpf());
                ui->lineEditNomeCompleto->setText(iterator->getNome());
                ui->lineEditEmail->setText(iterator->getEmail());
                ui->lineEditDDD->setText(QString::number(iterator->getFone().getDdd()));
                ui->lineEditDDI->setText(QString::number(iterator->getFone().getDdi()));
                ui->lineEditNumero->setText(QString::number(iterator->getFone().getNumero()));
                ui->lineEditLogradouro->setText(iterator->getEndereco().getLogradouro());
                ui->lineEdit_NumeroCasa->setText(iterator->getEndereco().getNumero());
                ui->lineEdit_CEP->setText(QString::number(iterator->getEndereco().getCep()));
            }
    }
}
}


void MainWindow::limparGrid(){
    ui->lineEditCPF->clear();
    ui->lineEditNomeCompleto->clear();
    ui->lineEditEmail->clear();
    ui->lineEditLogradouro->clear();
    ui->lineEdit_NumeroCasa->clear();
    ui->lineEdit_CEP->clear();
    ui->lineEditDDI->clear();
    ui->lineEditDDD->clear();
    ui->lineEditNumero->clear();
}
void MainWindow::mostrarContatosNaGrid(std::list<srlg::Contato> *listaDeContatos){
    try {
        if(listaDeContatos->empty()) ui->tableWidgetListaDeContatos->clearContents();
        ui->tableWidgetListaDeContatos->setRowCount(0);
        while(!listaDeContatos->empty()){
            srlg::Contato objeto = listaDeContatos->front();
            listaDeContatos->pop_front();
            QTableWidgetItem *itemCPF = new QTableWidgetItem(objeto.getCpf());
            QTableWidgetItem *itemNome = new QTableWidgetItem(objeto.getNome());
            QTableWidgetItem *itemEmail = new QTableWidgetItem(objeto.getEmail());
            QTableWidgetItem *itemTelefone = new QTableWidgetItem(objeto.getFone().obterTelefone());
            QTableWidgetItem *itemEndereco = new QTableWidgetItem(objeto.getEndereco().conseguirEndereco());
            itemCPF->setFlags((itemCPF->flags() & ~Qt::ItemIsEditable));
            itemNome->setFlags((itemCPF->flags() & ~Qt::ItemIsEditable));
            itemEmail->setFlags((itemCPF->flags() & ~Qt::ItemIsEditable));
            itemTelefone->setFlags((itemCPF->flags() & ~Qt::ItemIsEditable));
            itemEndereco->setFlags((itemCPF->flags() & ~Qt::ItemIsEditable));
            int linha = ui->tableWidgetListaDeContatos->rowCount();
            ui->tableWidgetListaDeContatos->insertRow(linha);
            ui->tableWidgetListaDeContatos->setItem(linha,0,itemCPF);
            ui->tableWidgetListaDeContatos->setItem(linha,1,itemNome);
            ui->tableWidgetListaDeContatos->setItem(linha,2,itemEmail);
            ui->tableWidgetListaDeContatos->setItem(linha,3,itemTelefone);
            ui->tableWidgetListaDeContatos->setItem(linha,4,itemEndereco);
        }

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    } catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}

void MainWindow::on_pushButtonIncluir_clicked()
{
    try {
        int DDI = ui->lineEditDDI->text().toInt();
        int DDD = ui->lineEditDDD->text().toInt();
        int numero = ui->lineEditNumero->text().toInt();
        srlg::Telefone fone(DDI,DDD, numero);
        QString cpf=ui->lineEditCPF->text();
        QString nome = ui->lineEditNomeCompleto->text();
        QString email = ui->lineEditEmail->text();
        QString logradouro = ui->lineEditLogradouro->text();
        QString numeroCasa = ui->lineEdit_NumeroCasa->text();
        int cep = ui->lineEdit_CEP->text().toInt();
        srlg::Endereco endereco(logradouro,numeroCasa,cep);
        srlg::Contato objContato(cpf,nome,email,fone,endereco);
        agendaDeContatosControle->incluir(objContato);
        mostrarContatosNaGrid(agendaDeContatosControle->getListaDeContatos());
        limparGrid();
        ui->lineEditCPF->clear();
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}
void MainWindow::on_pushButtonConsultar_clicked()
{
    try {

        if(ui->lineEditCPF->text().isEmpty()) throw QString ("CPF precisa estar preenchido");
        QString cpf = ui->lineEditCPF->text();
        srlg::Contato *objContato = agendaDeContatosControle->consultar(cpf);
        if(objContato==0) throw QString("Este cpf não está listado.");
        ui->lineEditCPF->setText(objContato->getCpf());
        ui->lineEditNomeCompleto->setText(objContato->getNome());
        ui->lineEditEmail->setText(objContato->getEmail());
        ui->lineEditDDD->setText(QString::number(objContato->getFone().getDdd()));
        ui->lineEditDDI->setText(QString::number(objContato->getFone().getDdi()));
        ui->lineEditNumero->setText(QString::number(objContato->getFone().getNumero()));
        ui->lineEditLogradouro->setText(objContato->getEndereco().getLogradouro());
        ui->lineEdit_NumeroCasa->setText(objContato->getEndereco().getNumero());
        ui->lineEdit_CEP->setText(QString::number(objContato->getEndereco().getCep()));
        delete objContato;
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO" , erro);
    }
}
void MainWindow::on_pushButtonLimpar_clicked()
{
    limparGrid();
}
void MainWindow::on_pushButtonExcluir_clicked()
{
    try {
        if(ui->lineEditCPF->text().isEmpty()) throw QString ("CPF precisa estar preenchido");
        QString cpf = ui->lineEditCPF->text();
        agendaDeContatosControle->excluir(cpf);
        mostrarContatosNaGrid(agendaDeContatosControle->getListaDeContatos());
        limparGrid();
        ui->lineEditCPF->clear();
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}


void MainWindow::on_pushButtonAlterar_clicked()
{
    try {
        int DDI = ui->lineEditDDI->text().toInt();
        int DDD = ui->lineEditDDD->text().toInt();
        int numero = ui->lineEditNumero->text().toInt();
        srlg::Telefone fone(DDI,DDD, numero);
        QString cpf=ui->lineEditCPF->text();
        QString nome = ui->lineEditNomeCompleto->text();
        QString email = ui->lineEditEmail->text();
        QString logradouro = ui->lineEditLogradouro->text();
        QString numeroCasa = ui->lineEdit_NumeroCasa->text();
        int cep = ui->lineEdit_CEP->text().toInt();
        srlg::Endereco endereco(logradouro,numeroCasa,cep);
        srlg::Contato objContato(cpf,nome,email,fone,endereco);
        agendaDeContatosControle->alterar(objContato);
        mostrarContatosNaGrid(agendaDeContatosControle->getListaDeContatos());
        limparGrid();
        ui->lineEditCPF->clear();
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_2_clicked()
{
    this->showMinimized();
}

