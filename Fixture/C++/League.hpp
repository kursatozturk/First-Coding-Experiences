#ifndef _LEAGUE_H_
#define _LEAGUE_H_

#include "Week.hpp"
#include "Fixture.hpp"

class League{
	LinkedList<Team>* Teams_of_league;//standing table & team's fixtures is here
	LinkedList<Week>* Weeks_of_league;//whole fixture is here
	std::string Name_of_League; 
public:
	League();
	League(std::string name);
	LinkedList<Team>* getTeams();
	LinkedList<Week>* getWeeks();
	void Teams();//get_teams_name;
	void Create_Fixture();
	void Sort_Teams();//yazmadın bunu
	void Create_Match(int a,int b);//helper to the Create_Fixture
	void Swap(int* A, int* B,int weeknum,int last);//helper to the Create_Fixture
	void print_standing_table();
	void print_whole_fixture();




};

#endif