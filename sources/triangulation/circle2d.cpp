#include "circle2d.h"

bool Circle2D::IsPointContained(QPointF point)
{
    QPointF centerToPoint = m_Center - point;

    float dist = std::sqrt(std::pow(centerToPoint.x(), 2) +
        std::pow(centerToPoint.y(), 2));
    return dist <= m_Radius;
}
