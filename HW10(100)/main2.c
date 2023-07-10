#include <stdio.h>
#include <stdlib.h>
#define STACK_BLOCK_SIZE 10 // my first size of stack
#define ERROR_VALUE -5 // i will return this WHEN I TRY TO POP ELEMENT IN A STACK WHICH IS EMPTY STACK
typedef struct{
	int currentsize;
	int maxsize;
	int *array;
}stack;



int full_or_not(stack *s){
	if(s->currentsize==s->maxsize-1){
		return 1; // that means stack is full
	}
	else if(s->currentsize==-1){
		return 2;// that means stack is empty
	}
	return 0; // that means stack is available
}


void push(stack *s, int d){
	int check;
	check=full_or_not(s);
	if(check==1){ // that means stack is full i cannot add any element to stack
		return;
	}
	s->currentsize++; // incremented currentsize 
	s -> array[s -> currentsize] = d; // assignin the coming number
	//printf("%d\n",s->array[s->currentsize]);
}

int pop(stack *s){
	int check;
	check=full_or_not(s);
	if(check==2){ // that means if stack is empty i cannot pop any element so i need to return ERROR_VALUE
		return ERROR_VALUE;
	}
	return s -> array[s -> currentsize--]; // i return that currentsize and i decresed the currentsize
}

void increment_or_decrement_size_of_stack(stack *s, stack *t, stack *f){
	if(s->maxsize!=STACK_BLOCK_SIZE){ // that if statements is checking the size of the tower is not equal to 10
		// if it is not equal to 10 i need to mallocate it again
		s->array=(int *)malloc(sizeof(int) * s->maxsize);
		t->array=(int *)malloc(sizeof(int) * s->maxsize);
		f->array=(int *)malloc(sizeof(int) * s->maxsize);
	}
}

stack *init_return(){ // initializing an empty stack
	stack *temp;
	temp=(stack*)malloc(sizeof(stack));
	temp->array=(int *)malloc(sizeof(int) * STACK_BLOCK_SIZE);
	temp->currentsize=-1; // i will increment this currentsize when i push a new element...
	return temp;
}

int init(stack *s){
	if(s->currentsize==-1){ // i check currentsize. if it is not equal to -1 that means stack is not created
		return 1;
	}
	return 0;
}

void print_disks(char from, char to, int number){
	printf("Move the disk %d from '%c' to '%c'\n",number,from,to);
}

void move_disks(stack *s, stack *f,char a, char b){
	int check1;
	int check2;
	check1=pop(s); // getting the pop value
	check2=pop(f); // getting the pop value
	//printf("check1: %d\ncheck2: %d\n\n",check1,check2);
	if(check1==ERROR_VALUE){ // that means stack *s is empty // i need to push into stack *s with check2
		push(s,check2);
		print_disks(b,a,check2);
	}
	else if(check2==ERROR_VALUE){ // that means stack *f is empty // i need to push into stack *f with check1
		push(f,check1);
		print_disks(a,b,check1);
	}
	else if(check1>check2){ // since the rule is greater number cannot be above a lower number, i need to check this rule here...
		push(s,check1); // i need to push greater number firstly, after that i can push lower number
		push(s,check2);
		print_disks(b,a,check2);
	}
	else if(check2>check1){// since the rule is 'greater number cannot be above a lower number', i need to check this rule here...
		push(f,check2);// i need to push greater number firstly, after that i can push lower number
		push(f,check1);
		print_disks(a,b,check1);
	}
}

void tower_of_hanoi(stack *start, stack *temp, stack *final){
	
	int number_of_moves=1; // that is my number of moving; it is (2^n)-1
	int i;
	char s='1',t='2',f='3'; // these are my blocks
	for(i=0;i<start->maxsize;i++){
		number_of_moves*=2; 
	}
	number_of_moves-=1; // i found the number of moves
	for(i=start->maxsize;i>0;i--){
		push(start,i); // i push start stack all numbers
	}
	/*
	
	For an even number of disks:

	make the legal move between pegs A and B (in either direction),
	make the legal move between pegs A and C (in either direction),
	make the legal move between pegs B and C (in either direction),
	repeat until complete.
	
	For an odd number of disks:

	make the legal move between pegs A and C (in either direction),
	make the legal move between pegs A and B (in either direction),
	make the legal move between pegs B and C (in either direction),
	repeat until complete.

	*/
	for(i=0;i<number_of_moves;i++){
		if(start->maxsize%2==0){ // this is for even numbers
			if(i%3==0) 
				move_disks(start,temp,s,t);
			else if(i%3==1)	
				move_disks(start,final,s,f);
			else	
				move_disks(temp,final,t,f);
		}
		else{ // this is for odd numbers
			if(i%3==0)
				move_disks(start,final,s,f);
			else if(i%3==1)
				move_disks(start,temp,s,t);
			else	
				move_disks(temp,final,t,f);
		}
	}
	
}

/*
void tower(char from_peg, char to_peg, char aux_peg, int n){
	if(n==0){
		return;
	}
		tower(from_peg,aux_peg,to_peg,n-1);
		printf("Move disk %d from peg %c to peg %c\n",n,from_peg,to_peg);
		tower(aux_peg,to_peg,from_peg,n-1);
}*/

int main(){
	stack *start;
	stack *temp;
	stack *final;
	int check=0;
	int number;
	start=init_return(); //creating new empty stack
	temp=init_return(); //creating new empty stack
	final=init_return(); //creating new empty stack
	check=init(start); //checking if stack is created or not
	if(check==0){
		printf("\n\nError occured while creating stack!!\n\n");
		return 0;
	}
	check=init(temp); //checking if stack is created or not
	if(check==0){
		printf("\n\nError occured while creating stack!!\n\n");
		return 0;
	}
	check=init(final); //checking if stack is created or not
	if(check==0){
		printf("\n\nError occured while creating stack!!\n\n");
		return 0;
	}
	else{
		printf("Stack is succesfully created\n");
		printf("Enter Tower size: ");
		scanf("%d",&start->maxsize); // i got the maxsize into the start stack
		temp->maxsize=start->maxsize;
		final->maxsize=start->maxsize;
		increment_or_decrement_size_of_stack(start,temp,final); // checking the size of tower lower or greater than 10
		tower_of_hanoi(start,temp,final);
	}
	

	return 0;
}



