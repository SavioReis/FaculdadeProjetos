#include "exercicio5.h"

namespace srlg {
    exercicio5::exercicio5() {}

    double exercicio5::calcularPiRecursivo(int termo) {
        if (termo <= 0) {
            return 0.0;
        }

        int denominador = (termo * 2) - 1;
        int sinal = termo % 2 == 0 ? -1 : 1;

        return (4.0 / denominador * sinal) + calcularPiRecursivo(termo - 1);
    }

    double exercicio5::calcularPiFor() {
        double pi = 0.0;
        int termo = 1;

        for (int i = 1; ; i++) {
            int denominador = (i * 2) - 1;
            int sinal = i % 2 == 0 ? -1 : 1;

            double novoTermo = 4.0 / denominador * sinal;

            if (novoTermo >= 0.0001 || novoTermo <= -0.0001) {
                pi += novoTermo;
            } else {
                break;
            }
        }

        return pi;
    }
}
