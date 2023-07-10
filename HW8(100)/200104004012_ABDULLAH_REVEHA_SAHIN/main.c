#include <stdio.h> // standart
#include <stdlib.h> // to malloc
#include "util.h"

/*
i do not need to more comment line for main function it is clear to understand
*/

int main(){
	
	int xs,currentlen=0,seqlen;
	int *loop; // loop array
	int looplen; // int pointer
	int *histogram;
	int i;
	histogram=(int*)calloc(9,sizeof(int)); // fill with zero with using calloc
	printf("Please enter the sequence length: ");
	scanf("%d",&seqlen);
	printf("Please enter the first element: ");
	scanf("%d",&xs);
	looplen=seqlen/2;
	loop=(int *)malloc(sizeof(int)*looplen); 
	check_loop_iterative(generate_sequence,xs,seqlen,loop,&looplen); // calling function
	if(looplen==1 || looplen==0){
		printf("No loop found.");
	}
	else{ // printing loop array
		printf("Loop: {");
		for(i=0;i<looplen+1;i++){
			if(i==looplen){
				printf("%d}\n",loop[i]);		
			}	
			else{
				printf("%d, ",loop[i]);
			}
		}
	}	
	hist_of_firstdigits(generate_sequence,xs,seqlen,histogram,1); // i send 1 for the digit. it must start from 1
	printf("\n\nHistogram of the sequence: {");
	for(i=0;i<9;i++){
		if(i==8){
			printf("%d}\n",histogram[i]);
		}
		else{
			printf("%d, ",histogram[i]);
		}
	}
	free(histogram); // free memory of the histogram
	return 0;
}




