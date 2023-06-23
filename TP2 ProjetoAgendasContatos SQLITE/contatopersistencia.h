#ifndef CONTATOPERSISTENCIA_H
#define CONTATOPERSISTENCIA_H
#include <ICrudContato.h>
#include <contato.h>
#include <fstream>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>
#include <QDir>
namespace srlg{
class ContatoPersistencia: public IContatoCRUD
{
private:
    QString nomeDoArquivoNoDisco;
public:
    ContatoPersistencia();
    void incluir (const Contato &objContato) const;
    Contato *consultar(QString &cpf) const;
    std::list<Contato> *getListaDeContatos() const;
    void excluir(QString cpf) const;
    void alterar(const Contato &objContato) const;
};
}
#endif // CONTATOPERSISTENCIA_H
