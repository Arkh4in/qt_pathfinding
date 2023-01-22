#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>

#include "ui_qt_widget_test.h"
#include "graphpainter.h"

class qt_widget_test : public QMainWindow
{
    Q_OBJECT

public:
    qt_widget_test(QWidget *parent = nullptr);
    ~qt_widget_test();

private:
    Ui::qt_widget_testClass *ui;
    QGraphicsScene *scene;
    GraphPainter *graphPainter;

public slots:
    void test() 
    {
    };
};
