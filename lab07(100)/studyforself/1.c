#include <stdio.h>
#include <string.h>


int main(){
	
	char string[100];
	char reverse[100];
	char temp;
	int i;
	int j; // to keep length of string
	int len;
	printf("Enter a string: ");
	scanf("%[^\n]s",string);
	printf("Normal string: %s\n",string);
	len=strlen(string);
	j=len-1;
	for(i=0;i<len;i++){
		reverse[j]=string[i];
		j--;
	}
	j=len-1;
	reverse[len]='\0';
	for(i=0;i<len/2;i++){
		temp=string[i];
		string[i]=string[j];
		string[j]=temp;
		j--;
	}
	printf("Reversed string is: %s\n",string);
	printf("Reversed string is: %s\n",reverse);
	
	
	return 0;
}
