#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "tabhashprofessor.h"
#include <QFile>
#include <QTextStream>
#include "professor.h"

class Arquivo
{
private:
    TabHashProfessor *vetor;

public:
    Arquivo();
    Arquivo(TabHashProfessor *entrada);
    void abrir();
    void carregar_elementos(QTextStream &in);
};

#endif // ARQUIVO_H
