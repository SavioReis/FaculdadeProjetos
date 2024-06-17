#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <stdexcept>

namespace srlg {

class graph
{
private:
    int numVertices;
    std::vector<std::list<std::pair<int, int>>> adjList;
public:
    graph();
    void alterarPesoAresta(int v1, int v2, int newWeight);
    void removerVertice(int v);
    void adicionarAresta(int v1, int v2, int weight);
    void adicionarVertice();
    int access(int v1, int v2) const;
    int getsize() const;
    const std::vector<std::list<std::pair<int, int>>>& getAdjList() const{
        return adjList;
    }
    void removerTodosVertices();
    void removerAresta(int v1, int v2);
};
}

#endif // GRAPH_H
