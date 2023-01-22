#include "qt_widget_test.h"
#include "triangulation/graph2d.h"

qt_widget_test::qt_widget_test(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QRect rect(QPoint(0, 0), QPoint(100, 100));
    Triangulation::Graph2D graph(rect);

    graph.AddVertex(QPointF(31, 51));
    graph.AddVertex(QPointF(22, 22));
    graph.AddVertex(QPointF(53, 63));
    graph.AddVertex(QPointF(64, 44));
    graph.AddVertex(QPointF(65, 25));
    graph.AddVertex(QPointF(0, 50));
    graph.AddVertex(QPointF(50, 0));
    graph.AddVertex(QPointF(50, 50));
    graph.AddVertex(QPointF(10, 51));
    graph.AddVertex(QPointF(22, 48));
    graph.AddVertex(QPointF(53, 63));
    graph.AddVertex(QPointF(95, 44));


    graph.Triangulate();

    graphPainter = new GraphPainter();
    graphPainter->SetEdges(graph.GetEdges());
    scene->addItem(graphPainter);
    graphPainter->setPos(0, 0);
}

qt_widget_test::~qt_widget_test()
{}
