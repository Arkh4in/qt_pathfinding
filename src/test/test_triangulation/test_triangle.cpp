#include <QPointF>

#include "catch_amalgamated.hpp"
#include "triangulation\triangle2d.h"


TEST_CASE("compare 2 triangles with same points", "[vector]")
{
    QPointF p0 = QPointF(0, 0);
    QPointF p1 = QPointF(0, 1);
    QPointF p2 = QPointF(1, 0);

    Triangulation::Triangle2D tri0 = Triangulation::Triangle2D(p0, p1, p2);
    Triangulation::Triangle2D tri1 = Triangulation::Triangle2D(p1, p2, p0);

    REQUIRE(tri0 == tri1);
}