#include <stdio.h>
#include <stdlib.h>

typedef struct tipopilha{
int chave;
struct tipopilha *prox;
}NoPilha, *Topo;

void inicializa(Topo *x){
    *x=NULL;
}

int is_empity(Topo x){
    if (x==NULL){
        return 1;
    }else{
        return 0;
        }
}

void push(Topo *x, int n){
Topo aux;
aux=(NoPilha*)malloc(sizeof(NoPilha));
if(aux){
    aux->chave=n;
    aux->prox=*x;
    *x=aux;
}else{
    printf("Pilha cheia\n");
}
}

void pop(Topo *x){
Topo aux;
    if (!(is_empity(*x))){
        aux=*x;
        *x=(*x)->prox;
        free(aux);
    }
}

int ComparaTam(Topo x, Topo y){
    if ((x==NULL)||(y==NULL)){
        if ((x==NULL)&&(y==NULL)){
            return 1;
        }else{
            return 0;
        }
    }else{
        pop(&x);
        pop(&y);
        return(ComparaTam(x, y));
    }
}

int main(){
Topo p, q;
inicializa(&p);
inicializa(&q);
push(&p, 1);
push(&p, 2);
push(&q, 3);
push(&q, 4);
//push(&p, 5);
printf("%d", ComparaTam(p,q));
return 0;
}
