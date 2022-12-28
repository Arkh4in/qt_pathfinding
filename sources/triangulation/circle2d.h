#pragma once
#include <QPointF>

class Circle2D
{
public: 
    Circle2D(QPointF center, float radius) : m_Center{ center }, m_Radius{ radius } {};
    bool IsPointContained(QPointF point);
    QPointF m_Center;
    float m_Radius;
};

