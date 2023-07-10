#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "lab14_data.bin"
#define NUMOFITEMS 2


typedef struct item_t{
	int id;
	char name[50];
	float price;
}item_t;

typedef union {
	int phone;
	char mail[50];
}contactInfo_t;

typedef struct itemWithCont_t{
	int id;
	char name[50];
	float price;
	int phone;
	char mail[50];
}itemWithCont_t;

int counter=0;
FILE *ptr;
void printItem(item_t *items){
	int i;
	int j;
	printf("\nPrinting....\n\n");
	for(i=0,j=counter-2;j<counter;i++,j++){
		printf("Id:\t%d\n",items[j].id);
		printf("Name:\t%s\n",items[j].name);
		printf("Price:\t%.2f\n",items[j].price);
	}
}

item_t *getItems(item_t *items, int size){
	printf("Id=> %d\n",counter+1);
	items[size].id=counter+1;
	printf("Name=> ");
	scanf(" %s",items[size].name);
	printf("Price=> ");
	scanf("%f",&items[size].price);
	counter++;
	return items;
}
 item_t readAnItem(FILE *ptr){
 	item_t temp;
 	int i;
 	ptr=fopen(FILENAME,"ab+");
 	printf("\nReading from file:\n");
 	for(i=0;i<counter;i++){
 	
 		fread(&temp,sizeof(item_t),1,ptr);
 		printf("Id=>\t%d\n",i+1);
 		printf("Name=>\t%s\n",temp.name);
 		printf("Price=>\t%.2f\n",temp.price);
 		printf("\n");
 	}
 	fclose(ptr);
}

int writeItems(char filename[],item_t *items, int size){
	
	ptr=fopen(filename,"ab+");
	if(ptr==NULL){
		return 0;
	}
	
	int i;
	
	for(i=counter-2;i<counter;i++){
		fwrite(&items[i],sizeof(item_t),1,ptr);
	}
	
	printf("\nSuccesfully wrote data to file\n\n");
	fclose(ptr);
	return 1;
}

void contactInfoAdder(item_t *items, int size, itemWithCont_t contacts[]){

	int i;
	contactInfo_t temp;
	for(i=0;i<counter;i++){
		printf("\nEnter the phone for %s=> ",items[i].name);
		scanf("%d",&temp.phone);
		contacts[i].phone=temp.phone;
		printf("Enter a mail for %s=> ",items[i].name);
		scanf(" %s",temp.mail);
		strcpy(contacts[i].mail,temp.mail);
		contacts[i].id=i+1;
		contacts[i].price=items[i].price;
		strcpy(contacts[i].name,items[i].name);
	}
}

void printItemWithContactInfo(itemWithCont_t itemsWithCont[]){
	printf("\nPrinting with contact information...\n\n");
	int i;
	for(i=0;i<counter;i++){
		printf("\nId=>\t%d\n",i+1);
		printf("Name=>\t%s\n",itemsWithCont[i].name);
		printf("Price=>\t%.2f\n",itemsWithCont[i].price);
		printf("Phone number=>\t%d\n",itemsWithCont[i].phone);
		printf("Mail=>\t%s\n",itemsWithCont[i].mail);
	}
}
void flushInputBuffer(){
	char tmp;
	do{
		scanf("%c",&tmp);
	}while(tmp!='\n');
}


int main(){
	item_t *items;
	items=(item_t*)malloc(sizeof(item_t)*50);
	itemWithCont_t contacts[50];
	items[counter]=*getItems(items,counter);
	items[counter]=*getItems(items,counter);
	printItem(items);
	writeItems(FILENAME,items,0);
	items[counter]=*getItems(items,counter);
	items[counter]=*getItems(items,counter);
	writeItems(FILENAME,items,0);
	readAnItem(ptr);
	printItem(items);
	
	contactInfoAdder(items,counter,contacts);
	printItemWithContactInfo(contacts);
	return 0;
}
