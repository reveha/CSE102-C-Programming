#include <stdio.h>
#include <stdlib.h>
int power_raiser(int base, int power);

int main()
{
    int x = power_raiser(2,3);
    printf("%d",x);
}

int power_raiser(int base, int power){

int ans=1;

if (power == 1){
ans = base;
}
else{
ans = base * power_raiser(base,power-1);
}
return (ans);

}
