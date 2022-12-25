#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "menumodel.h"

int main(int argc, char *argv[])
{
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
