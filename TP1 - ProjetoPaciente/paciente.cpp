#include "paciente.h"

namespace srlg{
    const QString &Paciente::getNomeCompleto() const
    {
        return nomeCompleto;
    }

    void Paciente::setNomeCompleto(const QString &newNomeCompleto)
    {
        nomeCompleto = newNomeCompleto;
    }

    int Paciente::getPeso() const
    {
        return peso;
    }

    void Paciente::setPeso(int newPeso)
    {
        if(newPeso <= 0) throw QString("O peso não pode ser <= 0");
        peso = newPeso;
    }

    float Paciente::getAltura() const
    {
        return altura;
    }

    void Paciente::setAltura(float newAltura)
    {
        if(newAltura <= 0) throw QString("A altura não pode ser <=0. Utilize . no lugar de ,");
        altura = newAltura;
    }

    const QString &Paciente::getSexo() const
    {
        return sexo;
    }

    void Paciente::setSexo(const QString &newSexo)
    {
        /*if(newSexo == "M" || newSexo == "F") {sexo = newSexo;}
        else {throw QString("Informe M para masculino e F para feminino");}*///TRATAMENTO DE EXCESSÃO CASO SEJA USADO lineEdit no lugar da comboBox
        sexo = newSexo;
    }

    Paciente::Paciente(QString nomeCompleto, int peso, float altura, QString sexo):
        nomeCompleto(nomeCompleto),
        peso(0),
        altura(0),
        sexo(sexo)
    {
        if (peso <= 0) throw QString("Peso não pode ser menor ou igual a 0");
        if (altura <= 0) throw QString("Altura não pode ser menor ou igual 0. Utilize . no lugar de ,");
        this->peso = peso;
        this->altura = altura;
        this->sexo = sexo;
    }

    Paciente::Paciente():
        nomeCompleto(""), //inicializando cada atributo
        peso(0),
        altura(0),
        sexo("")
    {}

    float Paciente::calcularIMC()const{
        return (peso/(altura*altura));
    }

    float Paciente::calcularPesoIdeal()const{
        if(sexo == "MASCULINO") return 72.7*altura-58;
        if(sexo == "FEMININO") return 62.1*altura-44.7;
    }

    QString Paciente::calcularFaixaDePeso()const{
        if(calcularIMC() < 20) return QString("Abaixo do peso ideal");
        if(calcularIMC() <= 25) return QString("Peso normal");
        if(calcularIMC() <= 30) return QString("Excesso de peso");
        if(calcularIMC() <= 35) return QString("Obesidade");
        return QString("Obesidade morbida");
    }
}
