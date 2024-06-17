#include "graphpaint.h"
#include <QPainter>
#include <cmath>
#include <QMouseEvent>

namespace srlg {

GraphPaint::GraphPaint(QWidget *parent) : QWidget(parent), graph(nullptr), isDraggingWeight(false)  {}

void GraphPaint::setGraph(const srlg::graph *graph) {
    this->graph = graph;
    calculateVertexPositions();
    update();
}

void GraphPaint::calculateVertexPositions() {
    vertexPositions.clear();
    if (!graph) return;
    int numVertices = graph->getsize();
    int radius = std::min(width(), height()) / 2 - 20;
    QPointF center(width() / 2, height() / 2);
    for (int i = 0; i < numVertices; ++i) {
        double angle = (2 * M_PI / numVertices) * i;
        int x = center.x() + radius * cos(angle);
        int y = center.y() + radius * sin(angle);
        vertexPositions[i] = QPointF(x, y);
    }
}

void GraphPaint::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    if (!graph) return;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QBrush vertexBrush(Qt::black);
    QPen vertexPen(Qt::white);
    vertexPen.setWidth(3);

    for (int v1 = 0; v1 < graph->getsize(); ++v1) {
        for (const auto &neighbor : graph->getAdjList()[v1]) {
            int v2 = neighbor.first;
            int weight = neighbor.second;
            if (vertexPositions.contains(v1) && vertexPositions.contains(v2)) {
                if (v1 == v2) {
                    // Ajuste do arco para auto-ligações
                    QRectF loopRect(vertexPositions[v1].x() + 10, vertexPositions[v1].y() - 25, 40, 40);
                    QPen loopPen(Qt::white);
                    loopPen.setWidth(3);  // Mesma espessura das linhas entre vértices distintos
                    painter.setPen(loopPen);
                    painter.drawArc(loopRect, 0, 16 * 360);
                    painter.setBrush(Qt::black); // Desenhar o quadrado atrás do peso
                    QRectF weightRect(vertexPositions[v1].x() + 20, vertexPositions[v1].y() - 35, 16, 16);
                    painter.drawRect(weightRect);
                    painter.setPen(Qt::white);
                    QFont font = painter.font();
                    font.setPointSize(8);
                    painter.setFont(font);
                    painter.drawText(weightRect, Qt::AlignCenter, QString::number(weight));
                } else {
                    painter.drawLine(vertexPositions[v1], vertexPositions[v2]);
                    QPointF midPoint = (vertexPositions[v1] + vertexPositions[v2]) / 2;
                    painter.setBrush(Qt::black);
                    painter.drawRect(midPoint.x() - 8, midPoint.y() - 8, 16, 16);
                    painter.setPen(Qt::white);
                    QFont font = painter.font();
                    font.setPointSize(8);
                    painter.setFont(font);
                    painter.drawText(midPoint.x() - 5, midPoint.y() + 5, QString::number(weight));
                }
            }
        }
    }

    for (int v = 0; v < graph->getsize(); ++v) {
        if (vertexPositions.contains(v)) {
            painter.setBrush(vertexBrush);
            painter.setPen(vertexPen);
            painter.drawEllipse(vertexPositions[v], 10, 10);
            QString vertexText = QString::number(v);
            QFontMetrics fontMetrics = painter.fontMetrics();
            int textWidth = fontMetrics.horizontalAdvance(vertexText);
            int textHeight = fontMetrics.height();
            QPointF textPos = vertexPositions[v] - QPointF(textWidth / 2, -textHeight / 4);
            painter.drawText(textPos, vertexText);
        }
    }
}

void GraphPaint::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        for (int v1 = 0; v1 < graph->getsize(); ++v1) {
            for (const auto &neighbor : graph->getAdjList()[v1]) {
                int v2 = neighbor.first;
                int weight = neighbor.second;
                QPointF midPoint = (vertexPositions[v1] + vertexPositions[v2]) / 2; // Calcula o ponto médio
                // Converter as coordenadas do mouse para coordenadas relativas ao widget
                QPointF mousePos = event->localPos();
                QRectF weightRect(midPoint.x() - 8, midPoint.y() - 8, 16, 16);
                if (weightRect.contains(mousePos)) {
                    // Iniciar o arrastar do peso
                    isDraggingWeight = true;
                    originalWeightPosition = midPoint;
                    currentMousePosition = mousePos;
                    draggedWeightIndex = weight; // Aqui você pode rastrear o índice do peso
                    update(); // Redesenhar a tela para refletir a mudança
                    return;
                }
            }
        }
    }
}

void GraphPaint::mouseMoveEvent(QMouseEvent *event) {
    if (isDraggingWeight) {
        QPointF delta = event->localPos() - currentMousePosition;
        originalWeightPosition += delta;
        currentMousePosition = event->localPos();
        update();
    }
}

void GraphPaint::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);

    if (isDraggingWeight) {
        isDraggingWeight = false;
        update();
    }
}

void GraphPaint::updateIncremental(int v1, int v2) {
    // Atualiza apenas a nova aresta adicionada entre os vértices v1 e v2
    if (vertexPositions.contains(v1) && vertexPositions.contains(v2)) {
        // Se os vértices existem, atualiza apenas a área em torno da nova aresta
        QRectF areaToUpdate = QRectF(vertexPositions[v1], vertexPositions[v2]).normalized().adjusted(-20, -20, 20, 20);
        update(areaToUpdate.toRect());
    } else {
        // Caso contrário, atualiza toda a cena
        update();
    }
}

} // namespace iom
