#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtDebug>

#include "ui/menumodel.h"
#include "triangulation/triangle2d.h"

int main(int argc, char *argv[])
{
    Triangle2D tri(QPointF(0,0), QPointF(0, 5), QPointF(5, 0));
    for (int i = -10; i < 10; ++i)
    {
        for (int j = -10; j < 10; ++j)
        {
            if (tri.CircumscribeCircleContains(QPointF(i, j)))
            {
                qDebug() << "triangle contains point: " << i << ":" << j;
            }
        }
    }


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
