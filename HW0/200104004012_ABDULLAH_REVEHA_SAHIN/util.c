#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d\n", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3= n1*n2;
    *d3=d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3=n1*d2;
    *d3=n2*d1;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    int a=2;  // to while loop 
    int neg1=0; // to check numerator is negative	
    int neg2=0; // to check denominator is negative
    int zer1=0; // to check numerator is zero
    int zer2=0; //to check denominator  is zero
    int gcd=1; 
    
	if(*n<0){
		(*n)*=-1;	//if the numerator is negative i convert it to positive to find GCD
		neg1=1;		// i said "neg1 is equal to 1" to remember numerator was negative
	}
	if(*d<0){
		(*d)*=-1;	//if the denominator  is negative i convert it to positive to find GCD
		neg2=1;		// i said "neg2 is equal to 1" to remember denominator was negative
	}
	if(*n==0){
		zer1=1;			//if the numerator is zero i said "zer1 is equal to 1" to pass finding GCD part.
	}
	if(*d==0){
		zer2=1;			//if the denominator is zero i said "zer2 is equal to 1" to pass finding GCD part.
	}
	if(zer1==0 && zer2==0){ //this if checking both number are not zero!!
  		while(a<=(*n)  || a<=(*d)){	//this loop to simplfy both numbers	
  				if((*n)%a==0 && (*d)%a==0){		
  					gcd=a;		
  				}
  				a++;  		
  		}
       }
  	(*n)/=gcd;	
  	(*d)/=gcd;

	if(neg1==1 || neg2==1){					
		if(neg1==1 && neg2==1){			//THIS PART TO CHECK BOTH NUMBER IS NEGATIVE OR JUST ONLY ONE
							//i did not write here because both numbers already are positive now			
							// I CONVERTED THE NUMBER TO POSITIVE IF BOTH NUMBERS ARE NEGATIVE		
		}								
		else if(neg1==1){
			(*n)*=-1;			//IF ONLY ONE NUMBER IS NEGATIVE I CONVERT IT TO AGAIN NEGATIVE
		}
		else if(neg2==1){
			(*d)*=-1;			//IF ONLY ONE NUMBER IS NEGATIVE I CONVERT IT TO AGAIN NEGATIVE
		}
   	 }
   	 
} /* end fraction_div */


