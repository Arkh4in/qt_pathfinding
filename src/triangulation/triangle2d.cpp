#include <stdexcept>

#include "triangle2d.h"

namespace Triangulation
{
    struct Line 
    {
        //Line is ax+b
        float a;
        float b;
    };

    QPointF Triangle2D::GetCircumscribedCircleCenter() const
    {
        QPointF a = m_A;
        QPointF b = m_B;
        QPointF c = m_C;

        Line n1, n2;

        if (a.y() != b.y() && b.y() != c.y())
        {
            n1 = GetNormalLineFromPoints(a, b);
            n2 = GetNormalLineFromPoints(b, c);
        }
        else if (a.y() == b.y())
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

    QPointF Triangle2D::GetLinesIntersection(const Line &l1, const Line &l2) const
    {
        //Check for parallel lines
        if (l1.a == l2.a)
            throw std::invalid_argument("Cant find intersection for 2 parallel lines");

        float a = l1.a - l2.a;
        float b = l1.b - l2.b;

        float x = -b / a;
        return QPointF(x, l1.a * x + l1.b);
    }

    Line Triangle2D::GetNormalLineFromPoints(const QPointF &p1, const QPointF &p2) const
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
        m_A = a;
        m_B = b;
        m_C = c;

        m_AB = Edge2D(a, b);
        m_BC = Edge2D(b, c);
        m_CA = Edge2D(c, a);


        m_CircumscribedCircleCenter = GetCircumscribedCircleCenter();
    
        QPointF radiusVector = m_CircumscribedCircleCenter -m_A;

        m_CircumscribedSquaredRadius = radiusVector.x() * radiusVector.x() + radiusVector.y() * radiusVector.y();
    }

    bool Triangle2D::Contains(const Edge2D& edge) const
    {
        return(m_AB == edge ||
            m_BC == edge ||
            m_CA == edge);
    }

    bool Triangle2D::Contains(const QPointF& point) const
    {
        return(m_A == point ||
           m_B == point ||
           m_C == point);
    }

    bool Triangle2D::CircumscribeCircleContains(const QPointF& point) const
    {
        QPointF radiusVector = m_CircumscribedCircleCenter - point;
        return radiusVector.x() * radiusVector.x() + radiusVector.y() * radiusVector.y() <= m_CircumscribedSquaredRadius; //compare squared dist
    }
}
