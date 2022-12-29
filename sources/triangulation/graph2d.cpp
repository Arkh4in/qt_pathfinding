#include <QPointF>
#include <QRect>

#include "graph2d.h"



void Graph2D::InitTriangulation()
{
    QPointF point = m_Vertice.pop();
    m_Triangles.append(Triangle2D(point, m_SuperTriangle.GetA(), m_SuperTriangle.GetB()));
    m_Triangles.append(Triangle2D(point, m_SuperTriangle.GetB(), m_SuperTriangle.GetC()));
    m_Triangles.append(Triangle2D(point, m_SuperTriangle.GetC(), m_SuperTriangle.GetA()));
}

void Graph2D::RemoveSuperTriangle()
{
    QStack<Triangle2D> toRemove;
    for (Triangle2D& tri : m_Triangles)
    {
        if (tri.Contains(m_SuperTriangle.GetA()) ||
            tri.Contains(m_SuperTriangle.GetB()) ||
            tri.Contains(m_SuperTriangle.GetC()))
        {
            toRemove.push(tri);
        }
    }
    while (toRemove.size() > 0)
    {
        m_Triangles.removeOne(toRemove.pop());
    }
}

Graph2D::Graph2D(QRect boundaries) : 
    m_SuperTriangle(QPointF(boundaries.left() - boundaries.width(), boundaries.top() - boundaries.height()),
    QPointF(boundaries.left(), boundaries.bottom() + 2* boundaries.height()),
    QPointF(boundaries.right() + 2* boundaries.width(), boundaries.top()))
{
    m_Boundaries = boundaries;
    m_Vertice.push(boundaries.topLeft());
    m_Vertice.push(boundaries.bottomLeft());
    m_Vertice.push(boundaries.topRight());
    m_Vertice.push(boundaries.bottomRight());
}

void Graph2D::AddRectangleObstacle(QRect obstacle)
{
}

void Graph2D::AddVertex(QPointF vertex)
{
    m_Vertice.append(vertex);
}

void Graph2D::Triangulate()
{
    QList<Triangle2D> toRemove;
    InitTriangulation();
    while (m_Vertice.size() > 0)
    {
        QPointF p = m_Vertice.pop();
        for (Triangle2D& tri : m_Triangles)
        {
            if (tri.CircumscribeCircleContains(p))
            {
                toRemove.append(tri);
            }
        }
        while (toRemove.size() > 0)
        {
            Triangle2D tri = toRemove.takeLast();
            m_Triangles.removeOne(tri);

            if (!IsEdgeSharedWithBadTriangle(toRemove, tri.GetAB()))
            {
                m_Triangles.append(Triangle2D(p, tri.GetA(), tri.GetB()));
            }

            if (!IsEdgeSharedWithBadTriangle(toRemove, tri.GetBC()))
            {
                m_Triangles.append(Triangle2D(p, tri.GetB(), tri.GetC()));
            }

            if (!IsEdgeSharedWithBadTriangle(toRemove, tri.GetCA()))
            {
                m_Triangles.append(Triangle2D(p, tri.GetC(), tri.GetA()));
            }
        }
    }
    RemoveSuperTriangle();
}

bool Graph2D::IsEdgeSharedWithBadTriangle(QList<Triangle2D>& triangles, Edge2D edge)
{
    bool isContained = false;
    for (const Triangle2D& t : triangles)
    {
        if (t.Contains(edge))
        {
            isContained = true;
            return true;
        }
    }
    return false;
}