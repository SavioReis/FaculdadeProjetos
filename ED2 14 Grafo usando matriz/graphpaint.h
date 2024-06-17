#ifndef GRAPHPAINT_H
#define GRAPHPAINT_H

#include <QWidget>
#include "grafo.h"

namespace srlg {
class GraphPaint : public QWidget {
    Q_OBJECT

public:
    GraphPaint(QWidget *parent = nullptr);
    void setGraph(grafo *g);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    grafo *graph;
};
}

#endif // GRAPHPAINT_H
