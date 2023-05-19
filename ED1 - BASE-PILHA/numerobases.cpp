#include "numerobases.h"
#include <pilha.h>
#include <mainwindow.h>

NumeroBases::NumeroBases():
 base(0),numeroBase(0){

}

QString NumeroBases::CalcularNumeroBase(){
    srlg::Pilha pa{numeroBase};
    QString resultado;
    QString sn = "0123456789ABCDEF";
    int valor;
    QString res,txt;
    while(numeroBase!=0)
      {
          valor =numeroBase%base;
          numeroBase=numeroBase/base;
          resultado+=sn[valor];
          pa.inserir(QString(sn[valor]).toInt());
      }
    for(int i=resultado.size()-1;i>=0;i--)
    {
          res+=resultado[i];
    }
    txt += "O Resultado: " + res + "\n";
    txt += "O Primeiro Topo: " + QString::number(pa.acessar()) + "\n";
    txt += "Retirado Da Pilha: " + QString::number(pa.retirar()) + "\n";
    return txt;
}
void NumeroBases::SetBase(int Base){
     this->base = Base;
}
void NumeroBases::SetNumeroBase(int NumeroBase){
    this->numeroBase = NumeroBase;
}
int  NumeroBases::GetNumeroBase(){
   return this->numeroBase;
}
