#include "contatopersistencia.h"

namespace srlg {

const QString FILE_ARQUIVO = "C:\\Users\\Sávio Reis\\Desktop\\Programação\\TP2\\TP2 ProjetoAgendasContatos SQLITE\\Banco de dados\\Contatos.db";
const QString ERROR_OPEN_DB = "Persistencia - Erro ao abrir o banco de dados - Método ";
const QString ERROR_EXEC_QUERY = "Persistencia - Erro ao executar a consulta SQL - Método ";

ContatoPersistencia::ContatoPersistencia() : nomeDoArquivoNoDisco(FILE_ARQUIVO) {}

void ContatoPersistencia::incluir(const Contato &objContato) const {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nomeDoArquivoNoDisco);

    if (!db.open()) {
        throw QString(ERROR_OPEN_DB + "incluir: ") + db.lastError().text();
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Contatos (cpf, nome, email, ddi, ddd, numero, logradouro, numeroCasa, cep) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);");
    query.bindValue(0, objContato.getCpf());
    query.bindValue(1, objContato.getNome());
    query.bindValue(2, objContato.getEmail());
    query.bindValue(3, objContato.getFone().getDdi());
    query.bindValue(4, objContato.getFone().getDdd());
    query.bindValue(5, objContato.getFone().getNumero());
    query.bindValue(6, objContato.getEndereco().getLogradouro());
    query.bindValue(7, objContato.getEndereco().getNumero());
    query.bindValue(8, objContato.getEndereco().getCep());

    if (!query.exec()) {
        db.close();
        throw QString(ERROR_EXEC_QUERY + "incluir: ") + query.lastError().text();
    }

    db.close();
}

std::list<Contato> *ContatoPersistencia::getListaDeContatos() const {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nomeDoArquivoNoDisco);

    if (!db.open()) {
        throw QString(ERROR_OPEN_DB + "getListaDeContatos: ") + db.lastError().text();
    }

    QSqlQuery query("SELECT cpf, nome, email, ddi, ddd, numero, logradouro, numeroCasa, cep FROM Contatos;");
    std::list<Contato> *listaDeContatos = new std::list<Contato>();

    while (query.next()) {
        QString cpf = query.value(0).toString();
        QString nome = query.value(1).toString();
        QString email = query.value(2).toString();
        int ddi = query.value(3).toInt();
        int ddd = query.value(4).toInt();
        int numero = query.value(5).toInt();
        QString logradouro = query.value(6).toString();
        QString numeroCasa = query.value(7).toString();
        int cep = query.value(8).toInt();
        srlg::Endereco endereco(logradouro, numeroCasa, cep);
        srlg::Telefone fone(ddi, ddd, numero);
        srlg::Contato objContato(cpf, nome, email, fone, endereco);
        listaDeContatos->push_back(objContato);
    }

    db.close();
    return listaDeContatos;
}

Contato *ContatoPersistencia::consultar(QString &cpf) const {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nomeDoArquivoNoDisco);

    if (!db.open()) {
        throw QString(ERROR_OPEN_DB + "consultar: ") + db.lastError().text();
    }

    QSqlQuery query;
    query.prepare("SELECT cpf, nome, email, ddi, ddd, numero, logradouro, numeroCasa, cep "
                  "FROM Contatos WHERE cpf = ?;");
    query.bindValue(0, cpf);

    if (!query.exec()) {
        db.close();
        throw QString(ERROR_EXEC_QUERY + "consultar: ") + query.lastError().text();
    }

    if (!query.next()) {
        db.close();
        return nullptr;
    }

    QString cpfObj = query.value(0).toString();
    QString nome = query.value(1).toString();
    QString email = query.value(2).toString();
    int ddi = query.value(3).toInt();
    int ddd = query.value(4).toInt();
    int numero = query.value(5).toInt();
    QString logradouro = query.value(6).toString();
    QString numeroCasa = query.value(7).toString();
    int cep = query.value(8).toInt();

    srlg::Endereco endereco(logradouro, numeroCasa, cep);
    srlg::Telefone fone(ddi, ddd, numero);
    srlg::Contato *objContato = new Contato(cpfObj, nome, email, fone, endereco);

    db.close();
    return objContato;
}

void ContatoPersistencia::excluir(QString cpf) const {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nomeDoArquivoNoDisco);

    if (!db.open()) {
        throw QString(ERROR_OPEN_DB + "excluir: ") + db.lastError().text();
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Contatos WHERE cpf = ?;");
    query.bindValue(0, cpf);

    if (!query.exec()) {
        db.close();
        throw QString(ERROR_EXEC_QUERY + "excluir: ") + query.lastError().text();
    }

    db.close();
}

void ContatoPersistencia::alterar(const Contato &objContato) const {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nomeDoArquivoNoDisco);

    if (!db.open()) {
        throw QString(ERROR_OPEN_DB + "alterar: ") + db.lastError().text();
    }

    QSqlQuery query;
    query.prepare("UPDATE Contatos SET cpf = ?, nome = ?, email = ?, ddi = ?, ddd = ?, numero = ?, logradouro = ?, numeroCasa = ?, cep = ? WHERE cpf = ?;");
    query.bindValue(0, objContato.getCpf());
    query.bindValue(1, objContato.getNome());
    query.bindValue(2, objContato.getEmail());
    query.bindValue(3, objContato.getFone().getDdi());
    query.bindValue(4, objContato.getFone().getDdd());
    query.bindValue(5, objContato.getFone().getNumero());
    query.bindValue(6, objContato.getEndereco().getLogradouro());
    query.bindValue(7, objContato.getEndereco().getNumero());
    query.bindValue(8, objContato.getEndereco().getCep());
    query.bindValue(9, objContato.getCpf());

    if (!query.exec()) {
        db.close();
        throw QString(ERROR_EXEC_QUERY + "alterar: ") + query.lastError().text();
    }

    db.close();
}

}  // namespace srlg
