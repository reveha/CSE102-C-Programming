#include <stdio.h>
#include <math.h>

typedef struct{
	int x;
	int y;
	
}coordinates;

typedef struct{
	coordinates points[2];
	float radius;
	float perimeter;
	float area;
	
}circle;

void print_struct(circle crc[],int number){

	static int index=0;
	int i,j;
	static float min=9999;
	float array[number];
	int check=1;
	float temp_min;
	for(i=0;i<number;i++){
		array[i]=crc[i].radius;
	}
	if(index==0){
		for(i=0;i<number;i++){
			if(crc[i].radius<min){
				min=crc[i].radius;// to find min number
			}
		}
	}
	//printf("%d\n",min);
	for(i=0;i<number;i++){
		if(min==crc[i].radius){
			printf("Circle %d\tRadius: %.2f\tPerimeter: %.2f\t Area: %.2f\n",i+1,crc[i].radius,crc[i].perimeter,crc[i].area);
			min=crc[i].radius;
		}
	}
	for(i=0;i<number;i++){ // to find latest min number
		if(array[i]>min && check==1){
			printf("\n%d\n",i);
			temp_min=array[i];
			
			for(j=i;j<number;j++){
				if(temp_min>array[j] && array[j]!=min){
					check=0;
					break;
				}
			}	
		}
		if(check==1){
			
			break;
		}
		check=1;
	}
	
	min=temp_min;
	printf("%.2f\n",min);
	if(index==number-1){
		return;
	}
	index++;
	print_struct(crc,number);
}

circle calculate(circle crc, int index, coordinates coor){
	
	printf("\n\nCircle %d...\n",index+1);
	printf("Coordinates of center: ");
	scanf("%d %d",&coor.x,&coor.y);
	crc.points[0].x=coor.x;
	crc.points[0].y=coor.y;
	printf("Coordinates of point P: ");
	scanf("%d %d",&coor.x,&coor.y);
	crc.points[1].x=coor.x;
	crc.points[1].y=coor.y;
	crc.radius=sqrt(((crc.points[1].x-crc.points[0].x)*(crc.points[1].x-crc.points[0].x))+((crc.points[1].y-crc.points[0].y)*(crc.points[1].y-crc.points[0].y)));
	
	crc.perimeter=2*3.14*crc.radius;
	crc.area=3.14*crc.radius*crc.radius;
	//printf("%.2f\n",crc.radius);
	return crc;
}

int is_prime(int number){
	static int divider=2;
	static int result=1;
	if(number%divider==0){
		result=0;
	}
	if(divider==number){
	//printf("aaa\n");
		return 1;
	}
	divider++;
	is_prime(number);
	if(result==1){
	//printf("cc\n");
		return 1;
	}
	else if(result==0){
	//printf("bb\n");
		return 0;
	}
}

void factorization(int number){
	static int divider=2;
	if(divider==number){
		printf("%d*",divider);
		return;
	}
	if(number%divider==0){
		printf("%d*",divider);	
		factorization(number/divider);
	}
	else{
		divider++;
		factorization(number);
	}
	
}	

int main(){
	printf("PART 1\n\n");
	int number;
	printf("Number of circle: ");
	scanf("%d",&number);
	int array[number];
	circle crc[number];
	coordinates coor;
	int i;
	int temp[number];
	for(i=0;i<number;i++){
		crc[i]=calculate(crc[i],i,coor);
	//	printf("%.2f\n",crc[i].radius);
	}
	
	
	printf("Printing circles in an ascending order...\n\n");
	print_struct(crc,number);
	
	printf("\n\nPART2\n\n\n");
	printf("Enter a number: ");
	scanf("%d",&number);
	int result=is_prime(number);
	if(result==1){
		printf("%d is a prime number.\n",number);
	}
	else{
		printf("%d: ",number);
		factorization(number);	
	}
	

	return 0;
}
























