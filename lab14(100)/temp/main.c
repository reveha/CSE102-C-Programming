#include <stdio.h>
#include <stdlib.h>


typedef struct binary{
	int data;
	char str[50];
	
}binary;


int main(){
	FILE *ptr=fopen("binary.bin","ab+");
	binary a,b;
	printf("Enter a number: ");
	scanf("%d",&a.data);
	printf("Enter a string: ");
	scanf(" %s",a.str);
	fwrite(&a,sizeof(binary),1,ptr);
	rewind(ptr);
	while(!feof(ptr)){		
		fread(&b,sizeof(binary),1,ptr);
		if(feof(ptr)){
			break;
		}
		printf("\n%d\n%s\n",b.data,b.str);
	}
	fclose(ptr);
	
	return 0;
}
