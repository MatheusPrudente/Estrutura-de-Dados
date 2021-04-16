/*Escreva uma função que inverta os elementos de uma Lista Dinâmica.*/

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

typedef struct Estrutura {
	int dado;
	struct Estrutura* prox;
} Elemento;

typedef struct {
	Elemento *inicio;
} Lista;

void inicializar(Lista *l ){
	l ->inicio = NULL;
}

void exibirLista(Lista l ){
	Elemento* elem = l .inicio;
	
	printf("\n[");
	while(elem != NULL){
		printf("%d",elem->dado);
		if(elem->prox != NULL){
			printf(",");

		}
		elem= elem->prox;
	}
	printf("]");
	
}

void inserir(int dado, Lista *l ){
	Elemento *ant = NULL;
	Elemento *p = l ->inicio;
	int enc = 0;
	
	while(p != NULL && p->dado < dado) {
		ant = p;
		p = p->prox;

	}
	
	if(p != NULL && p->dado == dado){
		printf("\nElemento existente");
		enc++;
	}

   if(enc == 0){
   		Elemento* novoElem = (Elemento*)malloc(sizeof(Elemento));
   		novoElem->dado = dado;
		novoElem->prox = p;
		if (ant != NULL) {
			ant->prox = novoElem;
		} else { 
			l ->inicio = novoElem;
		}
   }

}

void remover(int dado, Lista *l ){
	Elemento* ant = NULL;
	Elemento* p = l ->inicio;
	int enc = 0;
	
	while(p != NULL) {
		if (p->dado == dado) {
			enc++;
			break;
		}
		ant = p;
		p = p->prox;
	}
	
	if( enc!=0 ) {
			if (ant != NULL) { 
			ant->prox = p->prox;
		} else {
		 	l ->inicio = p->prox;
		}

		p->prox = NULL;
		free(p);
		printf("\nElemento removido");
	}
	else{
		printf("\nElemento nao existente");

	}



}

void inverterLista(Lista *l){
	

	Elemento *ant = NULL;
	Elemento *aux = NULL;
	Elemento *p = l ->inicio;
	
	while(p != NULL) {
		
		if (p->prox == NULL){
			l->inicio = p;
		}	
			aux = ant;
			ant = p;
			p = p->prox;
			ant->prox = aux;
	}
  
}


void main(){
	Lista l;
	inicializar(&l);
	inserir(1,&l);
	inserir(4,&l);
	inserir(2,&l);
	inserir(6,&l);
	inserir(3,&l);
	inserir(10,&l);
	inserir(7,&l);
	printf("\nLista nomal : ");
	exibirLista(l);
	inverterLista(&l);
	printf("\n\nLista invertida : ");
	exibirLista(l);
}

