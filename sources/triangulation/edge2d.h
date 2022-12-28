#pragma once
#include <QPointF>

class Edge2D
{
public: 
    QPointF from, to;

    float GetLength();
};

