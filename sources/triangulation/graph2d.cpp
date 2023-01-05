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
        QPointF(boundaries.left(), boundaries.bottom() + 2 * boundaries.height()),
        QPointF(boundaries.right() + 2 * boundaries.width(), boundaries.top()))
{
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

        //TODO: work with edges instead of triangles to remove this complexity
        QList<Edge2D> sharedEdges;
        for (Triangle2D& tri : toRemove)
        {
            AppendIfNewSharedEdge(toRemove, sharedEdges, tri, tri.GetAB());
            AppendIfNewSharedEdge(toRemove, sharedEdges, tri, tri.GetBC());
            AppendIfNewSharedEdge(toRemove, sharedEdges, tri, tri.GetCA());
        }

        while (toRemove.size() > 0)
        {
            Triangle2D tri = toRemove.takeLast();
            m_Triangles.removeOne(tri);

            if (!sharedEdges.contains(tri.GetAB()))
            {
                m_Triangles.append(Triangle2D(p, tri.GetA(), tri.GetB()));
            }

            if (!sharedEdges.contains(tri.GetBC()))
            {
                m_Triangles.append(Triangle2D(p, tri.GetB(), tri.GetC()));
            }

            if (!sharedEdges.contains(tri.GetCA()))
            {
                m_Triangles.append(Triangle2D(p, tri.GetC(), tri.GetA()));
            }
        }
    }
    RemoveSuperTriangle();
}

void Graph2D::AppendIfNewSharedEdge(QList<Triangle2D>& triangles, QList<Edge2D>& badEdges, Triangle2D triangle, Edge2D edge)
{
    for (const Edge2D& e : badEdges)
    {
        if(edge == e)
            return;
    }
    bool isContained = false;
    for (const Triangle2D& t : triangles)
    {
        if (t != triangle && t.Contains(edge))
        {
            badEdges.append(edge);
            return;
        }
    }
}