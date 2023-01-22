#include "qt_widget_test.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_widget_test w;
    w.show();
    return a.exec();
}
