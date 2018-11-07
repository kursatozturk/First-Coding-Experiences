#ifndef _MATCH_H_
#define _MATCH_H_

#include "Team.hpp"
#include "Node.hpp"
using namespace std;

typedef struct score
{
	short HomeScore;
	short AwayScore;
	score(): HomeScore(-1), AwayScore(-1) { };
	score(short h,short a) : HomeScore(h), AwayScore(a) { };
	friend ostream& operator<<(ostream& out, const score x);
}score;



class Match {
	Node<Team> *Home;
	Node<Team> *Away;
	score Score;
public:
	Match();
	Match(Node<Team> *h,Node<Team> *a);
	Node<Team> *getHome();
	Node<Team> *getAway();
	score getScore();
	void setScore(score S);
	friend ostream& operator<<(ostream& out, const Match match);
	bool operator==(Match& rhs);
};

#endif