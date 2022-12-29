#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtDebug>
#include <QPointF>
#include <QRect>

#include "ui/menumodel.h"
#include "triangulation/graph2d.h"

int main(int argc, char *argv[])
{
    QRect rect(QPoint(0, 0), QPoint(10, 10));
    Graph2D graph(rect);
    graph.AddVertex(QPointF(2, 2));
    graph.AddVertex(QPointF(5, 8));
    graph.AddVertex(QPointF(8, 5));
    graph.Triangulate();


#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<MenuModel>("Menu", 1, 0, "MenuModel");
    MenuModel menu;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty(QStringLiteral("Menu"), &menu);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
