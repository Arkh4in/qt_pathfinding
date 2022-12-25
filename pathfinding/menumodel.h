#pragma once
#include <QtQuick>

class MenuModel : public QObject
{
    Q_OBJECT

private:
    int m_Counter = 0;

public:
    Q_PROPERTY(int counter MEMBER m_Counter NOTIFY counterChanged)

signals:
    void counterChanged();

public slots:
    void addToCounter();
};

