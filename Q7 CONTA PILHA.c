#include <stdio.h>
#include <stdlib.h>

int conta(char *m){
int i, contpush=0, contpop=0;
    for (i=0; m[i]!='\0'; i++){
        if (m[i]=='#'){
            contpush++;
        }else if (m[i]=='@'){
            if(contpush-contpop==0){
                printf("O comando %d nao pode ser executado pois no momento nao existe nada para desempilhar\n");
            }else{
                contpop++;
            }
        }else if(m[i]=='&'){
            if (contpush-contpop==0){
                printf("O comando %d nao pode ser executado pois no momento nao existe nada na pilha, portanto nao ha topo\n");
            }
        }
    }
    return contpush-contpop;
}

int main (){
char m[100]="##@##@&&@@#@##@##@#";
int r;
r=conta(m);
printf("%d\n", r);
return 0;
}
