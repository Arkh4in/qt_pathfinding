#pragma once
#include <QList>
#include <QStack>

#include "triangle2d.h"

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
    void AppendIfNewSharedEdge(QList<Triangle2D>& triangles, QList<Edge2D>& badEdges, Triangle2D triangle, Edge2D edge);

public:
    Graph2D(QRect boundaries);

    void AddRectangleObstacle(QRect obstacle);
    void AddVertex(QPointF vertex);

    void Triangulate();
};

