#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indeks;
typedef struct{
	char title[50];
	char author[50];
	char sb[50];
	int year;
	
}book;

book *st;
book *st2;
char temp2[50];

void get_info(int index){
	fflush(stdin);
	printf("Please enter book title: ");
	scanf(" %[^\n]s",st[index].title);
	printf("Please enter book author = ");
	scanf(" %[^\n]s",st[index].author);
	if(index==0){
		strcpy(temp2,st[index].author);
	}
	printf("Please enter book subject = ");
	scanf(" %[^\n]s",st[index].sb);
	printf("Please enter book year = ");
	scanf("%d",&st[index].year);
	printf("\n****************\n");
}
void get_title(){
	char str[50];
	int i;
	printf("Enter a books title = ");
	scanf(" %[^\n]s",str);
	for(i=0;i<indeks;i++){
		if(strcmp(str,st[i].title)==0){
			printf("Book found\n");
			if(i==0){
				printf("Title -> %s\nAuthor -> %s\nSubject -> %s\nYear -> %d\n",st[i].title,temp2,st[i].sb,st[i].year);
			}
			else{
				printf("Title -> %s\nAuthor -> %s\nSubject -> %s\nYear -> %d\n",st[i].title,st[i].author,st[i].sb,st[i].year);
			}	
			printf("*****************\n");
			break;
		}
	}
	printf("*****************\n");
	
}
void get_author(){
	char str[50];
	int i;
	printf("Enter a books author = ");
	scanf(" %[^\n]s",str);
	for(i=0;i<indeks;i++){
	if(i!=0){
		if(strcmp(str,st[i].author)==0){
			printf("Book found\n");
			if(i==0){
				printf("Title -> %s\nAuthor -> %s\nSubject -> %s\nYear -> %d\n",st[i].title,temp2,st[i].sb,st[i].year);
			}
			else{
				printf("Title -> %s\nAuthor -> %s\nSubject -> %s\nYear -> %d\n",st[i].title,st[i].author,st[i].sb,st[i].year);
			}	
			printf("*****************\n");
			break;
		}
	}
	else{
		if(strcmp(str,temp2)==0){
			printf("Book found\n");
			if(i==0){
				printf("Title -> %s\nAuthor -> %s\nSubject -> %s\nYear -> %d\n",st[i].title,temp2,st[i].sb,st[i].year);
			}
			else{
				printf("Title -> %s\nAuthor -> %s\nSubject -> %s\nYear -> %d\n",st[i].title,st[i].author,st[i].sb,st[i].year);
			}	
			printf("*****************\n");
			break;
		}
	}
	}
	printf("*****************\n");
}
void get_sb(){
	char str[50];
	int i;
	printf("Enter a books subject = ");
	scanf(" %[^\n]s",str);
	for(i=0;i<indeks;i++){
		if(strcmp(str,st[i].sb)==0){
			printf("Book found\n");
			if(i==0){
				printf("Title -> %s\nAuthor -> %s\nSubject -> %s\nYear -> %d\n",st[i].title,temp2,st[i].sb,st[i].year);
			}
			else{
				printf("Title -> %s\nAuthor -> %s\nSubject -> %s\nYear -> %d\n",st[i].title,st[i].author,st[i].sb,st[i].year);
			}	
			printf("*****************\n");
			break;
		}
	}
	printf("*****************\n");
}

void get_sorted(){
	int min=0;
	int i,j;
	int array[indeks];
	int temp;
	for(i=0;i<indeks;i++){
		array[i]=st[i].year;
	}
	for(i=0;i<indeks;i++){
		for(j=i+1;j<indeks;j++){
			if(array[j]>array[i]){
				temp=array[j];
				array[j]=array[i];
				array[i]=temp;	
			}
		}
	}
	printf("********************\n\nList of Books\n************************\n");
	for(j=0;j<indeks;i<j++){
		for(i=0;j<indeks;i++){
			if(array[j]==st[i].year){
				if(i==0){
					printf("%d. Book\n\nTitle -> %s\nAuthor -> %s\nSubject -> %s\nYear ->%d\n",j+1,st[i].title,temp2,st[i].sb,st[i].year);
				}
				else{
					printf("%d. Book\n\nTitle -> %s\nAuthor -> %s\nSubject -> %s\nYear ->%d\n",j+1,st[i].title,st[i].author,st[i].sb,st[i].year);
				}	
				printf("**************************\n");
				break;
			}
		}
	}
}
void list_all_book(){
	int i;
	printf("***************************\n\nList of Books\n****************************\n");
	for(i=0;i<indeks;i++){
		if(i==0){
			printf("%d. Book\n\nTitle -> %s\nAuthor -> %s\nSubject -> %s\nYear ->%d\n",i+1,st[i].title,temp2,st[i].sb,st[i].year);
		}
		else{
			printf("%d. Book\n\nTitle -> %s\nAuthor -> %s\nSubject -> %s\nYear ->%d\n",i+1,st[i].title,st[i].author,st[i].sb,st[i].year);
		}	
		printf("************************\n");
	}
}
void submenu(){
	int choice;
	do{
		printf("SUBMENU\n");
		printf("\t1. Get by Title\n");
		printf("\t2. Get by Author\n");
		printf("\t3. Get by Subject\n");
		printf("\t4. Sorted List by Year (DESC)\n");
		printf("\t5. List All Books\n");
		printf("\t6. EXIT SUBMENU\n");
		printf("Choose = ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				get_title();
				break;
			case 2:
				get_author();
				break;
			case 3:
				get_sb();
				break;
			case 4:
				get_sorted();
				break;
			case 5:
				list_all_book();
				break;
			case 6:
				printf("RETURNED MAIN MENU\n");
				break;
			default:
				printf("TRY AGAIN\n");
				break;					
		}
		
	}while(choice!=6);
}


void clear(){
	int i;
	for(i=0;i<indeks;i++){
		strcpy(st2[i].title,st[i].title);
		strcpy(st2[i].author,st[i].author);
		strcpy(st2[i].sb,st[i].sb);
		st2[i].year=st[i].year;
	}
	
}

void fill(){
	int i;
	for(i=0;i<indeks-1;i++){
		strcpy(st[i].title,st2[i].title);
		strcpy(st[i].author,st2[i].author);
		strcpy(st[i].sb,st2[i].sb);
		st[i].year=st2[i].year;
	}
}



int main(){
	
	st=(book *)malloc(sizeof(book)*indeks);
	strcpy(st[0].author,"");
	int choice;
	int i;
	indeks=2;
	int check=0;
	do{
		printf("1. Add New Book\n");
		printf("2. List Books\n");
		printf("3. EXIT\n");
		printf("\nChoose = ");
		scanf("%d",&choice);
		printf("****************\n");
		switch(choice){
			case 1:
				if(check==0){
					for(i=0;i<indeks;i++){
						get_info(i);
					}
					strcpy(st[0].author,temp2);
					check=1;
				}
				else{
					st2=(book *)malloc(sizeof(book)*indeks);
					clear();
					indeks++;
					st=(book*)calloc(indeks,sizeof(book));
					fill();
					get_info(indeks-1);
				}	
				
				break;
			case 2:
				submenu();
				break;
			case 3:
				printf("GOOD BYE\n");
				break;
			default:
				printf("TRY AGAIN\n");
				break;		
		}
		
		
		
	}while(choice!=3);





	
	
	
	return 0;
}













