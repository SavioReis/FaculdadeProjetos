#include "exercicio3.h"

namespace srlg {
    exercicio3::exercicio3() {}

    void exercicio3::imprimirNumerosImparesFor(int n, QString& resultado) {
        for (int i = 1; i <= n; i += 2) {
            resultado += QString::number(i) + " ";
        }
    }

    void exercicio3::imprimirNumerosImparesRecursivo(int n, QString& resultado) {
        if (n <= 0) {
            return;
        }
        imprimirNumerosImparesRecursivo(n - 2, resultado);
        resultado += QString::number(n) + " ";
    }
}
