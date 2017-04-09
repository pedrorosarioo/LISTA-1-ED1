#include <stdio.h>
#include <stdlib.h>
enum {A=0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, X, Z};

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

int verifica(char p){
if (p=='A')
    return A;
if (p=='B')
    return B;
if (p=='C')
    return C;
if (p=='D')
    return D;
if (p=='E')
    return E;
if (p=='F')
    return F;
if (p=='G')
    return G;
if (p=='H')
    return H;
if (p=='I')
    return I;
if (p=='J')
    return J;
if (p=='K')
    return K;
if (p=='L')
    return L;
if (p=='M')
    return M;
if (p=='N')
    return N;
if (p=='O')
    return O;
if (p=='P')
    return P;
if (p=='Q')
    return Q;
if (p=='R')
    return R;
if (p=='S')
    return S;
if (p=='T')
    return T;
if (p=='U')
    return U;
if (p=='V')
    return V;
if (p=='X')
    return X;
if (p=='Z')
    return Z;
}

int main(){
char conta[100]="ABC++D*D*";
int i, valor[26] = {1,2,3,4,5,6,7,8,9,10};
Pilha x;
for(i=0; conta[i]!='\0'; i++){
    if (conta[i]=='+'){
        push(&x, (pop(&x)+pop(&x)));
    }else if (conta[i]=='-'){
        push(&x, (pop(&x)-pop(&x)));
    }else if (conta[i]=='*'){
        push(&x, (pop(&x)*pop(&x)));
    }else if (conta[i]=='/'){
        push(&x, (pop(&x)/pop(&x)));
    }else
        push(&x, valor[verifica(conta[i])]);
}
printf("%d\n", pop(&x));
return 0;
}

//FALTA TRATAR O 0!!!

