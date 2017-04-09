#include <stdio.h>
#include <stdlib.h>

int fat(int n){
int r=n;
while (n>1){
   r=r*(n-1);
   n--;
}
return r;
}


int main(){
int p;
p=fat(5);
printf("%d", p);
return 0;
}
