#include "League.hpp"
#include <algorithm>
#include <sstream>
using namespace std;

League::League(){
	throw "YOU CAN'T CREATE A LEAGUE WITHOUT A NAME!";
}

League::League(string name){
	Name_of_League = name;
	Weeks_of_league = new LinkedList<Week> ();
	Teams_of_league = new LinkedList<Team> ();
	Weeks_of_league->getHead() = new week ();

}
LinkedList<Team>* Week::getTeams(){
	return Teams_of_league;
}

LinkedList<Week>* Week::getWeeks(){
	return Weeks_of_league;
}

void League::Teams(){ // reading from file will be added
	int number_of_teams;

	cout << "How many teams will be in the " << Name_of_League << "?" << endl;
	cin >> number_of_teams;
	for(int i = 0; i < number_of_teams ; i++){
		string name;
		cin >> name;
		Team team(name);
		Fixture * Empty_fixt = new Fixture;
		team.setFixture(Empty_fixt);
		this->Teams_of_league->insertNode(this->Teams_of_league->getTail(),team);
	}
}


void League::Create_Fixture(){
	if (this->Teams_of_league->getSize()%2 == 1){
		Team byTeam("by");
		this->Teams_of_league->insertNode(this->Teams_of_league->getTail(),byTeam);
	}
	int N = this->Teams_of_league->getSize();
	int *A = new int[N/2];
	int *B = new int[N/2];
	for(int i = 0; i < N/2; i++){
		A[i] = i;
		B[i] = N-i-1;
	}
	for(int round = 0; round < N-1; round ++){
		Week x;
		this->Weeks_of_league->insertNode(this->Weeks_of_league->getTail(),x);
		
		for(int index = 0; index < N/2; index++){
			Create_Match(A[index],B[index]);
		}Swap(A,B,round,N-1);
	}
}
void League::Create_Match(int a,int b){
	Node<Team> *p(this->Teams_of_league->getHead());
	int min_ = min(a,b);
	for(int i = 0; i < min_; i++){
		p = p->getNext();
	}
	Node<Team> *H = p;
	int max_ = max(a,b);
	for(int i = min_; i < max_; i++){
		p = p->getNext();
	}
	Node<Team> *A = p;
	Match match_(H,A);
	H->getData()->getFixture()->getFixt()->insertNode( H->getData()->getFixture()->getFixt()->getTail(), match_);
	A->getData()->getFixture()->getFixt()->insertNode( A->getData()->getFixture()->getFixt()->getTail(), match_);
	this->Weeks_of_league->getTail()->getData()->insertNode(this->Weeks_of_league->getTail()->getData()->getTail(),match_);

}
void League::Swap(int* A, int* B,int weeknum,int last){
	stringstream X;
	int PrevLast = B[(last-1)/2];
	if(weeknum%2 == 0){
		X << last;
		X << ',';
		X << PrevLast;
	}
	else{
		X << PrevLast;
		X << ',';
		X << last;
	}
	for(int i = 0; i < (last+1)/2; i++){
		if(A[i] != last){
			X << ',';
			X << A[i];
		}
		if(i!= (last-1)/2 && B[i] != last){
			X << ',';
			X << B[i];
		}
	}
	for(int i = 0; i< (last+1)/2; i+=1){
		char c;
		X >> A[i];
		X >> c;
		X >> B[i];
		X >> c;
	}
}

void League::print_standing_table(){
	Node<Team> *teams = this->Teams_of_league.getHead();
	size_t rank = 1;
	cout << this->Name_of_League << endl;
	while(teams){
		cout << rank << ". " << *(teams->getData()) << endl;
		teams = teams->getNext();
	}

}
void League::print_whole_fixture(){
	Node<Week> *p = this->Weeks_of_league.getHead();
	while(p){
		cout << *(p->getData());

		p = p->getNext();

	}


}