#ifndef _WEEK_H_
#define _WEEK_H_

#include "LinkedList.hpp"
#include "Match.hpp"
using namespace std;

class Week : public LinkedList<Match>{
	int WeekNum;
public:
	Week();
	void setWeekNum(int num);
	int getWeekNum();
	friend ostream& operator<<(ostream& out,const Week week);
};


#endif