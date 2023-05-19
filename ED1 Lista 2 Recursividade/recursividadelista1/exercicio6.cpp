#include "exercicio6.h"
#include <cmath>

namespace srlg {
    exercicio6::exercicio6() {}

    double exercicio6::calcularPiRecursivo(int termo) {
        if (termo == 0) {
            return 0.0;
        }

        double denominador = pow((2 * termo - 1), 3);
        double termoAtual = (termo % 2 == 0) ? (-1.0 / denominador) : (1.0 / denominador);

        return termoAtual + calcularPiRecursivo(termo - 1);
    }

    double exercicio6::calcularPiFor() {
        double pi = 0.0;
        int termos = 51;

        for (int i = 1; i <= termos; i++) {
            double denominador = pow((2 * i - 1), 3);
            double termoAtual = (i % 2 == 0) ? (-1.0 / denominador) : (1.0 / denominador);

            pi += termoAtual;
        }

        pi *= 32;
        pi = cbrt(pi);

        return pi;
    }
}
