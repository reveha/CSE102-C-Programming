#include <stdio.h>
#include <string.h>

int main(){
	
	char string[100];
	char reverse[100];
	int word=0;
	int i,j;
	int len;
	int last_index;
	int c=0;
	int k=0;
	printf("Enter string: ");
	scanf("%[^\n]s",string);
	len=strlen(string);
	last_index=len-1;
	for(i=0;i<last_index;i++){
		if(string[i]==' ' && string[i+1]!=' '){
			word++;
			
		}
		else{
			c=1;
		}
	}
	if(c==1){
		word++;
	}
	printf("There are %d word in the string\n",word);
	int index=0;
	int end_word=len-1;
	
	
	
	
	
	
	
	
	
	return 0;
}
