#include "Team.hpp"
#include <ostream>

using namespace std;

void Team::incScored(int s){
	scored_goal += s;
}

void Team::incConceded(int c){
	conceded_goal += c;
}

void Team::incPoint(int p){ 
	points += p;
}

void Team::incMatch(){
	played_match++;
}

short Team::getPoints(){
	return points;
}

short Team::getScored(){
	return scored_goal;
}

short Team::getConceded(){
	return conceded_goal;
}

string Team::getName(){
	return name;
}

Fixture *Team::getFixture(){
	return fixt_of_team;
}
void Team::setFixture(Fixture* a){
	fixt_of_team=a;
}

bool Team::operator==(Team &rhs){
	return (this->name == rhs.name);
}
ostream& operator<<(ostream& out ,const Team team ){
	out << team.name << "\t" << team.played_match << "\t" << team.scored_goal << "\t" << team.conceded_goal << "\t" << team.scored_goal - team.conceded_goal << "\t" << team.points << endl;
	return out;
}