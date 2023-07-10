#include <stdio.h>
#include "util.h"


int main() {
    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");



    /*
     TODO: Complete this code to read two fractional numbers and print their 
             multiplication and division results...
    */
  //  printf("TODO: Remove this printf and add the code to read two fractional numbers and .....\n");
/* A fractional number: 13/7 */
    int Num1, Den1;
    /* A fractional number: 13/7 */
    int Num2, Den2;
    /* An unitilized fractional number */
    int Num3, Den3;

    printf("First number:\nNum: ");
    scanf("%d",&Num1);
    do{	//I SAID THAT THE DENOMINATOR CANNOT BE ZERO. I AM CHECKING THIS HERE.
  	  printf("Den: ");
  	  scanf("%d",&Den1);
  	  if(Den1==0){
  	  	printf("The denominator cannot be zero!!\n");
   	  }
   	 
    }while(Den1==0);
    fraction_print(Num1, Den1);
    printf("\n");
    printf("Second number:\nNum: ");
    scanf("%d",&Num2);
     do{	  //I SAID THAT THE DENOMINATOR CANNOT BE ZERO. I AM CHECKING THIS HERE.
  	  printf("Den: ");
  	  scanf("%d",&Den2);
  	  if(Den2==0){
  	  	printf("The denominator cannot be zero!!\n");
   	  }
   	
    }while(Den2==0);
    fraction_print(Num2, Den2);
    printf("\n");
    
    printf("Addition: ");
    fraction_add(Num1, Den1, Num2, Den2, &Num3, &Den3);
    fraction_print(Num3, Den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(Num1, Den1, Num2, Den2, &Num3, &Den3);
    fraction_print(Num3, Den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(Num1, Den1, Num2, Den2, &Num3, &Den3);
    fraction_print(Num3, Den3);
    printf("\n");

    printf("Division: ");
    fraction_div(Num1, Den1, Num2, Den2, &Num3, &Den3);
    fraction_print(Num3, Den3);
    if(Num1==0 && Num2==0){
    	printf("The result is indeterminate!!\n");
    }
    else if(Num2==0){
    	printf("The result is undefined!!\n");
    }
    printf("\n");    
  

    return(0);
}
