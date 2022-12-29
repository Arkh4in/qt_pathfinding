#pragma once
#include <QPointF>

class Edge2D
{
public: 
    Edge2D() = default;
    Edge2D(QPointF from, QPointF to) : m_From{ from }, m_To(to){};
    QPointF m_From, m_To;

    bool operator== (const Edge2D& rhs)const
    {
        return (m_From == rhs.m_From && m_To == rhs.m_To) ||
            (m_To == rhs.m_From && m_From == rhs.m_To);
    }
};

