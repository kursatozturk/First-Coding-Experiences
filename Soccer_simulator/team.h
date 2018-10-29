#ifndef TEAM_H
#define TEAM_H


enum STATISTICS{
	PLAYEDMATCH,
	SCOREDGOAL,
	CONCEDEDGOAL, 
	WIN, 
	LOSE, 
	DRAW, 
	POINTS};

enum STRENGTHS{
	ATTACKPOWER,
	DEFENSEPOWER,
	PASSING,
	TEAMCHEM,
	TEAMOVERALL};

enum PHILOSOPHY{
	ATTACK,
	POSSESSION_GAME,
	BALANCE,
	COUNTER_ATTACK,
	DEFENSIVE};

struct Transfers{
	long int budget;
	std::vector<std::pair<long int, const Player *> > newTransfers;
	Transfers():budget(0), newTransfers(std::vector<std::pair<long int, const Player *> >()){};
	void transferPlayer(Player *newPlayer, long int TransferFee){
		newTransfers.push_back(std::pair<long int, const Player *>(TransferFee, newPlayer));
		budget -= TransferFee;
	}
	void sellPlayer(Player *oldPlayer, long int TransferFee){
		
	}
}

class Statistics{
	std::vector<std::pair<uint, uint> > stats;
public:
	Statistics();
	~Statistics() = default;

	void setStat(const STATISTICS, const uint,const bool);
	const std::pair<uint, uint>& getStat(const STATISTICS) const;
};


class Strength{
	std::vector<uint, uint> strengths; //first is the processed time. Second is the current strength value.
public:
	Strength();
	Strength(const std::vector<Player *>);
	Strength(const std::vector<Player *>,const PHILOSOPHY);
	~Strength() = default; 
	const uint& getStrength(const STRENGTHS) const;
	void updateStrength(const Player *);
};

class Team{
	std::string TeamName;
	std::vector<Player *> Squad;
	Transfers TeamTransfers;
	Strength TeamStrength;
	Statistics TeamStats;
public:
	Team() = delete;
	Team(conststd::string teamName,const std::vector<Player *> squad);
	Team(conststd::string teamName,const std::vector<Player *> squad,const PHILOSOPHY GamePhilosophy);
	TransferTo(const Player *, const Team *);
	TransferFrom(const Player *, const Team *);

};

#endif
