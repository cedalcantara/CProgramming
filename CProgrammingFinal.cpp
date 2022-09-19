#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

void teamvp();
void win();
void highest();
void input();
void exit();

int teams[2][12],aplyr,bplyr,ascr,bscr;

void main()
{

int option;
//clrscr();

//gotoxy(33,3);
printf("Main Menu\n");
//gotoxy(21,8);
printf("(1) Input Scores\n");
//gotoxy(21,10);
printf("(2) Most Valuable Player\n");
//gotoxy(21,12);
printf("(3) Winner of the Game\n");
//gotoxy(21,14);
printf("(4) Highest Pointers\n");
//gotoxy(21,16);
printf("(5) Exit");
//gotoxy(15,21);
printf("Input Choice: ");
scanf("%d", &option);

switch(option){

    case 1: input();
			break;
	case 2: teamvp();
			break;
	case 3: win();
			break;
	case 4: highest();
			break;
	default: exit();
			break;
			}
getch();
}

void input()
{
 int plyr,team,scr;
 int teams[2][12]={0};
// clrscr();
 //gotoxy(23,9);
 printf("BASKETBALL GAME");

 do{
   do{//gotoxy(28,11);
      printf("Select Team (1 or 2) : ");
      scanf("%d",&team);
     }while(team ==1 && team ==2);
   do{//gotoxy(28,13);
      printf("Select Player (1-12) : ");
      scanf("%d",&plyr);
     }while(plyr < 0 || plyr > 12);
   do{//gotoxy(28,15);
      printf("Input Score (1-3)   : ");
      scanf("%d",&scr);
     }while(scr > 3);
	 //clrscr();
	 //gotoxy(23,9);
	 printf("BASKETBALL GAME");
   if(team == 1){
      teams[0][plyr-1] += scr;}
   else{teams[1][plyr-1] += scr;}
  }while(team !=0 && plyr != 0 && scr!=0);
  main();
getch();
}

void teamvp()
{

 int mvp[2][12],teams[2][12];
 int i,j,c;
 int first=0,mid,last=11,target;
 int first2=0,mid2,last2=11,target2;
 int aplyr,bplyr,ascr,bscr;

	//team 1 mvp
	for(c=0;c<12;c++){
		mvp[0][c]=teams[0][c];
			 }

	for(c = 0; c<=11; c++)
	{
		i=c;
		while (i>0 && mvp[0][i] < mvp[0][i-1]){

			ascr = mvp[0][i];
			mvp[0][i]=mvp[0][i-1];
			mvp[0][i-1]=ascr;

		}
	}
	target=mvp[0][11];
	while (first<=last){
		mid =(first+last)/2;
		if (target>teams[0][mid]){
			first=mid+1;
		}
		else if(target<teams[0][mid]){
			last=mid-1;
		}
		else
			first=last+1;
	}
	if (target==teams[0][mid]){
		aplyr=mid;
		}

	//team 2 mvp
	for(c=0;c<12;c++){
		mvp[1][c]=teams[1][c];
				     }

	for(c = 0; c<=11; c++)
	{
		while (i>0 && mvp[1][i] < mvp[1][i-1])
		{
			bscr = mvp[1][i];
			mvp[1][i]=mvp[1][i-1];
			mvp[1][i-1]=bscr;
		}
	}
	target2=mvp[1][11];
	while (first2<=last2){
		mid2 =(first2+last2)/2;
		if (target2>teams[1][mid2]){
			first2=mid2+1;
		}
		else if(target2<teams[1][mid2]){
			last2=mid2-1;
		}
		else
			first2=last2+1;
	}
	if (target2==teams[1][mid2]){
		bplyr=mid2;
		}


 //clrscr();
 //gotoxy(33,4);
	printf("Most Valuable Player(MVP)");
 //gotoxy(22,7);
	printf("Player %d with %d point/s from Team 1 and",aplyr,ascr);
 //gotoxy(24,8);
	printf("Player %d with %d point/s from Team 2",bplyr,bscr);
getch();
 }

void win()
{
 int teams[2][12];
 int k;
 int t1scr = 0, t2scr=0;

	 for(k=0;k<12;k++)
		{
		t1scr=t1scr+teams[0][k];
		t2scr=t2scr+teams[1][k];
		}
    // clrscr();
     //gotoxy(39,13);
     printf("Result");
	if(t1scr>t2scr)
	{
		//gotoxy(29,14);
		printf("Team 1 Won! with %d Points",t1scr);
	}
	else if(t1scr<t2scr)
	{
		//gotoxy(29,14);
		printf("Team 2 Won! with %d Points",t2scr);
	}
	else
	{
		 //gotoxy(17,14);
		 printf("The Result is Draw with Both teams Scoring %d Point/s",t1scr);
	}
getch();
}

void highest()
{
 int ascr,bscr,aplyr,bplyr;
 //clrscr();
 //gotoxy(29,10);
 printf("Highest Scorer of the Game");
   if(ascr!=0 || bscr!=0)
      {
	if(ascr>bscr)
	{
		//gotoxy(25,11);
		printf("Player %d with %d point/s from Team 1",aplyr,ascr);
	}
	else if(ascr==bscr)
	{
	  //gotoxy(14,11);
	  printf("Player %d of Team 1 and Player %d of Team 2 with %d point/s",aplyr,bplyr,ascr);
	}
	else if(bscr>ascr)
	{
	    //gotoxy(25,11);
	    printf("Player %d with %d point/s from Team 2",bplyr,bscr);
	}
      }
   else
      {
	//gotoxy(39,11);
	printf("NONE");
      }
getch();
 }

void exit()
{
  // gotoxy(25,10);
   printf ("THANKS FOR USING THE PROGRAM");
  // delay(1500);

}

