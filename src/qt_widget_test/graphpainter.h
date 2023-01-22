#pragma once
#include <QGraphicsItem>
#include <QPainter>

#include "triangulation\edge2d.h"


class GraphPainter : public QGraphicsItem
{
private: 
    QList<Triangulation::Edge2D> m_Edges;

public: 
    void SetEdges(const QList<Triangulation::Edge2D>& edges);

protected:
    QRectF boundingRef() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget /* = nullptr */);

    // Inherited via QGraphicsItem
    virtual QRectF boundingRect() const override;
};

