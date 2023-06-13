#include "contatopersistencia.h"

namespace srlg {
ContatoPersistencia::ContatoPersistencia() : nomeDoArquivoNoDisco("Contatos.txt") {}

void ContatoPersistencia::criarArquivo() const {
    std::ofstream arquivoContatoBD(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out | std::ios::app);
    if (!arquivoContatoBD.is_open()) {
        throw QString("Persistencia - Arquivo de Contatos nao foi aberto - Metodo incluir");
    }
}

void ContatoPersistencia::incluir(const Contato &objContato) const {
    std::ofstream arquivoContatoBD(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out | std::ios::app);
    if (!arquivoContatoBD.is_open()) {
        throw QString("Persistencia - Arquivo de Contatos nao foi aberto - Metodo incluir");
    }
    arquivoContatoBD << objContato.toString().toStdString() << "\n";
}

std::list<Contato> *ContatoPersistencia::getListaDeContatos() const {
    try {
        std::ifstream arquivoAgenda(nomeDoArquivoNoDisco.toStdString().c_str());
        if (!arquivoAgenda.is_open()) {
            throw QString("Arquivo de Agenda nao foi aberto - getListaDeContatos");
        }

        std::list<srlg::Contato> *listaDeContatos = new std::list<Contato>();
        std::string linha;
        while (getline(arquivoAgenda, linha)) {
            QString str = QString::fromStdString(linha);
            QStringList strList = str.split(";");
            if (strList.size() != 9) {
                continue;
            }
            QString cpf = strList[0];
            QString nome = strList[1];
            QString email = strList[2];
            int ddi = strList[3].toInt();
            int ddd = strList[4].toInt();
            int numero = strList[5].toInt();
            QString logradouro = strList[6];
            QString numeroCasa = strList[7];
            int cep = strList[8].toInt();
            srlg::Endereco endereco(logradouro, numeroCasa, cep);
            srlg::Telefone fone(ddi, ddd, numero);
            srlg::Contato objContato(cpf, nome, email, fone, endereco);
            listaDeContatos->push_back(objContato);
        }

        arquivoAgenda.close();
        return listaDeContatos;
    } catch (QString &erro) {
        throw erro;
    } catch (std::bad_alloc &erro) {
        throw QString("Objeto da classe list nao foi criado");
    }
}

Contato *ContatoPersistencia::consultar(QString &cpf) const {
    try {
        std::ifstream arquivoAgenda(nomeDoArquivoNoDisco.toStdString().c_str());
        if (!arquivoAgenda.is_open()) {
            throw QString("Arquivo de Agenda nao foi aberto");
        }

        std::string linha;
        while (getline(arquivoAgenda, linha)) {
            QString str = QString::fromStdString(linha);
            QStringList strList = str.split(";");
            if (strList.size() != 9) {
                continue;
            }
            QString cpfObj = strList[0];
            QString nome = strList[1];
            QString email = strList[2];
            int ddi = strList[3].toInt();
            int ddd = strList[4].toInt();
            int numero = strList[5].toInt();
            QString logradouro = strList[6];
            QString numeroCasa = strList[7];
            int cep = strList[8].toInt();
            srlg::Endereco endereco(logradouro, numeroCasa, cep);
            srlg::Telefone fone(ddi, ddd, numero);
            srlg::Contato *objContato = new Contato(cpf, nome, email, fone, endereco);
            if (cpf == cpfObj) {
                arquivoAgenda.close();
                return objContato;
            }
            delete objContato;
        }

        arquivoAgenda.close();
        return nullptr;
    } catch (QString &erro) {
        throw erro;
    } catch (std::bad_alloc &erro) {
        throw QString("Objeto da classe list nao foi criado");
    }
}

void ContatoPersistencia::excluir(QString cpf) const {
    try {
        std::list<srlg::Contato> *listaDeContatos = getListaDeContatos();
        std::ofstream arquivoContatoBD(nomeDoArquivoNoDisco.toStdString().c_str());
        if (!arquivoContatoBD.is_open()) {
            throw QString("Persistencia - Arquivo de Contatos nao foi aberto - Metodo incluir");
        }
        for (const auto &contato : *listaDeContatos) {
            if (cpf != contato.getCpf()) {
                arquivoContatoBD << contato.toString().toStdString() << "\n";
            }
        }
        arquivoContatoBD.close();
        delete listaDeContatos;
    } catch (QString &erro) {
        throw QString("Erro ao excluir o contato");
    }
}

void ContatoPersistencia::alterar(const Contato &objContato) const {
    try {
        excluir(objContato.getCpf());
        incluir(objContato);
    } catch (QString &erro) {
        throw QString("Erro ao alterar contato");
    }
}
}
