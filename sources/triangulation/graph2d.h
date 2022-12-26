#pragma once
#include <QList>

class Triangle2D;
class Edge2D;
class QRect;

class Graph2D
{
private: 
    QRect m_Boundaries;

    QList<Triangle2D> m_Triangles;
    QList<Edge2D> m_ConstraintedEdges;

public:
    void AddRectangleObstacle(QRect obstacle);
    void Triangulate();
    void SetBoundaries();
};

