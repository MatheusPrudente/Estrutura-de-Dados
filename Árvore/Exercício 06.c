//Uma Árvore Binária é estritamente binária se todos os nós da árvore possuem 2 filhos. 
//Implemente uma função que verifica se uma Árvore AVL é estritamente binária.

#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#define TRUE 1
#define FALSE 0

typedef struct estrutura {
	int fb;
	int altura;
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

void emOrdem(NO* no){
	if (no != NULL){
	    printf("[");
		emOrdem(no->esq);
		printf("%d.h%d.fb%d",no->info,no->altura,no->fb);
		emOrdem(no->dir);
		printf("]");
	}
}

void imprimirArvore(ARVORE arv) {
    emOrdem(arv.raiz);
}

void calculaAlturaFB(NO** no){ 
    //obter a altura do n? a esquerda
    int altEsq = 0, altDir = 0;
    if ((*no)->esq != NULL) {
    	altEsq = (*no)->esq->altura;
	}
    //obter a altura do n? a direita
    if ((*no)->dir != NULL) {
		altDir = (*no)->dir->altura;
	}
    //calcular a altura deste n?
    if (altEsq > altDir) {
    	(*no)->altura = altEsq + 1;
	} else {
		(*no)->altura = altDir + 1;
	}
    //calcular FB deste n?
    (*no)->fb = altDir - altEsq;
}

void rotacaoDir(NO** raiz){ 
	NO* pai = (*raiz);
	NO* filho = (*raiz)->esq;
    pai->esq = filho->dir;
    filho->dir = pai;
    (*raiz) = filho;
    calculaAlturaFB(&((*raiz)->dir));
    calculaAlturaFB(&(*raiz));
}

void rotacaoEsq(NO** raiz) {
	NO* pai = (*raiz);
	NO* filho = (*raiz)->dir;
	pai->dir = filho->esq;
	filho->esq = pai;
	(*raiz) = filho;
	calculaAlturaFB(&((*raiz)->esq));
    calculaAlturaFB(&(*raiz));
}

void balancear(NO** no) {
	if ((*no)->fb == 2) {
		if ((*no)->dir->fb == -1) {
			rotacaoDir(&((*no)->dir));
		}
		rotacaoEsq(&(*no));
	} else if ((*no)->fb == -2) {
		if ((*no)->esq->fb == 1) {
			rotacaoEsq(&((*no)->esq));
		}
		rotacaoDir(&(*no));
	}
}

void insereNaArvore(ARVORE* arv, int novaInfo){
    inserir(&(arv->raiz), novaInfo);
}

void inserir(NO** noAtual, int novaInfo){
	//Procurar o local da inser??o
	if ((*noAtual) == NULL){
		(*noAtual) = (NO*) malloc(sizeof(NO));
		(*noAtual)->info = novaInfo;
		(*noAtual)->esq = NULL;
		(*noAtual)->dir = NULL;
    } else if (novaInfo > (*noAtual)->info) {
    	inserir(&((*noAtual)->dir), novaInfo);
	} else if (novaInfo < (*noAtual)->info) {
		inserir(&((*noAtual)->esq), novaInfo);
	}
	//Recalcular a altura e o FB dos n?s
	calculaAlturaFB(&(*noAtual));
	//Balancear a ?rvore caso necess?rio
	balancear(&(*noAtual));
}

void substituir(NO** noAtual, NO** noSub){
    if ((*noSub)->dir != NULL) {
        substituir(&(*noAtual), &((*noSub)->dir));
    } else {
        (*noAtual)->info = (*noSub)->info;
        (*noSub) = (*noSub)->esq;
    }
    if ((*noSub) != NULL) {
	    //Recalcular a altura e o FB dos n?s
		calculaAlturaFB(&(*noSub));
		//Balancear a ?rvore caso necess?rio
		balancear(&(*noSub));
	}
}

int remover(NO** noAtual, int infoRemo){		
	//Procurar o elemento
	if ((*noAtual) == NULL) {
		return FALSE;
	}
    if (infoRemo < (*noAtual)->info){
		return remover(&((*noAtual)->esq), infoRemo);
	} else if (infoRemo > (*noAtual)->info) {
		return remover(&((*noAtual)->dir), infoRemo);
	} else { //Se encontrado, remover considerando os casos
		if ((*noAtual)->dir == NULL) { //N?o tem filho pra direita
			(*noAtual) = (*noAtual)->esq;
		} else if ((*noAtual)->esq == NULL) { //N?o tem filho pra esquerda
			(*noAtual) = (*noAtual)->dir;
		} else {
			substituir(&(*noAtual), &((*noAtual)->esq));
		}
	}
	if ((*noAtual) != NULL) {
		//Recalcular a altura e o FB dos n?s
		calculaAlturaFB(&(*noAtual));
		//Balancear a ?rvore caso necess?rio
		balancear(&(*noAtual));
	}
	return TRUE;
}

void removerNaArvore(ARVORE* arv, int infoRemo){
	int deuCerto = remover(&arv->raiz, infoRemo);
	if (!deuCerto) {
		printf("Elemento nao encontrado!\n");
	}
}

int verificar(NO* no){
	int qtd = 0;
	
	if (no != NULL){	
		if(no->esq != NULL && no->dir != NULL){
			qtd++;
		}
		if(no->esq == NULL && no->dir == NULL){
			return 1;
		}
		
		return qtd+verificar(no->esq) + verificar(no->dir);
	}

	
}

int totalNo(NO* no){
	
	if (no != NULL){
		 return 1 + totalNo(no->esq) + totalNo(no->dir);
	}
}


int verificarArvoreBinaria(ARVORE arv){
	int qtd =  verificar(arv.raiz);
	int tNo = totalNo(arv.raiz);

	if(qtd == tNo){
	   return 1;
	}
	return 0;


	
}


void main() {
	ARVORE arv;
	inicializar(&arv);

	printf("Insercoes:\n");
	insereNaArvore(&arv, 100);
	imprimirArvore(arv);
	printf("\n");
	insereNaArvore(&arv, 80);
	imprimirArvore(arv);
	printf("\n");
	insereNaArvore(&arv, 60);
	imprimirArvore(arv);
	printf("\n");
	insereNaArvore(&arv, 90);
	imprimirArvore(arv);
	printf("\n");
	insereNaArvore(&arv, 40);
	imprimirArvore(arv);
	printf("\n");
	insereNaArvore(&arv, 79);
	imprimirArvore(arv);
	printf("\n");
	insereNaArvore(&arv, 84);
	imprimirArvore(arv);
	printf("\n");
	printf("\nA arvore eh estritamente binaria ? %d",verificarArvoreBinaria(arv));
}	

