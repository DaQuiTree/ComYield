#ifndef YIELDDATA_H
#define YIELDDATA_H

class YieldData{
    unsigned short milk;
    unsigned short cond;
    bool bClear;
public:
    YieldData();
    ~YieldData();
    void GenericData();
    void GetData(unsigned short& mv, unsigned short& cv, bool& bc);
};
#endif // YIELDDATA_H
