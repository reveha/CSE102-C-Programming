#include <stdio.h>
#include <math.h>

void write_file(int value);
int gcd_calculator(int x1, int x2);
int lcm_calculator(int x1, int x2);
void calculate_mean();
double standart_deviation_calculator(int mean, int count);





int main(){
	int x1,x2;
	int choice;
	int result;

	do{
		printf("Enter the calculator type(0 to exit)\n");
		printf(" 1. GCD Calculator\n");
		printf(" 2. LCM Calculator\n");
		printf(" 3. Standard Deviation Calculator\n");
		printf("-----------------------------------\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("Pleas enter two different number;\n");
			printf("Number 1: ");
			scanf("%d",&x1);
			printf("Number 2: ");
			scanf("%d",&x2);
			result=gcd_calculator(x1,x2);
			printf("GCD of these two numbers: %d\n",result);
			write_file(result);
			printf("The result is written to the results.txt file.\n");
		}
		else if(choice==2){
			printf("Please enter two different number :\n");
			printf("Number 1: ");
			scanf("%d",&x1);
			printf("Number 2: ");
			scanf("%d",&x2);
			result=lcm_calculator(x1,x2);\
			printf("LCM of these two numbers: %d\n",result);
			write_file(result);
		}
		else if(choice==3){
			calculate_mean();
			
		}
	}while(choice!=0);

	
	return 0;
}

void write_file(int result){
		FILE *ptr=fopen("results.txt","a");
		fprintf(ptr,"%d ",result);
		fclose(ptr);
}
int gcd_calculator(int x1, int x2){
	int i=2;
	int gcd=1;
	while(i<=x1 || i<=x2){
		if(x1%i==0 && x2%i==0){
			gcd=i;	
				
		}
		i++;
	}
	return gcd;

	
}

int lcm_calculator(int x1, int x2){
	int gcd;
	gcd=gcd_calculator(x1,x2);
	int returned_value;			
	returned_value=(x1*x2)/gcd;
	
	return returned_value;			
}

double standart_deviation_calculator(int mean, int counter){
	FILE *ptr=fopen("results.txt","r");
	int c=0;
	int readed_value;
	double last_result=0;
	int i;
	int first_result;
	while(!feof(ptr)){
		
			fscanf(ptr,"%d",&readed_value);
			if(feof(ptr)){
		
			break;
			}
			first_result=(readed_value-mean)*(readed_value-mean);
			last_result+=first_result;

	}	
	last_result/=counter;
	last_result = sqrt(last_result);

	fclose(ptr);
	return last_result;
}
void calculate_mean(){

	FILE *ptr=fopen("results.txt","r");
	int c=0;
	int i=1,readed_value;
	int counter=0;
	int mean=0;
	double returned_value;
	while(!feof(ptr)){


			fscanf(ptr,"%d",&readed_value);
			if(feof(ptr)){
				break;
			}
			printf("%d. Number: %d\n",i,readed_value);
			counter++;
			mean+=readed_value;

		i++;
	}
	fclose(ptr);
	mean/=counter;
	printf("Mean: %d\n",mean);
	printf("Total Count: %d\n",counter);
	returned_value=standart_deviation_calculator(mean,counter);
	printf("Standard Deviation : %.2lf\n",returned_value);


}

