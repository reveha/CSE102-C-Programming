#include <stdio.h>
#include <string.h>

typedef union{
	char name[50];
	char adress[50];
	int phone;
}Person;

typedef union{
	float money[3];
}Loan;

typedef struct{
	Person Customer;
	Loan Loans[3];
}BankAccount;

int number_of_customers=0; // to keep number of customers for local customers in the program while is running!!
int temp_customer=0;  // to keep number of the customer for all customers while program is running including txt file
BankAccount bank[50];
int counter2=0; // when i add a new customer to understand which index i am in. if the counter2 is zero i can get the last index of the number of the customer

void fill_zero(){ // filling all numbers with zero to make check easily
	int i;
	for(i=0;i<number_of_customers;i++){
		bank[i].Loans[0].money[0]=0;
		bank[i].Loans[0].money[1]=0;
		bank[i].Loans[0].money[2]=0;
		bank[i].Loans[1].money[0]=0;
		bank[i].Loans[1].money[1]=0;
		bank[i].Loans[1].money[2]=0;
		bank[i].Loans[2].money[0]=0;
		bank[i].Loans[2].money[1]=0;
		bank[i].Loans[2].money[2]=0;	
	}
}

float calculateLoan(float amount, int period, float interestRate){ // recursive function to calculate loan
	float total;
	if(period==0){
		return 1;
	}
	total=(1+interestRate) * calculateLoan(1,period-1,interestRate);
	
	return amount*total;
}

int get_ID(){ // to get id number for added new customer
	FILE *ptr=fopen("customers.txt","a+");
	char str[50];
	int number;
	while(!feof(ptr)){
		fscanf(ptr," %[^\n]s",str);
		fscanf(ptr," %[^\n]s",str);
		fscanf(ptr,"%d\n",&number);
		counter2++; // global variable
	}
	fclose(ptr);
	return counter2;
}

void listCustomers(){
	int i;
	int counter=0;
	int j;
	float loan1,loan2,loan3;
	int k;
	if(counter2==0){ // that means program is opened new. and first time you entered add a new customer button
		k=get_ID();
	}	
	else{ // that means you didn't firstly tap the add new customer button. so i can say my index is counter 2. i do not need to get all customer number 
		k=counter2;
	}
	for(i=0;i<number_of_customers;i++,k++){ // number of customers
		printf("Customer ID = %d\n",k); // k is customer ID 
		printf("Customer Name = %s\n",bank[i].Customer.name);
		if(bank[i].Loans[0].money[0]==0){
			printf("Loans = 0\n\n"); // that means this customer didnot take any credit
		}
		else{
			for(j=0;j<3;j++){
				if(bank[i].Loans[j].money[0]!=0){
					counter++; // this for how many times the customer get credit
				}
			}
			if(counter==1){ // this for printf image
				loan1=calculateLoan(bank[i].Loans[0].money[0],bank[i].Loans[0].money[2],bank[i].Loans[0].money[1]); // calculating loan
				printf("Loans = [%.4f] => ",loan1);
				printf("%.4f\n\n",loan1);
			}
			else if(counter==2){// this for printf image
				loan1=calculateLoan(bank[i].Loans[0].money[0],bank[i].Loans[0].money[2],bank[i].Loans[0].money[1]);
				printf("Loans = [%.4f + ",loan1);
				loan2=calculateLoan(bank[i].Loans[1].money[0],bank[i].Loans[1].money[2],bank[i].Loans[1].money[1]);
				printf("%.4f] => ",loan2);
				printf("%.4f\n\n",loan1+loan2);
			}
			else if(counter==3){// this for printf image
				loan1=calculateLoan(bank[i].Loans[0].money[0],bank[i].Loans[0].money[2],bank[i].Loans[0].money[1]);
				printf("Loans = [%.4f + ",loan1);
				loan2=calculateLoan(bank[i].Loans[1].money[0],bank[i].Loans[1].money[2],bank[i].Loans[1].money[1]);
				printf("%.4f +",loan2);
				loan3=calculateLoan(bank[i].Loans[2].money[0],bank[i].Loans[2].money[2],bank[i].Loans[2].money[1]);
				printf("%.4f] => ",loan3);
				printf("%.4f\n\n",loan1+loan2+loan3);
			}		
		}	
	}
}

void addCustomer(){
	int number_of_customers2=0; // to assign it to temp_customer;
	char temp[50];
	int temp2;
	FILE *ptr=fopen("customers.txt","a+");
	while(!feof(ptr)){
		fscanf(ptr," %[^\n]s\n",temp);
		fscanf(ptr," %[^\n]s\n",temp);
		fscanf(ptr," %d\n",&temp2);
		number_of_customers2++; // i got the number of customer in the txt file
	}
	if(number_of_customers2==50){
		printf("\n\nThe bank capacite is full now. Please try again later!\n\n"); //  it can be at most 50
		return;
	}
	number_of_customers2--;
	printf("Please enter your name:");
	scanf(" %[^\n]s",temp);
	fprintf(ptr,"%s\n",temp);
	printf("Please enter your adress: ");
	scanf(" %[^\n]s",bank[number_of_customers].Customer.adress);
	fprintf(ptr,"%s\n",bank[number_of_customers].Customer.adress);
	printf("Please enter your phone number: ");
	scanf("%d",&bank[number_of_customers].Customer.phone);
	fprintf(ptr,"%d\n",bank[number_of_customers].Customer.phone);
	strcpy(bank[number_of_customers].Customer.name,temp); // i need to print just name of the customer. so i need to strcpy them because my variable is union
	number_of_customers++; // increasing my local customer number
	temp_customer=number_of_customers2+number_of_customers;// to getting all customer number here
	fclose(ptr);
}


void newLoan(){
	FILE *ptr=fopen("loans.txt","a+"); // to keep loan information
	FILE *ptr2=fopen("customers.txt","a+"); // to keep customer information
	char str[50];
	char str2[50];
	int number;
	printf("Please enter your name in the bank system: ");
	scanf(" %[^\n]s",str); // i did everything according to the name of the customer
	int i;
	int index;
	int check=0;
	int counter=0;
	float number2;
	while(!feof(ptr2)){
		fscanf(ptr2," %[^\n]s\n",str2);
		if(strcmp(str,str2)==0){
			counter++; // to understand if there is that name of customer or not;
		}
	}
	if(counter==0){
		printf("\n\nNO FOUND THAT NAME!!\n\n");
	}
	else{
		counter=0;
		while(!feof(ptr)){ // i started to get name of customer from the loan.txt file. according to the number i can understand how many credit that customer has;
			fscanf(ptr," %[^\n]s\n",str2);
			if(strcmp(str,str2)==0){
				counter++; // increasing counter
			}	
			fscanf(ptr,"%f\n",&number2);
			fscanf(ptr,"%f\n",&number2);
			fscanf(ptr,"%f\n",&number2);
		}
		if(counter==3){
			printf("\n\nYOUR CREDIT IS FULL\n\n"); 
			return; // i can return credit is full
		}
		for(i=0;i<number_of_customers;i++){
			if(strcmp(str,bank[i].Customer.name)==0){
				check=1; // to understand my customer is local or not!!
				index=i;
				break;
			}
		}
		if(check==0){ // if the customer is not local that means from the txt file 
			do{ // these do whiles to check valid number or not
				printf("Enter the amount of the loan: ");
				scanf("%f",&number2);
				if(number2<=0){
					printf("\nEnter a valid number!!\n");
				}
			}while(number2<=0);
			fprintf(ptr,"%s\n",str);
			fprintf(ptr,"%.4f\n",number2);
			do{
				printf("Enter the interest rate: ");
				scanf("%f",&number2);
				if(number2<=0){
					printf("\nEnter a valid number!!\n");
				}
			}while(number2<=0);	
			fprintf(ptr,"%.4f\n",number2);
			do{
				printf("Enter the time period: ");
				scanf("%f",&number2);
				if(number2<=0){
					printf("\nEnter a valid number!!\n");
				}
			}while(number2<=0);	
			fprintf(ptr,"%.4f\n",number2);
			
		}
		else{ // my customer is local i need to keep numbes into the union so that i can print it for choice 1 from the main menu
			do{	 // these do whiles to check valid number or not
				printf("Enter the amount of the loan: ");
				scanf("%f",&bank[index].Loans[counter].money[0]);
				if(bank[index].Loans[counter].money[0]<=0){
					printf("\nEnter a valid number!!\n");
				}
			}while(bank[index].Loans[counter].money[0]<=0);
			
			fprintf(ptr,"%s\n",str);
			fprintf(ptr,"%.4f\n",bank[index].Loans[counter].money[0]);
			do{	
				printf("Enter the interest rate: ");
				scanf("%f",&bank[index].Loans[counter].money[1]);
				if(bank[index].Loans[counter].money[1]<=0){
					printf("\nEnter a valid number!!\n");
				}
			}while(bank[index].Loans[counter].money[1]<=0);
			
			fprintf(ptr,"%.4f\n",bank[index].Loans[counter].money[1]);
			do{	
				printf("Enter the time period: ");
				scanf("%f",&bank[index].Loans[counter].money[2]);
				if(bank[index].Loans[counter].money[2]<=0){
					printf("\nEnter a valid number!!\n");
				}
			}while(bank[index].Loans[counter].money[2]<=0);
			
			fprintf(ptr,"%.4f\n",bank[index].Loans[counter].money[2]);
		}
	}
	fclose(ptr);
	fclose(ptr2);
}



void getReport(){
	FILE *ptr=fopen("loans.txt","a+");
	FILE *ptr2=fopen("customers.txt","a+");
	int i=0;
	int counter=0;
	char str[50];
	char str2[50];
	int number;
	int check;
	float number2;
	float amount;
	float period;
	float interestRate;
	int index=0;
	int choice;
	printf("\t1. List All Customers\n");
	printf("\t2. List loan information for a person\n");
	scanf("%d",&check);
	if(check==1){
		while(!feof(ptr2)){ // printing all customers we have		
			fscanf(ptr2," %[^\n]s\n",str2);
			if(feof(ptr2)){
				break;
			}
			i++;
			printf("=====================================\n");
			printf("Costumer ID = %d\n",i);
			printf("Customer Name = %s\n",str2);
			fscanf(ptr2," %[^\n]s\n",str2);
			printf("Customer Adress = %s\n",str2);
			fscanf(ptr2,"%d\n",&number);
			printf("Customer Phone = %d\n",number);
			printf("=====================================\n\n");
		}
	}	
	else if(check==2){ // printing loans for a customer that you want 
		printf("Please enter the name of the customer you want to get loan report: ");
		scanf(" %[^\n]s",str); // getting the customer name form the user
		check=0;
		rewind(ptr2);
		while(!feof(ptr2)){
			fscanf(ptr2," %[^\n]s\n",str2);
			if(strcmp(str,str2)==0){
				check=1; // that means there is a customer for that name
			}
			fscanf(ptr2,"%f\n",&number2);
			fscanf(ptr2,"%f\ntanim",&number2);
			fscanf(ptr2,"%f\n",&number2);
		}
		rewind(ptr);
		if(check==0){ // there is no customer i can return
			printf("\nThere is no any person for that name!\n\n");
			return;
		}
		while(!feof(ptr)){
			fscanf(ptr," %[^\n]s\n",str2);
			if(strcmp(str,str2)==0){
				counter++; // to understand how many credit the customer has
			}
			fscanf(ptr,"%f\n",&number2);
			fscanf(ptr,"%f\n",&number2);
			fscanf(ptr,"%f\n",&number2);
		}
		if(counter==0){
			printf("\nThere is no any Loan information about that person!\n\n");
			return; // there is no any loan i can return
		}
		else{
			rewind(ptr);
			if(counter==3){ //there are 3 loans info
			index=0;
				do{
					printf("\nThere are %d loans information.\n",counter);
					printf("Which one do you want to get?(1-2-3) = ");
					scanf("%d",&choice); 
					switch(choice){
						case 1:
						case 2:
						case 3:
							while(!feof(ptr)){
								fscanf(ptr," %[^\n]s\n",str2);
								if(strcmp(str,str2)==0){
									index++; // increasing index
									fscanf(ptr,"%f\n",&amount); // getting values
									fscanf(ptr,"%f\n",&interestRate);
									fscanf(ptr,"%f\n",&period);
									if(index==choice){ // if index equals to choice i can print the loan information for that choice
										printf("\n=====================================\n");
										printf("Total credit value for %d. Loan = %.4f\n",index,calculateLoan(amount,period,interestRate));
										for(i=0;i<period;i++){
											printf("%d. Month Installment = %.4f\n",i+1,calculateLoan(amount,period,interestRate)/period);
										}
										printf("\n");
									}	
								}
								else{
									fscanf(ptr,"%f\n",&number2);
									fscanf(ptr,"%f\n",&number2);
									fscanf(ptr,"%f\n",&number2);
								}
							}
						break;
					default :
						printf("\nEnter a valid number!!\n\n");
						break;	
					}	
				}while(choice!=1 && choice!=2 && choice!=3);
			}
			else if(counter==2){ // same operations for counter=2. one difference we have 2 loans
				index=0;
				do{
					printf("\nThere are %d loans information.\n",counter);
					printf("Which one do you want to get?(1-2) = ");
					scanf("%d",&choice);
					switch(choice){
						case 1:
						case 2:
							while(!feof(ptr)){
								fscanf(ptr," %[^\n]s\n",str2);
								if(strcmp(str,str2)==0){
									index++;
									fscanf(ptr,"%f\n",&amount);
									fscanf(ptr,"%f\n",&interestRate);
									fscanf(ptr,"%f\n",&period);
									if(index==choice){ // if they are equal i can print
										printf("\n=====================================\n");
										printf("Total credit value for %d. Loan = %.4f\n",index,calculateLoan(amount,period,interestRate));
										for(i=0;i<period;i++){
											printf("%d. Month Installment = %.4f\n",i+1,calculateLoan(amount,period,interestRate)/period);
										}
										printf("\n");
									}	
								}
								else{
									fscanf(ptr,"%f\n",&number2);
									fscanf(ptr,"%f\n",&number2);
									fscanf(ptr,"%f\n",&number2);
								}
							}
						break;
					default :
						printf("\nEnter a valid number!!\n\n");
						break;	
					}	
				}while(choice!=1 && choice!=2);
			}	
			else{ // we have just one loan information i got the first loan i do not need to check index
				printf("\nThere are %d loan information.",counter);
				while(!feof(ptr)){
					fscanf(ptr," %[^\n]s\n",str2);
					if(strcmp(str,str2)==0){
						fscanf(ptr,"%f\n",&amount);
						fscanf(ptr,"%f\n",&interestRate);
						fscanf(ptr,"%f\n",&period);
						break;
					}
					fscanf(ptr,"%f\n",&number2);
					fscanf(ptr,"%f\n",&number2);
					fscanf(ptr,"%f\n",&number2);
				}
				printf("\n=====================================\n");
				printf("Total credit value = %.4f\n",calculateLoan(amount,period,interestRate));
				for(i=0;i<period;i++){
					printf("%d. Month Installment = %.4f\n",i+1,calculateLoan(amount,period,interestRate)/period);
				}
				printf("\n");
			}
		}
		
	}
	else{
		printf("\n\nPlease enter a valid number!\n");
	}
	fclose(ptr);
	fclose(ptr2);
}

int clear (){ // THIS IS MY FFLUSH(STDIN) FUNCTION THIS RETURN A VALUE 
// IF THE RETURNED VALUE 0 THAT MEANS THE USER ENTERED 1 DIGIT. OTHERWISE MORE THAN ONE DIGIT THIS IS FALSE!!!
	int counter=0;
	while ( getchar() != '\n' ){
		counter++;
	}
	return counter;
}

int main(){
	
	char choice;
	int x;
	do{ // this is my main menu
		printf("=====================================\n");
		printf("Welcome to the Bank Management System\n");
		printf("=====================================\n");
		printf("\t1. List All Customers\n");
		printf("\t2. Add New Customer\n");
		printf("\t3. New Loan Application\n");
		printf("\t4. Report Menu\n");
		printf("\t5. Exit System\n");
		scanf(" %c",&choice);
		x=clear(); // clearing buffer
		if(x!=0){// that means you entered at least 2 digit character this is false
			choice='a';
		}
		switch(choice){
			case '1':
				listCustomers();
				break;
			case '2':
				addCustomer();
				fill_zero();
				break;
			case '3':
				newLoan();
				break;
			case '4':
				getReport();
				break;
			case '5':
				printf("GOOD BYE!\n");
				break;
			default:
				printf("\nPLEASE ENTER A VALID ENTRY!\n\n");					
		}
	}while(choice!='5');
	

	return 0;
}

