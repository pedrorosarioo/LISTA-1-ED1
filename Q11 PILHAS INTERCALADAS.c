#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int p[100];
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

int pop (Pilha *v){
int r;
     if(!(is_empity(v))){
        r=v->p[v->topo];
        v->topo--;
        return r;
     }else{
        return 0;
     }
}

void push(Pilha *v, int n){
     if(!(is_full(v))){
        v->topo++;
        v->p[v->topo]=n;
     }else{
        printf("Pilha cheia \n\n");
}
}

void intercala(Pilha *v, Pilha *s){
int r;
Pilha aux;
aux.topo=-1;
    while((!(is_empity(v))||(!(is_empity(s))))){
        r=pop(v);
        if (r){
            push(&aux, r);
        }
        r=pop(s);
        if (r){
            push(&aux, r);
        }
    }
    while(!(is_empity(&aux))){
        push(v, pop(&aux));
    }
}
int main(){
    int q;
    Pilha x, y;
    x.topo = -1;
    y.topo = -1;

    for(q=0; q<5; q++){
        push(&x, q+10);
    }
    for(q=0; q<5; q++){
        push(&y, q+21);
    }
    intercala(&x, &y);
    while(x.topo>-1){
        q=pop(&x);
        printf ("%d ", q);
    }
    return 0;
}
