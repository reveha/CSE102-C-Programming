#include <stdio.h>
#include <string.h>
#define MIN(x,y) (((x)<(y)) ? (x) : (y)) // macro
#define THREE_MIN(a,b,c) MIN(MIN(a,b),c)

void findMaximumDistance(int distanceOfCities[], int start, int end, int result[]);

int recursiveMinStrDiff(char str1[], char str2[], int m, int n);



int main(){
	
	
	int distance[5]={20,56,18,45,40};
	int result[4];
	int start=0;
	int end=4;
	int m,n;	
	char str1[50];
	char str2[50];
	findMaximumDistance(distance,start,end,result);
	printf("%d %d\n",result[0],result[1]);
	// i got the strings from the user
	printf("enter first string: ");
	scanf("%s",str1);
	printf("enter second string: ");
	scanf("%s",str2);
	m=strlen(str1);
	n=strlen(str2);
	if(str1[0]!=str2[0]){
		printf("%d\n",recursiveMinStrDiff(str1,str2,m,n)+1);
	}
	else if(str1[m-1]==str2[n-1]){ // i need to check the last index to print true result
			printf("%d\n",recursiveMinStrDiff(str1,str2,m,n));
	}
	
	else{
		printf("%d\n",recursiveMinStrDiff(str1,str2,m,n)-1);
	}

	return 0;
}

void findMaximumDistance(int distanceOfCities[], int start, int end, int result[]){
	int i;
	static int max=0; // these max and min values are changed every called the function and finally i found the max and min values !!
	static int min=900000000;
	int mid;
	mid=(start+end)/2;
	
	if(start==end){
	// i checked for max and min values in if statements !!
	// i found max and min values these if statements!!
		if(distanceOfCities[start]>max){
			max=distanceOfCities[start];
		}
		if(distanceOfCities[start]<min){
			min=distanceOfCities[start];
		}
		return ;
	}
	else if(start+1==end){
	// i checked for max and min values in if statements !!
	// i found max and min values these if statements!!
		if(distanceOfCities[start]>max){
			max=distanceOfCities[start];
		}
		if(distanceOfCities[end]<min){
			min=distanceOfCities[end];
		}
		if(distanceOfCities[start]<min){
			min=distanceOfCities[start];
		}
		if(distanceOfCities[end]>max){
			max=distanceOfCities[end];
		}
		return ;
	}
	else if(start+1==end && start!=0){
	// i checked for max and min values in if statements !!
	// i found max and min values these if statements!!
		if(distanceOfCities[start]>max){
			max=distanceOfCities[start];
		}
		if(distanceOfCities[end]<min){
			min=distanceOfCities[end];
		}
		if(distanceOfCities[start]<min){
			min=distanceOfCities[start];
		}
		if(distanceOfCities[end]>max){
			max=distanceOfCities[end];
		}
		return ;
	}
	findMaximumDistance(distanceOfCities,start,mid,result);
	findMaximumDistance(distanceOfCities,mid+1,end,result);
	result[0]=max;
	result[1]=min;
}




int recursiveMinStrDiff(char str1[], char str2[], int m, int n){
	int min1,min2,min3;
	if(m==0 && n==0){
		return 1; // that means words are not same but strlens are same
	}
	else if(m==0){ // i do not need to check str1 empty!
		return n;
	}
	else if(n==0){
		return m;	// i do not need to  check str2 empty!
	}
	else if(strcmp(str1,str2)==0){
		return 0;
	}
	if(str1[m]==str2[n]){
		return	recursiveMinStrDiff(str1,str2,m-1,n-1);
	}
	else{
		min1=recursiveMinStrDiff(str1,str2,m,n-1);
		min2=recursiveMinStrDiff(str1,str2,m-1,n);
		min3=recursiveMinStrDiff(str1,str2,m-1,n-1);
	}
	return 1+THREE_MIN(min1,min2,min3); // i need to return +1 because of the index
}







