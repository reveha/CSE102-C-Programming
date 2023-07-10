#include <stdio.h>

void x_star_display(int height);
void diamond_star_display(int height);

void multiplication_table_display(int size);

void is_polindrome_integer(int n);




int main(){
	
	int choice;
	int height;
	int size;
	int n;
	do{
		printf("Enter option 1 to x_star_display\n");
		printf("Enter option 2 to diamond_star_display\n");
		printf("Enter option 3 to multiplication_rable_display\n");
		printf("Enter option 4 to palindrome check number\n");
		printf("Enter option -1 to exit!!\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("Enter an odd integer as the height: ");
			scanf("%d",&height);
			if(height%2==0){
				printf("You must enter odd numbe!!!\n");
			}
			else{
				x_star_display(height);
			}	
		}
		else if(choice==2){
			printf("Enter an odd integer as the height: ");
			scanf("%d",&height);
			if(height%2==0){
				printf("You must enter odd numbe!!!\n");
			}
			else{
				diamond_star_display(height);
			}
		}
		else if(choice==3){
			printf("Enter an integer as the size: ");
			scanf("%d",&size);
			multiplication_table_display(size);
		}
		else if(choice==4){
			printf("Enter an integer as the polindrome: ");
			scanf("%d",&n);
			is_polindrome_integer(n);
		}
	}while(choice!=-1);
	

	
	return 0;
}

void x_star_display(int height){
	int i;
	int j;
	for(i=0;i<height;i++){
		for(j=0;j<height;j++){
			if(j==i || j==height-1-i){
				printf("*");
			}
			
				printf(" ");
				
		}
		
		printf("\n");
	}
	
	
	
	
}

void diamond_star_display(int height){
	int i,j,k;
	int temp_height=(height/2)+1;
	for(i=0;i<temp_height;i++){
		
		
		
		
		printf("\n");	
	}
	
	/*
	for(i=0;i<limit;i++){
		for(j=0;j<limit-1-i;j++){
		printf(" ");
		}
		if(i==0){
			printf("*");
		}
		else{
			for(j=0;j<=i;j++){
				printf("* ");
			}
		}
		printf("\n");
		
	}
	*/
}

void multiplication_table_display(int size){
	int i,j;
	printf("    ");
	for(i=0;i<size;i++){
		if(i==0){
			for(j=0;j<size;j++){
				printf("%d ",j+1);
			}
			printf("\n");
			for(j=0;j<size;j++){
				printf("--");
			}
			printf("\n");
		}		
		for(j=0;j<size;j++){
			if(j==0){
				printf("%d*  ",i+1);
			}
			printf("%2.d  ",(j+1)*(i+1));	
		}
		printf("\n");
	}

}



void is_polindrome_integer(int n){
	int i,j;
	int counter=0;
	int counter2=0;
	int temp1;
	int temp2;
	int temp3;
	int c=1;
	temp1=n;
	temp2=n;
	temp3=n;
	while(temp1!=0){
		temp1/=10;
		counter++;
	}
	for(i=0;i<counter;i++){
		for(j=counter-1;j>i;j--){
			temp3/=10;
		}
		temp3%=10;
		for(j=0;j<i;j++){
			temp2/=10;
		}
		temp2%=10;
		if(temp3!=temp2){
			c=2;
		}
		temp2=n;
		temp3=n;		
		
	}
	if(c==2){
		printf("not polindrome\n");
	}
	else{
		printf("polindrome\n");
	}
	
}










