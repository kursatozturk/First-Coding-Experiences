#ifndef _FIXTURE_H_
#define _FIXTURE_H_
#include "Match.hpp"
#include "LinkedList.hpp"

class Fixture{
	LinkedList<Match> *Match_Fixture;
public:
	LinkedList<Match> *getFixt();
	Fixture();
	friend ostream& operator<<(ostream& out,const Fixture fixt);
};


#endif
