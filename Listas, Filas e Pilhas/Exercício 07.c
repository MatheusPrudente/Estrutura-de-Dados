/*Em um sistema operacional comum, existem programas específicos 
do próprio sistema que cuidam da ordem de execução dos processos.
Para definir a ordem, estes programas do S.O. utilizam uma estrutura 
de dados chamado de Fila de Prioridades. Em uma Fila de Prioridades,
os elementos da fila são associados a um valor de prioridade. 
Desta forma, a inserção OU a remoção devem ser modificadas para que
o elemento de maior prioridade seja obtido em uma operação de remoção
nesta fila especial. Considerando a estrutura abaixo, 
implemente as funções de inserção e remoção desta Fila de Prioridades.

typedef struct estrutura {
        int numProcesso;
        int prioridade;
        struct estrutura *prox;
} NO;

typedef struct {
        NO* inicio;
} FILA_PRIORIDADE;

*/

#include "stdio.h"
#include "malloc.h"

typedef struct estrutura {
        int numProcesso;
        int prioridade;
        struct estrutura *prox;
} NO;

typedef struct {
        NO* inicio;
} FILA_PRIORIDADE;

void inicializar(FILA_PRIORIDADE *f ){
	f ->inicio = NULL;
}

void inserir(int numProcesso,int prioridade, FILA_PRIORIDADE *f ){
	NO *ant = NULL;
	NO *p = f ->inicio;
	int enc = 0;
	
	while(p != NULL && p->prioridade > prioridade) {
		ant = p;
		p = p->prox;

	}
	
	if(p != NULL && p->numProcesso == numProcesso){
		printf("\nProcesso existente");
		enc++;
	}

   if(enc == 0){
   		NO* novoNo = (NO*)malloc(sizeof(NO));
   		novoNo-> numProcesso= numProcesso;
   		novoNo->prioridade = prioridade;
		novoNo->prox = p;
		if (ant != NULL) {
			ant->prox = novoNo;
		} else { 
			f ->inicio = novoNo;
		}
   }

}

void remover(int numProcesso, FILA_PRIORIDADE *f ){
	NO* ant = NULL;
	NO* p = f ->inicio;
	int enc = 0;
	
	while(p != NULL) {
		if (p->numProcesso == numProcesso) {
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
		 	f ->inicio = p->prox;
		}
		printf(" [%d/%d]",p->prioridade, p->numProcesso);
		p->prox = NULL;
		free(p);
		printf("\Processo removido");
	}
	else{
		printf("\nProcesso nao encotrado");

	}



}

void exibirLista(FILA_PRIORIDADE f ){
	NO* no = f .inicio;
	printf("\nLista (NumPrioridade/NumProcesso) : ");
	printf("\n[");
	while(no != NULL){
		printf(" %d/%d",no->prioridade, no->numProcesso);
		if(no->prox != NULL){
			printf(",");

		}
		no= no->prox;
	}
	printf("]");
	
}

void main(){
	FILA_PRIORIDADE l;
	inicializar(&l);
	inserir(1,10,&l);
	inserir(4,20,&l);
	inserir(2,2,&l);
	inserir(6,3,&l);
	inserir(3,45,&l);
	inserir(10,54,&l);
	inserir(7,43,&l);
	inserir(20,100,&l);
	exibirLista(l);
}

