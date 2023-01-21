#pragma once
#include "menumodel.h"

void MenuModel::AddToCounter()
{
    m_Counter++;
    CounterChanged();
}