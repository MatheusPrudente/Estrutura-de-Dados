/*Escreva uma função de inserção de elementos 
em uma Lista Dinâmica com Nó Cabeça (note que você deverá criar a estrutura de definição da lista também)*/

#include "stdio.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

typedef struct Estrutura {
	int dado;
	struct estrutura *prox;
} Elemento;

typedef struct {
	Elemento *cabeca;
} Lista;

void inicializar(Lista *l){
	Elemento *novoElem = (Elemento*) malloc(sizeof(Elemento));
	novoElem->prox = NULL;
	l->cabeca = novoElem;
}



void inserir(int dado, Lista *l){

	Elemento *ant = l->cabeca;
	Elemento *p = l->cabeca->prox;
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
		ant->prox = novoElem;
		
   }
	
}


void exibirLista(Lista l) {	
	Elemento *p = l.cabeca;
	
	printf("\n\nLista : ");
	printf("\n[");
	while (p -> prox != NULL) {
	
		p = p->prox;
		printf("%d", p->dado);
		if (p -> prox  != NULL) {
		printf(",");
		
		}
		
	}
	printf("]");
}


void main(){
	Lista l;
	inicializar(&l);
	inserir(1,&l);
	inserir(4,&l);
	inserir(2,&l);
	inserir(6,&l);
	inserir(3,&l);
	inserir(6,&l);
	exibirLista(l);

	
}


