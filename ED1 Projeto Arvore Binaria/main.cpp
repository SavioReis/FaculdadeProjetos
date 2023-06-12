#include <iostream>
#include "ArvoreBinaria.h"

int main() {
    try {
        ED1::ArvoreBinaria teste;
        std::cout << "Incluindo dados na árvore criada" << std::endl;
        std::cout << "Incluindo valor 50" << std::endl;
        teste.inserir(50);
        std::cout << "Incluindo valor 40" << std::endl;
        teste.inserir(40);
        std::cout << "Incluindo valor 60" << std::endl;
        teste.inserir(60);
        std::cout << "Incluindo valor 35" << std::endl;
        teste.inserir(35);
        std::cout << "Incluindo valor 45" << std::endl;
        teste.inserir(45);
        std::cout << "Incluindo valor 70" << std::endl;
        teste.inserir(70);
        std::cout << "Incluindo valor 56" << std::endl;
        teste.inserir(56);

        std::cout << std::endl << "Mostrando os dados da árvore criada" << std::endl;
        teste.imprimir();

        std::cout << "\nRemovendo o valor 60 da árvore" << std::endl;
        teste.remover(60);
        std::cout << std::endl << "Mostrando os dados da árvore após remover o valor" << std::endl;
        teste.imprimir();

        std::cout << std::endl;
        std::cout << std::endl << "Mostrando a árvore sendo destruída" << std::endl;
        teste.imprimir();
        std::cout << std::endl;
        std::cout << std::endl << "Mostrando a árvore sendo destruída" << std::endl;
    }
    catch (std::string& erro) {
        std::cout << std::endl << "Erro: " << erro << std::endl;
    }

    return 0;
}



