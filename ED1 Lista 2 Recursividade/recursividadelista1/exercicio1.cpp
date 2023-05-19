#include "exercicio1.h"

namespace srlg {
    exercicio1::exercicio1() {}

    void exercicio1::imprimirNumerosFor(int n, QString& resultado) {
        for (int i = 1; i <= n; i++) {
            resultado += QString::number(i) + " ";
        }
    }

    void exercicio1::imprimirNumerosRecursivo(int n, QString& resultado) {
        if (n == 1) {
            resultado += QString::number(n) + " ";
            return;
        }
        imprimirNumerosRecursivo(n - 1, resultado);
        resultado += QString::number(n) + " ";
    }
}
