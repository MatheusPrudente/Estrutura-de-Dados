/*Escreva uma função para contar o número de elementos na Lista Dinâmica*/

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

void inicializar(Lista *l){
	l->inicio = NULL;
}

void inserir(int dado, Lista *l){
	Elemento *ant = NULL;
	Elemento *p = l->inicio;
	int enc = 0;
	
	
	while(p != NULL) {
		if (p->dado == dado) {
			printf("\nElemento existente");
			enc++;
			break;
		}
		ant = p;
		p = p->prox;
	}

   if(enc == 0){
   		Elemento* novoElem = (Elemento*)malloc(sizeof(Elemento));
   		novoElem->dado = dado;
		novoElem->prox = p;
		if (ant != NULL) {
			ant->prox = novoElem;
		} else { 
			l->inicio = novoElem;
		}
   }

}

void remover(int dado, Lista *l){
	Elemento* ant = NULL;
	Elemento* p = l->inicio;
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
		 	l->inicio = p->prox;
		}

		p->prox = NULL;
		free(p);
		printf("\nElemento removido");
	}
	else{
		printf("\nElemento nao existente");

	}



}

int contarElemento(Lista l) {
	int quantidade = 0;
	Elemento* p = l.inicio;
	
	while(p != NULL) {
		quantidade++;
		p = p->prox;
	}
	return quantidade;
}

void main(){
	Lista l;
	inicializar(&l);
	inserir(1,&l);
	inserir(4,&l);
	inserir(3,&l);
	inserir(2,&l);
	inserir(5,&l);
	inserir(7,&l);

	printf("\nQuantidade de elementos : %d",contarElemento(l));

	
	
}
