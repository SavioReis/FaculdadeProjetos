#ifndef GRAPHPAINT_H
#define GRAPHPAINT_H

#include <QWidget>
#include <QMap>
#include <QVector>
#include <QPair>
#include <QPointF>
#include <QMouseEvent>
#include "graph.h"

namespace srlg {

class GraphPaint : public QWidget {
    Q_OBJECT

public:
    GraphPaint(QWidget *parent = nullptr);
    void setGraph(const srlg::graph *graph);
    void updateIncremental(int v1, int v2);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    const srlg::graph *graph;
    void calculateVertexPositions();
    QMap<int, QPointF> vertexPositions;

    // Adicione os métodos de evento aqui
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    // Adicione as variáveis de controle do peso arrastado aqui
    bool isDraggingWeight;
    QPointF originalWeightPosition;
    QPointF currentMousePosition;
    int draggedWeightIndex;
};

} // namespace iom
#endif // GRAPHPAINT_H
