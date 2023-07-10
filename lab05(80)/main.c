#include <stdio.h>

// DO NOT FORGET COMMENT LINES !!

void display(); // to print arrays

void convolutional(void (*display)()); //for part 1

void multi(void (*display)()); // for part 2;
void trace(void (*display)()); // for part 3;
void transpose(void (*display)()); // for part 4;
int main(){
	
	
	int choice;
	
	do{ // my main menu 
		printf("Choose the matrix operation,\n"); 
		printf("------------------------------------------\n");
		printf("1. Convolutional Filter for 1D array\n");
		printf("2. Multiplication\n");
		printf("3. Trace\n");
		printf("4. Transpose\n");
		printf("5. Exit\n");
		printf("------------------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				convolutional(&display);
				break;
			case 2:
				multi(&display);	
				break;
			case 3:
				trace(&display);
				break;
			case 4:
				transpose(&display);
				break;
			case 5:
				printf("GOOD BYE\n");
				break;
			default:
				printf("TYPE CORRECTLY!!!\n");
				break;
		}
	}while(choice!=5);
	
	
	return 0;
}


void display(int array[],int a,int my_array2[3][3]){
	int i,j,r=3; //r to understand last index 
	int result;
	// a to understand which part will be printed
	if(a==1){ // for part 1 prints
		printf("Convolutional FIlter Result:\n");
		for(i=0;i<8;i++){
			printf("%d ",array[i]);
		}
	}
	
	else if(a==2){
	
	}
	else if(a==3){ // for part 3 print
		printf("Matrix:\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("%d ",my_array2[i][j]); // i printed here
			}
			printf("\n");
		}
		printf("Trace of matrix is : %d\n\n",my_array2[0][0]+my_array2[1][1]+my_array2[2][2]); // my result
	}
	else if(a==4){
	  // A matrisinin transpozisyonunu görüntüleme
   			 printf("\nTranspose of the matrix\n");
	for(i=0; i<3; ++i){
    		    for(j=0; j<3; ++j){
       			     printf("%d  ",my_array2[i][j]);
       			     if(j==r-1)
            		    printf("\n\n");
			}
		}	
		}
	}
	

void convolutional(void (*display)()){
	int kernel[3]={-1,1,-1};
	int my_array[10];
	int new_array[8];
	int x[3][3]; // to send display
	int i,j;
	printf("ENTER 1D ARRAY (10 ELEMENTS)\n");
	for(i=0;i<10;i++){
		scanf("%d",&my_array[i]); // i got the 1D array from user.
	}
	for(i=0;i<10;i++){
		for(j=i;j<=i;j++){
			if(j<8){
				new_array[i]=my_array[j]*kernel[0]+my_array[j+1]*kernel[1]+my_array[j+2]*kernel[2]; // i created new_array
			}
		}
	}
	display(new_array,1,x);
	
	
}


void multi(void (*display)()){
	int my_array[3][3];
	int my_array2[3][3];
	int result[3][3];
	int i,j,k;
	printf("Enter first matrix\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&my_array[i][j]);
		}
	}
	printf("Enter second matrix\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&my_array2[i][j]);
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			result[i][j]=0;
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				result[i][j]+=my_array[i][k]*my_array2[k][j];
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	
	
}


void trace(void (*display)()){
	int my_array[3][3];
	int my_array2[3][3];
	int x[10]; // send display
	int i,j;
	int result;
	printf("Enter first matrix\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&my_array[i][j]); // i got the values in 2d array from the user
		}
	}
	
	printf("Enter second matrix\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&my_array2[i][j]);// i got the values in 2d array from the user
		}
	}
	display(x,3,my_array);
	display(x,3,my_array2);
}

void transpose(void (*display)()){
	int a[3][3], transpose[3][3], i, j;
	int my_array2[3][3];
	int x[10];

    // Matrisin elemanlarını saklıyoruz
    printf("\nFIRST MATRIX:\n");
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
        {
            scanf("%d", &a[i][j]); // I GOT THE FIRST MATRIX
        }
        
        
         printf("SECOND MATRIX:\n");
            for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
        {
            scanf("%d", &my_array2[i][j]); // I GOT THE SECOND MATRIX
        }



    // FINDGIN TRANSPOSE
    for(i=0; i<3; ++i){
        for(j=0; j<3; ++j)
        {
            transpose[j][i] = a[i][j]; // i convert i and j 
        }
}	
	display(x,4,transpose); //FOR 1. MATRIX
	  for(i=0; i<3; ++i){
        for(j=0; j<3; ++j)
        {
            transpose[j][i] = my_array2[i][j];
        }
}
	display(x,4,transpose); // FOR 2. MATRIX
  
}

