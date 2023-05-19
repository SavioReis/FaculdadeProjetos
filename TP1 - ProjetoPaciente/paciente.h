#ifndef PACIENTE_H
#define PACIENTE_H

#include <QString>

namespace srlg{
    class Paciente
    {
    private:
        //Atributo
        QString nomeCompleto;
        int peso;
        float altura;
        QString sexo;
    public:
        //Metodos
        Paciente(); // Construtor Padrão
        Paciente(QString nomeCompleto, int peso, float altura, QString sexo);

        float calcularIMC()const;//usar const toda vez que o metodo nao alterar os atributos
        float calcularPesoIdeal()const;
        QString calcularFaixaDePeso()const;

        const QString &getNomeCompleto() const;
        void setNomeCompleto(const QString &newNomeCompleto);
        int getPeso() const;
        void setPeso(int newPeso);
        float getAltura() const;
        void setAltura(float newAltura);
        const QString &getSexo() const;
        void setSexo(const QString &newSexo);
    };
}
#endif // PACIENTE_H
