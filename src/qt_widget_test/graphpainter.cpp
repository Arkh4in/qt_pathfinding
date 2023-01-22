#include "graphpainter.h"

void GraphPainter::SetEdges(const QList<Triangulation::Edge2D>& edges)
{
    m_Edges = edges;
}

QRectF GraphPainter::boundingRef() const
{
    return QRectF(-25, -40, 50, 80);
}

void GraphPainter::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    painter->setPen(pen);
    
    for (Triangulation::Edge2D& edge : m_Edges)
    {
        painter->drawLine(edge.m_From, edge.m_To);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphPainter::boundingRect() const
{
    return QRectF();
}
