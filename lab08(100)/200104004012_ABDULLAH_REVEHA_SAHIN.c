#include <stdio.h>
#include <string.h>

int reverse(char str[], char reversed[], int i);
void merge(int arr[], int p, int q, int r );
void mergeSort(int arr[], int l, int r);

/*
in mergesort function i found the middle index for every called function
i divided the function in 2 part in first part i sent to l to q
in second part i sent to q+1 to r
finally i called merge function with (arr,l,q,r)


*/



int main(){
	char str[100]="cse108801esc";
	str[strlen(str)]='\0'; // to understand finish the string
	char reversed[100];
	int i=0;
	reverse(str,reversed,i);
	reversed[strlen(str)]='\0'; // to understand finish the string
	printf("Reversed string: %s\n",reversed);
	if(strcmp(str,reversed)==0){ // that means they are equal
		printf("String is palindrome\n");
	}
	else{
		printf("String is not a palindrome\n");
	}
	
	int arr[7]={4,9,2,5,32,11,3}; // when you fix the size of array please fill the correct number in the size array
	mergeSort(arr,0,(sizeof(arr)/4)-1); // (sizeof(arr)/4)-1 means length-1 of the array
	for(i=0;i<sizeof(arr)/4;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}


int reverse(char str[], char reversed[], int i){
	if(i==strlen(str)-1){ //that means i checked every index
		reversed[strlen(str)-1]=str[0];
		return 0;
	}
	else{
		reversed[i]=str[strlen(str)-i-1]; // i assigned reversed string here
		reverse(str,reversed,i+1);
	}
	
}

void merge(int arr[], int p, int q, int r ){
	int n1=q-p+1;
	int n2=r-q;
	int L[n1] , M[n2];
	
	for(int i=0;i<n1;i++){
		L[i]=arr[p+i];
	}
	for(int j=0;j<n2;j++){
		M[j]=arr[q+1+j];
	}
	
	int i,j,k;
	i=0;
	j=0;
	k=p;
	while(i<n1 && j<n2){
		if(L[i] <= M[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=M[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=M[j];
		j++;
		k++;
	}

}


void mergeSort(int arr[], int l, int r){

	int q;
	if(l<r){
		q=(l+r)/2;
		mergeSort(arr,l,q); //  i divided in 2 part function mergeSort in every called
		mergeSort(arr,q+1,r);
		merge(arr,l,q,r); // i combined it together
	}
	
	return ;
}

/*
void mergeSort2(int arr[], int l, int r){
	static int counter=0;
	if(counter==r){
		return ;
	}
	
	else{
		merge(arr,l,counter,r);
		counter++;
		mergeSort(arr,l,r);		
	}	
}
*/




