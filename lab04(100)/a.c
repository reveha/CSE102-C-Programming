#include <stdio.h>
#include <stdlib.h>

int ucleyici(int sayi, int sayi2);
int ciftleyici(int func(int a, int b));

int main()
{

printf("%d\n", ciftleyici(ucleyici));

}

int ucleyici(int sayi, int sayi2){

sayi*=sayi2;

return sayi;

}

int ciftleyici(int func(int a, int b)){
	int a=5;
	int b=7;
int x = func(a,b);

x*=2;

return x;
}
