#include <stdio.h>


typedef enum{
	sunday,monday,tuesday,wednesday,thursday,friday,saturday

}days;

typedef enum{
	harddisk,monitor,keyboard,mouse

}products;

typedef enum{
	buy=1,orders,prices,exit
	
}selections;

typedef enum{
	harddisk_price=2,monitor_price=5,keyboard_price=3,mouse_price=10
}product_prices;

typedef enum{
	dolar=4,euro=5,pound=9,peso=10
}currencies;	

int add();
int multiple();
void write_file(int a, int b);
void print_days(int day);
void readOrderFIle(void p_day(int));
void prices_func(int add(int),int multiple(int), void print_days(int));
int main(){
	
	int choice;
	int product;
	int day;
	do{
		printf("Welcome to the TechMarket.\n");
		printf(" 1. Buy Product\n");
		printf(" 2. Orders\n");
		printf(" 3. All Orders Prices\n");
		printf(" 4. Exit\n");
		printf("----------------\n");
		scanf("%d",&choice);
		if(choice==buy){
			printf("Select your product:\n");
			printf(" 0. Harddisk\n");
			printf(" 1. Monitor\n");
			printf(" 2. Keyboard\n");
			printf(" 3. Mouse\n");
			printf("----------------\n");
			scanf("%d",&product);
			printf("Select your arrival day[0-6]:\n");
			printf(" sunday,monday,tuesday,wednesday,thursday,friday,saturday\n");
			printf("----------------\n");
			scanf("%d",&day);
			write_file(product,day);
			
		}
		else if(choice==orders){
			readOrderFIle(print_days);
		}
		else if(choice==prices){
			prices_func(add,multiple,print_days);
		}
	}while(choice!=4);
	
	
	
	
	
	return 0;
}

void write_file(int a, int b){	
	FILE *ptr=fopen("orders.txt","a+");
	fprintf(ptr,"%d %d ",a,b);
	fclose(ptr);
}


void print_days(int a){
	if(a==0){
			printf("Day: Sunday\n");
		}
		else if(a==1){
			printf("Day: Monday\n");
		}
		else if(a==2){
			printf("Day: Tuesday\n");
		}
		else if(a==3){
			printf("Day: Wednesday\n");
		}
		else if(a==4){
			printf("Day: Thursday\n");
		}
		else if(a==5){
			printf("Day: Friday\n");
		}
		else if(a==6){
			printf("Day: Saturday\n");
		}
	
}
void readOrderFIle(void p_day(int)){
	int a;// to get day value;
	FILE *ptr=fopen("orders.txt","a+");
	rewind(ptr);
	while(!feof(ptr)){
		fscanf(ptr,"%d ",&a);
		printf("Product ID: %d, ",a);
		fscanf(ptr,"%d ",&a);
		p_day(a);
		
	}
	fclose(ptr);
}

int add(int a){
	
	return a;
}

int multiple(int a){
	int returned_value;
	if(a==0){
		returned_value=harddisk_price*dolar;
	}
	else if(a==1){
		returned_value=monitor_price*euro;
	}
	else if(a==2){
		returned_value=keyboard_price*pound;
	}
	else if(a==3){
		returned_value=mouse_price*peso;
	}
	
	return returned_value;
}

void prices_func(int add(int),int multiple(int),void print_days(int)){
	FILE *ptr=fopen("orders.txt","a+");
	rewind(ptr);
	int a;
	int x;
	int total=0;
	while(!feof(ptr)){
		fscanf(ptr,"%d ",&a);
		if(a==0){
			printf("Product: Harddisk, ");
		}
		else if(a==1){
			printf("Product: Monitor, ");
		}
		else if(a==2){
			printf("Product: Keyboard, ");
		}
		else if(a==3){
			printf("Product: Mouse, ");
		}
		x=multiple(a);
		total+=add(x);
		fscanf(ptr,"%d ",&a);
		print_days(a);\
		
		
	}
	printf("Total prices: %d TL\n\n",total);
	
	
	fclose(ptr);
}








