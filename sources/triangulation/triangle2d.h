#pragma once
#include "edge2d.h"

class QPointF;
struct Line;

class Triangle2D
{
public: 
    Triangle2D(QPointF a, QPointF b, QPointF c);

    QPointF GetA() const { return m_A; }
    QPointF GetB() const { return m_B; }
    QPointF GetC() const { return m_C; }

    Edge2D GetAB() const { return m_AB; }
    Edge2D GetBC() const { return m_BC; }
    Edge2D GetCA() const { return m_CA; }

    bool Contains(const Edge2D& edge) const;
    bool Contains(const QPointF& point) const;

    bool CircumscribeCircleContains(const QPointF& point)const;

    bool operator== (const Triangle2D& rhs)const
    {
        return rhs.Contains(m_A) && rhs.Contains(m_B) && rhs.Contains(m_C);
    }

    bool operator!= (const Triangle2D& rhs)const
    {
        return !rhs.Contains(m_A) 
            || !rhs.Contains(m_B) 
            || !rhs.Contains(m_C);
    }

private : 
    Edge2D m_AB;
    Edge2D m_BC;
    Edge2D m_CA;

    QPointF m_A;
    QPointF m_B;
    QPointF m_C;

    float m_CircumscribedSquaredRadius = 0;
    QPointF m_CircumscribedCircleCenter;
    
    QPointF GetCircumscribedCircleCenter() const;
    QPointF GetLinesIntersection(const Line &l1, const Line &l2) const;
    Line GetNormalLineFromPoints(const QPointF &p1, const QPointF &p2) const;
};

