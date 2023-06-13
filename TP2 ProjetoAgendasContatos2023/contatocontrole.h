#ifndef CONTATOCONTROLE_H
#define CONTATOCONTROLE_H
#include <ICrudContato.h>
#include <QString>
#include <contato.h>
#include <contatopersistencia.h>
namespace srlg {

class ContatoControle : public IContatoCRUD
{
private:
    srlg::IContatoCRUD *contatoPersistencia;
    void verificarRegrasIncluir(const Contato &objContato) const;
    void verificarCPF(const Contato &objContato) const;
public:
    ContatoControle();
    void incluir (const Contato &objContato) const;
    std::list<Contato> *getListaDeContatos() const;
    Contato *consultar (QString &cpf) const;
    void alterar(const Contato &objContato) const;
    void excluir(QString cpf) const;
    void criarArquivo()const;
};
}
#endif // CONTATOCONTROLE_H
