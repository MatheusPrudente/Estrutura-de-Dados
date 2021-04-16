//Escreva uma função que determina a altura de uma Árvore Binária de Busca.

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define TRUE 1
#define FALSE 0

#include "stdio.h"
#include "stdlib.h"

typedef struct estrutura {
	int info;
	struct estrutura *esq;
	struct estrutura *dir;
} NO; 

typedef struct {
	NO* raiz;
} ARVORE;

void inicializar(ARVORE *arv) {
	arv->raiz = NULL;
}

int buscar(NO* noAtual, int infoProc) {
	if (noAtual == NULL) {
		return FALSE;
	}
	if (noAtual->info == infoProc) {
		return TRUE;
	}
	if (noAtual->info < infoProc) {
		return buscar(noAtual->dir, infoProc);
	} else {
		return buscar(noAtual->esq, infoProc);
	}
}

int buscarNaArvore(ARVORE arv, int infoProc) {
	return buscar(arv.raiz, infoProc);
}

void inserir(NO** noAtual, int novaInfo) {
	if (*noAtual == NULL) {
		NO* novoNo = (NO*) malloc(sizeof(NO));
		novoNo->esq = NULL;
		novoNo->dir = NULL;
		novoNo->info = novaInfo;
		*noAtual = novoNo;
	} else if ((*noAtual)->info < novaInfo) {
		return inserir(&((*noAtual)->dir), novaInfo);
	} else {
		return inserir(&((*noAtual)->esq), novaInfo);
	}
}

void inserirNaArvore(ARVORE *arv, int novaInfo) {
	inserir(&arv->raiz, novaInfo);
}

void preOrdem(NO* noAtual) {
	if (noAtual != NULL) {
		printf("%d ", noAtual->info);
		preOrdem(noAtual->esq);
		preOrdem(noAtual->dir);	
	}
}

void emOrdem(NO* no){
	if (no != NULL){
	    printf("[");
		emOrdem(no->esq);
		printf("%d",no->info);
		emOrdem(no->dir);
		printf("]");
	}
}


void imprimir(ARVORE arv) {
	preOrdem(arv.raiz);
	printf("\n");
	emOrdem(arv.raiz);
}


void substituir(NO** noAtual, NO** noSub) {
	if ((*noSub)->dir != NULL) {
		substituir(&(*noAtual), &((*noSub)->dir));
	} else {
		(*noAtual)->info = (*noSub)->info;
		(*noSub) = (*noSub)->esq;
	}
}

int remover(NO** noAtual, int infoRemo) {
	if ((*noAtual) == NULL) { //N?o existe
		return FALSE;
	} else if (infoRemo > (*noAtual)->info) { //Caso recursivo
		return remover(&((*noAtual)->dir), infoRemo);
	} else if (infoRemo < (*noAtual)->info) { //Caso recursivo
		return remover(&((*noAtual)->esq), infoRemo);
	} else { //Encontrei o caboco!
		if ((*noAtual)->dir == NULL) { //CASO 1 e 2
			(*noAtual) = (*noAtual)->esq;
		} else if ((*noAtual)->esq == NULL) { //CASO 2
			(*noAtual) = (*noAtual)->dir;
		} else { //CASO 3
			substituir(&(*noAtual), &((*noAtual)->esq));
		}
		return TRUE;
	}
}

void removerNaArvore(ARVORE *arv, int infoRemo) {
	int deuCerto = remover(&arv->raiz, infoRemo);
	if (!deuCerto) {
		printf("Elemento nao encontrado!\n");
	}
}

int alturaTotal(NO* no){
	if (no != NULL){
		
		int altEsq = alturaTotal(no->esq);
		int altDir = alturaTotal(no->dir);
		
		if(altDir < altEsq ){
			return altEsq + 1;
		}
		else {
			return altDir + 1;
		}
	}
	
	
}

int alturaTotalDaArvore(ARVORE arv){
	return alturaTotal(arv.raiz);
}
void main() {
	ARVORE arv;
	inicializar(&arv);
	inserirNaArvore(&arv, 15);
	inserirNaArvore(&arv, 20);
	inserirNaArvore(&arv, 8);
	inserirNaArvore(&arv, 5);
	inserirNaArvore(&arv, 9);
	inserirNaArvore(&arv, 10);
	imprimir(arv);
	printf("\n");

	printf("\nA altura da arvore eh : %d ",	alturaTotalDaArvore(arv));
}
