#include <stdio.h>
#include <stdlib.h>

typedef struct{
        char p[100];
        int topo;
}Pilha;


int is_empity(Pilha *v){
    if (v->topo==-1){
       return 1;
    }else{
       return 0;
    }
}

int is_full(Pilha *v){
    if (v->topo>=100){
       return 1;
    }else{
       return 0;
    }
}

char pop (Pilha *v){
char r;
     if(!(is_empity(v))){
        r=v->p[v->topo];
        v->topo--;
        return r;
     }else{
        return 0;
     }
}

void push(Pilha *v, char n){
     if(!(is_full(v))){
        v->topo++;
        v->p[v->topo]=n;
     }else{
        printf("Pilha cheia \n\n");
}
}

void invertepalavra(char *x, int n, int m){
Pilha p;
p.topo=-1;
int y=n;
while(n<=m){
    push(&p, x[n]);
    n++;
}
for (n=y; n<=m; n++){
    x[n]=pop(&p);
}
}

int main(){
int i, x1, x2;
char m[100] = "ESTE EXERCICIO E MUITO FACIL";
for(i=0; ((i<100)&&(m[i]!= '\0')); i++){
    if (m[i]!= ' '){
        x1=i;
        while((m[i]!= ' ')&&(m[i]!='\0')){
            i++;
        }
        x2=i-1;
        invertepalavra(m, x1, x2);
        i=x2;
    }
}
printf("%s", m);
return 0;
}

