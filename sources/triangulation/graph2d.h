#pragma once
#include <QPointF>
#include <QList>
#include "triangle2d.h"

class Graph2D
{
private: 
    QList<Triangle2D> triangles;

public:
    void AddObstacleAABB(QPointF a, QPointF b);
    void Triangulate();

};

