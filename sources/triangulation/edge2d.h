#pragma once
#include <QPointF>

class Edge2D
{
public: 
    QPointF from, to;

    float GetLength();

    bool operator== (const Edge2D& rhs)const
    {
        return from == rhs.from && to == rhs.to;
    }
};

