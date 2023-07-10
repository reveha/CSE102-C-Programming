#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14


/*
	1) I CALLED THE CALCULATE FUNCTION IN THE MAIN MENU
	2) I CALLED SELECT_SHAPE FUNCTION IN THE CALCULATE FUNCTION
	3) IF SELECT_SHAPE DOES NOT RETURN ZERO I CALLED SELECT_CALC FUNCTION IN CALCULATE FUNCTION
	4) IF SELECT_CALC DOES NOT RETURN ZERO, I DID TASKS. I GOT VALUES FROM USER AND I CHECKED EVERY ERROR CASE!.
	5) IF USER ENTER ZERO, I EXIT 
	THIS IS ALL MY CODE!!
	I SEND ENUM TYPE INTO calc_triangle, calc_quadrilateral, calc_circle, calc_pyramid, calc_cylinder
	FINALLY I CREATED SWITCH CASE STATEMENT WITH ENUM TYPES!!!
	SINCE I GOT THE CHAR VALUES FROM THE USER FOR CALCULATE, SELECT_SHAPE AND SELECT_CALC FUNCTION, I STARTED ENUMS FROM 49 (ASCII MEANS 1)
*/
typedef enum{
	triangle=49,quadrilateral,circle,pyramid,cylinder
}shapes;

typedef enum{
	area=49,perimeter,volume

}calculators;

int calc_triangle(int en);
int calc_quadrilateral(int en);
int calc_circle(int en);
int calc_pyramid(int en);
int calc_cylinder(int en);
int select_shape();
int select_calc();
int calculate(int (*select_shape)(), int (*select_calc)());
int clear (){ // THIS IS MY FFLUSH(STDIN) FUNCTION THIS RETURN A VALUE 
// IF THE RETURNED VALUE 0 THAT MEANS THE USER ENTERED 1 DIGIT. OTHERWISE MORE THAN ONE DIGIT THIS IS FALSE!!!
	int counter=0;
	while ( getchar() != '\n' ){
		counter++;
	}
	return counter;
}


int main(){
	int returned_value;
	returned_value=calculate(&select_shape,&select_calc); // IF THE VALUE 0 GOOD BYE :)
	if(returned_value==0){
		printf("\nGOOD BYE!\n");
	}
	return 0;
}
int calc_triangle(int en){
//	IN EVERY CALCULATE FUNCTION, IF THERE IS ANY ERROR I RETURNED ZERO. FINALLY I CHECKED THE RETURNED VALUE IN CALCULATE FUNCTION.!!!
	float side1,side2,side3;
	float s; // S IN FORMULA
	float area_of_triangle;
	float semiperimeter;
		switch(en){
			case area:
				printf("\nPlease enter three sides of Triangle :\n");
				fflush(stdin);
				if(!scanf("%f",&side1)){ // THAT IF MEANS: IF SCANF IS WRONG ENTER HERE
				// I MEAN IF YOU ENTER A CHAR THIS SCANF WILL BE WRONG, SO THIS IF STATEMENT WILL WORK
					while(getchar()!='\n');// CLEARING BUFFER
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side2)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side3)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				semiperimeter=(side1+side2+side3)/2.0;
				if((side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2) && (semiperimeter>side1 && semiperimeter>side2 && semiperimeter>side3)){ // RULE OF TRIANGLE!!
					s=(side1+side2+side3)/2;
					area_of_triangle=sqrt(s*(s-side1)*(s-side2)*(s-side3));
					printf("\nArea of TRIANGLE : %.2f\n\n",area_of_triangle);
					return 1;
				}
  	 			 else{
	   		 		printf("\nERROR ! Please enter a valid triangle.\n\n");
	   		 		return 0;
				}
				break;
			case perimeter:
				printf("\nPlease enter three sides of Triangle :\n");
				fflush(stdin);
				if(!scanf("%f",&side1)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side2)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side3)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				semiperimeter=(side1+side2+side3)/2.0;
				if((side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2) && (semiperimeter>side1 && semiperimeter>side2 && semiperimeter>side3)){ // RULE OF TRIANGLE
					s=side1+side2+side3;
					printf("\nPerimeter of TRIANGLE : %.2f\n\n",s);
					return 1;
				}
  	 			 else{
	   		 		printf("\nERROR ! Please enter a valid triangle.\n\n");
	   		 		return 0;
				}
			break;
		}	
}
int calc_quadrilateral(int en){
	float side1,side2,side3,side4;
	float area_of_qua;
	float s;
		switch(en){
			case area:
				printf("Please enter four sides of Quadrilateral :\n");
				fflush(stdin);
				// I GOT THE SIDES OF QUA
				if(!scanf("%f",&side1)){
					while(getchar()!='\n'); // CLEARING BUFFER 
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side2)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side3)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side4)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(side1<=0 || side2<=0 || side3<=0 || side4<=0){
					printf("\nERROR ! Please enter a valid quadrilateral.\n\n");
					return 0;
				}
  	 			 else{
	   		 		s=(side1+side2+side3+side4)/2;
	   		 		area_of_qua=sqrt((s-side1)*(s-side2)*(s-side3)*(s-side4));
	   		 		printf("\nArea of QUADRILATERAL : %.2f\n\n",area_of_qua);
	   				return 1;
				}
				break;
			case perimeter:
				printf("Please enter four sides of Quadrilateral :\n");
				fflush(stdin);
				if(!scanf("%f",&side1)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side2)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side3)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&side4)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(side1<=0 || side2<=0 || side3<=0 || side4<=0){
					printf("\nERROR ! Please enter a valid quadrilateral.\n\n");
					return 0;
				}
  	 			 else{
	   		 		s=side1+side2+side3+side4;
	   		 		printf("\nPerimeter of QUADRILATERAL : %.2f\n\n",s);
	   		 		return 1; // THAT MEANS TRUE!
				}
				break;
			default:
				break;
		}
}
int calc_circle(int en){
	float radius;
	float area_of_circle;
	float perimeter_of_circle;
		switch(en){
			case area:
				printf("Please enter radius of Circle :\n");
				fflush(stdin);
				if(!scanf("%f",&radius)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}	
				if(radius<=0){
					printf("\nPlease enter a valid radius\n\n");
					return 0;
				}
  	 			 else{
	   		 		area_of_circle=PI*radius*radius;
	   		 		printf("\nArea of CIRCLE : %.2f\n\n",area_of_circle);
	   		 		return 1;
				}
				break;
			case perimeter:
				printf("Please enter radius of Circle :\n");
				fflush(stdin);
				if(!scanf("%f",&radius)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}		
				if(radius<=0){
					printf("\nPlease enter a valid radius\n\n");
					return 0;
				}
  	 			 else{
	   		 		perimeter_of_circle=2*PI*radius;
	   		 		printf("\nPerimeter of CIRCLE : %.2f\n\n",perimeter_of_circle);
	   		 		return 1;
				}
				break;
			default:
				break;
		}
	
}
int calc_pyramid(int en){
	float base_side,height;
	float B,L,volume;
		switch(en){
			case area:
				printf("Please enter the base side and slant height of a Pyramid :\n");
				fflush(stdin);
				if(!scanf("%f",&base_side)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&height)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}	
				if(base_side<=0 || height<=0){
					printf("\nPlease enter a valid length\n\n");
					return 0;
				}
  	 			 else{
	   		 		B=base_side*base_side;
	   		 		L=2*base_side*height;
	   		 		printf("\nBase Surface Area of a PYRAMID : %.2f\n\n",B);
	   		 		printf("\nLateral Surface Area of a PYRAMID : %.2F\n\n",L);
	   		 		printf("\nSurface Area of a PYRAMID : %.2f\n\n",B+L);
	   		 		return 1;
				}
				break;
			case perimeter:
				printf("Please enter the base side of a Pyramid :\n");
				fflush(stdin);
				if(!scanf("%f",&base_side)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(base_side<=0){
					printf("\nPlease enter a valid length\n\n");
					return 0;
				}
				else{
					printf("\nBase Surface Perimeter of a PYRAMID : %.2f\n\n",4*base_side);
					return 1;
				}
				break;
			case 51: // when i write here volume instead of 51, i got error! WHY I DONT KNOW
				printf("Please enter the base side and height of a Pyramid :\n");
				fflush(stdin);
				if(!scanf("%f",&base_side)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&height)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}	
				if(base_side<=0 || height<=0){
					printf("\nPlease enter a valid length\n\n");
					return 0;
				}
  	 			 else{
	   		 		volume=base_side*base_side*height/3;
	   		 		printf("\nVolume of a PYRAMID : %.2f\n\n",volume);
	   		 		return 1;
				}
				break;
			default:
				break;
		}
	
}
int calc_cylinder(int en){
	float radius,height;
	float B,L,S,volume;
		switch(en){
			case area:
				printf("Please enter the radius and height of a Cylinder :\n");
				fflush(stdin);
				if(!scanf("%f",&radius)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&height)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}			
				if(radius<=0 || height<=0){
					printf("\nPlease enter a valid length\n\n");
					return 0;
				}
  	 			 else{
	   		 		B=PI*radius*radius;
	   		 		L=2*PI*radius*height;
	   		 		S=2*PI*radius*(radius+height);
	   		 		printf("\nBase Surface Area of a CYLINDER : %.2f\n\n",B);
	   		 		printf("\nLateral Surface Area of a CYLINDER : %.2f\n\n",L);
	   		 		printf("\nSurface Area of a CYLINDER : %.2f\n\n",S);
	   		 		return 1;
				}
				break;
			case perimeter:
				printf("Please enter the base side of a Cylinder :\n");
				fflush(stdin);
				if(!scanf("%f",&radius)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&height)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}	
				if(radius<=0 || height<=0){
					printf("\nPlease enter a valid length\n\n");
					return 0;
				}
				else{
					printf("\nBase Surface Perimeter of a CYLINDER : %.2f\n\n",2*PI*radius);
					return 1;
				}
				break;
			case 51: // when i write here volume instead of 51, i got error!
				printf("Please enter the base side and height of a Cylinder :\n");
				fflush(stdin);
				if(!scanf("%f",&radius)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}
				if(!scanf("%f",&height)){
					while(getchar()!='\n');
					printf("\nERROR ! Please enter a valid entry.\n\n");
					return 0;
				}	
				if(radius<=0 || height<=0){
					printf("\nPlease enter a valid length\n\n");
					return 0;
				}
  	 			 else{
	   		 		volume=PI*radius*radius*height;
	   		 		printf("\nVolume of a CYLINDER : %.2f\n\n",volume);
	   		 		return 1;
				}
				break;
			default:
				break;
		}
	
}

int select_shape(){
	char choice_shape;
	int returned_value;
	int counter;
	do{
		printf("Welcome to the geometric calculator!\n\n");
		printf("Select a shape to calculate:\n");
		printf("-------------------------------------\n");
		printf("1. Triangle\n");
		printf("2. Quadrilateral\n");
		printf("3. Circle\n");
		printf("4. Pyramid\n");
		printf("5. Cylinder\n");
		printf("0. Exit\n");
		printf("-------------------------------------\n");
		printf("Input: ");
		scanf(" %c",&choice_shape);
		counter=clear();
		if(counter==0){
			switch(choice_shape){
				case triangle:
					return 49; // 49 MEANS 1 IN ASCII
				case quadrilateral:
					return 50;
				case circle:
					return 51;
				case pyramid:
					return 52;
				case cylinder:
					return 53;
				case '0':
					returned_value=0;
					break;
				default:
					printf("\nERROR ! Please enter a valid entry.\n\n");
					break;			
			}
		}
		else{
				printf("\nERROR ! Please enter a valid entry.\n\n");
		}
	}while(choice_shape!='0');
	return returned_value;
}
int select_calc(){
	char choice_calc;
	int returned_value;
	int counter;
	do{
		printf("Select calculator:\n");
		printf("-------------------------------------\n");
		printf("1. Area\n");
		printf("2. Perimeter\n");
		printf("3. Volume\n");
		printf("0. Exit\n");
		printf("-------------------------------------\n");
		printf("Input : ");
		scanf(" %c",&choice_calc);
		counter=clear(); // I GOT THE COUNTER. IF COUNTER IS ZERO THAT MEANS YOU ENTERED 1 DIGIT. AND I CHECKED THIS ENTERED VALUE AFTER THIS IF STATEMENT
		if(counter==0){
			switch(choice_calc){
				case area:
					return 49; // 49 MEANS 1 IN ASCII 
				case perimeter:
					return 50;
				case volume:
					return 51;
				case '0':
					returned_value=0;
					break;
				default:
					printf("\nERROR ! Please enter a valid entry.\n\n");			
					break;
			}
		}
		else{
			printf("\nERROR ! Please enter a valid entry.\n\n");
		}
	}while(choice_calc!='0');
	
	return returned_value; // THIS RETURN ZERO TO EXIT INTO CALCULATE

}


int calculate(int (*select_shape)(), int (*select_calc)()){
	int returned_value1,returned_value;
	int ret_value=0;
	do{
		returned_value1=select_shape();
		if(returned_value1==0){
			return returned_value1; // IF ZERO WAS ENTERED GOOD BYE
		}
		returned_value=select_calc();
		if(returned_value==0){
			return returned_value; // IF ZERO WAS ENTERED GOOD BYE
		}
		switch(returned_value1){
			case triangle:
				switch(returned_value){
					case area:
						do{
							ret_value=calc_triangle(area);
						}while(ret_value==0); // IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case perimeter:
						do{
							ret_value=calc_triangle(perimeter);
						}while(ret_value==0);	// IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case volume:
						printf("\nERROR ! You cannot calculate the volume of a triangle. Please try again.\n\n");
						break;
					default:
						break;		
				}
				break;
			case quadrilateral:
				switch(returned_value){
					case area:
						do{
							ret_value=calc_quadrilateral(area);
						}while(ret_value==0);// IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case perimeter:
						do{
							ret_value=calc_quadrilateral(perimeter);
						}while(ret_value==0); // IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case volume:
						printf("\nERROR ! You cannot calculate the volume of a quadrilateral. Please try again.\n\n");
						break;
					default:
						break;	
				}
				break;
			case circle:
				switch(returned_value){
					case area:
						do{
							ret_value=calc_circle(area);
						}while(ret_value==0);	 // IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case perimeter:
						do{
							ret_value=calc_circle(perimeter);
						}while(ret_value==0); // IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case volume:
						printf("\nERROR ! You cannot calculate the volume of a circle. Please try again.\n\n");	
						break;
					default:
						break;		
				}
				break;
			case pyramid:
				switch(returned_value){
					case area:
						do{
							ret_value=calc_pyramid(area);
						}while(ret_value==0);	 // IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case perimeter:
						do{
							ret_value=calc_pyramid(perimeter);
						}while(ret_value==0);	// IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case volume:
						do{
							ret_value=calc_pyramid(volume);
						}while(ret_value==0);	// IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					default:
						break;			
				}
				break;
			case cylinder:
				switch(returned_value){
					case area:
						do{
							ret_value=calc_cylinder(area);
						}while(ret_value==0);	// IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case perimeter:
						do{
							ret_value=calc_cylinder(perimeter);
						}while(ret_value==0);	// IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					case volume:
						do{
							ret_value=calc_cylinder(volume);
						}while(ret_value==0);	// IF INVALID CHAR IS ENTERED, I GOT THE VALUE AGAIN UNTIL RET_VALUE BECOME 1!!!
						break;
					default:
						break;			
				}
				break;			
		}
	}while(1);	
	
	
	
	return returned_value; // THIS RETURNS ZERO TO MAIN TO EXIT 
}



