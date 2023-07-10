#include <stdio.h>

#define MAX_Y 16
#define MIN_Y -16
#define MAX_X 56
#define MIN_X -56

/*
	I DO NOT NEED TO USE MORE COMMENT LINE BECAUSE THIS HOMEWORK CONTAINS MOSTLY IF ELSE.
	I DO NOT NEED TO EXPLAIN EVERY IF ELSE THEY ARE CLEAR.
*/


void write_equation(int a,int b, int c);
void draw_graph();
void draw_graph2();  //THIS IS ALSO PRINTING THE GRAPH. HOWEVER IF THERE IS ANY COLLISION WITH THE NUMBERS WHICH ARE Y AXIS NUMBERS, I MOVED THEM TO LEFT!!!!!! IT IS VERY COMPLEX BUT IT IS WORKING :D
void draw_into_file();

int main(){
	int choice;
	int a,b,c; //for part 1 variables
	do{
		printf("Select an operation...\n");
		printf("1 -> Enter the coefficients.\n");
		printf("2 -> Draw the graph.\n");
		printf("3 -> Print the graph into a.txt file.\n");
		printf("4 -> Exit.\n");
		printf("Choice: ");
		scanf("%d",&choice);
		if(choice==1){
			printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n\n");
			printf("a: ");
			scanf("%d",&a);
			printf("b: ");
			scanf("%d",&b);
			printf("c: ");
			scanf("%d",&c);
			write_equation(a,b,c);
			printf("coefficients.txt file has been created.\n");
		}
		else if(choice==2){
			draw_graph();
			//draw_graph2();
		}
		else if(choice==3){
			draw_into_file();
		}
		else if(choice==4){
			printf("GOOD BYE!\n");
		}
		else{
			printf("Please enter valid number!!\n");
		}
		
	
	}while(choice!=4);
	

	
	return 0;
}


void write_equation(int a, int b, int c){
	FILE *ptr=fopen("coefficients.txt","w");
	fprintf(ptr,"%d\n",a);
	fprintf(ptr,"%d\n",b);
	fprintf(ptr,"%d\n",c);
	fclose(ptr);
}

void draw_graph(){
	FILE *ptr=fopen("coefficients.txt","r");
	int a,b,c;
	int y,x; // y and x axis
	int temp_x;
	int k=0;
	if(ptr==NULL){
		printf("There is no coefficients.txt file !!\n");
	}
	else{
		fscanf(ptr,"%d\n",&a);
		fscanf(ptr,"%d\n",&b);
		fscanf(ptr,"%d\n",&c);
		printf("Coefficients has been read from the coefficient.txt file.\n");
		printf("Printing the graph of x=%d*(y*y) + %d*y + %d\n",a,b,c);
		for(y=MAX_Y;y>=MIN_Y;y--){
			for(x=MIN_X;x<=MAX_X;x++){
				temp_x=a*y*y + b*y +c;
				printf("\033[0;37m");
				if(x==-1){ //THIS IF STATEMNT IS PRINTING THE Y AXIS NUMBERS IF THERE IS NO COLLISSION ANY POINTS OF GRAPH
					if(y==5){
						if(temp_x!=-1 && temp_x!=-2){			
							printf("\033[0;33m");
							printf("\b%d",y);
						}							
					}
					else if(y==10 || y==15 || y==-5){			
						if(temp_x!=-1 && temp_x!=-2 && temp_x!=-3){
							printf("\033[0;33m");
							printf("\b\b%d",y);
						}
					}
					else if(y==-10 || y==-15){
						if(temp_x!=-1 && temp_x!=-2 && temp_x!=-3 && temp_x!=-4){
							printf("\033[0;33m");
							printf("\b\b\b%d",y);
						}
					}
				}
				if(y==-1){ //THIS IF STATEMNT IS PRINTING THE X AXIS NUMBERS IF THERE IS NO COLLISSION ANY POINTS OF GRAPH
					if(x%10==0 && x!=0){
						if(x<0){
							if(temp_x!=x-1 && temp_x!=x-2 && temp_x!=x-3){
			//IF NUMBERS ARE NEGATIVE THERE ARE 3 DIGIT F.E -->  -10 "-,1,0" SO I NEED TO CHECK 3 DIGIT HERE			
								printf("\033[0;33m");
								printf("\b\b\b%d",x);			
							}
						}
						else if(x>0){
							if(temp_x!=x-1 && temp_x!=x-2){
			//IF NUMBERS ARE POSITIVE THERE ARE 3 DIGIT F.E -->  10 "1,0" SO I NEED TO CHECK 2 DIGIT HERE					
								printf("\033[0;33m");
								printf("\b\b%d",x);			
							}
						
						}
					}
					else if(x==0){
						if(temp_x!=x && temp_x!=x-1){
			// THIS IF IS PRINTING ZERO !!			
							printf("\033[0;33m");
							printf("\b%d",x);
							printf("\033[0;37m");
						}
					}
					
				}
				if(y==MAX_Y && x==0){
					printf("^");
				}
				else if(y==MIN_Y && x==0){
					printf("v");
				}	
				else if((x==temp_x) && y!=MAX_Y && y!=MIN_Y){
					printf("\033[0;34m");
					printf("#");	
				}			
				else if(x==0){ // Y AXIS
					printf("|");
				}
				else if(y==0 && x==MIN_X){
					printf("<");
				}
				else if(y==0 && x==MAX_X){
					printf(">");
				}
				else if(y==0){ // X AXIS
					printf("-");
				}
				else{
					printf(" ");
				}						
			}
			printf("\n");
		}	
	}	
	
	fclose(ptr);
}

 
void draw_into_file(){
	FILE *fp=fopen("graph.txt","w+");
	FILE *ptr=fopen("coefficients.txt","r");
	int a,b,c;
	int y,x; // y and x axis
	int temp_x;
	int k=0;
	if(ptr==NULL || fp==NULL){
		printf("There is no coefficients.txt file !!\n");
	}
	else{
		fscanf(ptr,"%d\n",&a);
		fscanf(ptr,"%d\n",&b);
		fscanf(ptr,"%d\n",&c);
		printf("Coefficients has been read from the coefficient.txt file.\n");	
		for(y=MAX_Y+1;y>=MIN_Y;y--){
		temp_x=a*y*y + b*y + c;
			for(x=MIN_X;x<=MAX_X;x++){
				if(y!=0){
					if(x==0){
						if(y==MAX_Y+1){
							if((a==0 && b==0) && c<0){
								fprintf(fp," ^");
							}
							else{
								fprintf(fp,"^");
							}	
						}
						else{
							if(temp_x==x){
								if(a==0 && b==0 && c==0){
									fprintf(fp,"|");
								}
								else{
									fprintf(fp,"#");
								}	
							}
							else{
								fprintf(fp,"|");
							}
						}	
					}
					else{
						if(temp_x==x){
							if(y!=MAX_Y+1){
								fprintf(fp,"#");
							}
						}						
						else{
							fprintf(fp," ");
						}
					}
				}
							
				else{
					if(x==MIN_X){
						fprintf(fp,"<");
					}
					else if(x==MAX_X){
						fprintf(fp,">");
					}
					else{
						if(temp_x==x){
							if(a==0 && b==0 && c==0){
								fprintf(fp,"|");
							}
							else{
								fprintf(fp,"#");
							}
						}
						else{
							if(x==0){
								fprintf(fp,"|");
							}
							else{	
								fprintf(fp,"-");
							}
						}			
					}
				}				
			}
			fprintf(fp,"\n");
		}	
	}
	printf("The graph of x=%d*(y*y) + %d*y + %d has been written to graph.txt file.\n",a,b,c);
	fclose(ptr);
	fclose(fp);	
}




//THIS IS ALSO PRINTING THE GRAPH. HOWEVER IF THERE IS ANY COLLISION THE NUMBERS WHICH ARE Y AXIS NUMBERS, I MOVED THEM TO LEFT!!!!!! IT IS VERY COMPLEX BUT IT IS WORKING :D
void draw_graph2(){
	FILE *ptr=fopen("coefficients.txt","r");
	int a,b,c;
	int y,x; // y and x axis
	int temp_x;
	int k=0;
	if(ptr==NULL){
		printf("There is no coefficients.txt file !!\n");
	}
	else{
		fscanf(ptr,"%d\n",&a);
		fscanf(ptr,"%d\n",&b);
		fscanf(ptr,"%d\n",&c);
		printf("Coefficients has been read from the coefficient.txt file.\n");
		printf("Printing the graph of x=%d*(y*y) + %d*y + %d\n",a,b,c);
		for(y=MAX_Y+1;y>=MIN_Y;y--){
			temp_x=a*y*y + b*y + c;
			for(x=MIN_X;x<=MAX_X;x++){
				if(y!=0){
					if(x==0){
						if(y==MAX_Y+1){
							if((a==0 && b==0) && c<0){
								printf(" ^"); // IF A AND B IS ZERO AND C LESS THAN ZERO I NEED TO MOVE 1 LINE TO RIGHT " ^ ".
							}
							else{
								printf("^");
							}
						}
						else{
							
							if(temp_x==x){
								printf("\033[0;34m");
								printf("#");
								printf("\033[0;37m");	
							}
							else{
								if(y==-1){
									printf("\b|");
								}
								else{
									printf("|");
								}	
							}
						}	
					}
					else{
						if(x==-1){
// IN THESE IF STATEMENTS, I MOVED THE Y AXIS NUMBER IF THEY ARE ACCROSS THE POINTS !!! THERE ARE 4 VARIUS I CHECKED ALL OF THEM  !!!	
							if(y%5==0){
								if(y>0){
									if(y==5){
										if(temp_x==x ){
											printf("\033[0;35m");
											printf("\b\b%d",y);
											printf("\033[0;37m");			
										}
										else if(temp_x==x-1){
											printf("\033[0;35m");
											printf("\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("#");
											printf("\033[0;37m");
										}
										else if(temp_x==x-2){
											printf("\033[0;35m");
											printf("\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("# ");
											printf("\033[0;37m");
											
										}
										else if(temp_x==x-3){
											printf("\033[0;35m");
											printf("\b\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("#  ");
											printf("\033[0;37m");
											
										}
										else{
											printf("\033[0;35m");
											printf("\b%d",y);
											printf("\033[0;37m");
										}	
									}
									else{
										if(temp_x==x){
											printf("\033[0;35m");
											printf("\b\b\b%d",y);
											printf("\033[0;37m");
										
										}
										else if(temp_x==x-1){
											printf("\033[0;35m");
											printf("\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("#");
											printf("\033[0;37m");
										}
										else if(temp_x==x-2){
											printf("\033[0;35m");
											printf("\b\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("# ");
											printf("\033[0;37m");
											
										}
										else if(temp_x==x-3){
											printf("\033[0;35m");
											printf("\b\b\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("#  ");
											printf("\033[0;37m");
											
										}
										else{
											printf("\033[0;35m");
											printf("\b\b%d",y);
											printf("\033[0;37m");
										}
									}	
								}
								else{
									if(y==-5){
										if(temp_x==x ){
											printf("\033[0;35m");
											printf("\b\b\b%d",y);
											printf("\033[0;37m");
										
										}
										else if(temp_x==x-1){
											printf("\033[0;35m");
											printf("\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("#");
											printf("\033[0;37m");
										}
										else if(temp_x==x-2){
											printf("\033[0;35m");
											printf("\b\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("# ");
											printf("\033[0;37m");
											
										}
										else if(temp_x==x-3){
											printf("\033[0;35m");
											printf("\b\b\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("#  ");
											printf("\033[0;37m");
											
										}
										else{
											printf("\033[0;35m");
											printf("\b\b%d",y);
											printf("\033[0;37m");
										}
									}
									else{
										if(temp_x==x ){
											printf("\033[0;35m");
											printf("\b\b\b\b%d",y);
											printf("\033[0;37m");
										
										}
										else if(temp_x==x-1){
											printf("\033[0;35m");
											printf("\b\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("#");
											printf("\033[0;37m");
										}
										else if(temp_x==x-2){
											printf("\033[0;35m");
											printf("\b\b\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("# ");
											printf("\033[0;37m");
											
										}
										else if(temp_x==x-3){
											printf("\033[0;35m");
											printf("\b\b\b\b\b\b\b%d ",y);
											printf("\033[0;34m");
											printf("#  ");
											printf("\033[0;37m");
											
										}
										else{
											printf("\033[0;35m");
											printf("\b\b\b%d",y);
											printf("\033[0;37m");
										}
									}
								}
							}
							
						}
						if(y==-1){
							if(x%10==0 || x==-1){
								if(x!=0 && x>0){
									if(temp_x!=x-1 && temp_x!=x-2){
										printf("\033[0;35m");
										printf("\b\b%d",x);
										printf("\033[0;37m");
									}
									else{
										
									}
								}
								else if(x==-1){
									if(temp_x!=-1){
										printf("\033[0;35m");
										printf("0");
										printf("\033[0;37m");
									}
									else{
										printf("\033[0;34m");
										printf("#");
										printf("\033[0;37m");
									}
									
								}
								else if(x!=0 && x<0){
									if(temp_x!=x-1 && temp_x!=x-2 && temp_x!=x-3){
										printf("\033[0;35m");
										printf("\b\b\b%d",x);
										printf("\033[0;37m");
									}
									else{
										
									}
								}
							}				
						}
						if(temp_x==x){
							if(y!=MAX_Y+1){
								if((x==-1) && y%5==0 && y!=0){
									printf("\033[0;34m");
									printf(" #");
									printf("\033[0;37m");
								}			
								else{
									printf("\033[0;34m");
									printf("#");
									printf("\033[0;37m");
								}	
							}	
						}						
						else{
							if(a==0 && b==0 && c==0 && x==-1 && y==-1){
								
							}
							else{
								if(temp_x==0 && x==-1 && y==-1){
									
								}
								else{
									printf(" ");
								}	
							}	
						}	
					}
				}
							
				else{
					if(x==MIN_X){
						printf("<");
					}
					else if(x==MAX_X){
						printf(">");
					}
					else{
						if(temp_x==x){
								printf("\033[0;34m");
								printf("#");
								printf("\033[0;37m");		
						}
						else{
							if(x==0){
								printf("|");
							}
							else{	
								printf("-");
							}
						}			
					}
				}				
			}
			printf("\n");
		}	
	}	
	
	fclose(ptr);
}











