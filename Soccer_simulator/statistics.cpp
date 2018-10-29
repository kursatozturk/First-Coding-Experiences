#include "statistic.h"


Statistic::Statistic(Availability  availability=AVAILABLE,
                     short goal=0,
                     short assist=0,
                     short number_matches=0,
                     short conceded=0,
                     short card_days=0,
                     short injured_days=0)
{
     statistics[0] = goal;
     statistics[1] = assist;
     statistics[2] = number_matches;
     statistics[3] = conceded;
     statistics[4] = card_days;
     statistics[5] = injured_days;
}
Statistic::Statistic()
{
     statistics[0] = 0;
     statistics[1] = 0;
     statistics[2] = 0;
     statistics[3] = 0;
     statistics[4] = 0;
     statistics[5] = 0;
}
short Statistic::getStatistics(Statistics i)
{
    return statistics[i];
}
void  Statistic::changeStatistics(Statistics i,short value)
{
   statistics[i] = value;
}
void  Statistic::increaseQuality(Statistics i)
{
    statistics[i]+=1;
}
void  Statistic::decreaseQuality(Statistics i)
{
    statistics[i]-=1;
}
void  Statistic::printStatistics()const
{
    std::cout<<"Goal : "<< statistics[0]<<"\nAssist : "<<statistics[1] <<"\nNumber of Matches : "<<statistics[2]<<"\nConceded : "
                        <<statistics[3]<<"\nCard days left : "<<statistics[4]<<"\nInjured days left :"<<statistics[5]<<std::endl;

}



Statistic::~Statistic()
{

}
