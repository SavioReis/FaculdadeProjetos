#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <stdexcept>

namespace srlg {
class grafo {
public:
    grafo();
    void adicionarVertice();
    void removerTodosVertices();
    void adicionarAresta(int v1, int v2, int peso);
    void removerAresta(int v1, int v2);
    void alterarPesoAresta(int v1, int v2, int novoPeso);
    int getsize() const;
    const std::vector<std::vector<int>>& getAdjMatrix() const;

private:
    std::vector<std::vector<int>> adjMatrix;
};
}

#endif // GRAFO_H
