#pragma once
#include <QList>
#include <QStack>

#include "circle2d.h"

class Triangle2D;
class Edge2D;
class QRect;

class Graph2D
{
private: 
    QRect m_Boundaries;

    QList<Triangle2D> m_Triangles;
    QStack<QPointF> m_Vertice;
    QList<Edge2D> m_ConstraintedEdges;

    Triangle2D m_SuperTriangle;

    void InitTriangulation();
    void RemoveSuperTriangle();

public:
    void AddRectangleObstacle(QRect obstacle);
    void AddVertex(QPointF vertex);

    void Triangulate();
    void SetBoundaries(QRect boundaries);
};

