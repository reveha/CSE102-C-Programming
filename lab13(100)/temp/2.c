#include <stdio.h>
#include <stdlib.h>



typedef struct node{
	int data;
	struct node *next;
}node;

void show(node *l){
	
	while(l->next!=NULL){
		printf("%d>",l->data);
		l=l->next;
	}
	printf("%d\n",l->data);
}

node *adhead(node *l, int data){
	
		node *new=(node*)malloc(sizeof(node));
		new->data=data;
		new->next=l;
		return new;
		
	
}


void addlast(node *l, int data){
	if(l==NULL){
		l->data=data;
		l->next=NULL;
		return;
	}
	while(l->next!=NULL){
		l=l->next;
	}
	l->next=(node*)malloc(sizeof(node));
	l=l->next;
	l->data=data;
	l->next=NULL;
}	



void reverse(node *l){
	node *temp=NULL;	
	while(l!=NULL){
		temp=adhead(temp,l->data);
		l=l->next;
	}
	show(temp);
}

int main(){
	node *l=NULL;
	l=(node*)malloc(sizeof(node));
	addlast(l,10);
	addlast(l,90);
	addlast(l,55);
	//show(l);
	l=adhead(l,41);
	//show(l);
	reverse(l);
	//show(l);
	return 0;
}
