#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define ROW 15
#define COLUMN 15

/*
	0 means horizontally left to right
	1 means horizontally right to left
	2 means vertically up to down
	3 means vertically down to up
	4 means diagonally left up to right down
	5 means diagonally right up to left down
	6 means left down to right up
	7 means right down to left up
	*/

void rand_select(int txt_index[7]); // to get random values for which word will be taken from txt file (random indexes)
void select_words(char str[7][15], int txt_index[7]); // this is taking words according to the numbers returned
void fill_starting_points_and_direction(int starting_row[7], int starting_column[7], int dirx[7]);// this function determines the starting row and column for every word also the direction
void fill_table(int dir[7],int board[ROW][COLUMN],char str[7][15], int starting_row[7], int start_column[7]); // this function fills the board which is printed the screen
void print_table(int board[ROW][COLUMN]); // this function prints the table
void gameplay(int board[ROW][COLUMN],char str[7][15],int dir[7],int starting_row[7],int starting_column[7]); // this function for user gameplay
void fill_X(int board[ROW][COLUMN],int dir, int row, int col, char str2[15]); // this function fills in the board with 'X' on correct points and directions
int direction(); //returns a number between [0,7]
int rand_row(); //returns a number between [0,14]
int rand_column(); // returns a number between [0,14]
int rand_char(); // returns a number between [98,123]

int main(){
	srand(time(NULL));
	char str[7][15]; // my words are kept in this string array
	int txt_index[7]; // my words indexes are kept in this array
	int board[ROW][COLUMN]; // my board
	int starting_row[7]; // kept starting row points
	int starting_column[7]; // kept starting column points
	int dir[7]; // kept direction of the words
	rand_select(txt_index); // i got the indexes of the words 
	select_words(str,txt_index); // i got the words from the txt file
	for(int i=0;i<7;i++){
		printf("%s\n",str[i]); // i printed for you to understand words
	}
	fill_starting_points_and_direction(starting_row,starting_column,dir); // i got the starting points and directions for every word
	fill_table(dir,board,str,starting_row,starting_column); // i filled the table with correct points and directions
	gameplay(board,str,dir,starting_row,starting_column); // this is our game, this function also calss print_table() function
	printf("\n");	
		for(int i=0;i<7;i++){
		printf("%d. word '%s' direction : %2d		row: %2d		col :%2d\n",i,str[i],dir[i],starting_row[i],starting_column[i]);
	}
	
	return 0;
}
int rand_row(){
	int row=rand()%15;
	return row;
}
int rand_column(){
	int column=rand()%15;
	return column;
}
int rand_char(){
	int ch;
	
	do{
		ch=rand()%123;
	}while(ch<97);
	
	return ch;
}
int direction(){
	int a;
	a=rand()%8; 
	/*
	0 means horizontally left to right
	1 means horizontally right to left
	2 means vertically up to down
	3 means vertically down to up
	4 means diagonally left up to right down
	5 means diagonally right up to left down
	6 means left down to right up
	7 means right down to left up
	*/
	return a;
}
void rand_select(int txt_index[7]){
	int i,j;
	for(i=0;i<7;i++){
		txt_index[i]=rand()%50;
		if(txt_index[i]==0){
			txt_index[i]++;
		}
	}
	for(i=0;i<7;i++){ // i need to check every word if there is same word in my string array
		for(j=0;j<i;j++){
			if(txt_index[i]==txt_index[j]){
				txt_index[j]=rand()%50;
				if(txt_index[j]==0){
					txt_index[j]++;
				}
			}
		}
	}
}

		
void select_words(char str[7][15], int txt_index[7]){
	FILE *ptr=fopen("wordlist.txt","r");
	int c=0;
	int i=0;
	int index=0; // to keep in str string
	
	while(c<7){
		for(i=0;i<txt_index[index];i++){
			fscanf(ptr,"%s",str[index]); // i got the words
		}
		index++;
		c++;
		rewind(ptr); 
	}
	fclose(ptr);
	
}

void fill_starting_points_and_direction(int starting_row[7], int starting_column[7], int dir[7]){
	int i;
	for(i=0;i<7;i++){
		starting_row[i]=rand_row();
		starting_column[i]=rand_column();
	}
	for(i=0;i<7;i++){
		dir[i]=direction();
	}
	// this function is very simple you can understand
}
void print_table(int board[ROW][COLUMN]){ // printing table in this function 
	int i,j;
	printf("\n");
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(board[i][j]=='X'){
				printf("\033[0;33m%c ",board[i][j]);
			}
			else{
				printf("\033[0;37m%c ",board[i][j]);
			}	
		}
		printf("\n");
	}
	printf("\n");
}


void fill_table(int dir[7],int board[ROW][COLUMN],char str[7][15], int starting_row[7], int starting_column[7]){
	/*
	i need to check every direction to get correct result
	for every direction there is different way for the letters to be kept in the board
	*/
	int i,j;
	int check=1;
	int col,row;
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			board[i][j]=' ';
		}
	}
	int counter=0;
	while(counter<7){
		if(dir[counter]==0){ // that means right to left
			col=starting_column[counter]; // i assigned starting_column into temporary col variable
			row=starting_row[counter]; // i assigned starting_row into temporary row variable 
			for(i=0;i<strlen(str[counter]);i++){ 
				if(starting_column[counter]+strlen(str[counter])>15){
				// this if statement means the word did not fit into the table
					check=0;
					starting_row[counter]=rand_row(); // i got the starting row again
					starting_column[counter]=rand_column(); // i got the starintg column again
					dir[counter]=direction(); // i got the direction of the word again 
					col=starting_column[counter]; // i assigned new column into temporary col variable 
					row=starting_row[counter]; // i assigned new row into temporary row variable 
					counter--; // i need to check again same index so i decreased counter 
					break; // exit the loop 
				}
				else if(board[starting_row[counter]][col]!=' '){
				// this if statements means there is an collusion with another word
				// and i did same operation with below !!
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					col=starting_column[counter];
					row=starting_row[counter];
					counter--;
					break;
				}
				col++; 
				// since the direction of the word left to right i increased just column of the word
			}
			if(check==1){
			// if check is 1 that means there is no any error to keep word into board
				col=starting_column[counter]; // to start correct points
				for(i=0;i<strlen(str[counter]);i++){
					board[starting_row[counter]][col]=str[counter][i];
					col++; // direction is left to right !!!
				}
			}	
		}
		else if(dir[counter]==1){
		// that means right to left 
			col=starting_column[counter];
			row=starting_row[counter];
			for(i=0;i<strlen(str[counter]);i++){
				if(starting_column[counter]-strlen(str[counter])<-1){
				// this if statement means the word did not fit into the table
				// same operations with below !!!
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					col=starting_column[counter];
					row=starting_row[counter];
					counter--;
					break;
				}
				else if(board[row][col]!=' '){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					col=starting_column[counter];
					row=starting_row[counter];
					counter--;
					break;
				}	
				col--; 
				// i need to decrease column of the word because word is going to right to left !!
			}
			if(check==1){
				col=starting_column[counter];
				for(i=0;i<strlen(str[counter]);i++){
					board[starting_row[counter]][col]=str[counter][i];
					col--;
					// right to left
				}
			}	
		}
		else if(dir[counter]==2){
		// this means up to down
			col=starting_column[counter];
			row=starting_row[counter];
			for(i=0;i<strlen(str[counter]);i++){
				if(starting_row[counter]+strlen(str[counter])>15){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					counter--;
					break;
				}
				else if(board[row][starting_column[counter]]!=' '){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					counter--;
					break;
				}
				row++;
				// i need to increase row of the word because word is going to up to down
			}
			if(check==1){
				row=starting_row[counter];
				for(i=0;i<strlen(str[counter]);i++){
					board[row][starting_column[counter]]=str[counter][i];
					row++;
					// up to down!!
				}
			}	
		}
		else if(dir[counter]==3){
		// this means down to up
			col=starting_column[counter];
			row=starting_row[counter];
			for(i=0;i<strlen(str[counter]);i++){
				if(starting_row[counter]-strlen(str[counter])<-1){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					counter--;
					break;
				}
				else if(board[row][starting_column[counter]]!=' '){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					counter--;
					break;
				}	
				row--;
				// i need to decrease row of the word because the direction of the word down to up
			}
			if(check==1){
				row=starting_row[counter];
				for(i=0;i<strlen(str[counter]);i++){
					board[row][starting_column[counter]]=str[counter][i];
					row--;
					// down to up
				}
			}	
		}
		else if(dir[counter]==4){
		// direction is left up to right down
			col=starting_column[counter];
			row=starting_row[counter];
			for(i=0;i<strlen(str[counter]);i++){
				if(starting_row[counter]+strlen(str[counter])>15 || starting_column[counter]+strlen(str[counter])>15){
					//printf("\naa\n");	
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					//printf("word: %d row: %d col :%d\n",counter,row,col);
					counter--;
					break;
				}
				else if(board[row][col]!=' '){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					counter--;
					break;
				}
				row++;
				col++;
				// i need to increase both row and column because direction of the word is left up to right down
			}
			if(check==1){
				row=starting_row[counter];
				col=starting_column[counter];
				for(i=0;i<strlen(str[counter]);i++){
					board[row][col]=str[counter][i];
					row++;
					col++;
					// left up to right down
				}
			}	
		}
		else if(dir[counter]==5){
		// this means right up to left down
			col=starting_column[counter];
			row=starting_row[counter];	
			for(i=0;i<strlen(str[counter]);i++){			
				if(starting_row[counter]+strlen(str[counter])>15 || starting_column[counter]-strlen(str[counter])<-1){
					//printf("\nbb\n");
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					//printf("word: %d row: %d col :%d\n",counter,row,col);
					counter--;
					break;
				}
				else if(board[row][col]!=' '){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					counter--;
					break;
				}
				row++;
				col--;
				// i need to increase row of the word and decrease column of the word because of the direction of the word is right up to left down
			}
			if(check==1){
				row=starting_row[counter];
				col=starting_column[counter];
				for(i=0;i<strlen(str[counter]);i++){
					board[row][col]=str[counter][i];
					row++;
					col--;
					// right up to left down
				}
			}	
		}
		else if(dir[counter]==6){
		// this if statement means left down to right up
			col=starting_column[counter];
			row=starting_row[counter];
			for(i=0;i<strlen(str[counter]);i++){
				if(starting_row[counter]-strlen(str[counter])<-1 || starting_column[counter]+strlen(str[counter])>15){
					//printf("\ncc\n");
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					//printf("word: %d row: %d col :%d\n",counter,row,col);
					counter--;
					break;
				}
				else if(board[row][col]!=' '){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					
					counter--;
					break;
				}
				row--;
				col++;
				// i need to decrease row of the word and i need to increase column of the word because of the direction of the word is left down to right up
			}
			if(check==1){
				row=starting_row[counter];
				col=starting_column[counter];
				for(i=0;i<strlen(str[counter]);i++){
					board[row][col]=str[counter][i];
					row--;
					col++;
					// left down to right up
				}
			}	
		}
		else if(dir[counter]==7){
		// this if statements means direction of the word is right down to left up
			col=starting_column[counter];
			row=starting_row[counter];
			for(i=0;i<strlen(str[counter]);i++){
				if(starting_row[counter]-strlen(str[counter])<-1 || starting_column[counter]-strlen(str[counter])<-1){
					//printf("\ndd\n");
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];
					//printf("word: %d row: %d col :%d\n",counter,row,col);
					counter--;
					break;
				}
				else if(board[row][col]!=' '){
					check=0;
					starting_row[counter]=rand_row();
					starting_column[counter]=rand_column();
					dir[counter]=direction();
					row=starting_row[counter];
					col=starting_column[counter];;
					counter--;
					break;
				}
				row--;
				col--;
				// i need to decrease both of the row and column of the word because direction of the word right down to left up
			}
			if(check==1){
				row=starting_row[counter];
				col=starting_column[counter];
				for(i=0;i<strlen(str[counter]);i++){
					board[row][col]=str[counter][i];
					row--;
					col--;
					// right down to left up
				}
			}	
		}
		counter++;
		check=1;
	}
	for(i=0;i<ROW;i++){
		for(j=0;j<COLUMN;j++){
			if(board[i][j]==' '){
				board[i][j]=rand_char();// i filled into the board with random chars
			}
		}
	}
	
	
}
void fill_X(int board[ROW][COLUMN],int dir, int row, int col,char str2[15]){
	int i,j;
	/*
	i increase or decrease the row and column according to the direction of the word here and i filled with 'X' into the board on correct positions
	*/
	/*
	0 means horizontally left to right
	1 means horizontally right to left
	2 means vertically up to down
	3 means vertically down to up
	4 means diagonally left up to right down
	5 means diagonally right up to left down
	6 means left down to right up
	7 means right down to left up
	*/
	switch(dir){
		case 0:
			for(i=0;i<strlen(str2);i++){
				board[row][col]='X';
				col++;
			}
			break;
		case 1:
			for(i=0;i<strlen(str2);i++){
				board[row][col]='X';
				col--;
			}
			break;	
		case 2:
			for(i=0;i<strlen(str2);i++){
				board[row][col]='X';
				row++;
			}
			break;
		case 3:
			for(i=0;i<strlen(str2);i++){
				board[row][col]='X';
				row--;
			}
			break;
		case 4:
			for(i=0;i<strlen(str2);i++){
				board[row][col]='X';
				row++;
				col++;
			}
			break;	
		case 5:
			for(i=0;i<strlen(str2);i++){
				board[row][col]='X';
				row++;
				col--;
			}
			break;	
		case 6:
			for(i=0;i<strlen(str2);i++){
				board[row][col]='X';
				row--;
				col++;
			}
			break;	
		case 7:
			for(i=0;i<strlen(str2);i++){
				board[row][col]='X';
				row--;
				col++;
			}
			break;		
		default:
			break;			
	}
	
}
void gameplay(int board[ROW][COLUMN],char str[7][15],int dir[7],int starting_row[7],int starting_column[7]){
	
	char str2[15];// to get word from the user
	char str3[5];//to exit 
	int indexes[2];// to get indexes from the user // indexes[0] keeps row, indexes[1] keeps column;
	int mistakes=3;
	int i,j;
	int total_points=0;
	int check=0;
	print_table(board);
	while(mistakes!=0){
		printf("Enter coordinates and word: ");
		scanf("%d %d %s",&indexes[0],&indexes[1],str2); // i got the coordinates and word
		
		for(i=0;i<7;i++){
			if(strcmp(str2,str[i])==0){ // if words are same 
				if(indexes[0]==starting_row[i] && indexes[1]==starting_column[i]){ // i checked the coordinates
					fill_X(board,dir[i],indexes[0],indexes[1],str2); // fill with 'X' correct cooridantes
					print_table(board);// print the table
					total_points+=2; // total points +2
					printf("Founded! You got 2 points. Your total points: %d\n",total_points);
					check=1; // to understane mistakes
				}
			}
		}
		if(check==0){ // there is mistake
			mistakes--;
			printf("Wrong choice! You have only %d lefts.\n",mistakes);
		}
		if(total_points==14){ // understand the every word is founded
			printf("Counguraltions!! You found every words!! You won the game!!\n");
			break;
		}
		check=0;
		if(mistakes==0){
			break;
		}
		printf("Press any key to continue (':q means to exit'): ");
		scanf("%s",str3);
		if(strcmp(str3,":q")==0){
			printf("Good bye\n");
			break;
		}
	}
	
	printf("Your total points: %d\nTHANK YOU FOR PLAYING THE GAME\n\n",total_points);
	
}


