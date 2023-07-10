#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int variable;
	char str[50];
	struct list *next;
}list;


void showNodes(list *n){
	// Until the item equal NULL we show the datas
	while(n->next != NULL){
		printf("%d ",n->variable);
		n = n->next;
	}
	printf("%d\n",n->variable);
}


list *insert(list *linked,int number){
	
	if(linked==NULL){
		linked=(list*)malloc(sizeof(list));
		linked->variable=number;
		linked->next=NULL;
		return linked;
	}	
	if(linked->variable>number){
		list *current=(list*)malloc(sizeof(list));
		current=linked;
		while(current->next!=NULL){
			if(current->next->variable>=number){
				current=current->next;
			}
			else{
				break;
			}	
		}
		
		list *new2=(list*)malloc(sizeof(list));
		new2->variable=number;
		new2->next=current->next;
		current->next=new2;	
		return linked;
	}
	
	else{
		list *new=(list*)malloc(sizeof(list));
		new->variable=number;
		new->next=linked;
		//showNodes(new);
		return new;
	}
	

}

list *addposition(list *linked, int number, int number2){
	list *current=(list*)malloc(sizeof(list));
	current=linked;
	while(current->next!=NULL && current->variable!=number2){
		current=current->next;
	}
	list *temp=(list*)malloc(sizeof(list));
	temp->variable=number;
	temp->next=current->next;
	current->next=temp;
	return linked;
}

list *delete(list *linked, int number){
	list *current=(list*)malloc(sizeof(list));
	current=linked;
	int counter=0;
	int i;
	while(current->next!=NULL && current->next->variable!=number){
		current=current->next;
	}
	
	list *last=(list*)malloc(sizeof(list));
	list *after=(list*)malloc(sizeof(list));
	last=current;
	after=current->next->next;
	free(current->next);
	last->next=after;
	return linked;
}

void reverse(struct list** head)
{
    struct list* previous = NULL;   // the previous pointer
    struct list* current = *head;   // the main pointer
 
    // traverse the list
    while (current != NULL)
    {
        // tricky: note the next node
        struct list* next = current->next;
 
        current->next = previous;    // fix the current node
 
        // advance the two pointers
        previous = current;
        current = next;
    }
 
    // fix the head pointer to point to the new front
    *head = previous;
}


int main(){
	list *linked;
	linked=NULL;
	int number=5;
	while(number>0){
		printf("enter number: ");
		scanf("%d",&number);
		if(number>0){
			linked=insert(linked,number);
			showNodes(linked);
		}
		
	}
	printf("hangi sayiyi eklemek istersiniz: ");
	scanf("%d",&number);
	int number2;
	printf("hangi sayinin onune eklemek istersiniz: ");
	scanf("%d",&number2);
	linked=addposition(linked,number,number2);
	showNodes(linked);
	delete(linked,number);
	showNodes(linked);
	reverse(&linked);
	showNodes(linked);
	return 0;
}
