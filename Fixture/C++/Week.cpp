#include "Week.hpp"

using namespace std;

Week::Week() : LinkedList<Match>(){
	WeekNum = 1;
}

void Week::setWeekNum(int num){
	WeekNum = num;}

int Week::getWeekNum(){ 
 	return WeekNum;}

ostream& operator<<(ostream& out,const Week week){
		out << week.WeekNum << ". week: " << endl;
		Node<Match> *p = week.getHead();
		while(p){
			out << *(p->getData());
			p = p->getNext();
		}
		return out;
	}

