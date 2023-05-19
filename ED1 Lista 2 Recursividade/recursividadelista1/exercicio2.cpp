#include "exercicio2.h"

namespace srlg {
    exercicio2::exercicio2() {}

    void exercicio2::imprimirNumerosParesFor(int n, QString& resultado) {
        for (int i = 2; i <= n; i += 2) {
            resultado += QString::number(i) + " ";
        }
    }

    void exercicio2::imprimirNumerosParesRecursivo(int n, QString& resultado) {
        if (n <= 0) {
            return;
        }
        imprimirNumerosParesRecursivo(n - 2, resultado);
        resultado += QString::number(n) + " ";
    }
}
