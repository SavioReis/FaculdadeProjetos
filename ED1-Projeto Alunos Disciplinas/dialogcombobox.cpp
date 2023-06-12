#include "dialogcombobox.h"
#include "ui_dialogcombobox.h"
#include "QRegularExpression"
#include <alunodao.h>
DialogComboBox::DialogComboBox(QWidget *parent , QString nomeDoArquivo ,QString tipo) :
    QDialog(parent),
    ui(new Ui::DialogComboBox)
{
    ui->setupUi(this);

    ui->labelTexto->setText(tipo);

    AlunoDAO obj;
    qDebug() << "constutor";



    if (tipo == "Listar Disciplina"){
        ui->labelTexto2->setText("Selecione a Disciplina:");
        std::list<std::string> disciplinas = obj.separarDisciplinas(nomeDoArquivo);
        for (const auto& disciplina : disciplinas) {
            ui->comboBox->addItem(QString::fromStdString(disciplina));
            qDebug() << QString::fromStdString(disciplina);
        }
    }else if (tipo == "Listar Turma"){
        ui->labelTexto2->setText("Selecione a Turma:");
        std::list<std::string> turmas = obj.separarTurmas(nomeDoArquivo);
        for (const auto& turma : turmas) {
            ui->comboBox->addItem(QString::fromStdString(turma));
            qDebug() << QString::fromStdString(turma);
        }
    }else {
        ui->labelTexto2->setText("Selecione o curso:");
        std::list<std::string> cursos = obj.separarCursos(nomeDoArquivo);
        for (const auto& curso : cursos) {
            ui->comboBox->addItem(QString::fromStdString(curso));
            qDebug() << QString::fromStdString(curso);
        }

    }

}


DialogComboBox::~DialogComboBox()
{
    delete ui;
}


void DialogComboBox::on_pushButtonOK_clicked()
{
    QString selectedValue = ui->comboBox->currentText();
    emit valueSelected(selectedValue); // Emitir o sinal personalizado com o valor selecionado
    close(); // Fechar a janela DialogComboBox
}

