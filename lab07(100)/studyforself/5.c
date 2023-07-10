#include <stdio.h>
#include <string.h>

int main(){
	
	
	// deleting repeating chars
	char string[100];
	char deleted[100];
	printf("Enter string: ");
	scanf("%[^\n]s",string);
	int array[25];
	int i,j,k;
	int len=strlen(string);
	for(i=0;i<25;i++){
		array[i]=0;
	}
	for(i=0;i<25;i++){
		if(string[i]<='z' && string[i]>='a'){
			array[string[i]-97]++;
		}
		else if(string[i]<='Z' && string[i]>='A'){
			array[string[i]-65]++;
		}
	}
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(string[i]==string[j] && string[i]!=' '){
				for(k=j;k<len;k++){
					string[k]=string[k+1];
				}	
			}
		}
	}
	int index=0;
	

	printf("Deleted string : %s\n",string);
	
	return 0;
}
