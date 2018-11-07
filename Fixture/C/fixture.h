#ifndef FIXTURE_H_
#define FIXTURE_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define nextm(match) 	  ((match)->next_match)
#define prevm(match)  	  ((match)->prev_match)
#define score(match)  	  ((match)->score)
#define ha(match)         ((match)->home_away)
#define nextt(team)   	  ((team)->next_team)
#define prevt(team)   	  ((team)->prev_team)
#define name(team)    	  ((team)->name_of_team)
#define code(team)    	  ((team)->code_num)
#define matches(team)     ((team)->fixture)
#define title(league) 	  ((league)->title)
#define numb(league)      ((league)->number_of_teams)
#define teams_of(league)  ((league)->teams)
#define same(match)       ((match)->same_match)
#define opponent(match)   ((match)->opponent)
#define week(match)		  ((match)->week)
#define team(match)		  ((match)->team)
#define w(team)			  ((team)->w)
#define d(team)			  ((team)->d)
#define l(team)			  ((team)->l)
#define goals(team)		  ((team)->goals)
#define pts(team)		  ((team)->pts)

#define HOME 1
#define AWAY 2

typedef struct match
{
	int score[2];
	char *team,*opponent;
	char home_away;/* 2 for away // 1 for home*/
	struct match* next_match;
	struct match* prev_match;
	struct match* same_match;
	struct match* week;
}fixt ,*fixt_;

typedef struct team {
	char *name_of_team;
	int code_num;
	int w,d,l;
	int goals[2];
	int pts;
	struct team *next_team;
	struct team *prev_team;
	fixt_ fixture;
}team ,*team_;

typedef struct league{
	char *title;
	int number_of_teams;
	int code_num;
	team_ teams;
}league ,*league_ ;


void get_teams_file(league_ League);

int *first_matches(league_ League);

void fixture(league_ League);

void scores(league_ League);

void get_points(league_ League);

void sort_teams(league_ League);

void print_standing_table(league_ League);

#endif //FIXTURE_H_