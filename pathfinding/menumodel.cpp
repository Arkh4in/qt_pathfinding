#pragma once
#include "menumodel.h"

void MenuModel::addToCounter()
{
    m_Counter++;
    counterChanged();
}