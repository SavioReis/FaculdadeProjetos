#include "piloto.h"
namespace srlg{
Piloto::Piloto():
    codigo(0),
    nome(""),
    pais(""),
    idade(0),
    equipe(""),
    motor(""),
    classificacao(),
    pontuacaoFinal(0)
{
}

Piloto::Piloto(int codigo,QString nome, QString pais, int idade, QString equipe,QString motor, int classificacao[7]):
    codigo(codigo),
    nome(nome),
    pais(pais),
    idade(idade),
    equipe(equipe),
    motor(motor),
    classificacao(),
    pontuacaoFinal(0)
{
    for(int i=0;i<7;i++){
        this->classificacao[i] = classificacao[i];
    }
}

int Piloto::getCodigo() const
{
    return codigo;
}

void Piloto::setCodigo(int newCodigo)
{
    codigo = newCodigo;
}

const QString &Piloto::getNome() const
{
    return nome;
}

void Piloto::setNome(const QString &newNome)
{
    nome = newNome;
}

const QString &Piloto::getPais() const
{
    return pais;
}

void Piloto::setPais(const QString &newPais)
{
    pais = newPais;
}

int Piloto::getIdade() const
{
    return idade;
}

void Piloto::setIdade(int newIdade)
{
    idade = newIdade;
}

const QString &Piloto::getEquipe() const
{
    return equipe;
}

void Piloto::setEquipe(const QString &newEquipe)
{
    equipe = newEquipe;
}

const QString &Piloto::getMotor() const
{
    return motor;
}

void Piloto::setMotor(const QString &newMotor)
{
    motor = newMotor;
}

int Piloto::getPontuacaoFinal() const
{
    return pontuacaoFinal;
}

void Piloto::setPontuacaoFinal(int newPontuacaoFinal)
{
    pontuacaoFinal = newPontuacaoFinal;
}

void Piloto::setClassificacao(int array[7]){
    for(int i=0;i<7;i++){
        classificacao[i]=array[i];
    }
}

void Piloto::calcularPontuacaoFinal(){
    pontuacaoFinal=0;
    int pontos[7]={0,40,30,25,20,15,10};

    for(int i=0;i<7;i++){
        pontuacaoFinal+=pontos[classificacao[i]];
    }
}
}
