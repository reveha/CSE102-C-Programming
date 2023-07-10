#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{ // my struct 
	char bookname[30];
	char author[30];
	int year;
	struct node *next;
}node;


void print_nodes(node *root){ // printing the struct
	while(root->next!=NULL){
		printf("%s %s %d\n\n",root->bookname,root->author,root->year);
		root=root->next;
	}
	printf("%s %s %d\n",root->bookname,root->author,root->year);
}


node *instert_node(node *root, char *bookname, char *author, int year){ // this function insert new elements according to the years
	//printf("12%s %s %d\n",bookname,author,year);
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		strcpy(root->bookname,bookname);
		strcpy(root->author,author);
		root->year=year;
		root->next=NULL;
	//	printf("123%s,%s,%d\n",root->bookname,root->author,root->year);
		return root;
	}
	if(root->year<year){ 
		node *current=(node*)malloc(sizeof(node));
		current=root;
		while(current->next!=NULL){
			if(current->next->year<=year){ //this if to check correct position for year
				current=current->next;
			}
			else{
				break;
			}	
		}
		
		node *new2=(node*)malloc(sizeof(node)); // created new struct
		new2->year=year;
		strcpy(new2->bookname,bookname); // copying strings
		strcpy(new2->author,author);
		new2->next=current->next; //it points to current next
		current->next=new2;	
		//printf("12345%s,%s,%d\n",root->bookname,root->author,root->year);
		return root;
	}
	else{
		node *new=(node*)malloc(sizeof(node));
		new->year=year;
		strcpy(new->bookname,bookname);
		strcpy(new->bookname,author);
		new->next=root;
		//showNodes(new);
		return new;
	}
}

node *delete_node(node *root, char *bookname){
	int check=0;
	if(strcmp(root->bookname,bookname)==0){ // this to check if the name is first index. i need to check it otherwise i will get segfault
		node *second=NULL;
		second=root->next;
		free(root);
		root=second;
		return root;
	}
	
	node *current=(node*)malloc(sizeof(node));
	node *current2=(node*)malloc(sizeof(node));
	current=root;
	current2=root;
	while(current2->next!=NULL){
		current2=current2->next;
		if(strcmp(current2->bookname,bookname)==0){ // checking in the struct if there is no that name book
			check=1;
		}
	}
		
	if(check==1){ // i break the structu into to 2 sturct and i freed deleted element finally i pointed first part to second part
		while(current->next!=NULL && strcmp(current->next->bookname,bookname)!=0){ // i found here the latest element before the user want
			current=current->next;
			if(strcmp(current->next->bookname,bookname)==0){
				check=1;
			}
		}
		node *last=(node*)malloc(sizeof(node));
		node *after=(node*)malloc(sizeof(node));
		last=current; //first part
		after=current->next->next; // second part
		free(current->next);
		last->next=after;
	}
	else{
		printf("%s is not in the list.\n\n",bookname);
	}
	return root;
}


node *readfile(){ // basic readfile function 
	node *root;
	root=NULL;
	FILE *ptr=fopen("source.txt","a+");
	char str[50];
	char str2[50];
	int year;
	printf("Reading the source.txt file...\n");
	while(!feof(ptr)){
		fscanf(ptr," %s %s %d\n",str,str2,&year);
		//printf("\n\n%s %s %d\n\n",str,str2,year);
		root=instert_node(root,str,str2,year); // calling every time we get string
	}
	printf("Printing the linked list...\n\n");
	//print_nodes(root);
	
	
	return root;
}



int main(){
	node *root;
	root=NULL;
	char str[50];
	root=readfile();
	print_nodes(root);
	printf("\nwhich book dou you want to delete? ");
	scanf(" %s",str);
	root=delete_node(root,str);
	printf("\nPrinting the linked list...\n\n");
	print_nodes(root);
	
	
	
	
	
	
	return 0;
}
