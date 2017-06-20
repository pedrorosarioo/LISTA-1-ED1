#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int p[10];
        int topo;
}Pilha;

typedef struct NoLista{
    union{
		int chave;
		Pilha *pil;
	};
    struct NoLista *prox;
}NoLista, *Lista;


// -------------------- PILHA ---------------------------------------------------------------

int is_empity(Pilha *v){
    if (v->topo==-1){
       return 1;
    }else{
       return 0;
    }
}

int is_full(Pilha *v){
    if (v->topo>=10){
       return 1;
    }else{
       return 0;
    }
}

int pop(Pilha *v){
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

// ---------------------------------- LISTA -----------------------------------------------------------------

void inicializa(Lista *x){
    *x=NULL;
}

int InsereLista(Lista *x, int n){
Lista aux, ant=NULL, dep=*x;

aux=(Lista)malloc(sizeof(NoLista));
if (aux==NULL) return 0;
aux->chave=n;
if (dep==NULL){
    *x=aux;
    aux->prox=NULL;
    return 1;
}else{
    while (dep!=NULL){
        if (aux->chave<dep->chave)break;
        ant=dep;
        dep=dep->prox;
    }
    if (ant==NULL){
        aux->prox=*x;
        *x=aux;
    }else{
        aux->prox=ant->prox;
        ant->prox=aux;
    }
}
return 1;
}

Lista BuscaLista(Lista *x, int n){
Lista aux;
    for (aux=*x; aux!=NULL; aux=aux->prox){
        if (aux->chave==n){
            return aux;
        }
    }
return NULL;
}

int ExcluiLista(Lista *x, int n){
Lista ant=NULL, aux=*x;
if ((BuscaLista(x, n))){
    while (aux!=BuscaLista(x, n)){
        ant=aux;
        aux=aux->prox;
    }
    if (ant==NULL){
        *x=aux->prox;
        free(aux);
    }else{
        ant->prox=aux->prox;
        free(aux);
    }
    return 1;
}
return 0;
}

void PrintaLista(Lista x){
Lista aux=x;
    while (aux){
        printf("%d ", aux->chave);
        aux=aux->prox;
    }
}
// ------------------------------- ESPECIFICAS ---------------------------------------------------

int My_Pop(Lista *x){
Lista aux, r, menor;
r=(Lista)malloc(sizeof(NoLista));
	if (r==NULL) exit(1);
	for(aux=*x; aux; aux=aux->prox){
		if ((aux->pil)->topo > -1){
			if ((aux==*x)||((aux->pil)->p[(aux->pil)->topo]<(menor->pil)->p[(menor->pil)->topo])){
				menor=aux;
			}
		}
	}
	return pop(menor->pil);
}

void Ordenada(Lista *L1, int n, Lista *L2){
int i;
	for (i=0; i<n; i++){
		InsereLista(L2, My_Pop(L1));
	}
}

int main(){
Lista x, y;
inicializa(&x);
inicializa(&y);
x=(Lista)malloc(sizeof(NoLista));
x->prox=(Lista)malloc(sizeof(NoLista));
(x->prox)->prox=NULL;
Pilha k, j; //Teste com duas pilhas
k.topo=-1;
j.topo=-1;
push(&k, 15);
push(&k, 14);
push(&k, 13);
push(&k, 12);
push(&k, 8);
push(&j, 12);
push(&j, 11);
push(&j, 10);
push(&j, 9);
push(&j, 9);
push(&j, 7);
x->pil=&k; //Pilhas alocadas manualmente apenas para testes
(x->prox)->pil=&j;
Ordenada(&x, 10, &y);
PrintaLista(y);
	return 0;
}
