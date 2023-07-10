#include <stdio.h>
#include <stdlib.h>

typedef struct{ // my struct
	int *array;
	int currentsize;
}dynamic_array;

int counter2; // to keep end of the size of struct array

int *resize_array(int *array, int currentsize){
	dynamic_array temp;
	temp.array=array; // assigned temp array
	int i;
	array=(int*)calloc(counter2,sizeof(int)); // it callocs according to the given currentsize	
	for(i=0;i<counter2-1;i++){
		array[i]=temp.array[i];
	}
	array[counter2-1]=currentsize-1; // assigning last element
	
	return array;
}

dynamic_array read_from_file(char *filename, dynamic_array arr){
	FILE *ptr=fopen(filename,"a+"); // open a file
	int i;
	int counter=0;
	rewind(ptr);
	while(!feof(ptr)){
		fscanf(ptr,"%d\n",&arr.currentsize); // i got the values from txt file
		counter++; // increment
		counter2++;
		arr.currentsize++;
		arr.array=resize_array(arr.array,arr.currentsize); // callocing my array
	}
	rewind(ptr); // go back the txt file
	counter=0;
	//while(!feof(ptr)){
	//	fscanf(ptr,"%d\n",&arr.array[counter]); // i got the values from txt file into the struct array
	//	counter++;
	//}
	//counter2=counter; // my end of the size of array is counter2 it is global
	fclose(ptr);
	return arr; // returnin array
}

dynamic_array removeData(dynamic_array arr, int number){
	dynamic_array temp; // to keep last struct array 
	temp.array=(int *)calloc(counter2,sizeof(int)); // callocing it
	temp=arr;
	int i;
	int j;
	int check=0;
	for(i=0;i<counter2;i++){
		if(arr.array[i]==number){
			check=1; // that means i found the first number which is wanted from us
			break;
			
		}
	}
	if(check==1){
		//printf("\n\n%d\n\n",counter2);
		arr.array=(int *)calloc(counter2-1,sizeof(int)); // i callocated my struct array again with counter2-1 size 
		for(j=0;j<counter2;j++){ // this for assigning my array again
			if(j==i){
				arr.array[j]=temp.array[i+1];
				i++;
			}
			else{
				arr.array[j]=temp.array[j];
			}
		}
		counter2-=1;
	}
	return arr;
}

void print_array(dynamic_array arr){
	int i;
	for(i=0;i<counter2;i++){ // printing
		printf("%d\n",arr.array[i]);
	}
}




int main(){
	dynamic_array arr;
	int number;
	char filename[50];

	printf("Enter the file name: ");
	scanf(" %s",filename); // got the file name
	arr=read_from_file(filename,arr);
	printf("Data in source file\n*******************************\n");
	print_array(arr);
	
	do{
		printf("\nEnter the number you want to be deleted (negative to exit): ");
		scanf("%d",&number); // got the removed number
		arr=removeData(arr,number);
		printf("Array after deletion\n*********************************\n");
		print_array(arr);
	}while(number>=0);
	
	
	return 0;
}
