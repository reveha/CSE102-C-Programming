#include <stdio.h>
#include <string.h>

#define MAX_LEN 200
void alphabeticSort(char arr[][MAX_LEN], int n);
void generateTagParser(char temp[], char arr[]);
void comment();

int main(){
	int choice;
	int n;
	int count;
	
	
	
	do{// my menu
		char temp[100];
		char arr2[100];
		printf("1. to sort\n");
		printf("2. to generate tag parser\n");
		printf("0. to exit\n");
		scanf("%d",&choice);
		if(choice==1){ // menu choice
			printf("enter the count of how many strings you will enter...\n");
			scanf("%d",&count);
			char arr[count][MAX_LEN]; // i created 2d strings
			alphabeticSort(arr,count);
			printf("\n\n");
		}
		else if(choice==2){
			printf("enter string: ");
			scanf(" %s",arr2); // i got the string from user
			fflush(stdin); // clearing buffer
			generateTagParser(temp,arr2);
		}	
		else if(choice!=0){
			printf("you typed incorrectly\n");
		}	
	}while(choice!=0);
	printf("\n\n");
	comment();// printing comments

	
	return 0;
}

void alphabeticSort(char arr[][MAX_LEN], int n){
	int i;
	int j;
	char temp[100];
	printf("enter the strings..\n");
	for(i=0;i<n;i++){
		scanf("%s",arr[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(arr[i],arr[j])>0){ // if arr[i] greater than arr[j] i switched them
				strcpy(temp,arr[j]); // classic switch 
				strcpy(arr[j],arr[i]);
				strcpy(arr[i],temp);
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d. %s\n",i,arr[i]);
	}
}

void generateTagParser(char temp[], char arr[100]){
	int i=0;
	/*
	since the temp string cannot be empty after i used it, when you run the code 2. time there will be mistake.
	*/
	
	int len=strlen(arr);
	if(len<5){ // some assigning operations here
	//strcat is appending 
		temp[0]='<';
		temp[1]='<';
		strcat(temp,arr);
		temp[len+2]='>'; 
		temp[len+3]='>';
		temp[len+4]='\0'; // ending;
		
	}
	else if(len>10){// some assigning operations here
		temp[0]='/';
		temp[1]='+';
		strcat(temp,arr);
		temp[len+2]='+';
		temp[len+3]='/';
		temp[len+4]='\0'; // ending
	}
	else{// some assigning operations here
		temp[0]='*';
		strcat(temp,arr);
		temp[len+2]='*';
		temp[len+3]='\0'; // ending
	}
	printf("\n%s\n",temp);
	strncpy(temp, "",strlen(temp)); // i tried to clear temp file but it doesnot work
	
}
void comment(){
	printf("FUNCTION: alphabeticSort\n\nIt does:\n\n\n\nfirstly i got the strings from user\n\n\n\nsecondly i created a nested loop to sort strings\n\n\n\n i checked every string with each other and if strcmp returned a value that greater than zero that means this string greater than other\n\n\n\n i switched them\n\n\n\n");
	printf("FUNCTION: generateTagParser\n\n\nIT does:\n\n\nFirstly i got the string from user in the function\n\n\n\n i counted the length of the string with strlen function\n\n\n\nafter that i created 3 if statement to verify length of the string\n\n\n\nfor example if len less than 5 i assigned \narr[0]='<'\narr[1]='<'\nstrcat(temp,arr)// to append temp string\ntemp[len+2]='>';\ntemp[len+3]='>';\ntemp[len+4]='NULL'; // ending;\n\n\n i have to put 'NULL' char end of the string.\n\nFinally i printed the result\n\n");
}





