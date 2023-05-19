#include "exercicio4.h"

namespace srlg {
    exercicio4::exercicio4() {}

    int exercicio4::calcularSomatorioFor(int n) {
        int somatorio = 0;
        for (int i = 1; i <= n; i++) {
            somatorio += i;
        }
        return somatorio;
    }

    int exercicio4::calcularSomatorioRecursivo(int n) {
        if (n == 1) {
            return 1;
        }
        return n + calcularSomatorioRecursivo(n - 1);
    }
}
