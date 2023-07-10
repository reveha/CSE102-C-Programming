#include <stdio.h>
#include "utils.h"

int main(){
	//PART 1
	printf("---------PART 1---------\n\n");
	int x,y,z,n;
	int query=1; // to check password is 4 digits. for loop. i used it for do while loop
	int f_i; // TO CHECK WHICH VALUE WAS RETURNED
	printf("Enter the first integer: ");
	scanf("%d",&x);
	printf("Enter the second integer: ");
	scanf("%d",&y);
	printf("Enter the divisor: ");
	scanf("%d",&z);
	f_i=find_divisible(x,y,z);
	if(f_i==-1){
		printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
	}
	else{
		printf("The first integer between %d and %d divided by %d is %d\n",x,y,z,f_i);
		printf("Enter the number how many next: ");
		scanf("%d",&n);

		f_i=find_nth_divisible(n,f_i,z);
		if(f_i>=y){ // since i do not know the up limit when the program in the function, i compare the limit here.
			printf("Error code -999:\n");
			printf("No possible to find %dth disivible between %d and %d divided by %d\n",n+1,x,y,z);
		}
		else{
			printf("The %dth integer between %d and %d divided by %d is %d\n",n+1,x,y,z,f_i);
		}	
	}

	//PART 2
	char identity_number[50];
	int password;
	int i,ret_num;
	float cash_amount;
	printf("\n---------PART 2---------\n\n");
	printf("Enter your identity number: ");
	scanf("%s",identity_number);
	ret_num=validate_identity_number(identity_number);	
	if(ret_num==0){
		printf("Invalid identity number!\n");	
	}
	else{
		do{
			printf("Enter your password: ");
			scanf("%d",&password);
			ret_num=create_customer(identity_number,password);
			if(ret_num==0){
				printf("Your password must be 4 digits!\n");
				query=0;
			}
			else{
				query=1;
			}
		}while(query==0); // this loop to check password is four digits.
		
		
		// PART3
			printf("\n---------PART 3---------\n\n");
			printf("Enter your identity number: ");
			scanf("%s",identity_number);
			printf("Enter your password: ");
			scanf("%d",&password);
			ret_num=check_login(identity_number,password);
			if(ret_num==0){
				printf("Invalid identity number or password.\n");
			}
			else{
				printf("Login Successful.\n");
				printf("Enter your withdraw amount: ");
				scanf("%f",&cash_amount);
				ret_num=withdrawable_amount(cash_amount);
				printf("Withdrawable amount is: %d\n",ret_num);	
			}
	}
	

	return 0;
}
