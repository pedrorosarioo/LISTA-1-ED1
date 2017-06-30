#include <stdio.h>
#include <stdlib.h>


typedef struct NoLista{
    int chave;
    struct NoLista *prox;
	struct NoLista *ant;
}NoLista, *Lista;

typedef struct NoTipoLista{
    union{
		int chave;
		Lista deque[2];
	};
    struct NoTipoLista *lprox;
}TipoNoLista, *TipoLista;


// -------------------- PILHA ---------------------------------------------------------------

void inicializa(Lista x[]){
  x[0]=NULL;
	x[1]=NULL;
}

int InsereFim(Lista y[], int n){
Lista aux;
aux=(Lista)malloc(sizeof(NoLista));
if (aux==NULL) return 0;

	aux->chave=n;
	aux->prox=NULL;
	aux->ant=NULL;

	if(y[1]==NULL){
		y[0]=aux;
		y[1]=aux;
	}else{
		y[1]->prox=aux;
		aux->ant=y[1];
		y[1]=y[1]->prox;
	}
	
return 1;
}

int InsereInicio(Lista y[], int n){
Lista aux;
aux=(Lista)malloc(sizeof(NoLista));
if (aux==NULL) return 0;

	aux->chave=n;
	aux->prox=NULL;
	aux->ant=NULL;

	if(y[0]==NULL){
		y[0]=aux;
		y[1]=aux;
	}else{
		y[0]->ant=aux;
		aux->prox=y[0];
		y[0]=y[0]->ant;
	}
return 1;
}
	


Lista RemoveInicio(Lista y[]){
Lista aux=y[0];
	if (y[0]==NULL) return NULL;
	if (y[0]==y[1]){
		y[0]=NULL;
		y[1]=NULL;
		return aux;
	}
	y[0]=y[0]->prox;
	aux->prox=NULL;
	y[0]->ant=NULL;
	return aux;
}

Lista RemoveFim(Lista y[]){
Lista aux=y[0];
	if (y[1]==NULL) return NULL;
	if (y[0]==y[1]){
		y[0]=NULL;
		y[1]=NULL;
		return aux;
	}
	y[1]=y[1]->ant;
	aux->ant=NULL;
	y[1]->prox=NULL;
	return aux;
}

Lista Remove(Lista y[]){
Lista aux=y[0];
	if (y[1]==NULL) return NULL;
	if (y[0]==y[1]){
		y[0]=NULL;
		y[1]=NULL;
		return aux;
	}
  if (y[1]->chave > y[0]->chave) return RemoveInicio(y);
  else return RemoveFim(y);
}

void InsereLista(TipoLista *x, TipoLista n){
TipoLista aux=n, ant=NULL, dep=*x;
if(aux->deque[0]!=NULL){
  if (dep==NULL){
      *x=aux;
      aux->lprox=NULL;
  }else{
      while (dep!=NULL){
          if (((aux->deque[0])->chave<(dep->deque[0])->chave)&&((aux->deque[0])->chave<(dep->deque[1])->chave))break;
          ant=dep;
          dep=dep->lprox;
      }
      if (ant==NULL){
          aux->lprox=*x;
          *x=aux;
      }else{
          aux->lprox=ant->lprox;
          ant->lprox=aux;
      }
  }
}else free(aux);
}

TipoLista ExcluiLista(TipoLista *x, TipoLista n){
TipoLista ant=NULL, aux=*x;
    while (aux!=NULL){
        if (aux==n) break;
        ant=aux;
        aux=aux->lprox;
    }
    if (ant==NULL){
        *x=aux->lprox;
    }else{
        ant->lprox=aux->lprox;
    }
    return aux;
}

void PrintaFila(Lista y[]){
  while(y[0]!=NULL){
    printf("%d ", y[0]->chave);
    RemoveInicio(y);
  }
}

// ------------------------------- ESPECIFICAS ---------------------------------------------------
void PROVA_Exclusao(TipoLista *x, Lista y[]){
TipoLista aux2, aux3;
Lista aux;
aux3=*x;
  if (aux3->deque[0]==NULL){
    *x=(*x)->lprox;
    free(aux3);
  }else{ 
    if ((((*x)->deque[0])->chave>(((*x)->lprox)->deque[0])->chave)&&(((*x)->deque[0])->chave>(((*x)->lprox)->deque[1])->chave)){
    aux2 = ExcluiLista(x, *x);
    InsereLista(x, aux2);
  }
  aux=Remove((*x)->deque);
  InsereFim(y, aux->chave);
  }
}

void Ordenada(TipoLista *x, Lista y[], int n){
int i;
  for(i=0; i<n; i++){
    if ((*x)&&((*x)->lprox)){
      PROVA_Exclusao(x, y);
    }
  }
}

int main(){
TipoLista aux, aux2, x=(TipoLista)malloc(sizeof(TipoNoLista));
Lista y[2];
int n=4;

  y[0]=NULL;
  y[1]=NULL;
  x->deque[0]=NULL;
  x->deque[1]=NULL;
  InsereFim(x->deque, 2);
  InsereFim(x->deque, 4);
  
  aux2=(TipoLista)malloc(sizeof(TipoNoLista));
  aux2->deque[0]=NULL;
  aux2->deque[1]=NULL;
  InsereFim(aux2->deque, 3);
  InsereFim(aux2->deque, 8);
  InsereFim(aux2->deque, 9);
  InsereLista(&x, aux2);
  printf("%d %d\n", (aux2->deque[0])->chave, (aux2->deque[1])->chave);
  
  aux2=(TipoLista)malloc(sizeof(TipoNoLista));
  aux2->deque[0]=NULL;
  aux2->deque[1]=NULL;
  InsereFim(aux2->deque, 5);
  InsereFim(aux2->deque, 15);
  InsereLista(&x, aux2);
  printf("%d %d\n", (aux2->deque[0])->chave, (aux2->deque[1])->chave);
  
  aux2=(TipoLista)malloc(sizeof(TipoNoLista));
  aux2->deque[0]=NULL;
  aux2->deque[1]=NULL;
  InsereFim(aux2->deque, 7);
  InsereFim(aux2->deque, 6);
  InsereLista(&x, aux2);
  printf("%d %d\n", (aux2->deque[0])->chave, (aux2->deque[1])->chave);
  
  aux2=(TipoLista)malloc(sizeof(TipoNoLista));
  aux2->deque[0]=NULL;
  aux2->deque[1]=NULL;
  InsereFim(aux2->deque, 16);
  InsereFim(aux2->deque, 5000);
  InsereLista(&x, aux2);
  printf("%d %d\n", (aux2->deque[0])->chave, (aux2->deque[1])->chave);
  
  aux2=(TipoLista)malloc(sizeof(TipoNoLista));
  aux2->deque[0]=NULL;
  aux2->deque[1]=NULL;
  InsereFim(aux2->deque, 6000);
  InsereFim(aux2->deque, 3000);
  InsereLista(&x, aux2);
  
  printf("%d %d\n", (aux2->deque[0])->chave, (aux2->deque[1])->chave); 
  
  Ordenada(&x, y, n);
  PrintaFila(y);
  
  
  
	return 0;
}



