#include "fixture.h"

char *readLine(FILE *f){
	char *k=NULL;
	int i=0;
	while(1){
		char c;
		if(fscanf(f,"%c",&c)==-1)return k;
		if(c=='\n')return k;
		i++;
		k=realloc(k,(i)*sizeof(char));
		*(k+i-1)=c;

	}
}

void get_teams_file(league_ League){
	int k;
	unsigned int code=code(League)*100;
	char *p;
	team_ name_taker;
	teams_of(League)=malloc(sizeof(team));
	name_taker=teams_of(League);
	FILE *f=fopen("teams.txt","r");
	name(name_taker)=readLine(f);
	prevt(name_taker)=NULL;
	w(name_taker)=d(name_taker)=l(name_taker)=goals(name_taker)[0]=goals(name_taker)[1]=pts(name_taker)=0;
	code(name_taker)=(++code);
	nextt(name_taker)=NULL;
	matches(name_taker)=NULL;
	numb(League)++;
	while(p=readLine(f)){
		team_ newt;
		int i=0;
		newt=malloc(sizeof(team));
		nextt(newt)=NULL;
		matches(newt)=NULL;
		w(newt)=0; d(newt)=0 ; l(newt)=0 ; goals(newt)[0]=0; goals(newt)[1]=0; pts(newt)=0;
		prevt(newt)=name_taker;
		nextt(name_taker)=newt;
		code(newt)=(++code);
		name(newt)=malloc(1);
		while(*(p+i)){
			*(name(newt)+i)=*(p+i);
			i++;
			name(newt)=realloc(name(newt),(i+1));
			
		}
		name_taker=nextt(name_taker);
		numb(League)++;
	}
}
void name_adder(char *give, char **take){
	int i=0;
	*take=malloc(i+1);

	while(*(give+i)){
		*(*take+i)=*(give+i);
		i++;
		*take=realloc(*take,i+1);
	}
}

int *first_matches(league_ League){
	team_ home, away;
	fixt_ home_link=NULL, away_link=NULL;
	int Lcode=code(League);
	int rand_team;
	int count_of_matches=0;
	int *arr,i=0;
	home=teams_of(League);
	arr=malloc(numb(League)*sizeof(int));
	while(count_of_matches<numb(League)/2){
		if(home==NULL || nextt(home)==NULL)break;
		away=nextt(home);
		do{
		rand_team=rand()%numb(League) +1;
		rand_team+=100*Lcode;
		}while(rand_team<=code(home));
		while(away){

			if(rand_team==code(away)){
				if(matches(away)){
					away=nextt(home);
					do{
					rand_team=rand()%numb(League) +1;
					rand_team+=100*Lcode;
					}while(rand_team<=code(home));
					continue;
				}
				fixt_ home_match,away_match;
				matches(away)=malloc(sizeof(fixt));
				matches(home)=malloc(sizeof(fixt));
				home_match=matches(home);
				away_match=matches(away);
				nextm(home_match)=NULL;prevm(home_match)=NULL;
				nextm(away_match)=NULL;prevm(away_match)=NULL;
				same(home_match)=away_match;
				same(away_match)=home_match;
				name_adder(name(home),&opponent(away_match));
				name_adder(name(home),&team(home_match));
				name_adder(name(away),&opponent(home_match));
				name_adder(name(away),&team(away_match));
				ha(home_match)=HOME;
				ha(away_match)=AWAY;
				score(home_match)[0]=score(home_match)[1]=score(away_match)[0]=score(away_match)[1]=-1;
				if(home_link){
					week(home_link)=home_match;
				}
				if(away_link){
					week(away_link)=away_match;
				}
				home_link=home_match;
				away_link=away_match;
				week(home_match)=NULL;
				week(away_match)=NULL;
				*(arr+i)=code(home);*(arr+i+1)=code(away);
				i+=2;
				count_of_matches++;
			}
			away=nextt(away);
		}		
		do{
			home=nextt(home);
		}while(home && matches(home));
	}
	return arr;
}

void mixt(int **arr,int length){
	int *p=*arr;
	int i,tmp1,tmp2;

	tmp1=*(p+2);
	*(p+2)=*(p+1);
	for(i=1;i<length-2;i++){
			if(i%2==0){
				tmp2=*(p+i+2);
				*(p+i+2)=tmp1;
				tmp1=tmp2;}
			
			else{
				*(p+i)=*(p+i+2);
			}
		

	}
	*(p+length-1)=tmp1;
}

void fixture(league_ League){
	int *arr,holder,second_half=0;
	team_ teams;
	teams=teams_of(League);

	arr=first_matches(League);
	holder=arr[1];
	mixt(&arr,numb(League));

	while(second_half<2){
		int i;
		fixt_ home_link=NULL,away_link=NULL;
		for(i=0;i<numb(League);){
			fixt_ home_match,away_match,next_home,next_away;
			team_ tmp,home=NULL,away=NULL;
			tmp=teams;
			while(tmp){
				if(code(tmp)==*(arr+i)){home=tmp;}
				if(code(tmp)==*(arr+i+1)){away=tmp;}
				if(home && away){i+=2;break;}
				tmp=nextt(tmp);
			}
			home_match=matches(home);
			away_match=matches(away);
			while(nextm(home_match))	home_match=nextm(home_match);
			while(nextm(away_match))	away_match=nextm(away_match);
			nextm(home_match)=malloc(sizeof(fixt));next_home=nextm(home_match);
			nextm(away_match)=malloc(sizeof(fixt));next_away=nextm(away_match);
		
			nextm(next_home)=NULL;prevm(next_home)=home_match;
			nextm(next_away)=NULL;prevm(next_away)=away_match;
			same(next_home)=next_away;
			same(next_away)=next_home;
			name_adder(name(home),&opponent(next_away));
			name_adder(name(home),&team(next_home));
			name_adder(name(away),&opponent(next_home));
			name_adder(name(away),&team(next_away));
			if(second_half<1){
				ha(next_home)=HOME;
				ha(next_away)=AWAY;
			}	
			else{
				ha(next_home)=AWAY;
				ha(next_away)=HOME;
			}

			score(next_home)[0]=score(next_home)[1]=score(next_away)[0]=score(next_away)[1]=-1;
			if(home_link){
				week(home_link)=next_home;
			}
			if(away_link){
				week(away_link)=next_away;
			}
			home_link=next_home;
			away_link=next_away;
			week(next_home)=NULL;
			week(next_away)=NULL;

		}

		mixt(&arr,numb(League));
		if(second_half<2 &&arr[1]==holder){
			second_half++;
		}
	
	}
}

void sort_teams(league_ League){
	team_ teams;
	int flag=1;
	while(flag){
		flag=0;
		teams=teams_of(League);

		while(nextt(teams)){

			if(pts(teams)<pts(nextt(teams))){
				team_ tmpnext=NULL,tmpprev=NULL;
				tmpnext=nextt(teams);
				tmpprev=prevt(teams);
				nextt(teams)=nextt(tmpnext);
				prevt(teams)=tmpnext;
				if(tmpprev)nextt(tmpprev)=tmpnext;
				else teams_of(League)= tmpnext;
				if(nextt(tmpnext))prevt(nextt(tmpnext))=teams;
				prevt(tmpnext)=tmpprev;
				nextt(tmpnext)=teams;
				flag=1;
				continue;
			}
			if(pts(teams)==pts(nextt(teams))){
				int avg1,avg2;
				avg1=goals(teams)[0]-goals(teams)[1];
				avg2=goals(nextt(teams))[0]-goals(nextt(teams))[1];
				if(avg1>=avg2){
					teams=nextt(teams);
					continue;
				}
				else{
					team_ tmpnext=NULL,tmpprev=NULL;
					tmpnext=nextt(teams);
					tmpprev=prevt(teams);
					nextt(teams)=nextt(tmpnext);
					prevt(teams)=tmpnext;
					if(tmpprev)nextt(tmpprev)=tmpnext;
					else teams_of(League)=tmpnext;
					if(nextt(tmpnext))prevt(nextt(tmpnext))=teams;
					prevt(tmpnext)=tmpprev;
					nextt(tmpnext)=teams;
					flag=1;
					continue;
				}
			}
			teams=nextt(teams);
		}

	}
}

void print_standing_table(league_ League){
	int i=1;
	FILE *f;
	f=fopen("STANDINGS","w");
	team_ teams=teams_of(League);
	fprintf(f,"%3s%25s|%4s|%3s|%3s|%3s|%7s|%3s\n","","teams","pts","w","d","l","goals","avg" );
	{int i; for(i=0;i<57;i++)fprintf(f,"_");fprintf(f, "\n");}
	while(teams){
		fprintf(f,"%2d.%25s|%4d|%3d|%3d|%3d|%3d|%3d|%3d\n",i++,name(teams),pts(teams),w(teams),d(teams),l(teams),goals(teams)[0],goals(teams)[1],goals(teams)[0]-goals(teams)[1]);
		teams=nextt(teams);
	}
	fclose(f);
}

void get_points(league_ League){
	team_ teams=teams_of(League);
	while(teams){
		fixt_ matches_;
		w(teams)=0; d(teams)=0 ; l(teams)=0 ; goals(teams)[0]=0; goals(teams)[1]=0; pts(teams)=0;

		matches_=matches(teams);
		while(matches_){
			if(score(matches_)[0]==-1){break;}
			if(ha(matches_)==HOME){

				if(score(matches_)[0]>score(matches_)[1]){
					pts(teams)+=3;
					w(teams)++;
				}
				else if(score(matches_)[0]==score(matches_)[1]){
					pts(teams)++;
					d(teams)++;
				}
				else l(teams)++;

				goals(teams)[0]+=score(matches_)[0];
				goals(teams)[1]+=score(matches_)[1];
			}
			else{
				if(score(matches_)[1]>score(matches_)[0]){
					pts(teams)+=3;
					w(teams)++;
				}
				else if(score(matches_)[0]==score(matches_)[1]){
					pts(teams)++;
					d(teams)++;
				}
				else l(teams)++;

				goals(teams)[0]+=score(matches_)[1];
				goals(teams)[1]+=score(matches_)[0];
			}

			matches_=nextm(matches_);
		}
		teams=nextt(teams);	

	}
}

void get_score(league_ League,int week_num){
	team_ teams;
	fixt_ week;
	int i;
	teams=teams_of(League);
	week=matches(teams);
	for(i=1;i<week_num;i++)week = nextm(week);
	while(week){
		int h=0,a=0;
		fixt_ same;
		if(ha(week)==HOME){
			printf("match : %s - %s\n",team(week),opponent(week) );
			scanf("%d %d",&h,&a);
			score(week)[0]=h;
			score(week)[1]=a;
			same=same(week);
			score(same)[0]=h;
			score(same)[1]=a;
			
		}	
		if(ha(week)==AWAY){
			printf("match : %s - %s\n",opponent(week),team(week) );
			scanf("%d %d",&h,&a);
			score(week)[0]=a;
			score(week)[1]=h;
			same=same(week);
			score(same)[0]=a;
			score(same)[1]=h;
			
	}
		get_points(League);
		sort_teams(League);
		print_standing_table(League);
		

		week=week(week); 
	}


}
void scores(league_ League){
	int week_num=2*(numb(League)-1);
	int i;
	for(i=0;i<week_num;i++){
		get_score(League,i+1);
		}
}
