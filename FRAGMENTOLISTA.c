#include <stdio.h>
#include <stdlib.h>

typedef struct NoLista{
    int chave;
    struct NoLista *prox;
}NoLista, *Lista;

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

Lista BuscaDaProva(Lista *x, NoLista *y){
Lista aux=*x, ant=NULL;
	if(aux){
		while(aux!=NULL){
			if (aux==y) break;
			ant=aux;
			aux=aux->prox;
		}
		if (ant==NULL){
			*x=NULL;
			return aux;
		}else{
			ant->prox=NULL;
			return aux;
		}
	}
	return NULL;
}

void PrintaLista(Lista x){
	if (x==NULL){
		printf("Lista vazia");
	}else{
		while (x!=NULL){
			printf("%d ", x->chave);
			x=x->prox;
		}
	}
}

int main(){
int p;
Lista x, y, r=NULL;
inicializa(&x);
InsereLista(&x, 1);
InsereLista(&x, 3);
InsereLista(&x, 2);
InsereLista(&x, 6);
y = x;

printf("Antes\n");
printf("X: ");
PrintaLista(x);
printf("\n");
printf("R: ");
PrintaLista(r);
printf("\n");

r=BuscaDaProva(&x, y);

printf("DEPOIS\n");
printf("X: ");
PrintaLista(x);
printf("\n");
printf("R: ");
PrintaLista(r);
printf("\n");

return 0;
}