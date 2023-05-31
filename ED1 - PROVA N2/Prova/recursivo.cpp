#include "recursivo.h"

namespace srlg {

recursivo::recursivo()
{

}
    int recursivo::divisorcomum(int x, int y) {
        if (y == 0)
            return x;
        return divisorcomum(y, x % y);
    }

    int recursivo::countDigit(int n, int k) {
        // Caso base: quando o número é 0, não há mais dígitos para verificar
        if (n == 0) {
            return 0;
        }

        // Verifica o último dígito do número
        int lastDigit = n % 10;

        // Caso o último dígito seja igual a k, incrementa o contador em 1
        if (lastDigit == k) {
            return 1 + countDigit(n / 10, k);
        } else {
            return countDigit(n / 10, k);
        }
    }
}

/*escreva um método recursivo que determina quantas vezes um digito k ocorre em um número natural n . por exemplo
o digito 2 ocorre 3 vezes em :796


fazer um metodo recursivo para calcular o e imprimir o maximo divisor comum (mdc) entre 2 números . por exemplo mdc(5 e 7)= 1 , (4,16)=4
*/
