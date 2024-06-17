#include "grafo.h"

namespace srlg {
grafo::grafo() {}

void grafo::adicionarVertice() {
    int newSize = adjMatrix.size() + 1;
    adjMatrix.resize(newSize);
    for (auto& row : adjMatrix) {
        row.resize(newSize, 0);
    }
}

void grafo::removerTodosVertices() {
    adjMatrix.clear();
}

void grafo::adicionarAresta(int v1, int v2, int peso) {
    if (v1 >= static_cast<int>(adjMatrix.size()) || v2 >= static_cast<int>(adjMatrix.size())) {
        throw std::runtime_error("Vértice inexistente.");
    }
    adjMatrix[v1][v2] = peso;
    adjMatrix[v2][v1] = peso;
}

void grafo::removerAresta(int v1, int v2) {
    if (v1 >= static_cast<int>(adjMatrix.size()) || v2 >= static_cast<int>(adjMatrix.size())) {
        throw std::runtime_error("Vértice inexistente.");
    }
    adjMatrix[v1][v2] = 0;
    adjMatrix[v2][v1] = 0;
}

void grafo::alterarPesoAresta(int v1, int v2, int novoPeso) {
    if (v1 >= static_cast<int>(adjMatrix.size()) || v2 >= static_cast<int>(adjMatrix.size())) {
        throw std::runtime_error("Vértice inexistente.");
    }
    adjMatrix[v1][v2] = novoPeso;
    adjMatrix[v2][v1] = novoPeso;
}

int grafo::getsize() const {
    return static_cast<int>(adjMatrix.size());
}

const std::vector<std::vector<int>>& grafo::getAdjMatrix() const {
    return adjMatrix;
}
}
