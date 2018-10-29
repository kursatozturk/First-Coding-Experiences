#include "team.h"


Statistics::Statistics(){for(int i = 0; i < 7; ++i)stats.push_back(std::pair<uint, uint>(0,0));}

void Statistics::setStat(const STATISTICS stat,const uint value, const bool home){
	if(home)stats[stat].first += value;
	else stats[stat].second += value;
}

const std::pair<uint, uint>& Statistics::getStat(const STATISTICS stat) const{
	return Statistics[stat];
}

Strength::Strength(){
	for(int i = 0; i < 5; ++i)strengths.push_back(std::pair<uint, uint>(1,0));
}



Strength::Strength(const std::vector<Player *> squad) : Strength(){
	vector<QUALITY> qualities = {PACE, SHOT, PAS, DRIBLING, DEFENSE, PHYSICS};
	
	for(auto q: qualities){
		uint quality = 0;
		uint quantity = 0;
		
		for(auto player: squad){
			quality += player->getQualities(q);
			quantity++;
		}

		switch(q){
			case PACE:
				strengths[ATTACKPOWER].second += (quality / (double) quantity) * 0.15; //%15 of the attackpower is PACE
				strengths[DEFENSEPOWER].second += (quality / (double) quantity) * 0.1; //%30 of the defensepower is PACE
				break;
			case SHOT:
				strengths[ATTACKPOWER].second += (quality / (double) quantity) * 0.2; //%20 of the attackpower is SHOT
				strengths[DEFENSEPOWER].second += (quality / (double) quantity) * 0.05; //%10 of the defensepower is SHOT 
				break;
			case PAS:
				strengths[ATTACKPOWER].second += (quality / (double) quantity) * 0.2; //%20 of the attackpower is PAS
				strengths[DEFENSEPOWER].second += (quality / (double) quantity) * 0.05; //%15 of the defensepower is PAS
				strengths[PASSING].second += (quality / (double) quantity) * 0.75; //%75 of the passing is PAS
				break;
			case DRIBLING:
				strengths[ATTACKPOWER].second += (quality / (double) quantity) * 0.25; //%25 of the attackpower is DRIBLING
				break;
			case DEFENSE:
				strengths[DEFENSEPOWER] += (quality / (double) quantity) * 0.6; //%60 of the defensepower is DEFENSE				
				break;
			case PHYSICS:
				strengths[ATTACKPOWER] += (quality / (double) quantity) * 0.2; //%20 of the attackpower is PHYSICS
				strengths[DEFENSEPOWER] += (quality / (double) quantity) * 0.2;//%20 of the defensepower is PHYSICS
				strengths[PASSING] += (quality / (double) quantity) * 0.25; //%25 of the passing is PHYSİCS
				break;
		}
	}
	strengths[TEAMOVERALL].second = (strengths[ATTACKPOWER].second + strengths[DEFENSEPOWER].second + strengths[PASSING].second) / 3;
	strengths[TEAMCHEM].second = strengths[TEAMOVERALL] / 3; 
}
// PHILOSOPHY => {ATTACK, POSSESSION_GAME, BALANCE, COUNTER_ATTACK, DEFENSIVE};
Strength::Strength(const std::vector<Player *> squad,const PHILOSOPHY Gamephilosophy):Strength(squad) {
	switch(Gamephilosophy){
		case ATTACK:
			strengths[TEAMOVERALL].second = strengths[ATTACKPOWER].second * 0.4 + strengths[PASSING].second * 0.35 + strengths[DEFENSEPOWER].second * 0.25;
			break;
		case POSSESSION_GAME:
			strengths[TEAMOVERALL].second = strengths[ATTACKPOWER].second * 0.25 + strengths[PASSING].second * 0.50 + strengths[DEFENSEPOWER].second * 0.25;
			break;
		case BALANCE:
			strengths[TEAMOVERALL].second = strengths[ATTACKPOWER].second * 0.35 + strengths[PASSING].second * 0.3 + strengths[DEFENSEPOWER].second * 0.35;
			break;
		case COUNTER_ATTACK:
			strengths[TEAMOVERALL].second = strengths[ATTACKPOWER].second * 0.35 + strengths[PASSING].second * 0.2 + strengths[DEFENSEPOWER].second * 0.45;
			break;
		case DEFENSIVE:
			strengths[TEAMOVERALL].second = strengths[ATTACKPOWER].second * 0.2 + strengths[PASSING].second * 0.3 + strengths[DEFENSEPOWER].second * 0.5;
			break;
	}
	strengths[TEAMCHEM].second = strengths[TEAMOVERALL] / 3;
}


const uint& Strength::getStrength(const STRENGTHS strength) const{
	return strengths[strength].second;
}
// qualities => {PACE, SHOT, PAS, DRIBLING, DEFENSE, PHYSICS}

void Strength::updateStrength(const Player* player,bool TransferTo){
	vector<QUALITY> qualities = {PACE, SHOT, PAS, DRIBLING, DEFENSE, PHYSICS};
	if(TransferTo)
		for(quality: qualities){
			switch(quality){
				case PACE:
					strengths[ATTACKPOWER].second += player->getQualities(quality) * 0.15;
					strengths[DEFENSEPOWER].second += player->getQualities(quality) * 0.1;
					break;
				case SHOT:
					strengths[ATTACKPOWER].second += player->getQualities(quality) * 0.2;
					strengths[DEFENSEPOWER].second += player->getQualities(quality) * 0.05;
					break;
				case PAS:
					strengths[ATTACKPOWER].second += player->getQualities(quality) * 0.2;
					strengths[ATTACKPOWER].second += player->getQualities(quality) * 0.05;
					strengths[ATTACKPOWER].second += player->getQualities(quality) * 0.75;
					break;
				case DRIBLING:
					strengths[ATTACKPOWER].second += player->getQualities(quality) * 0.25;
					break;
				case DEFENSE:
					strengths[DEFENSEPOWER].second += player->getQualities(quality) * 0.6;
					break;
				case PHYSICS:
					strengths[ATTACKPOWER].second += player->getQualities(quality) * 0.2;
					strengths[DEFENSEPOWER].second += player->getQualities(quality) * 0.2;
					strengths[PASSING].second += player->getQualities(quality) * 0.25;
					break;
			}
		}
	else
		for(quality: qualities){
			switch(quality){
				case PACE:
					strengths[ATTACKPOWER].second -= player->getQualities(quality) * 0.15;
					strengths[DEFENSEPOWER].second -= player->getQualities(quality) * 0.1;
					break;
				case SHOT:
					strengths[ATTACKPOWER].second -= player->getQualities(quality) * 0.2;
					strengths[DEFENSEPOWER].second -= player->getQualities(quality) * 0.05;
					break;
				case PAS:
					strengths[ATTACKPOWER].second -= player->getQualities(quality) * 0.2;
					strengths[ATTACKPOWER].second -= player->getQualities(quality) * 0.05;
					strengths[ATTACKPOWER].second -= player->getQualities(quality) * 0.75;
					break;
				case DRIBLING:
					strengths[ATTACKPOWER].second -= player->getQualities(quality) * 0.25;
					break;
				case DEFENSE:
					strengths[DEFENSEPOWER].second -= player->getQualities(quality) * 0.6;
					break;
				case PHYSICS:
					strengths[ATTACKPOWER].second -= player->getQualities(quality) * 0.2;
					strengths[DEFENSEPOWER].second -= player->getQualities(quality) * 0.2;
					strengths[PASSING].second -= player->getQualities(quality) * 0.25;
					break;
			}
		}	
}

Team::Team(const std::string teamName,const std::vector<Player *> squad):TeamName(teamName), Squad(squad), TeamStrength(squad), TeamStats(Statistics()) { }


Team::Team(std::string teamName, std::vector<Player *> squad,PHILOSOPHY Gamephilosophy):TeamName(teamName), Squad(squad), TeamStrength(squad,Gamephilosophy), TeamStats(Statistics()){ }


Team::TransferTo(Player *player,uint TransferFee, Team* OldTeam){
	Squad.push_back(player,true);
	TeamTransfers.transferPlayer(player,TransferFee);

}


