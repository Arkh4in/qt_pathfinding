#include <stdexcept>

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

    Line n1, n2;

    if (a.y() != b.y() && b.y() != c.y())
    {
        n1 = GetNormalLineFromPoints(a, b);
        n2 = GetNormalLineFromPoints(b, c);
    }
    else if(a.y() == b.y())
    {
        n1 = GetNormalLineFromPoints(a, c);
        n2 = GetNormalLineFromPoints(b, c);
    }
    else //if (b.y() == c.y())
    {
        n1 = GetNormalLineFromPoints(a, b);
        n2 = GetNormalLineFromPoints(a, c);
    }

    return GetLinesIntersection(n1, n2);
}

QPointF Triangle2D::GetLinesIntersection(Line l1, Line l2)
{
    //Check for parallel lines
    if (l1.a == l2.a)
        throw std::invalid_argument("Cant find intersection for 2 parallel lines");

    float a = l1.a - l2.a;
    float b = l1.b - l2.b;
    
    float x = -b / a;
    return QPointF(x, l1.a * x + l1.b);
}

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
    m_CircumscribedCircleCenter = GetCircumscribedCircleCenter();
    
    QPointF radiusVector = m_CircumscribedCircleCenter - m_Points[0];

    m_CircumscribedSquaredRadius = radiusVector.x() * radiusVector.x() + radiusVector.y() * radiusVector.y();
}

//bool Triangle2D::IsContaining(QPointF& const point) const
//{
//    return(a == point ||
//        b == point ||
//        c == point);
//}

bool Triangle2D::CircumscribeCircleContains(const QPointF& point) const
{
    QPointF radiusVector = m_CircumscribedCircleCenter - point;
    return radiusVector.x() * radiusVector.x() + radiusVector.y() * radiusVector.y() <= m_CircumscribedSquaredRadius; //compare squared dist
}
