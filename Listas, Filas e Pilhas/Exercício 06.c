/*Usando uma Pilha, escreva uma função que receba uma string e 
verifique se a string está com todos os parênteses “fechados”. 
Por exemplo, a string “(abc(ab(abc))ab)” está balanceada,
 enquanto que a string “(a(abc(abc))” não está balanceada.*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"

typedef struct Estrutura {
	char letra;
	struct Estrutura* prox;
} No;

typedef struct {
	No *topo;
} Pilha;

void inicializar(Pilha *p ){
	p->topo = NULL;
}

void exibirPilha(Pilha p ){
	No* no = p.topo;
	printf("\nTopo-->[");
	while(no != NULL){
		
		printf("%c",no->letra);
	
		if(no->prox != NULL){
			printf(",");

		}
		no= no->prox;
		
	}
	printf("]");
	
}


void empilhar(char letra, Pilha *p ){
	
	No* novoNo = (No*)malloc(sizeof(No));
   	novoNo->letra = letra;
   	novoNo->prox = p->topo;

   	p->topo = novoNo;
   
	
}

void empilharNaPilha(char frase [100], Pilha *p){
	int i;
	for(i = 0; i < strlen(frase); i++){
			empilhar(frase[i],p);
	}
	
}
char desempilhar(Pilha *p){
	
	No* no = p->topo;
	p->topo = p->topo->prox;
	no->prox = NULL;
	char letra = no->letra;
	
	free(no);
	
	return letra;
}

int verificarParente(Pilha p){
	int i; 
	int parEsq=0;
	int parDir=0;
	No* no = p.topo;
	
	while(no != NULL){
		
		if(no->letra == ')' ){
			parEsq++;
		} 
		if(no->letra == '('){
			parDir++;
		}
		no= no->prox;
		i++;
	}
	
	if(parEsq != parDir){
		return 0;
	}
	
	return 1;
	
}
void main(){
	Pilha p;
	inicializar(&p);	
	
	char frase[100];
	printf("\nInforme uma palavra : ");
	scanf("%s",frase);
	strupr(frase);
	empilharNaPilha(frase,&p);
	printf("\nPilha : "); 
	exibirPilha(p); 
	printf("\n\nFrase : %s",frase); 
	printf("\nTodos os parentes estao fechados ? %d",verificarParente(p));

}


