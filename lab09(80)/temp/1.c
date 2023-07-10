#include <stdio.h>


/* Function declaration */
int lcm(int a, int b, int multiple);
int gcd(int a, int b);
int fibonacci(int n);

int main()
{
    int num1, num2, LCM;
    int multiple=0;
    int limit;
    /* Input two numbers from user */
    printf("Enter any two numbers to find lcm: ");
    scanf("%d%d", &num1, &num2);
    
    /*
     * Ensures that first parameter of LCM function 
     * is always less than second 
     */
    if(num1 > num2)
        LCM = lcm(num2, num1,multiple);
    else
        LCM = lcm(num1, num2,multiple);
        
    printf("LCM of %d and %d = %d\n", num1, num2, LCM);
    int gcd_result=gcd(num1,num2);
    printf("gcd of %d and %d = %d\n", num1, num2, gcd_result);
    printf("Enter the fibonacci limit: ");
    scanf("%d",&limit);
    int i;
    for(i=1;i<=limit;i++){
    	printf("%d ",fibonacci(i));
    }
    return 0;
}


/**
 * Recursive function to find lcm of two numbers 'a' and 'b'.
 * Here 'a' needs to be always less than 'b'.
 */
int lcm(int a, int b, int multiple)
{
    
    /* Increments multiple by adding max value to it */
    multiple += b;
    
    /*
     * Base condition of recursion
     * If found a common multiple then return the multiple.
     */
    if((multiple % a == 0) && (multiple % b == 0))
    {
        return multiple;
    }
    else 
    {
        return lcm(a, b,multiple);
    }
}

int gcd(int a, int b){
	int gcd2=0;
	if(a%b==0){
		gcd2=b;
	}	
		
	else{
		return gcd(b,a%b);
	}
	return gcd2;
}
int fibonacci(int n){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}
