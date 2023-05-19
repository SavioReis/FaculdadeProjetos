#include "lista2.h"
#include "vector"

namespace srlg {
    lista2::lista2() {}

    int lista2::calcularSomaCubosRecursivo(int n) {
        if (n == 1) {
            return 1;
        }

        return n * n * n + calcularSomaCubosRecursivo(n - 1);
    }

    int lista2::calcularSomaCubosFor(int n) {
        int soma = 0;
        for (int i = 1; i <= n; i++) {
            soma += i * i * i;
        }
        return soma;
    }

    void lista2::imprimirNumerosDecrescenteRecursivo(int n, QString& resultado) {
        if (n == 0) {
            resultado += QString::number(n) + " ";
            return;
        }

        resultado += QString::number(n) + " ";
        imprimirNumerosDecrescenteRecursivo(n - 1, resultado);
    }

    void lista2::imprimirNumerosDecrescenteFor(int n, QString& resultado) {
        for (int i = n; i >= 0; i--) {
            resultado += QString::number(i) + " ";
        }
    }

    double lista2::findSmallestRecursive(const std::vector<double>& numbers, int index, double currentSmallest) {
        if (index == numbers.size()) {
            return currentSmallest;
        }

        if (numbers[index] < currentSmallest) {
            currentSmallest = numbers[index];
        }

        return findSmallestRecursive(numbers, index + 1, currentSmallest);
    }

    // Função iterativa (com loop for) para encontrar o menor elemento em um vetor
    int lista2::findSmallestIterative(const std::vector<int>& arr) {
        if (arr.empty()) {
            // Tratamento para vetor vazio (pode retornar um valor especial ou lançar uma exceção)
            return 0; // Retornando 0 como um valor padrão neste caso
        }

        int smallest = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
        }

        return smallest;
    }

    std::string lista2::decimalParaBinarioRecursivo(int n) {
        if (n == 0) {
            return "0";
        } else if (n == 1) {
            return "1";
        } else {
            return decimalParaBinarioRecursivo(n / 2) + std::to_string(n % 2);
        }
    }

    std::string lista2::decimalParaBinarioFor(int n) {
        std::string binario;

        for (int i = n; i > 0; i /= 2) {
            binario = std::to_string(i % 2) + binario;
        }

        return binario;
    }

    int lista2::calcularSomaCubosRecursivo(int X, int Y) {
        if (Y == 0) {
            return 1;
        }

        if (Y > 0) {
            return X * calcularSomaCubosRecursivo(X, Y - 1);
        } else {
            return 1 / (X * calcularSomaCubosRecursivo(X, -Y - 1));
        }
    }

    int lista2::calcularSomaCubosFor(int X, int Y) {
        int K = 1;
        for (int i = 0; i < Y; i++) {
            K *= X;
        }
        return K;
    }

    int lista2::multiplicarRecursivo(int n1, int n2) {
        if (n2 == 0) {
            return 0;
        } else {
            return n1 + multiplicarRecursivo(n1, n2 - 1);
        }
    }

    int lista2::multiplicarFor(int n1, int n2) {
        int resultado = 0;
        for (int i = 0; i < n2; i++) {
            resultado += n1;
        }
        return resultado;
    }

}
