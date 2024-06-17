#include "graphpaint.h"
#include <QPainter>
#include <cmath>

namespace srlg {
GraphPaint::GraphPaint(QWidget *parent) : QWidget(parent), graph(nullptr) {}

void GraphPaint::setGraph(grafo *g) {
    graph = g;
    update();
}

void GraphPaint::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    if (!graph) return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int numVertices = graph->getsize();
    if (numVertices == 0) return;

    int radius = std::min(width(), height()) / 2 - 20;
    QPoint center(width() / 2, height() / 2);

    std::vector<QPoint> positions(numVertices);

    for (int i = 0; i < numVertices; ++i) {
        double angle = 2 * M_PI * i / numVertices;
        int x = center.x() + radius * std::cos(angle);
        int y = center.y() + radius * std::sin(angle);
        positions[i] = QPoint(x, y);
    }

    painter.setPen(Qt::black);
    const auto& adjMatrix = graph->getAdjMatrix();

    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (adjMatrix[i][j] != 0) {
                painter.drawLine(positions[i], positions[j]);
                QPoint midPoint = (positions[i] + positions[j]) / 2;
                painter.drawText(midPoint, QString::number(adjMatrix[i][j]));
            }
        }
    }

    painter.setBrush(Qt::yellow);
    for (int i = 0; i < numVertices; ++i) {
        painter.drawEllipse(positions[i], 10, 10);
        painter.drawText(positions[i] + QPoint(10, 10), QString::number(i));
    }
}
}
