#ifndef LISTA2_H
#define LISTA2_H
#include "QString"

namespace srlg {
    class lista2 {
    public:
        lista2();
        //Exercicio1
        static int calcularSomaCubosRecursivo(int n);
        static int calcularSomaCubosFor(int n);
        //Exercicio2
        static void imprimirNumerosDecrescenteRecursivo(int n, QString& resultado);
        static void imprimirNumerosDecrescenteFor(int n, QString& resultado);
        //Exercicio3
        double findSmallestRecursive(const std::vector<double>& numbers, int index, double currentSmallest);
        int findSmallestIterative(const std::vector<int>& arr);
        //Exercicio4
        std::string decimalParaBinarioRecursivo(int n);
        std::string decimalParaBinarioFor(int n);
        //Exercicio 5
        int calcularSomaCubosRecursivo(int X, int Y);
        int calcularSomaCubosFor(int X, int Y);
        //Exercicio 6
        int multiplicarRecursivo(int n1, int n2);
        int multiplicarFor(int n1, int n2);
    };
}

#endif // LISTA2_H
