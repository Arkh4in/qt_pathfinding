#include "edge2d.h"

float Edge2D::GetLength()
{
    QPointF edge = to - from;
    return std::sqrt(std::pow(edge.x(), 2) + std::pow(edge.y(), 2));
}
