#include "quality.h"
Quality::Quality(short pace,
            short shot,
            short pas,
            short dribling,
            short defense,
            short physics):Statistic()
    {
        qualities[0] = pace;
        qualities[1] = shot;
        qualities[2] = pas;
        qualities[3] = dribling;
        qualities[4] = defense;
        qualities[5] = physics;

    }

short Quality::getQualities(QUALITY i)
    {
        return qualities[i];
    }
void Quality::setQuality(QUALITY i,short value)
    {
        qualities[i] = value;
    }
std::vector<short> Quality::getForm()
    {
        return form;
    }
void Quality::addFormValue(short value)
    {
        form.push_back(value);
    }
void Quality::clearForm()
    {
        form.clear();
    }
void Quality::printQuality()const
    {
    std::cout<<"Pace : "<< qualities[0]<<"\nShot : "<<qualities[1] <<"\nPas : "<<qualities[2]<<"\nDribbling : "
                        <<qualities[3]<<"\nDefense : "<<qualities[4]<<"\nPhysics :"<<qualities[5]<<std::endl;
    }


    Quality::~Quality()
    {
        form.clear();
    }
