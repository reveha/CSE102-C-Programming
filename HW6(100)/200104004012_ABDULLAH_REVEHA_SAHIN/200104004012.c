#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COLUMN 30


int dice();
int startGame();
void printMap(int game_area[ROW][COLUMN]);
void fill_array(int game_area[ROW][COLUMN]); // this function also calls printMap function!!

int main(){

	int game_area[ROW][COLUMN];
	fill_array(game_area);
	return 0;
}

int startGame(){
	
	int a;
	do{	
		a=rand()%7; // creating random numbers between [1,6]; to understand who start the game
	}while(a==0);
	
	return a;
}

int dice(){
	int a;
	do{
		a=rand()%7; // creating random numbers between [1,6];
	}while(a==0);
	return a;
}

void printMap(int game_area[ROW][COLUMN]){

//there is no problem printing it in %c mode it prints ascii table value 
	int i,j;
	
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){	
			if(game_area[i][j]=='1')  // these if statements printing the table with corrects colors !!!!
				printf("\033[0;33m%c",game_area[i][j]); 
			else if(game_area[i][j]=='2')
				printf("\033[0;34m%c",game_area[i][j]);
			else if(game_area[i][j]=='X')
				printf("\033[0;31m%c",game_area[i][j]);
			else if(game_area[i][j]=='_')
				printf("\033[0;32m%c",game_area[i][j]);
			else
				printf("\033[0;37m%c",game_area[i][j]);	
		}
			printf("\n");
	}
}

void fill_array(int game_area[ROW][COLUMN]){
	srand(time(NULL));
	int who_start,who_start2;
	int i,j;
	int counter[2]; // to keep dice
	counter[0]=0; // for player 1;
	counter[1]=0; // for player 2;
	int column[2]; // column[0] means player 1 columns, colum[1] means player 2 column
	int row[2];// row[0] means player 1 row, row[1] means player 2 row
	column[0]=1; // i assigned first column position of player 1
	column[1]=3; // i assigned first column position of player 2
	row[0]=1; // i assigned first row position of player 1
	row[1]=3; // i assigned first row position of player 2
	int back1=0; // to reverse counting, i mean if player 1 start to go back i said back1=1;
	int back2=0;// to reverse counting, i mean if player 2 start to go back i said back2=1;
	int g=0;
	int win1=0;//to understand player 1 won
	int win2=0;// to understand player 2 won
	printf("To start to game, players should dice and decide who is going to start first according to it....\n");
	do{
		printf("\033[0;33mPLAYER 1... press ENTER to dice");
		getchar();
		who_start=startGame(); // to get starting dice for player 1
		printf("DICE: %d\n",who_start);
		printf("\033[0;34mPLAYER 2... press ENTER to dice");
		getchar();
		who_start2=startGame(); // to get starting dice for player 2
		printf("DICE: %d\n",who_start2);
		if(who_start==who_start2){
			printf("\033[0;37mSame dice value.. Please try again.\n");
		}
	}while(who_start==who_start2);	
	if(who_start>who_start2){	
		printf("\033[0;37m *** PLAYER 1 will start the game... ***\n");
	}
	else{
		printf("\033[0;37m *** PLAYER 2 will start the game... ***\n");
	}
	while(win1==0 && win2==0){
		if(who_start>who_start2){ // player 1 starts the game i have to take the number for player 1 firstly	
				printf("\033[0;33mPLAYER 1... press ENTER to dice");
				getchar();
				counter[0]=dice();
				printf("DICE: %d\n",counter[0]);			
				if(back1==0){// that means player 1 is going to the right 
					column[0]+=counter[0];
				}
				else if(back1==1){ // that means player 1 has started to go left
					column[0]-=counter[0]; // i need to increase column of player 1
					if(column[0]<1){ // if the column less than 1 i need to say player 1 is on the game_area[i][1] column!!!
						row[0]+=column[0]-1; // i need to decrease 1 one more time because index is 1 
						column[0]=1; // column have to be 1 always when these if work
						if(row[0]<1){ // that means player 1 has won
							column[0]-=row[0]-1; // to get position of player 1 at the end of the game
							row[0]=1;
							win1=1; //player 1 won
						}
						else if(row[0]==2 || row[0]==1){
							win1=1; // player 1 won
						}
					}
				}
				if(column[0]>27){ // to understand player 1 has to move down (in column 27)
					row[0]+=column[0]-28; // i need to decrease 1 more time because index is 27
					column[0]=28; // column have to be 28
					if(row[0]>12){ // if row greater than 12 i can say player 1 will start go left!!
						back1=1; // back=1 to understand player 1 starts to move left line 85!!!!
						column[0]-=row[0]-13;
						row[0]=13;// player 1 row has to be 13
					}				
				}
				if(win1==1){
					printf("\n\033[0;33m ***PLAYER 1 WON THE GAME***\n");
				}
				// for player2 
				if(win1!=1){ // if player 1 won i do not need to look player 2 position
					printf("\033[0;34mPLAYER 2... press ENTER to dice");
					getchar();
					counter[1]=dice(); // to count player 2 dice
					printf("DICE: %d\n",counter[1]);
					if(back2==0){
						column[1]+=counter[1];// player 2 is moving right 
					}
					else if(back2==1){ // if player 2 has started to move left
						column[1]-=counter[1]; // decrease it
						if(column[1]<3){ // if column of player 2 less than 3  i need to say column of player 2 has to be 3 index
							row[1]+=column[1]-3;// i need to decrease 3 more because of the index !!
							column[1]=3;
							if(row[1]<3){ // if row less than 3  i need to say row of player 2 has to be 3 
								column[1]-=row[1]-3; // to get last position of the player 2
								row[1]=3;
								win2=1;// player 2 won
							}
							else if(row[1]==4 || row[1]==3){
								win2=1;// player 2 won
							}

						}
					}	
					if(column[1]>25){// to decrease row of player 2 when it arrives last column index !!!
						row[1]+=column[1]-26; // i got the position of the player 2
						column[1]=26; // column has to be 26
						if(row[1]>10){ // if row of the player 2 less than 10, i can understand it will start move left!!!
							back2=1; // to understand move left line 121!!!
							column[1]-=row[1]-11; // getting position
							row[1]=11;				
						}
					}
				}	
				if(win2==1){
					printf("\n\033[0;34m ***PLAYER 2 WON THE GAME***\n");
				}
		}
		// else part is same thing with the below, a difference is player 2 is starting the game!!!
		else{ // player 2 starts the game i have to take the number for player 2 firstly			
				printf("\033[0;34mPLAYER 2... press ENTER to dice");
				getchar();
				counter[0]=dice();
				printf("DICE: %d\n",counter[0]);				
				if(back2==0){
					column[1]+=counter[0];
				}
				else if(back2==1){
					column[1]-=counter[0];
					if(column[1]<3){
						row[1]+=column[1]-3;
						column[1]=3;	
						if(row[1]<3){						
							column[1]-=row[1]-3;
							row[1]=3;
							win2=1;
						}
						else if(row[1]==4 || row[1]==3){
							win2=1;
						}
					}
				}
				if(column[1]>25){
					row[1]+=column[1]-26;
					column[1]=26;
					if(row[1]>10){
						back2=1;
						column[1]-=row[1]-11;
						row[1]=11;				
					}
				}
				if(win2==1){
					printf("\n\033[0;34m ***PLAYER 2 WON THE GAME***\n");
				}
				if(win2!=1){
					printf("\033[0;33mPLAYER 1... press ENTER to dice");
					getchar();
					counter[1]=dice();
					printf("DICE: %d\n",counter[1]);
					if(back1==0){
						column[0]+=counter[1];
					}
					else if(back1==1){
						column[0]-=counter[1];
						if(column[0]<1){
							row[0]+=column[0]-1;
							column[0]=1;
							if(row[0]<1){
								column[0]-=row[0]-1;
								row[0]=1;
								win1=1;
							}
							else if(row[0]==2 || row[0]==1){
								win1=1;
							}
						}
					}
					if(column[0]>27){
						row[0]+=column[0]-28;
						column[0]=28;
						if(row[0]>12){
							back1=1;
							column[0]-=row[0]-13;
							row[0]=13;				
						}				
					}
				}	
				if(win1==1){
					printf("\n\033[0;33m ***PLAYER 1 WON THE GAME***\n");
				}
				
		}
		
			// these if statements is checking penalty points for player 1 and player 2
				if((row[0]==1 && column[0]==14)){
					column[0]-=2;
					printf("\033[0;33mPenalty for player 1 !!\n");
				}
				else if(row[0]==13 && column[0]==14){
					column[0]+=2;
					printf("\033[0;33mPenalty for player 1 !!\n");
				}
				else if(row[0]==7 && column[0]==28){
					row[0]-=2;
					printf("\033[0;33mPenalty for player 1 !!\n");
				}
				if((row[1]==3 && column[1]==10) || (row[1]==3 && column[1]==18)){
					column[1]-=2;
					printf("\033[0;34mPenalty for player 2 !!\n");
				}
				else if((row[1]==11 && column[1]==10) || (row[1]==11 && column[1]==18)){
					column[1]+=2;
					printf("\033[0;34mPenalty for player 2 !!\n");
				}
				else if((row[1]==5 && column[1]==26) || (row[1]==10 && column[1]==26)){
					row[1]-=2;
					printf("\033[0;34mPenalty for player 2 !!\n");
				}
		// end of the checking penalty points for players!!!
		
		for(i=0;i<ROW;i++){ // assigning table into array and printing it in this nested loop!!!
			for(j=0;j<COLUMN;j++){
				printf("\033[0;37m");
				// i do not need to explain this nested loop it is clear you can understand easily
				// according to the position of the table (i and j), i assigned some ascii table of char into the array!!
				if(i==row[0] && j==column[0]){
					game_area[i][j]='1';
				}
				else if(i==row[1] && j==column[1]){
					game_area[i][j]='2';
				}
				else if((i==2 && j==1) || (i==4 && j==3)){
					game_area[i][j]='_';
				}
				else if((i==1 && j==14) || (i==7 && j==28) || (i==13 && j==14) || (i==3 && j==10) || (i==3 && j==18) || (i==5 && j==26) || (i==10 && j==26) || (i==11 && j==10) || (i==11 && j==18)){
					game_area[i][j]='X';
				}
				else if(i==0 || i==14){
					game_area[i][j]='.';
				}
				else if(((i==1 || i==13) && j==0) || ((i==1 || i==13) && j==29)){
					game_area[i][j]=':';
				}
				else if(((i==2 || i==12) && j==0) || ((i==2 || i==12) && j==29)){
					game_area[i][j]=':';
				}
				else if((i==2 || i==12) && (j>1 && j<28)){
					game_area[i][j]='.';
				}
				else if((i==3 || i==4 || i==10 || i==11) && (j==0 || j==2 || j== 27 || j==29)){
					game_area[i][j]=':';
				}
				else if((i==4 || i==10) && (j>3 && j< 26)){
					game_area[i][j]='.';
				}
				else if((i>4 && i<10) && (j==0 || j==2 || j==4 || j==29 || j==27 || j==25)){
					game_area[i][j]=':';
				}
				else{
					game_area[i][j]=' ';
				}				
			}
		}
		printMap(game_area); // printing table with correct colors and position!!
	}		
}
