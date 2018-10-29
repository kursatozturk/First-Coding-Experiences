#ifndef QUALITY_H
#define QUALITY_H
#include <vector>
#include "statistic.h"
#include <iostream>
enum QUALITY {PACE,SHOT,PAS,DRIBLING,DEFENSE,PHYSICS};
class Quality :public Statistic
{
private:
    short qualities[6];
    std::vector<short> form;
public:
    Quality(short pace,
            short shot,
            short pas,
            short dribling,
            short defense,
            short physics);
    short getQualities(QUALITY i);
    void setQuality(QUALITY i,short value);
    std::vector<short> getForm();
    void addFormValue(short value);
    void clearForm();
    void printQuality()const;
    ~Quality();
    Quality() =delete;

};

#endif
