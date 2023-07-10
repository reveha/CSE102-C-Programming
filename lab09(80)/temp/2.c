#include <stdio.h>
#include <ctype.h>

int repeat(char str[],char ch);
int caps(char str[]);


int main(){
	char str[100],ch;
	printf("Enter your string: ");
	scanf("%[^\n]s",str);
	printf("Enter the letter that you want to count: ");
	scanf(" %c",&ch);	
	int result=repeat(str,ch);
	printf("There are %d times '%c' char in '%s'\n",result,ch,str);
	result=caps(str);
	printf("There are %d times capital letter in '%s'\n",result,str);
	return 0;
}

int repeat(char str[],char ch){
	static int counter=0;
	static int loop=0;
	if(str[loop]=='\0'){
		return counter;
	}
	else{
		if(str[loop]==ch){
			counter++;
			
		}
		loop++;
		return repeat(str,ch);
	}
	
}


int caps(char str[]){
	static int counter=0;
	static int loop=0;
	
	if(str[loop]=='\0'){
		return counter;
	}
	if(isupper(str[loop])){
		counter++;
	}
	loop++;
	return caps(str);
	
}



















