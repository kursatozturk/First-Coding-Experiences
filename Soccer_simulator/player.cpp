#include "player.h"
#include<iostream>
Player::Player(
                short pace,
                short shot,
                short pas,
                short dribling,
                short defense,
                short physics,

                std::string name,
                short age,
                std::vector<Position> position,
                short kit_number,
                short weight,
                short height,
                Mood mood,
                Foot foot,
                std::vector<long> market_value,
                std::string origin,
                Team* current_team):Quality(pace,shot,pas,dribling,defense,physics),Agreement()
     {
        this->name         = name;
        this->age          = age;
        this->position     = position;
        this->kit_number   = kit_number;
        this->weight       = weight;
        this->height       = height;
        this->mood         = mood;
        this->foot         = foot;
        this->market_value = market_value;
        this->origin       = origin;
        this->current_team = current_team;

     }

void Player::addHistory(Team* new_Team)
    {
        history.push_back(new_Team);

    }
void Player::addMarketValue(long value)
    {
        market_value.push_back(value);

    }
void Agreement::setAgreement(long salary,short start_date,short end_date)
    {
        salary = salary;
        start_date = start_date;
        end_date = end_date;
    }
long Agreement::getSalary()
    {
        return salary;
    }
short Agreement::getStartDate()
    {
        return start_date;
    }
short Agreement::getEndDate()
    {
        return end_date;
    }
void Player::printPlayer()const
    {
        std::cout<<"Name : "<<name<<"\nAge :"<<age<<"\nPosition : "<<position.front()<<"\nKit Number : "<<kit_number
                 <<"\nWeight : "<<weight<<"\nHeight : "<<height<<"\nMood : "<<mood<<"\nFoot : "<<foot<<"\nMarket Value : "
                 <<market_value.front()<<"\nOrigin : "<<origin<<std::endl;
        printQuality();
        printStatistics();
        std::cout<<std::endl;
    }
Player::~Player()
    {

    }
