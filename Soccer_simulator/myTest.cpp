#include <iostream>

#include <vector>

enum Stats {
 PLAYEDMATCH,
  SCOREDGOAL,
  CONCEDEDGOAL, 
  WIN, 
  LOSE, 
  DRAW, 
  POINTS};


class Statistics{

	std::vector<std::pair<uint, uint> > stats;

public:

	Statistics(){
		for(int i = 0; i < 7; ++i)stats.push_back(std::pair<uint, uint>(0,0));
	}
	~Statistics() = default;
	
	void setStat(Stats stat, uint value, bool home){
		if(home)stats[stat].first += value;
		else stats[stat].second += value;
	}

	std::pair<uint, uint> getStat(Stats stat){
		return stats[stat];
	}
};

int main() {
	Statistics stat;
	stat.setStat(WIN, 1, true);
	std::cout << stat.getStat(WIN).first << " - " << stat.getStat(WIN).second << std::endl;
	stat.setStat(LOSE, 1, false);
	std::cout << stat.getStat(LOSE).first << " - " << stat.getStat(LOSE).second << std::endl;
	
	return 0;
}