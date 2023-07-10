#include <stdio.h>
#define PI 3.14

void distance(int a1,int b1,int a2,int b2);
void midpoint(int a1,int b1,int a2,int b2);
void slope(int a1,int b1,int a2,int b2);
void area(float r);

float dist=0;
int main(){
	int x1,x2,y1,y2;
	printf("Enter the first coordinates (x1,y1):");
	scanf("%d %d",&x1,&y1);
	printf("Enter the second coordinates (x2,y2):");
	scanf("%d %d",&x2,&y2);
	
	slope(x1,y1,x2,y2);
	midpoint(x1,y1,x2,y2);
	area(dist);


	return 0;
}	

void distance(int a1,int b1,int a2,int b2){
	
	dist=(a2-a1)*(a2-a1)+(b2-b1)*(b2-b1);

}

void midpoint(int a1,int b1,int a2,int b2){
	float a3,b3;
	
	a3=(a1+a2)/2.0;
	b3=(b1+b2)/2.0;
	printf("The midpoint is (%.2f,%.2f)\n",a3,b3);
	distance(a1,b1,a3,b3);
		
		
}
	

void slope(int a1,int b1,int a2,int b2){
	
	
	float c;
	c=(b2-b1)/(a2-a1);
	printf("The slope is %.2f\n",c);
	
}

void area(float r){
	
	float area=PI*r;
	printf("The area of the circle is %.2f\n",area);
	
	
}
