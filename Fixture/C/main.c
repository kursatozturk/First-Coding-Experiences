#include "fixture.h"
void print_team_list(league_ League){
	team_ p;
	int i=1;
	p=teams_of(League);
	printf("%d team in %s:\n",numb(League),title(League) );
	while(p){
		printf("%d->\t%s code: %d\n",i,name(p),code(p));
		p=nextt(p);
		i++;
	}
}

void print_fixture(league_ League){
	team_ teams;
	fixt_ week;		
	int week_=1;
	teams=teams_of(League);
	week=matches(teams);
	while(week){
		fixt_ tmp;
		tmp=week;
		printf("%2d. WEEK: \n",week_++ );

		while(tmp){
			if(ha(tmp)==HOME)
			printf("%30s - %30s \n",team(tmp),opponent(tmp) );
			else
			printf("%30s - %30s \n",opponent(tmp),team(tmp) );
			tmp=week(tmp);
		}
		week=nextm(week);
	}
}

void print_deneme(league_ League,int week){
	int i=0,j=1;
	fixt_ fixta= matches(teams_of(League));
	for(j=1;j<week;j++) fixta=nextm(fixta);
	while(fixta){
		printf("%d: %s-%s\n",++i,team(fixta),opponent(fixta) );
		fixta=week(fixta);
	}
}
void test(){
	league_ League;
	League=malloc(sizeof(league));
	title(League)="League 1";
	code(League)=12;
	numb(League)=0;
	get_teams_file(League);
	print_team_list(League);
	printf("FIXTURE: \n\n");

	fixture(League);
	print_fixture(League);
	scores(League);

}



int main(){
	srand(time(NULL));
	test();
	return 0;
}
/*
Kastamonuspor
Osmaniyespor
Kocaelispor
Bursaspor
Ardahanspor
Istanbulspor
Aydinspor
Liverpool
Milan
Inter
Real Madrid
Barcelona
Atletico Madrid
Juventus
Paris st Germain
Istanbul Basaksehirspor
Besiktas
Gaziantepspor
Denizlispor
Fenerbahce

*/