#include <stdio.h>
#include <string.h>

int main(){
	
	
	// deleting specific char in a string
	char string[100];
	char deleted[100];
	printf("Enter string: ");
	scanf("%[^\n]s",string);
	printf("Enter character that you want to delete: ");
	char c;
	scanf(" %c",&c);
	int i,j;
	
	for(i=0,j=0;i<strlen(string);j++,i++){
		if(string[i]==c){
			j--;
		}
		else{
			deleted[j]=string[i];
		}
	}
	printf("Deleted %c char in a string : %s\n",c,deleted);
	
	
	
	return 0;
}

