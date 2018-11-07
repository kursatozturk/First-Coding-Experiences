#include "Fixture.hpp"

using namespace std;
Fixture::Fixture(){
	Match_Fixture = new LinkedList<Match>();
}
LinkedList<Match> *Fixture::getFixt(){
	return Match_Fixture;}

ostream& operator<<(ostream& out,const Fixture fixt){
	Node<Match> *p;
	p = fixt.Match_Fixture->getHead();
	while(p){
		out << *(p->getData());
		p = p->getNext();}
	return out;
}