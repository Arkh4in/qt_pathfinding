#include "triangle2d.h"

struct Line 
{
    //Line is ax+b
    float a;
    float b;
};

QPointF Triangle2D::GetCircumscribedCircleCenter()
{
    /* m_Vertice[0] = QPointF(-2, 1);
     m_Vertice[1] = QPointF(2, 2);
     m_Vertice[2] = QPointF(0, 0);*/
    
    QPointF a = m_Points[0];
    QPointF b = m_Points[1];
    QPointF c = m_Points[2];

    Line normal1 = GetNormalLineFromPoints(a, b);
    Line normal2 = GetNormalLineFromPoints(b, c);

    QPointF center;
    if (!TryGetLinesIntersection(normal1, normal2, center))
    {
        return QPointF();
    }
    return center;
}

bool Triangle2D::TryGetLinesIntersection(Line l1, Line l2, QPointF& intersection)
{
    //Check for parallel lines
    if (l1.a == l2.a)
        return false;

    float a = l1.a - l2.a;
    float b = l1.b - l2.b;
    
    intersection.setX(-b/a);
    intersection.setY(l1.a * intersection.x() + l1.b);

    return true;
}

//Line Triangle2D::GetLineFromPoints(QPoint p1, QPoint p2)
//{
//    Line l;
//    float dx = p2.x() - p1.x();
//    float dy = p2.y() - p1.y();
//
//    l.a = dx / dy;
//    l.b = p1.y() - (l.a * p1.x());
//    return l;
//}

Line Triangle2D::GetNormalLineFromPoints(QPointF p1, QPointF p2)
{
    Line l;
    float dx = p2.x() - p1.x();
    float dy = p2.y() - p1.y();

    // QPoint normalVector = QPoint(-dy, dx);
    // => this implies that l.a is dx / -dy

    l.a = dx / -dy;
    QPointF center = QPointF((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2);

    l.b = center.y() - (l.a * center.x());
    return l;
}


Triangle2D::Triangle2D(QPointF a, QPointF b, QPointF c)
{
    m_Points[0] = a;
    m_Points[1] = b;
    m_Points[2] = c;
}

Circle2D Triangle2D::GetCircumscribedCircle()
{
    QPointF center = GetCircumscribedCircleCenter();

    QPointF centerToVertex = center - m_Edges[0].from;
    
    float dist = std::sqrt(std::pow(centerToVertex.x(), 2) +
        std::pow(centerToVertex.y(), 2));

    return Circle2D(center, dist);
}

bool Triangle2D::IsContaining(QPointF& const point) const
{
    return(a == point ||
        b == point ||
        c == point);
}
