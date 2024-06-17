#include "graph.h"
#include <stdexcept> // Para std::runtime_error
#include <QString>

namespace srlg {

graph::graph() : numVertices(0) {}

void graph::removerVertice(int v) {
    if (v < 0 || v >= numVertices) {
        return;
    }
    adjList.erase(adjList.begin() + v);
    numVertices--;
    for (auto& neighbors : adjList) {
        for (auto it = neighbors.begin(); it != neighbors.end(); ) {
            if (it->first == v) {
                it = neighbors.erase(it);
            } else {
                if (it->first > v) {
                    it->first--;
                }
                ++it;
            }
        }
    }
}

void graph::adicionarAresta(int v1, int v2, int weight) {
    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
        int exists1 = -1;
        for (const auto& neighbor : adjList[v1]) {
            if (neighbor.first == v2) {
                exists1++;
            }
        }
        if (exists1 > 0) {
            throw std::runtime_error("Nessa ligação já tem um peso associado, para alterar o peso vá em Alterar.");
        }
        adjList[v1].push_back(std::make_pair(v2, weight));
        if (v1 != v2) {
            adjList[v2].push_back(std::make_pair(v1, weight));
        }
    } else {
        throw std::runtime_error("Vértices inválidos!");
    }
}

void graph::adicionarVertice() {
    adjList.push_back(std::list<std::pair<int, int>>());
    numVertices++;
}

int graph::access(int v1, int v2) const {
    if (v1 >= 0 && v1 < numVertices) {
        for (const auto& neighbor : adjList[v1]) {
            if (neighbor.first == v2) {
                return neighbor.second;
            }
        }
    }
    return -1;
}

void graph::alterarPesoAresta(int v1, int v2, int newWeight) {
    bool encontrou = false;
    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
        for (auto &neighbor : adjList[v1]) {
            if (neighbor.first == v2) {
                neighbor.second = newWeight;
                encontrou = true;
            }
        }
        if (!encontrou) {
            throw std::runtime_error("Não há ligações aqui");
        }
        if (v1 != v2) {
            for (auto& neighbor : adjList[v2]) {
                if (neighbor.first == v1) {
                    neighbor.second = newWeight;
                }
            }
        }
    } else {
        throw std::runtime_error("Vértices inválidos!");
    }
}

int graph::getsize() const {
    return numVertices;
}

void graph::removerTodosVertices()
{
    numVertices = 0;
    adjList.clear();
}

void graph::removerAresta(int v1, int v2) {
    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
        bool encontrou = false;
        auto& adjV1 = adjList[v1];
        for (auto it = adjV1.begin(); it != adjV1.end(); ++it) {
            if (it->first == v2) {
                adjV1.erase(it);
                encontrou = true;
            }
        }
        if (v1 != v2) {
            auto& adjV2 = adjList[v2];
            for (auto it = adjV2.begin(); it != adjV2.end(); ++it) {
                if (it->first == v1) {
                    adjV2.erase(it);
                    encontrou = true;
                }
            }
        }
        if (!encontrou) {
            throw std::runtime_error("Neste momento não há ligação entre os vértices");
        }
    } else {
        throw std::runtime_error("Vértices inválidos!");
    }
}

}
