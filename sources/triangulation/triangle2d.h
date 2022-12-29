#pragma once
#include "edge2d.h"

class QPointF;
struct Line;

class Triangle2D
{
public: 
    Triangle2D(QPointF a, QPointF b, QPointF c);

    QPointF GetA() const { return m_Points[0]; }
    QPointF GetB() const { return m_Points[1]; }
    QPointF GetC() const { return m_Points[2]; }

    bool Contains(const Edge2D& edge) const;
    bool Contains(const QPointF& point) const;

    bool CircumscribeCircleContains(const QPointF& point)const;

private : 
    Edge2D m_Edges[3];
    QPointF m_Points[3];

    float m_CircumscribedSquaredRadius = 0;
    QPointF m_CircumscribedCircleCenter;
    
    QPointF GetCircumscribedCircleCenter() const;
    QPointF GetLinesIntersection(const Line l1, const Line l2) const;
    Line GetNormalLineFromPoints(const QPointF p1, const QPointF p2) const;
};

