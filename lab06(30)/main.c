#include <stdio.h>

int main(){
	int choice;
	char alphabet[26][26];
	char plaintext[10]; // plain text
	char key[3]; // key
	char keystream[10]; // keystream;
	char ciphertext[10];
	char a='A';
	int i,j;
	int k=0;
	char c;
	for(i=0;i<26;i++){ // assigning alphabet here
		for(j=0;j<26;j++){
			alphabet[i][j]=a;
			if(a=='Z'){ // if a is Z i have to return it to A
				a='A';
			}
			else{
				a++;
			}	
		}
		a='A';
		a+=i+1;
		
		
	}
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			printf("%c ",alphabet[i][j]); // printing alphabet here ..
		}
		printf("\n");
	}
	printf("Enter plaintext:(10 char) \n");
	for(i=0;i<10;i++){ // i got the plaintext
		c=getchar();
		plaintext[i]=c;
	}
	printf("Enter the key (3 char): \n");
	while(getchar()!='\n');
	for(i=0;i<3;i++){
		c=getchar(); // i got the key
		key[i]=c;
	}
	k=0;
	printf("Keystream: ");
	
	keystream[0]=key[0];
	keystream[1]=key[1];
	keystream[2]=key[2];
	keystream[3]=key[0]; // i assigned keystreamm here
	keystream[4]=key[1];
	keystream[5]=key[2];
	keystream[6]=key[0];
	keystream[7]=key[1];
	keystream[8]=key[2];
	keystream[9]=key[0];
	for(i=0;i<10;i++){
		printf("%c",keystream[i]);
	}
	printf("\n");
	int t=0;
	k=0;
	int r,b; // to keep indexes 
	int y=0;// counter;
	int u=0;
	int p=0;
	while(1){
		for(i=0;i<26;i++){
		
			if(plaintext[i]==alphabet[i][0]){
				for(j=0;j<26;j++){
					if(keystream[j]==alphabet[i][j]){
						printf("%c",alphabet[i][j]);
						p++;
					}
				}
			}

		}
		if(p==9){
			break;
		}
	}
	return 0;
}




















