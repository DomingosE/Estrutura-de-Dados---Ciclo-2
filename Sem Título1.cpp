#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAXTAM 500

typedef struct {
	int Item[MAXTAM];
	int Topo;
	
} TopoPilha;

void TopoPilha_Inicia (TopoPilha *p){
	p->Topo = -1;
}

int TopoPilha_Vazia (TopoPilha *p){
	if (p->Topo == -1){
		return 1;
	} else{
		return 0;
	}
}

int TopoPilha_Cheia (TopoPilha *p){
	if (p->Topo == MAXTAM-1){
		return 1;
	} else {
		return 0;
	}
}

void TopoPilha_Insere (TopoPilha *p, int x){
	if (TopoPilha_Cheia(p) == 1 ){
		setlocale(LC_ALL,"");
		printf ("\nERRO: A Pilha está cheia");
	} else {
		p->Topo++;
		p->Item[p->Topo] = x;
	}
}

int TopoPilha_Remove (TopoPilha *p){
	int aux;
	if (TopoPilha_Vazia(p) == 1){
		setlocale(LC_ALL,"");
		printf("\nERRO: A pilha está vazia");
	} else {
		aux = p->Item[p->Topo];
		p->Topo--;
		return aux;
	}
}

int main(){
		TopoPilha *p = (TopoPilha*)malloc(sizeof(TopoPilha));
		TopoPilha_Inicia(p);
		
		TopoPilha_Insere(p, 1);
		TopoPilha_Insere(p, 2);
		TopoPilha_Insere(p, 3);
		
		int aux;
		
		aux = TopoPilha_Remove(p);
		printf("\nSAIU DA PILHA O VALOR: %d", aux);
		aux = TopoPilha_Remove(p);
		printf("\nSAIU DA PILHA O VALOR: %d", aux);
		aux = TopoPilha_Remove(p);
		printf("\nSAIU DA PILHA O VALOR: %d", aux);
		aux = TopoPilha_Remove(p);
		printf("\nSAIU DA PILHA O VALOR: %d", aux);
		
		return 0;
}		

