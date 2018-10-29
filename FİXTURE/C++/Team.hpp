#ifndef _TEAM_H_
#define _TEAM_H_

#include <string>
#include <ostream>

class Fixture;

class Team{
	std::string name;
	Fixture *fixt_of_team;
	short points;
	short scored_goal;
	short conceded_goal;
	short played_match;
	short Leage_rank;
	friend	std::ostream& operator<<(std::ostream& out,const Team team);


public:
	Team(): name(""),points(0),scored_goal(0),conceded_goal(0),played_match(0),fixt_of_team(NULL)  { };
	Team(std::string name_): name(name_),points(0),scored_goal(0),conceded_goal(0),played_match(0),fixt_of_team(NULL) { };

	void incScored(int s);
	void incConceded(int c);
	void incPoint(int p);
	void incMatch();
	short getPoints();
	short getScored();
	short getConceded();
	std::string getName();
	bool operator==(Team &rhs);
	Fixture *getFixture();
	void setFixture(Fixture* a);
	// GET POINTER;
	// SET POINTER;

};



#endif