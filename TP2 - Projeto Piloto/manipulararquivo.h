#ifndef MANIPULARARQUIVO_H
#define MANIPULARARQUIVO_H
#include <QString>
#include <fstream>
#include <QStringList>
#include <piloto.h>
#include <vector>


namespace srlg{
class ManipularArquivo
{
private:
        QString nomeDoArquivoNabiblioteca;
        std::vector<Piloto> listaDePilotos;
public:
    ManipularArquivo(QString nomeDoArquivoNabiblioteca);
    void buscarDadosNaBiblioteca();
    const std::vector<Piloto> &getlistaDePilotos()const;
    bool ordenaPontuacaoFinal(Piloto x, Piloto y)const;
};
}
#endif // MANIPULARARQUIVO_H
