// CRICKET SCORING SYSTEM //
// 19K-0172	ALI FAROOQ
// 19K-1338	JARI SAJJAD
// 19K-0344	HASSAN MUSTAFA

#include<stdio.h>
#include <stdlib.h> 
#include<string.h>
#include<stdbool.h>

int totalruns2(int[]);
void checkruns(int);
float strikerate(int , int);
double requiredrate(int ,int ,int );
float runrate(int , int);
int addruns(int players1,int runs);
void endinnings(char[],int ,int);
int totalruns(int []);
int main () 
{
	char team1[100], team2[100], a[11],b[11];
	char players1[11][100], players2[11][100];
	int players1scoreboard[11][200],players2scoreboard[11][200];
	int i,j,runs1,runs2,overs,TR1,TR2,OR,c,out1=0,out2=0,ballhit=0,playerruns1[11][200],countplayer1=0,playerruns2[11][200],countplayer2=0,player1=0,player2=0,playear3=0,player4=1;
	bool player1bool=true,player2bool=false;
	float SR,RR;
	bool freehit=false;
	
	FILE *fp;
	fp=fopen("project.txt","a");
	
	for(i=0;i<11;i++){
		for(j=0;j<200;j++){
			playerruns1[i][j]=-1;
			playerruns2[i][j]=-1;
			
		}
	}
	
	printf("\t\tWELCOME TO SCORING SYSTEM OF CRICKET\n");
	fprintf(fp,"\t\tWELCOME TO SCORING SYSTEM OF CRICKET\n\n");
	printf("Enter the name of team 1:\t");
	gets(team1);
	fprintf(fp,"Team 1 : %s\n", team1);
	printf("Enter the name of team 2:\t");
	gets(team2);
	fprintf(fp,"Team 2 : %s\n", team2);
	puts(team1);
	puts(team2);
	printf("Enter # overs:");
	scanf("%d", &overs);
	fprintf(fp,"Overs : %d\n", overs);
	int playingplayer=0;
int playingcounter=0;
	
	 //INPUT NAME OF PLAYERS OF BOTH TEAMS //
	for (i=0; i<=10; i++)
	{
		printf("Player name of team1  player %d:",i+1);
		fflush(stdin);
		gets(players1[i]);

	}
	printf("\n");
	
	for (i=0; i<=10; i++)
	{
		printf("Player name of team2 player %d:",i+1);
		fflush(stdin);
		gets(players2[i]);
	
	}
	for (i=0; i<=10; i++)
	{
	/*	printf("\nPlayer name of team1 player %d:",i+1);
		puts(players1[i]); */
		fprintf(fp,"Team 1, Player %d : %s\n", i+1, players1[i]);
	}
	printf("\n");
	for (i=0; i<=10; i++)
	{
	/*	printf("\nPlayer name of team2 player %d:",i+1);
		puts(players2[i]); */
		fprintf(fp,"Team 2, Player %d : %s\n", i+1, players2[i]);
	}
	printf("\n");
	printf("press 1 for 1 run\n press 2 for 2 runs\n press 3 for 3 runs\n press 4 for 4 runs\n press 5 for out\n press 6 for 6\n press 7 for wide ball\n press 8 for no ball");
	printf("\n............................1st Inning Starts............................\n");
	fprintf(fp,"\n\n............................1st Inning Starts............................\n");
	 //BALLS AND OVERS //
	player1=0,player2=1;
	for (i=1; i<=overs; i++)
	{
			if(out1==11){
				break;
			}
		OR = 0;
		for(j=1; j<=6; j++)
		{
			if(out1==10){
				break;
			}
	
			printf("Enter runs taken on this ball # %d: ", j);
			fflush(stdin);
			scanf("%d", &ballhit);
//				ballhit=rand()%7;
				printf("%d\n",ballhit);
	     		OR = OR + runs1;
			
				
				
		//		scanf("%d",&ballhit);
				printf("what happened on this ball %d\n" ,ballhit);
				fprintf(fp,"what happened on this ball %d\n" ,ballhit);
			
		TR1=0;
		TR1 = TR1 + ballhit;

if(player1bool){
	playingplayer=player1;
	playingcounter=countplayer1;
}else{
	playingplayer=player2;
	playingcounter=countplayer2;
}
				switch(ballhit)
				{
					case 1:
						runs1=ballhit+runs1;
						playerruns1[playingplayer][playingcounter]=ballhit;
							
					if(player1bool){
						countplayer1++;
						player1bool=false;
					}else{
						countplayer2++;
						player1bool=true;
						
					}
						
						break;
					case 2:
						runs1=ballhit+runs1;
		 				playerruns1[playingplayer][playingcounter]=ballhit;
					
					if(player1bool){
						countplayer1++;
					}else{
						countplayer2++;
						
					}
						break;
					case 3:
						runs1=ballhit+runs1;
						playerruns1[playingplayer][playingcounter]=ballhit;
					
					
					
					if(player1bool){
						countplayer1++;
						player1bool=false;
					}else{
						countplayer2++;
						player1bool=true;
					}
					break;
					case 4:
						runs1=ballhit+runs1;
						playerruns1[playingplayer][playingcounter]=ballhit;
					
					if(player1bool){
						countplayer1++;
					}else{
						countplayer2++;
						
					}
					break;
					case 5:
						printf("\nout\n");
						fprintf(fp,"\nout\n");
						out1++;
						if(player1bool)
						{
							player1=out1+1;
							playerruns1[playingplayer][playingcounter+1]=-1;
							countplayer1=0;
							
						}
						else
						{
							player2 = out1+1;
							playerruns1[playingplayer][playingcounter+1]=-1;
							countplayer2=0;
						}
						break;
					case 6:
						runs1=ballhit+runs1;
				playerruns1[playingplayer][playingcounter]=ballhit;
					
					if(player1bool){
						countplayer1++;
					}else{
						countplayer2++;
						
					}
								
					break;
					case 7:
						printf("\nwide ball\n");
						fprintf(fp, "\nwide ball\n");
						j--;
						runs1++;
						break;
					case 8:
						printf("\nno ball\n");
						fprintf(fp,"\nno ball\n");
						j--;
						runs1++;
						break;
			
						
								printf("total runs on the ball %d\n",runs1);				
								fprintf(fp,"total runs on the ball %d\n",runs1);				
				}
				//addruns(players1,runs);		
		}
	
		RR = runrate(runs1,overs);
		if(out1==10)
		{
			printf("all team out");
			fprintf(fp,"all team out");
			break;
		}
	}
//printf("Total runs of team 1 : %d", TR1);
//fprintf(fp,"Total runs of team 1 : %d", TR1);
for(i=0;i<out1;i++)
{
	int k=0;	
	printf("%s ",players1[i]);
	fprintf(fp, "%s ",players1[i]);
	while(playerruns1[i][k]!=-1)
	{
		
		printf("%d ",playerruns1[i][k]);
		fprintf(fp, "%d ",playerruns1[i][k]);
		k++;

	}
		printf(" totalruns %d",totalruns(playerruns1[i]));
		fprintf(fp, " totalruns %d",totalruns(playerruns1[i]));
	printf("\n");
	fprintf(fp,"\n");
}
	printf("\n\nTotal runs of team 1 : %d\n\n", runs1);
	fprintf(fp,"Total runs of team 1 : %d\n\n", runs1);
	printf("............................Second Inning Starts............................\n");
	printf("Target for %s is %d in %d overs ",team2,(runs1)+1,overs);
	printf("\nRequired Runrate %.2f",requiredrate(runs1,overs,0));
	fprintf(fp,"............................Second Inning Starts............................\n");
	fprintf(fp,"Target for %s is %d in %d overs ",team2,runs1,overs);
	fprintf(fp,"\nRequired Runrate %.2f",requiredrate(runs1,overs,0));

		
			player1=0,player2=1;
	for (i=1; i<=overs; i++)
	{
			/*if(out2==10){
				break;
			}
		OR = 0;*/
		for(j=1; j<=6; j++)
		{
			if(out2==11){
				break;
			}
	
			fflush(stdin);
printf("Enter runs taken on this ball # %d: ", j);
			fflush(stdin);
			scanf("%d", &ballhit);
//				ballhit=rand()%7;
				printf("%d\n",ballhit);
	     		OR = OR + runs2;
			
				
				
		//		scanf("%d",&ballhit);
				printf("what happened on this ball %d\n" ,ballhit);
				fprintf(fp,"what happened on this ball %d\n" ,ballhit);
			
		TR2 = TR2 + ballhit;

if(player1bool){
	playingplayer=player1;
	playingcounter=countplayer1;
}else{
	playingplayer=player2;
	playingcounter=countplayer2;
}
				switch(ballhit)
				{
					case 1:
						runs2=ballhit+runs2;
						playerruns2[playingplayer][playingcounter]=ballhit;
							
					if(player1bool){
						countplayer1++;
						player1bool=false;
					}else{
						countplayer2++;
						player1bool=true;
						
					}
						
						break;
					case 2:
						runs2=ballhit+runs2;
		 				playerruns2[playingplayer][playingcounter]=ballhit;
					
					if(player1bool){
						countplayer1++;
					}else{
						countplayer2++;
						
					}
						break;
					case 3:
						runs2=ballhit+runs2;
						playerruns2[playingplayer][playingcounter]=ballhit;
					
					
					
					if(player1bool){
						countplayer1++;
						player1bool=false;
					}else{
						countplayer2++;
						player1bool=true;
					}
					break;
					case 4:
						runs2=ballhit+runs2;
						playerruns2[playingplayer][playingcounter]=ballhit;
					
					if(player1bool){
						countplayer1++;
					}else{
						countplayer2++;
						
					}
					break;
					case 5:
						printf("\nout\n");
						fprintf(fp,"\nout\n");
						out2++;
						if(player1bool)
						{
							player1=out2+1;
							playerruns2[playingplayer][playingcounter+1]=-1;
							countplayer1=0;
							
						}
						else
						{
							player2 = out2+1;
							playerruns2[playingplayer][playingcounter+1]=-1;
							countplayer2=0;
						}
						break;
					case 6:
						runs2=ballhit+runs2;
				playerruns2[playingplayer][playingcounter]=ballhit;
					
					if(player1bool){
						countplayer1++;
					}else{
						countplayer2++;
						
					}
								
					break;
					case 7:
						printf("\nwide ball\n");
						fprintf(fp,"\nwide ball\n");
						j--;
						runs2++;
						break;
					case 8:
						printf("\nno ball\n");
						fprintf(fp, "\nno ball\n");
						j--;
						runs2++;
						break;
			
						
						printf("total runs on the ball %d\n",runs2);				
						fprintf(fp,"total runs on the ball %d\n",runs2);
				}
				//addruns(players1,runs);
		}
		RR = runrate(runs2,overs);
		if(out2==10)
		{
			printf("all team out");
			fprintf(fp,"all team out");
			break;
		}
	}	

//printf("Total Runs of team 2 : %d", TR2);
//fprintf(fp,"Total runs of team 2 : %d", TR2);

	printf("\n");
	fprintf(fp,"\n");

	
	
	printf("\n\nTotal runs of team 2 : %d\n\n", (runs2)-1);
	fprintf(fp,"Total runs of team 2 : %d\n\n", (runs2)-1);
	
	if(runs1 > runs2)
	{
		printf("The winner is Team %s", team1);
		fprintf(fp,"The winner is Team %s", team1);	
	}
	if(runs2 > runs1)
	{
		printf("The winner is Team %s", team2);
		fprintf(fp,"The winner is Team %s", team2);	
	}

	printf("\n\t\t..........MATCH HAS ENDED..........\n\n");
	fprintf(fp,"\n\t\t..........MATCH HAS ENDED..........\n\n");
	fclose(fp);
}
void checkruns(int x){
	FILE *fp;
	fp = fopen("project.txt", "a");
	printf("%d",x);
	fprintf(fp, "%d",x);
	fclose(fp);
}
float runrate(int runs,int over){
	int rr;
	rr = runs/over;
	return (rr);
}


double requiredrate(int target,int over,int runs){
	return (target-runs)/over;
}
float strikerate(int playerrun,int ballsplayed)
{
	float SS;
	SS = playerrun / ballsplayed ;
	printf("Strikerate : %f", SS);
}


int totalruns(int runs[40])
{
	int sum=0,i=0;
	while(runs[i]!=-1)
	{
		sum=sum+runs[i];
		i++;
	}
	return (sum);
	
}
int totalruns2(int runs[40])
{
	int sum=0,i=0;
	while(runs[i]!=-1)
	{
		sum=sum+runs[i];
		i++;
	}
	return (sum);
	
}
