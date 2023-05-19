#include "manipulararquivo.h"

namespace srlg{
ManipularArquivo::ManipularArquivo(QString nomeDoArquivo):
    nomeDoArquivoNabiblioteca(nomeDoArquivo)
{}

void ManipularArquivo::buscarDadosNaBiblioteca(){
    try {
        std::ifstream arquivo;
        arquivo.open(nomeDoArquivoNabiblioteca.toStdString().c_str());

        if(!arquivo.is_open()) throw QString("Arquivo não pode ser aberto!");

        std::string linha;
        QString texto;

        while(!arquivo.eof()){
            getline(arquivo,linha);
            texto+=QString::fromStdString(linha);
            texto+='\n';

            QString texto=  QString::fromStdString(linha);
            QStringList strList=texto.split(';');
            int codigo=strList[0].toInt();
            QString nome=strList[1];
            QString pais=strList[2];
            int idade=strList[3].toInt();
            QString equipe=strList[4];
            QString motor=strList[5];
            int arrayClassificacao[7];
            arrayClassificacao[0]=strList[6].toInt();
            arrayClassificacao[1]=strList[7].toInt();
            arrayClassificacao[2]=strList[8].toInt();
            arrayClassificacao[3]=strList[9].toInt();
            arrayClassificacao[4]=strList[10].toInt();
            arrayClassificacao[5]=strList[11].toInt();
            arrayClassificacao[6]=strList[12].toInt();

            Piloto p(codigo,nome,pais,idade,equipe,motor,arrayClassificacao);
            p.calcularPontuacaoFinal();
            this->listaDePilotos.push_back(p);
        }
        arquivo.close();
        std::sort(listaDePilotos.begin(),listaDePilotos.end(),[](Piloto x,Piloto y){
            if(x.getPontuacaoFinal()!=y.getPontuacaoFinal()) return x.getPontuacaoFinal()>y.getPontuacaoFinal();
        });


    } catch (QString &erro) {
        throw erro;
    }
}
const std::vector<Piloto> &ManipularArquivo::getlistaDePilotos()const{
    return listaDePilotos;
}
}
