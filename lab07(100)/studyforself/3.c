#include <stdio.h>
#include <string.h>

int main(){
	// most repeating char 
	char string[100];
	char letters[100];
	printf("Enter string: ");
	scanf("%[^\n]s",string);
	int len=strlen(string);
	int array[len];
	int max=0;
	int i,j;
	int counter=1;
	int my_index;
	char temp;
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(string[i]==string[j]){
				counter++;
				if(counter>=max){
					my_index=i;
				}
			}
		}
		if(counter>max){
			max=counter;
		}
		counter=1;
	}
	printf("Most occuring char is %c, %d times\n",string[my_index],max);

	
	
	return 0;
}
