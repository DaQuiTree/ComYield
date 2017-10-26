#include <QtGlobal>
#include <QDebug>
#include "yielddata.h"

YieldData::YieldData()
{
    milk = 0;
    cond = 0;
    bClear = false;
}

YieldData::~YieldData()
{

}

void YieldData::GenericData()
{
    milk = qrand();
    cond = qrand();
    bClear = false;
}

void YieldData::GetData(unsigned short &mv, unsigned short &cv, bool &bc)
{
    mv = milk;
    cv = cond;
    bc = bClear;
}
