#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {
	int t,s,w; //for part0
	double p,h; //for part0
	int d0; // to get returned value from dt0 function
	int choice; // for asking to user to understand which part will be done
	double pl,pw,sl,sw;	// for part 1
	double x1,x2,x3;	// for part 2
	int x4,x5;	//for part2
	char d1a,d1b;  // to get returned value from dt1a and dt1b
	double d2a,d2b;  // to get returned value from dt2a and dt2b	
	
	// PART3 VARIABLES
	int laptop_or_not; //laptop means 1, pc means 0 (binary numbers)
	int cpu;  // at least 5 options
	int gpu;  // at least 5 options
	double free_ram;  // real number
	double free_capacity;  // real number
	double d3a,d3b; // returned values
	// PART3 VARIABLES
	printf("PART 0\n\n");
	printf("Enter temperature(t), pressure(p), humidity(h), sunny_or_not(s) and day_of_the_week(w):");
	scanf("%d %lf %lf %d %d",&t,&p,&h,&s,&w);
	d0=dt0(t,p,s,h,w);
	if(d0==0){
		printf("AC turn off.\n\n");
	}
	else{
		printf("AC turn on.\n\n");
	}
	do{
		printf("Which problem do you want to solve?(0 to exit)\n");
		printf("1) PART1\n");
		printf("2) PART2\n");
		printf("3) PART3\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("Enter pl,pw,sl,sw:");
			scanf("%lf %lf %lf %lf",&pl,&pw,&sl,&sw);
			d1a=dt1a(pl,pw,sl,sw);
			if(d1a=='V'){
				printf("Part1a is Versicolor.\n");
			}
			else if(d1a=='v'){
				printf("Part1a is Virginca.\n");
			}
			else if(d1a=='s'){
				printf("Part1a is Setosa.\n");
			}
			d2a=dt1b(pl,pw,sl,sw);
			if(d2a=='V'){
				printf("Part1b is Versicolor.\n");
			}
			else if(d2a=='v'){
				printf("Part1b is Virginca.\n");
			}
			else if(d2a=='s'){
				printf("Part1b is Setosa.\n");
			}
		}
		else if(choice==2){
			printf("Enter the numbers x1, x2, x3, x4, and x5(x4 and x5 are binary numbers!!):");
			scanf("%lf %lf %lf %d %d",&x1,&x2,&x3,&x4,&x5);
			d2a=dt2a(x1,x2,x3,x4,x5);
			d2b=dt2b(x1,x2,x3,x4,x5);
			if(d2a==d2b){
				printf("The results are the same %.2lf.",d2a);
			}
			else{
				if(d2a>d2b){
					if(d2a-d2b<=CLOSE_ENOUGH){
						printf("The results are close enough. The average of the results is %.2lf\n",(d2a+d2b)/2);
					}
					else{
						printf("Results are not similar. The first result is %.2lf, second result is %.2lf.\n",d2a,d2b);
					}
				}
				else{
					if(d2b-d2a<=CLOSE_ENOUGH){
						printf("The results are close enough. The average of the results is %.2lf\n",(d2a+d2b)/2);
					}
					else{
						printf("Results are not similar. The first result is %.2lf, second result is %.2lf.\n",d2a,d2b);
					}
				}
			}
		}
		else if(choice==3){ // my part is checking that how many fps i can get????
				printf("\nCAN I RUN IT?\n\n");
				printf("This program is saying that how many fps you will get for new games.\n\n");
				printf("There must be at least 96.5 GB free capacity.\n");
				printf("Enter the objects that be wanted from you correctly!\n");
				do{
					printf("Enter your free capacity (GB):");
					scanf("%lf",&free_capacity);
				}while(free_capacity<0);
				do{
					printf("Enter your free RAM(GB)(meaning, memory which isn't used from operating system):");
					scanf("%lf",&free_ram);
				}while(free_ram<0);
				do{	
					printf("Is your computer laptop?(1 means yes, 0 means no):");
					scanf("%d",&laptop_or_not);
				}while(!(laptop_or_not==1 || laptop_or_not==0));
				
				do{	 // lets assume that the oldest amd ryzen series is 3. gen. Lets assume that the oldest intel cpu series is 6. gen.
					printf("Please choose a cpu model list below.\n"); 
					printf("(1)Intel i5 8. gen\n");  // not enough
					printf("(2)Intel i5 9. gen\n"); // not enough
					printf("(3)Intel i5 10. gen\n"); // enough
					printf("(4)Intel i5 11. gen\n");  // enough
					printf("(5)Intel i7 6. gen\n");  // not enough
					printf("(6)Intel i7 7. gen\n");  // not enough
					printf("(7)Intel i7 8. gen\n");  // enough
					printf("(8)Intel i7 9. gen\n");  // enough
					printf("(9)Intel i7 10. gen\n"); // enough
					printf("(10)Intel i7 11. gen\n"); // enough
					printf("(11)AMD Ryzen 4000 series 4. gen\n"); // not enough
					printf("(12)AMD Ryzen 4000 series 5. gen\n"); // enough
					printf("(13)AMD Ryzen 5000 series 3. gen\n");  // not enough
					printf("(14)AMD Ryzen 5000 series 4. gen\n");  // enough
					printf("(15)AMD Ryzen 5000 series 5. gen\n"); // enough
					scanf("%d",&cpu);
				}while(!(1<=cpu && cpu<=15));
				do{
					//lets assume that there are only these GPU.
					printf("Please choose a gpu model list below.\n");
					printf("(1)Nvidia MX330\n"); // not enough
					printf("(2)Nvidia MX450\n"); // not enough
					printf("(3)Nvidia GTX980\n"); // not enough
					printf("(4)Nvidia GTX1050\n"); // can run
					printf("(5)Nvidia GTX1650\n"); // can run
					printf("(6)Nvidia GTX2080\n"); // can run
					printf("(7)Nvidia GTX3090\n"); // can run
					printf("(8)Nvidia RTX3050\n"); // can run
					scanf("%d",&gpu);
				}while(!(1<=gpu && gpu<=8));
				d3a=dt3a(laptop_or_not,cpu,gpu,free_ram,free_capacity);	
				d3b=dt3b(laptop_or_not,cpu,gpu,free_ram,free_capacity);
				if(d3a==-1){
					printf("There is no enough place to store program.\n");
				}
				else{
					if(d3a>=d3b){
						if(d3a-d3b<=CLOSE_ENOUGH){
						    printf("The FPS is very similar for both checking. The average of FPS is about %.3lf.\n",(d3a+d3b)/2);
						}
						else{
							printf("Results are not similar. The first FPS is about %.3lf, second FPS is about %.3lf.\n",d3a,d3b);
						}
					}
					else{
						if(d3b-d3a<=CLOSE_ENOUGH){
						    printf("The FPS is similar for both checking. The average of FPS is about %.3lf.\n",(d3a+d3b)/2);
						}
						else{
							printf("Results are not similar. The first FPS is about %.3lf, second FPS is about %.3lf.\n",d3a,d3b);
						}
					}
				}
				//THESE IF STATEMENTS TO CLASSIFY FPS VALUES...
				//IF FPS LESS THAN 60 THAT MEANS NOT ENOUGH SPECS
				//IF FPS LESS THAN 90 GREATER THAN 60 THAT MEANS IT IS OKAY
				// IF FPS GREATER THAN 90 IT IS PERFECT TO PLAY GAME!!!
				if(d3a<60){
					printf("FOR 1. PROGRAM: Your computer can only run with low quality.\n");
					if(d3b<60){
						printf("FOR 2. PROGRAM: Your computer can only run with low quality.\n");
					}
					else if(d3b<90){
						printf("FOR 2. PROGRAM: Your computer can run new games but not with ultra mode.\n");
					}
					else{
						printf("FOR 2. PROGRAM: Your computer can run new games with ultra mode.\n");
					}
				}
				else if(d3a<90){
					printf("FOR 1. PROGRAM: Your computer can run new games but not with ultra mode.\n");
					if(d3b<60){
						printf("FOR 2. PROGRAM: Your computer can only run with low quality.\n");
					}
					else if(d3b<90){
						printf("FOR 2. PROGRAM: Your computer can run new games but not with ultra mode.\n");
					}
					else{
						printf("FOR 2. PROGRAM: Your computer can run new games with ultra mode.\n");
					}
				}
				else{
					printf("FOR 1. PROGRAM: Your computer can run new games with ultra mode.\n");
					if(d3b<60){
						printf("FOR 2. PROGRAM: Your computer can only run with low quality.\n");
					}
					else if(d3b<90){
						printf("FOR 2. PROGRAM: Your computer can run new games but not with ultra mode.\n");
					}
					else{
						printf("FOR 2. PROGRAM: Your computer can run new games with ultra mode.\n");
					}
				}
				
		}
		}while(choice!=0);
    return 0;
    

}
