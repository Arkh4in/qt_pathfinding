#include <QPointF>
#include <QRect>

#include "triangle2d.h"
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
    /*QStack<Triangle2D> toRemove;
    for (Triangle2D& tri : m_Triangles)
    {
        if (tri.IsContaining(m_SuperTriangle.GetA()) ||
            tri.IsContaining(m_SuperTriangle.GetB()) ||
            tri.IsContaining(m_SuperTriangle.GetC()))
        {
            toRemove.push(tri);
        }
    }
    while (toRemove.size() > 0)
    {
        m_Triangles.removeOne(toRemove.pop_back());
    }*/
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
    //QStack<Triangle2D> toRemove;
    //InitTriangulation();
    //while (m_Vertice.size() > 0)
    //{
    //    QPointF p = m_Vertice.pop_back();
    //    for (Triangle2D& tri : m_Triangles)
    //    {
    //        if (tri.CircumscribeCircleContains(p))
    //        {
    //            toRemove.push(tri);
    //            //must handle edges here
    //            m_Triangles.append(Triangle2D(p, tri.GetA(), tri.GetB()));
    //            m_Triangles.append(Triangle2D(p, tri.GetB(), tri.GetC()));
    //            m_Triangles.append(Triangle2D(p, tri.GetC(), tri.GetA()));
    //        }
    //    }
    //    while (toRemove.size() > 0)
    //    {
    //        m_Triangles.removeOne(toRemove.pop());
    //    }
    //}
    //RemoveSuperTriangle();
}

void Graph2D::SetBoundaries(QRect boundaries)
{
    m_Boundaries = boundaries;
    QPointF a = QPointF(m_Boundaries.left() - m_Boundaries.width(), m_Boundaries.bottom() - m_Boundaries.height());
    QPointF b = QPointF(m_Boundaries.left(), 3 * m_Boundaries.top());
    QPointF c = QPointF(3 * m_Boundaries.right(), m_Boundaries.bottom());

    m_Vertice.push(boundaries.topLeft());
    m_Vertice.push(boundaries.bottomLeft());
    m_Vertice.push(boundaries.topRight());
    m_Vertice.push(boundaries.bottomRight());

    m_SuperTriangle = Triangle2D(a, b, c);
}

