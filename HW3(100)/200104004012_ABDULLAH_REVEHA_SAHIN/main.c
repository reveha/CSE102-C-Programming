#include <stdio.h>
#include <math.h>

int sum(int n1, int n2, int flag);
int multi(int n1, int n2, int flag);
int isprime(int a);
void write_file(int number);
void sort_file();
void print_file();

/*
	IF YOU RUN FIRST TIME!
	BEFORE RUN PART 3 AND PART 4 YOU NEED TO RUN FIRSTLY PART 1!!! OTHERWISE YOU WILL GET ZERO!!
	THE REASON OF THESE THERE IS NO ANY TXT FILE AT THE BEGINNING OF THE FIRST RUNING!!!!!!


*/


int main(){
	int choice; // this variable for understanding which part will be done
	int n1,n2,flag,sum_or_mul; // this variables for part 1
	int returned_value;
	int N; // for part 2
	int i; //for part 2 for loop
	do{
		printf("\nSelect operation(0 to exit)\n");
		printf(" 1. Calculate sum/multiplication between two numbers\n");
		printf(" 2. Calculate prime numbers\n");
		printf(" 3. Show number sequence in file\n");
		printf(" 4. Sort number sequence in file\n");
		printf(" -----------------------------\n");
		printf("Choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("\nSelect operation\n");
				printf("Please enter '0' for sum, '1' for multiplication.\n");
				scanf("%d",&sum_or_mul);
				printf("Please enter '0' to work on even numbers. '1' to work on odd numbers.\n");
				scanf("%d",&flag);
				printf("PLease enter two different numer:\n");
				printf("Number 1: ");
				scanf("%d",&n1);
				printf("Number 2: ");
				scanf("%d",&n2);
				if(n1>n2){
					printf("Be careful that n2 must be greater than n1!!!!!!\n");
				}

				if(n1<0 || n2<0){ //negative checking
					printf("Numbers cannot be zero be careful after that time !!!!!!\n");
					break;
				}
				if(n1==n2){
					printf("Numbers cannot be same!!!\n");
					break;
				}
				
					switch(sum_or_mul){
						case 1:
							printf("Result\n");
							returned_value=multi(n1,n2,flag);
							switch(returned_value){
								case -1: // if function returned -1 that means error invalid flag 
									printf("ERROR.. INVALID FLAG!!\n");
									break;
								default:
									printf("%d\n",returned_value);
									switch(returned_value){
										case 0:
											printf("There is no any integer between numbers.\n");
											break;
										default:
											printf("The result is written tot the results.txt file.\n");
											break;
									}	
									break;	
							}
							break;
						case 0:
							printf("Result\n");
							returned_value=sum(n1,n2,flag);
							switch(returned_value){
								case -1: // if function returned -1 that means error invalid flag 
									printf("ERROR.. INVALID FLAG!!\n");
									break;
								default:
									printf("%d\n",returned_value);
									switch(returned_value){
										case 0:
											printf("There is no any integer between numbers.\n");
											break;
										default:
											printf("The result is written tot the results.txt file.\n");
											break;
									}	
									break;	
							}			
							break;
						default:
							printf("ERROR! INVALID VALUE FOR FLAG!!!\n");	
					}	
				break;	
			case 2:
				printf("Please enter an integer: ");
				scanf("%d",&N);
				if(N<0){
					printf("You cannot enter negative number!!\n");
				}
				for(i=1;i<N;i++){ // i started it from 1 to N and for each step i send the number to function..
					returned_value=isprime(i);
					if(returned_value==1){
						if(i!=1){
							printf("%d is a prime number.\n",i);
						}
					}
					else{ // i returned the value that can divide i  !
						printf("%d is not a prime number, it is dividible by %d.\n",i,returned_value);
					}
				}
				break;
			case 3:
				printf("Result:\n");
				print_file();
				break;
			case 4:
				printf("Sorting is complete.\n");
				printf("Result:\n");
				sort_file();
				break;	
			case 0:
				printf("\nGOOD BYE\n");
				break;	
			default:
				printf("Type correctly\n");
				break;
		}
	}while(choice!=0);
	
	
	
	
	return 0;
}

void write_file(int number){
	FILE *ptr=fopen("results.txt","a+");
	if(ptr==NULL){
		printf("OPENING FILE ERROR!!!!");
		return;
	}
	fprintf(ptr,"%d ",number);		
	fclose(ptr);	
}
int isprime(int a){
	int i;
	for(i=1;i<=sqrt(a);i++){
		if(a!=2 && i!=1){
			if(a%i==0){
				return i;
			}
		}
	}
	return 1;
	
	
}



int multi(int n1, int n2, int flag){
	int i;
	int mul=1;
	int returned_value;
	if(flag==0){ // that means even numbers
		if(n1>n2){
			if(n1-n2==2){ // if the difference between two numbers i have to check one of the number is odd or even !!!
				if(n1%2!=0){
					write_file(n2+1);
					return n2+1;
				}
				else{
					return 0;
				}
				
			}
			for(i=n2+1;i<n1;i++){
				if(i%2==0){
					if(i==n1-1 || i==n1-2){ // i printed this for last equation
						printf("%d = ",i);
					}
					else{
						printf("%d * ",i);
					}
					mul*=i;
				}
			}
		}
		else{
			if(n2-n1==2){
				if(n2%2!=0){
					write_file(n1+1);
					return n1+1;
				}
				else{
					return 0;
				}
				
			}
			for(i=n1+1;i<n2;i++){
				if(i%2==0){
					if(i==n2-1 || i==n2-2){ // i printed this for last equation
						printf("%d = ",i);
					}
					else{
						printf("%d * ",i);
					}
					mul*=i;
				}
			}	
		}
		returned_value=mul;
	}
	else if(flag==1){ //that means odd numbers
		if(n1>n2){
			if(n1-n2==2){
				if(n1%2==0){
					write_file(n2+1);
					return n2+1;
				}
				else{
					return 0;
				}
				
			}
			for(i=n2+1;i<n1;i++){
				if(i%2!=0){
					if(i==n1-1 || i==n1-2){
						printf("%d = ",i);
					}
					else{
						printf("%d * ",i);
					}
					mul*=i;
				}
			}
		}
		else{
			if(n2-n1==2){
				if(n2%2==0){
					write_file(n1+1);
					return n1+1;
				}
				else{
					return 0;
				}
				
			}
			for(i=n1+1;i<n2;i++){
				if(i%2!=0){
					if(i==n2-1 || i==n2-2){
						printf("%d = ",i);
					}
					else{
						printf("%d * ",i);
					}
					mul*=i;
				}
			}
		}
		returned_value=mul;
		
	}
	
	else{ // if flag is invalid i returned -1;
		return -1;
	}
	if(returned_value!=0){
		write_file(returned_value);
	}
	
	
	return returned_value;
}



int sum(int n1, int n2, int flag){
	
	int i;
	int add=0;
	int returned_value;
	if(flag==0){ // that means even numbers
		if(n1>n2){
			for(i=n2+1;i<n1;i++){
				if(i%2==0){
					if(i==n1-1 || i==n1-2){ // i printed for last equation
						printf("%d = ",i);
					}
					else{
						printf("%d + ",i);
					}
					add+=i;
				}
			}
		}
		else{
			for(i=n1+1;i<n2;i++){
				if(i%2==0){
					if(i==n2-1 || i==n2-2){ // i printed for last equation
						printf("%d = ",i);
					}
					else{
						printf("%d + ",i);
					}
					add+=i;
				}
			}	
		}
		returned_value=add;
	}
	else if(flag==1){ // that means odd numbers.
		if(n1>n2){
			for(i=n2+1;i<n1;i++){
				if(i%2!=0){
					if(i==n1-1 || i==n1-2){ // i printed for last equation
						printf("%d = ",i);
					}
					else{
						printf("%d + ",i);
					}
					add+=i;
				}
			}
		}
		else{
			for(i=n1+1;i<n2;i++){
				if(i%2!=0){
					if(i==n2-1 || i==n2-2){ // i printed for last equation
						printf("%d = ",i);
					}
					else{
						printf("%d + ",i);
					}
					add+=i;
				}
			}
		}
		returned_value=add;
		
	}
	
	else{ // i returned -1 for invalid flag
		return -1;
	}
	
	if(returned_value!=0){
		write_file(returned_value);
	}
	
	return returned_value;
}


void print_file(){
	FILE *ptr=fopen("results.txt","a+");	
	if(ptr==NULL){
		printf("OPENING FILE ERROR!!!!");
		return;
	}
	int readed_value=0;
	if(fscanf(ptr,"%d",&readed_value)==-1){
		return;
	}
	rewind(ptr);
	while(!feof(ptr)){
		fscanf(ptr,"%d ",&readed_value);
		printf("%d ",readed_value);
	}
		
	fclose(ptr);
}


void sort_file(){
	
	//THIS PART IS DOING SAME TASK BUT THIS PART IS DELETING EVERY MIN1, MIN2, MIN3 IN THE RESULTS.TXT AND 
	//FINALLY TAKE THE TRUE SORTING FROM TEMP.TXT
	// IF YOU WANT TO SEE HOW IT WORKS, DELETE THE 531. LINE AND OPEN TEMP.TXT FILE AFTER RUN PART 4. 
	//HOWEVER IF YOU RUN THE PROGRAM AGAIN, YOU HAVE TO DELETE CONTENTS OF TEMP.TXT
	
	FILE *ptr=fopen("results.txt","a+");
	FILE *temp_file=fopen("temp.txt","a+");
	if(ptr==NULL || temp_file==NULL){
		printf("OPENING FILE ERROR!!!!");
		return;
	}
	int x1;
	int min1,min2,min3; // these are my min1 min2 min3 variables.
	int counter=0,counter2=0,counter3=0; //counter is counting 
	int temp_number,temp_number2;
	int max=0;
	char ch='a';  // I INCREASED THAT CHAR EVERY GET VALUES FROM RESULTS.TXT
	char ch2; // TO UNDERSTAND TRUE LINE 
	char temp_ch; // THIS KEEPS LAST ch CHARACTER;
	int i; //FOR LOOP
	
	if(fscanf(ptr,"%d",&x1)==-1){
		return;
	}
	rewind(ptr);
	while(!feof(ptr)){
		fscanf(ptr,"%d ",&x1);
		counter++;	
	}
	if(counter==1){
		printf("%d \n",x1);
		return;
	}
	
	
	
	rewind(ptr);
	while(!feof(ptr)){
		fscanf(ptr,"%d ",&x1);
		if(x1>max){
			max=x1; // I FOUND THE MAX VALUE IN RESULTS.TXT FILE
		}
	}
	while(1){ //INFINITE LOOP I WILL USE BREAK TO EXIT FROM THE LOOP I ASKED YOU TO USE BREAK, YOU SAID THAT YES YOU CAN USE IT !!
		rewind(ptr);
		fscanf(ptr,"%d ",&x1); 
		if(feof(ptr)){   // PART 55 //IF THERE IS ONLY ONE INTEGER THAT IS GREATEST VALUE IN THE RESULTS.TXT. I BREAK.
			break;	
		}	
		min1=max;
		min2=max; //MIN1 MIN2 MIN3 IS EQUAL TO MAX VALUE
		min3=max;
		counter=0;
		counter3=0; // to count repeating numbers!! important !!
		i=0;
		rewind(ptr);
		while(!feof(ptr)){
			fscanf(ptr,"%d ",&x1);
			counter++;
			if(x1<=min1){
				temp_number=min1;
				min1=x1;
				temp_number2=min2;
				min2=temp_number;
				min3=temp_number2;
			}
			else if(x1<=min2 && x1>=min1){
				temp_number2=min2;
				min2=x1;
				min3=temp_number2;
			}
			else if(x1<=min3 && x1>=min2 && x1>=min1){
				min3=x1;
			}	
		}
		// COUNTER IS DIFFERENT EVERY COUNTING!!!!! BECAUSE I DELETED LAST MIN1,MIN2,MIN3 IN THE RESULTS.TXT FILE!!!!!
		if(counter==0){
			break; // THIS IS MY EXIT FROM THE INFINITE LOOP!! 
		}
		if(counter==1 ){
			fprintf(temp_file,"%d \n",min1);
			
		}
		else if(counter==2){
			fprintf(temp_file,"%d \n%d \n",min1,min2);
		}
		else{
			fprintf(temp_file,"%d \n%d \n%d \n",min1,min2,min3);
			
		}
		
	
		rewind(ptr);
		fprintf(temp_file,"%c ",ch); // I PUT ch CHARACTER TO UNDERSTAND WHERE I AM IN THE TEMP_FILE.txt
		while(!feof(ptr)){
			fscanf(ptr,"%d ",&x1);
			if(min1==min3){ // IF MIN1 AND MIN3 ARE EQUAL TO EACH OTHER PRINT ALL NUMBERS IN THE TEMP FILE.
				fprintf(temp_file,"%d ",x1);
			}
			else if(min2==min3 && min1!=min3){ //IF MIN2 AND MIN3 ARE EQUAL TO EACH OTHER I TAKE THE X1 VALUES WHICH ARE NOT EQUAL TO MIN1!!!!
				if(x1!=min1){
					fprintf(temp_file,"%d ",x1);
				}
			}
			else if(min2!=min3 && min1!=min3){
				if(x1!=min1 && x1!=min2){
					fprintf(temp_file,"%d ",x1); //I PRINTED THE VALUES WHICH ARE NOT LAST MIN1 , MIN2 ,MIN3 FROM RESULTS.TXT
				}
			}
			
		}
		
		fprintf(temp_file,"%c \n",ch); //I PUT ch CHARACTER TO UNDERSTAN WHERE I AM IN THE TEMP_FILE.txt
		temp_ch=ch; // I ASSIGNED CH TO TEMP_CH TO CHECK AFTER. THIS IS IMPORTANT!!
		ch=ch+1; // I INCREASED THE CH VALUE 
		freopen("results.txt","w+",ptr); // I DELETED THE CONTENTS OF RESULTS.TXT
		freopen("results.txt","a+",ptr);
		rewind(temp_file);
		while(!feof(temp_file)){
			while(fscanf(temp_file,"%d ",&x1)){ //THIS WHILE IS GOING TO SEE NON INTEGER !! THAT MEANS IF IT SEE MY ch CHARACTER IT WILL STOP
				
			}
			fscanf(temp_file,"%c ",&ch2);	// I GOT THE ch CHAR TO ch2 FROM TEMP.TXT FILE!!
			while(fscanf(temp_file,"%d ",&x1)){ //THIS WHILE IS GOING TO SEE NON INTEGER !! THAT MEANS IF IT SEE MY ch CHARACTER IT WILL STOP
				if(ch2==temp_ch){ //IF ch2 IS EQUAL TO LAST CH(TEMP_CH) I GOT THE VALUES WHICH ARE NOT LAST MIN1,MIN2,MIN3
					if(x1==min3){
						counter3++; // to count how many there are same numbers!!!!
					}
				}		
			}
			fscanf(temp_file,"%c ",&ch2);	// I GOT THE ch CHAR TO ch2
		}	
		rewind(temp_file);
		while(!feof(temp_file)){
			while(fscanf(temp_file,"%d ",&x1)){ //THIS WHILE IS GOING TO SEE NON INTEGER !! THAT MEANS IF IT SEE MY ch CHARACTER IT WILL STOP
				
			}
			fscanf(temp_file,"%c ",&ch2);	// I GOT THE ch CHAR TO ch2
			while(fscanf(temp_file,"%d ",&x1)){
				if(ch2==temp_ch){ //IF CH2 IS EQUAL LAST CH IT IS OKEY I AM HERE.
					if(x1!=min3){
						fprintf(ptr,"%d ",x1); // IF X1 IS NOT REPATING NUMBERS GET THE VALUES AND PRINT IT INTO RESULTS.TXT!
					}
					else{
						if(min1==min3){ // IF ALL MIN NUMBERS ARE EQUAL TO EACH OTHER I HAVE TO PRINT LAST_MIN3 NUMBER COUNTER3-2 TIMES  
							while(i<counter3-3){
								fprintf(ptr,"%d ",min3);
								i++;
							}
						}
						else if(min2==min3){// IF MIN2 AND MIN3 NUMBERS ARE EQUAL TO EACH OTHER 
									//I HAVE TO PRINT LAST_MIN3 NUMBER COUNTER3-2 TIMES 
							while(i<counter3-2){
								fprintf(ptr,"%d ",min3);
								i++;
							}
						
						}
						else if(min2!=min3){ // IF MIN2 IS NOT EQUAL TO MIN3 I HAVE TO PRINT LAST_MIN3 COUNTER3-1 TIMES.
							while(i<counter3-1){
								fprintf(ptr,"%d ",min3);
								i++;
							}
						}
					}
				}
				
			}
			fscanf(temp_file,"%c ",&ch2);	// I GOT THE ch CHAR TO ch2
			
		}
		
	}	// END OF THE INFINITE LOOP!!
	
	freopen("results.txt","w+",ptr); // I DELETED THE CONTENTS OF RESULTS.TXT FILE
	freopen("results.txt","a+",ptr);
	rewind(temp_file);
	while(!feof(temp_file)){
		while(fscanf(temp_file,"%d ",&x1)){//THIS WHILE IS GOING TO SEE NON INTEGER !! THAT MEANS IF IT SEE MY ch CHARACTER IT WILL STOP		
			fprintf(ptr,"%d ",x1);
			fscanf(ptr,"%d ",&x1);
			printf("%d ",x1);	// THIS VALUES ARE EVERY MIN1,MIN2,MIN3 
			
		}
		fscanf(temp_file,"%c ",&ch2);
		while(fscanf(temp_file,"%d ",&x1)){
				//THIS VALUES ARE BETWEEN THE CHARACTERS
		}
		fscanf(temp_file,"%c ",&ch2);
		
	}
	if(counter==4){  // I WRITE HERE THIS FOR PART 55!!! 
		printf("%d ",max);
		fprintf(ptr,"%d ",max);
	}
				
	
	freopen("temp.txt","w+",temp_file);// IF YOU WANT TO SEE WHAT I MEAN DELETE THIS 2 FREOPEN FUNCTION AND RUN PROGRAM, AND OPEN THE  
 						// TEMP.TXT FILE	
	fclose(ptr);
	fclose(temp_file);
	

	
}




