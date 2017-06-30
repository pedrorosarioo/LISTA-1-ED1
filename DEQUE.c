#include <stdio.h>
#include <stdlib.h>

typedef struct NoLista{
    int chave;
    struct NoLista *prox;
	struct NoLista *ant;
}NoLista, *Lista;

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
	

void Inverte(Lista y[]){
Lista aux;
	if (y[1]!=y[0]){
		if (y[0]->prox!=y[1]){
			aux=y[1]->ant;
			y[1]->prox=y[0]->prox;
			y[1]->ant=NULL;
			y[0]->prox=NULL;
			y[0]->ant=aux;
		}else{
			y[1]->prox=y[0];
			y[1]->ant=NULL;
			y[0]->prox=NULL;
			y[0]->ant=y[1];
		}
		aux=y[0];
		y[0]=y[1];
		y[1]=aux;
	}
}



int main(){
int p;
Lista x[2];
inicializa(x);
InsereFim(x, 2);
InsereFim(x, 3);
InsereFim(x, 1);
//Inverte(x);
printf("%d %d %d", x[0]->chave, (x[0]->prox)->chave, x[1]->chave);
return 0;
}