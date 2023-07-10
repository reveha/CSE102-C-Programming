#include <stdio.h>
#include <string.h>

int main(){
	
	
	// deleting unnecesarry spaces
	char string[100];
	char deleted[100];
	int i;
	int j;
	printf("enter string: ");
	scanf("%[^\n]s",string);
	int len=strlen(string);
	int counter=0;
	for(i=0;i<len-1;i++){
		if(string[i]==' ' && string[i+1]==' '){
			counter++;
		}
		if(counter==1){
			for(j=i;j<len-1;j++){
				string[j]=string[j+1];
			}
			len--;
			counter=0;
			i--;
		}
	}
	string[len]='\0';
	printf("%s\n",string);
	printf("\n");
	
	return 0;
	
	
}
