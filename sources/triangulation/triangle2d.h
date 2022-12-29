#pragma once
#include "edge2d.h"

class QPointF;
struct Line;

class Triangle2D
{
public: 
    Triangle2D(QPointF a, QPointF b, QPointF c);

    QPointF GetA() { return m_Points[0]; }
    QPointF GetB() { return m_Points[1]; }
    QPointF GetC() { return m_Points[2]; }

    //bool IsContaining(QPointF& const point)const;
    bool CircumscribeCircleContains(const QPointF& point)const;

private : 
    Edge2D m_Edges[3];
    QPointF m_Points[3];

    float m_CircumscribedSquaredRadius = 0;
    QPointF m_CircumscribedCircleCenter;
    
    QPointF GetCircumscribedCircleCenter();
    QPointF GetLinesIntersection(Line l1, Line l2);
    Line GetNormalLineFromPoints(QPointF p1, QPointF p2);
};

