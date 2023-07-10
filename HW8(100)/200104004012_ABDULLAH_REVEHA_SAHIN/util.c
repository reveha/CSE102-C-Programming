#include <stdio.h>
#include <stdlib.h>
#include "util.h"


void generate_sequence(int xs, int currentlen, int seqlen, int *seq){
	if(currentlen==seqlen){ // exit the recursive function. end of the index!!
		return ;
	}
	seq[currentlen]=xs; // assigning
	if(xs%2==0){ //these if statements are for function 
		xs/=2;
	}
	else{
		xs=3*xs+1;
	}
	generate_sequence(xs,currentlen+1,seqlen,seq);
}

int has_loop(int *seq, int seqlen, int looplen, int *ls, int *le){
	printf("Checking if there is a loop of length %d...\n",looplen);
	int index=0; // my index of first loop number 
	int index2=index+looplen; // index for second loop number
	int temp_index=index; //to increase 
	int temp_index2=index2; //to increase
	int limit=index2+looplen; //to for loop limit
	int array1[looplen]; // i will compare with array2
	int array2[looplen]; // to keep looped array in seq array
	int array3[looplen]; // last original array
	int i,k;
	int check=1; // to understand arrays are same or not!!
	*ls=-1; // to understant if there is any loop
	while(index<seqlen-(2*looplen)+1){ // this while loop is going to a limit which is according to be calculated looplen
		for(k=0;k<looplen;k++){ // i got first loop array in array1 variable with correct indexes
			array1[k]=seq[temp_index];
			temp_index++;
		}
		for(k=0,i=index2;i<limit;k++,i++){ // i got second loop array into array2 variable with correct indexes
			array2[k]=seq[temp_index2];
			temp_index2++;
		}
		for(i=0;i<looplen;i++){ 
			if(array1[i]!=array2[i]){
				//i check arrays if there is any difference i made check=0
				check=0;
			}
		}
		if(check==1){ // if check==1 i will return 1 and i assign ls and le
			*ls=index;
			*le=index2;
		}
		check=1; // i need to do this because of the loop
		index++; // i increase loop
		temp_index=index; // i assigned again because i will increase temp_index again when i assign into array1
		index2=index+looplen; // i assigned index2
		temp_index2=index2; // i assigned again because i will increase temp_index2 again when i assign into array2
		limit=index2+looplen; // i need to increase my index of second loop array
	}
	if(*ls!=-1){
		return 1;
	}
	return 0;
	
}

void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit){
	/*
	digit is starting from 1 and it going to until 9
	i checked every number's first digit and i compared it my digit variable	
	if digits are same i increased one h[digit-1]
	 
	*/
	int *seq;
	int currentlen=0;
	int number;
	seq=(int*)malloc(sizeof(int)*seqlen);
	f(xs,currentlen,seqlen,seq); // i created the sequnce
	int i;
	for(i=0;i<seqlen;i++){
		number=seq[i]; // i assigned it to compare
		while(seq[i]!=0){ // if seq[i] is equal to zero that means i found the first digit of seq[i]
			number=seq[i];
			seq[i]/=10; // i divided into 10 
		}
		//number is my first digit of the seq[i]
		if(number==digit){// compared them
			h[digit-1]++;
		}
	}
	if(digit==9){ // end of the function
		return;
	}
	else{
		hist_of_firstdigits(f,xs,seqlen,h,digit+1);
	}
	free(seq);
}

void check_loop_iterative(void (*f)(int xs2, int currentlen, int seqlen2, int *seq), int xs, int seqlen, int *loop, int *looplen){
	int *seq;
	int currentlen=0;// starting from zero
	int ls,le; // my last and first indexes of loop
	int i; // to for loop
	int temp_ls; // i did not want to change my ls variable so i created temp_ls
	seq=(int*)malloc(sizeof(int)*seqlen); // mallocated
	f(xs,currentlen,seqlen,seq);
	if(*looplen==seqlen/2){ // that means print only once the sequence 
		printf("Sequence: {");
		for(i=0;i<seqlen;i++){
			if(i==seqlen-1){
				printf("%d",seq[i]);
			}
			else{
				printf("%d, ",seq[i]);
			}
		}
		printf("}\n\n");
	}	
	if(*looplen==1 || *looplen==0){ // that means end of the function return to mains
		return ;
	}
	int temp_looplen=*looplen; // i send it to has_loop function, 
	int returned_value=0; // to check which value will be returned
	returned_value=has_loop(seq,seqlen,temp_looplen,&ls,&le);
	*looplen-=1;	 // i need to decrease looplen variable becase i will send it to has_loop function if there is no loop for length of last looplen
	if(returned_value==0){
		check_loop_iterative(generate_sequence,xs,seqlen,loop,looplen);
	}
	else{
		printf("\n\nLoop detected with a length of %d.\n",*looplen+1); 
		printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)\n",ls,le-1);
		// i decreased le by one because someone asked you to this index is not correct, and you said yes it is not correct!!!
		for(i=0,temp_ls=ls;temp_ls<le;i++,temp_ls++){
			loop[i]=seq[temp_ls];
			//printf("a%d\n",loop[i]);
		}		
	}
	free(seq); // free memory of the sequence 
}


