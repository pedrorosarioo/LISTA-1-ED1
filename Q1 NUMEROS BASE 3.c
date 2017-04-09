#include <stdio.h>
#include <stdlib.h>


int verifica(char *k, int n, int m){
int cont0=0, cont1=0, cont2=0;
while(n<=m){
    switch(k[n]){
        case '0':
            cont0++;
            break;
        case '1':
            cont1++;
            break;
        case '2':
            cont2++;
            break;
    }
n++;
}
if((cont0)&&(cont1)&&(cont0!=cont1)&&(cont0==cont2)){
    return 1;
}else{
    return 0;
}
}


int main(){
int i, x1, x2, r=0;
char m[100] = "00111122 012 000012222 001122";
for(i=0; ((i<100)&&(m[i]!= '\0')); i++){
    if (m[i]!= ' '){
        x1=i;
        while((m[i]!= ' ')&&(m[i]!='\0')){
            i++;
        }
        x2=i-1;
        r=r+verifica(m, x1, x2);
    }
}
printf("%d\n", r);
return 0;
}
