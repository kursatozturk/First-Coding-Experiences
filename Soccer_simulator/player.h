#ifndef PLAYER_H
#define PLAYER_H

#include "quality.h"
#include <string>
class Team
{
private:
    std::string name;
public:
    Team(std::string name)
        {
            name = name;
        }
};
class Agreement
{
private:
    long salary;
    short start_date;
    short end_date;
public:
    Agreement()
    {
        salary     = 0;
        start_date = 0;
        end_date   = 0;
    }
    void setAgreement(long salary,short start_date,short end_date);
    long getSalary();
    short getStartDate();
    short getEndDate();
};

enum Position {GK,LB,CB,RB,LM,CM,RM,LW,AM,RW,CF};
enum Mood {VERYBAD,BAD,NORMAL,GOOD,VERYGOOD};
enum Foot {LEFT,RIGHT,BOTH};
class Player:public Quality,public Agreement
{
private:
    std::string name;
    short age;
    std::vector<Position> position;
    short kit_number;
    short weight;
    short height;
    Mood mood;
    Foot foot;
    std::vector<long> market_value;
    std::string origin;
    Team* current_team;
    std::vector<Team *>history;
    Agreement agreement;
public:
    Player(
                short pace,
                short shot,
                short pas,
                short dribling,
                short defense,
                short physics,
                const std::string name,
                short age,
                std::vector<Position> position,
                short kit_number,
                short weight,
                short height,
                Mood mood,
                const Foot foot,
                std::vector<long> market_value,
                const std::string origin,
                Team* current_team
           );
        ~Player();
        Player() = delete;
        void addHistory(Team* new_Team);
        void addMarketValue(long value);
        void printPlayer()const;




};










#endif
