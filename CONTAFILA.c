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

void InsereNoFim(Lista y[], Lista n){
Lista aux=n;

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

int ContaFila(Lista y[]){
int cont=0;
Lista aux, aux2;
aux=y[1];

if (y[0]==NULL) return 0;
if (y[0]==y[1]) return 1;

	do{
		aux2=RemoveInicio(y);
		InsereNoFim(y, aux2);
		cont++;
	}while(y[1]!=aux);

return cont;
}




int main(){
int p;
Lista x[2];
inicializa(x);
InsereFim(x, 2);
InsereFim(x, 3);
//InsereFim(x, 1);
printf("%d", ContaFila(x));
return 0;
}