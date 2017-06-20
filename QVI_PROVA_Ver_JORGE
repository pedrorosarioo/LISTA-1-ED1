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
int Topo(Lista x){
  if ((x->pil)->topo == -1) return 0;
  return (((x)->pil)->p[((x)->pil)->topo]);
}

/*int My_Pop(Lista *x){
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
}*/

void InsereOrdenada(Lista *x, Lista *y){
Lista aux=*x, aux2;
  while(aux!=NULL){
    if (Topo(aux)>Topo(*y)) break;
    aux2=aux;
    aux=aux->prox;
  }
  if (aux==*x){
    (*y)->prox=aux;
    *x=*y;
  }else{
    (*y)->prox=aux2->prox;
    aux2->prox=*y;
  }
}

Lista RemoveOrdenada(Lista *x, Lista *y){
Lista aux=*x;
if(*y){
  if (*y==*x){
    *x=(*y)->prox;
    (*y)->prox=NULL;
    return *y;
  }
  while((aux->prox)&&(aux->prox!=*y)){
    aux=aux->prox;
  }
  if (aux->prox){
    aux->prox=(*y)->prox;
    (*y)->prox=NULL;
    return (*y);
  }
}
}

int My_Pop2(Lista *x){
int s;
Lista aux=*x, r;
  if(*x){
    if (Topo(aux)>Topo(aux->prox)){
      r=RemoveOrdenada(x, &aux);
      InsereOrdenada(x, &r);
      aux=*x;
    }
      if((aux->pil)->topo==-1){
        *x=(*x)->prox;
        free(aux);
        aux=*x;
      }
      return pop(aux->pil);
  }
return 0;
}


void Insere_Final(Lista *x, Lista *z, int n){
Lista y;
y=(Lista)malloc(sizeof(NoLista));
if (y==NULL) exit(1);
y->chave=n;
y->prox=NULL;
  if (*x==NULL){ 
    *x=y;
    *z=*x;
  }else{
    //printf("%d\n", *z);
    (*z)->prox=y;
    *z=y;
  }
}

void Ordenada(Lista *L1, int n, Lista *L2, Lista *L2f){
int i;
	for (i=0; i<n; i++){
	  //printf("%d ", (*L1)->prox);
		Insere_Final(L2, L2f, My_Pop2(L1));
	}
}

int main(){
Lista x, y, yf, e=NULL;
inicializa(&x);
inicializa(&y);
x=(Lista)malloc(sizeof(NoLista));
x->prox=(Lista)malloc(sizeof(NoLista));
(x->prox)->prox=NULL;
yf=y;
Pilha k, j; //Teste com duas pilhas
k.topo=-1;
j.topo=-1;
push(&k, 83);
push(&k, 81);
push(&k, 50);
push(&k, 40);
push(&k, 2);
push(&j, 84);
push(&j, 82);
push(&j, 60);
push(&j, 39);
push(&j, 2);
push(&j, 1);
x->pil=&k; //Pilhas alocadas manualmente apenas para testes
(x->prox)->pil=&j;
Ordenada(&x, 11, &y, &yf);
PrintaLista(y);
	return 0;
}
