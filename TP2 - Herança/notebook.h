#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "produto.h"

class Notebook: public Produto
{
protected:
    QString marca;
     QString modelo;
     QString memória_RAM;
      QString capacidade_HD;
     QString processado;
     QString tamanho_tela ;
     QString SO;
public:
     Notebook();
     const QString &getMarca() const;
     void setMarca(const QString &newMarca);
     const QString &getModelo() const;
     void setModelo(const QString &newModelo);
     const QString &getMemória_RAM() const;
     void setMemória_RAM(const QString &newMemória_RAM);
     const QString &getCapacidade_HD() const;
     void setCapacidade_HD(const QString &newCapacidade_HD);
     const QString &getProcessado() const;
     void setProcessado(const QString &newProcessado);
     const QString &getTamanho_tela() const;
     void setTamanho_tela(const QString &newTamanho_tela);
     const QString &getSO() const;
     void setSO(const QString &newSO);
};

#endif // NOTEBOOK_H
