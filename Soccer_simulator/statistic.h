#ifndef STATISTIC_H
#define STATISTIC_H
#include <iostream>
enum Availability  {AVAILABLE,INJURED,BANNED};
enum Statistics {GOAL,ASSIST,MATCHES,CONCEDED,CARD,INJUREDDAYS};
class Statistic
{
private:
    Availability  availability;
    short statistics[6];

public:
    Statistic(Availability  availability,
            short goal,
            short assist,
            short number_matches,
            short conceded,
            short card_days,
            short injured_days);
    Statistic();
    ~Statistic();
    short getStatistics(Statistics i);
    void  changeStatistics(Statistics i,short value);
    void  increaseQuality(Statistics i);
    void  decreaseQuality(Statistics i);
    void  printStatistics()const;



};
#endif
