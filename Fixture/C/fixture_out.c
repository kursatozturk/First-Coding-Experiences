#include "fixture.h"

void print_fixture(league_ League){
	team_ teams;
	fixt_ fixtures;
	int week_num=0;
	FILE *f;
	teams=teams_of(League);
	fixtures=matches(teams);
	f=fopen("fixture.out","w");
	while(fixtures){
		fixt_ week;
		fprintf(f,"WEEK %d \n\n",++week_num );
		week=fixtures;
		while(week){
			if(score(week)[0]==-1 && score(week)[1]==-1){
				if(ha(week)==HOME)
					fprintf(f,"%26s   -   %26s\n",team(week),opponent(week));
				else
					fprintf(f,"%26s   -   %26s\n",opponent(week),team(week));
			}
			else{
				if(ha(week)==HOME)
					fprintf(f,"%26s %2d-%2d %26s\n",team(week),score(week)[0],score(week)[1],opponent(week));
				else
					fprintf(f,"%26s %2d-%2d %26s\n",opponent(week),score(week)[1],score(week)[0],team(week));
			
			}

			week=week(week);
		}
		fprintf(f,"\n");
		fixtures=nextm(fixtures);
	}
	fclose(f);
}

void print_teams_fixture(league_ League){
	team_ teams;
	FILE *f;
	f=fopen("teams_fixture.out","w");
	teams=teams_of(League);
	while(teams){
		fixt_ fixtures;
		fixtures=matches(teams);
		fprintf(f,"%s\n", name(teams));
		while(fixtures){
			if(score(fixtures)[0]==-1 && score(fixtures)[1]==-1){
				if(ha(fixtures)==HOME)
					fprintf(f,"%26s   -   %26s\n",team(fixtures),opponent(fixtures));
				else
					fprintf(f,"%26s   -   %26s\n",opponent(fixtures),team(fixtures));
			}
			else{
				if(ha(fixtures)==HOME)
					fprintf(f,"%26s %2d-%2d %26s\n",team(fixtures),score(fixtures)[0],score(fixtures)[1],opponent(fixtures));
				else
					fprintf(f,"%26s %2d-%2d %26s\n",opponent(fixtures),score(fixtures)[1],score(fixtures)[0],team(fixtures));
			
			}
			fixtures=nextm(fixtures);
		}
		fprintf(f,"\n");
		teams=nextt(teams);
	}
	fclose(f);
}

int is_it_team(char *name, char *team){
	char *p,*q;
	p=name;
	q=team;
	while(*p && *q){
		if(*p!=*q)return 0;
		p++;
		q++;
		if(!*p && !*q)return 1;
	}
	return 0;
}

void get_score_of_match(league_ League,team_ teams, fixt_ fixtures){
	int a,h;
	team_ away_team;
	scanf("%d %d",&h,&a);
	score(fixtures)[0]=h;
	score(fixtures)[1]=a;

	away_team=teams_of(League);
	while(!is_it_team(name(away_team),opponent(fixtures)))away_team=nextt(away_team);
	if(ha(fixtures)==HOME){
		if(score(fixtures)[0]>score(fixtures)[1]){pts(teams)+=3;w(teams)++;l(away_team)++;}
		if(score(fixtures)[0]==score(fixtures)[1]){pts(teams)++;pts(away_team)++;d(teams)++;d(away_team)++;}
		else {pts(away_team)+=3;w(away_team)++;l(teams)++;}
		goals(teams)[0]+=score(fixtures)[0];goals(teams)[1]+=score(fixtures)[1];
		goals(teams)[0]+=score(fixtures)[1];goals(teams)[1]+=score(fixtures)[0];

	}
	
}
/*
// INPUT FROM USER
*/

void input_match(league_ League){
	team_ teams;
	team_ away_team;
	fixt_ fixtures;
	char *team_name;
	int i,week_num;
	printf("which team's which week's match?\n");
	scanf("%s %d",team_name,&week_num);
	teams=teams_of(League);
	while(!is_it_team(name(teams),team_name))teams=nextt(teams);
	fixtures=matches(teams);
	for(i=1;i<week_num;i++)fixtures=nextm(fixtures);
	get_score_of_match(League,teams,fixtures);

}
/*
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*/

void whole_season(league_ League){

}
int main(){
	league_ League;
	League=malloc(sizeof(league));
	title(League)="League 1";
	code(League)=12;
	numb(League)=0;
	get_teams_file(League);	
	fixture(League);
	print_fixture(League);
	print_teams_fixture(League);
	while(1){
	char c;
	input_match(League);
	print_fixture(League);
	print_teams_fixture(League);
boba:
	printf("do you want to continue? y/n\n");
	scanf("%c",&c);
	if(c=='y')continue;
	if(c=='n'){
		printf("it is over.\n");
		print_standing_table(League);
		break;
	}
	else{
		printf("WRONG LETTER!!\n");
		goto boba;
	}
	}
	return 0;
}