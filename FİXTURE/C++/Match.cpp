#include "Match.hpp"

Match::Match(){};
Match::Match(Node<Team> *h,Node<Team> *a){
	Home = h;
	Away = a;
}
ostream& Match::operator<<(ostream& out,const score x){
	if(x.HomeScore != -1) out << x.HomeScore << " - " << x.AwayScore;
	else out << " - ";
	return out;
}	

Node<Team> *Match::getHome(){
	return Home;
}
Node<Team> *Match::getAway(){
	return Away;
}
score Match::getScore(){
	return Score;
}
void Match::setScore(score S){
	Score = S;
}
ostream& operator<<(ostream& out,const Match match){
	out << match.Home->getData()->getName() << match.Score << match.Away->getData()->getName() << endl;
	return out;
}

bool Match::operator==(Match& rhs){
	return(this->Home == rhs.Home && this->Away == rhs.Away);
}