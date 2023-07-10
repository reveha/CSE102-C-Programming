#include <stdio.h>
#include "utils.h"



//PART 1
int find_divisible(int x, int y, int z){
	int t;
	if(x>=y){
		return -1;
	}
	else{
		for(t=x+1;t<y;t++){
			if(t%z==0){
				return t;
			}
		}
	}
	return -1;
}

int find_nth_divisible(int n, int f_i, int z){
	n*=z;		//i multiplied it with divisor and i added it to first integer that can be divided by z.
	f_i+=n;
	return f_i;
}

//PART 2
int validate_identity_number(char identity_number[]){
	int counter=0;
	int i=0;
	int odd_sum=0,even_sum=0;
	int subtract, temp;
	int first_ten_sum=0;
	while(identity_number[i]!='\0'){	//this is my strlen() function.
		counter++;	
		i++;
	}
	
	if(counter!=11){
		return 0; //if identity number has not 11 characters, i returned zero.
	}
	
	if(identity_number[0]-48==0){ // i added -48 to remove ascii values. 48 means zero in ascii table.
		return 0;		//if the first digit is zero, i returned zero.
	}
	
	for(i=0;i<counter;i++){
		if(!(identity_number[i]>47 && identity_number[i]<58)){ // i am checking here to understant all digits are integer. if they are not i returned zero
			return 0;
		}
	}

	for(i=1;i<8;i+=2){
		// this loop to add even digits until 8. digit.
		even_sum+=identity_number[i]-48; // i added -48 to remove ascii values. 48 means zero in ascii table.
	}
	
	for(i=0;i<9;i+=2){
		// this loop to add odd digits until 9. digit.
		odd_sum+=identity_number[i]-48; // i added -48 to remove ascii values. 48 means zero in ascii table.
	}

	temp=odd_sum; // i said temp is equal to sum of odd digits for not forgetting sum of odd digits.
	odd_sum*=7;
	subtract=odd_sum-even_sum;  
	
	if(subtract%10!=identity_number[9]-48){ // i added -48 to remove ascii values. 48 means zero in ascii table.
		return 0;
	}
	
	first_ten_sum=temp+even_sum+identity_number[9]-48; // i added -48 to remove ascii values. 48 means zero in ascii table.
	if(first_ten_sum%10!=identity_number[10]-48){ // i added -48 to remove ascii values. 48 means zero in ascii table.
		return 0;
	}
	return 1;
	
	
}

int create_customer(char identity_number[], int password){
	FILE *ptr=fopen("customeraccount.txt","w"); // i opened the file with write mode.
	int temp;  // to find how many digit password has.
	int counter=0;
	temp=password; 
	while(temp!=0){	// this loop my strlen() function.
		temp/=10;
		counter++;
	}
	if(counter!=4){
		return 0;
	}
	fprintf(ptr,"%s,%d",identity_number,password);  
	fclose(ptr); // i need to close my file. If i do not close it, it will work until the program ends.
	return 1;
}

//PART 3
int check_login(char identity_number[], int password){
	
	FILE *ptr=fopen("customeraccount.txt","r"); // i opened the same file with read mode.
	int i=0;
	char ch; // to compare with each digits of the array which is "identity_number".
	int key; // to compare with password
	for(i=0;i<11;i++){
		fscanf(ptr,"%c",&ch);
		if(ch!=identity_number[i]){
			return 0;
		}
	}
	fscanf(ptr,"%c",&ch);	//	I am getting here the comma ',' in customeraccount.txt
	fscanf(ptr,"%d",&key);
	if(key!=password){
		return 0;	
	}
	
	fclose(ptr);	// i need to close my file. If i do not close it, it will work until the program ends.
	return 1;
}

int withdrawable_amount(float cash_amount){
	int temp_cash; // i created an integer variable to keep just integer part of float number
	temp_cash=cash_amount; // i assigned it to cash_amount.
	temp_cash/=10;	
	temp_cash*=10;
	/*
		Since 10 can be divided by 20 and 50, i do not need to check that the number can be divided by 20 and 50. If i divided the integer number to 10, 
		and if i multiply it to 10 again, i get the result.
	*/
	return temp_cash;	
}
