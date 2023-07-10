#include <stdio.h>


int sum_of_digit(int number);
int max(int array[], int times);
int min(int array[], int times);
int palindrome(int number);
int reverse(int num);
int isPalindrome(int num);



int main(){
	
	int number;
	int times;
	printf("Enter the number that will be taken sum of the digits: ");
	scanf("%d",&number);
	int result=sum_of_digit(number);
	printf("Sum of digits for %d number is %d\n",number,result);
	
	printf("Enter how many number you will enter: ");
	scanf("%d",&times);
	int array[times];
	int i;
	for(i=0;i<times;i++){
		scanf("%d",&array[i]);
	}
	
	printf("Minimum value of the array is %d\nMaximum value of the array is %d\n",min(array,times),max(array,times));
	printf("Enter a number to check palindrome or not: ");
	scanf("%d",&number);
	printf("%d",palindrome(number));
	
	
	return 0;
}



int sum_of_digit(int number){
	static int sum=0;
	int temp_number2=number;
	int temp_number=temp_number2%10;
	temp_number2=number/10;
	sum+=temp_number;
	if(temp_number2==0){
		return sum;
	}
	sum_of_digit(temp_number2);
}

int max(int array[], int times){
	static int loop=0;
	static int max2=0;
	if(loop==times){
		return max2;
	}
	else{
		if(array[loop]>max2){
			max2=array[loop];
			
		}
		loop++;
		max(array,times);
	}
	

	
}
int min(int array[], int times){
	static int loop2=0;
	static int min2=99999999;
	if(loop2==times){
		return min2;
	}
	else{
		if(array[loop2]<min2){
			min2=array[loop2];		
		}
		loop2++;
		min(array,times);
	}
	

}

int palindrome(int number){
	
	static int number1;
	static int number2;
	int number3;
	number1=number;
	number3=number1%10;
	number1=number/10;
	
	
	
	

	
	
}
int isPalindrome(int num)
{
    if(num == reverse(num))
    {
        return 1;
    }
    return 0;
}


int reverse(int num)
{
    int rem;
    static int sum=0;
    if(num!=0){
            rem=num%10;
            sum=sum*10+rem;
            reverse(num/10);
    }
        else
            return sum;
    return sum;
} 








