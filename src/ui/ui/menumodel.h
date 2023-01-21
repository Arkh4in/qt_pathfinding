#pragma once
#include <QtQuick>

class MenuModel : public QObject
{
    Q_OBJECT

private:
    int m_Counter = 0;

public:
    Q_PROPERTY(int Counter MEMBER m_Counter NOTIFY CounterChanged)

signals:
    void CounterChanged();

public slots:
    void AddToCounter();
};

