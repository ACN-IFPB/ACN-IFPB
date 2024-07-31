#include <stdio.h>
#include <stdlib.h>

#define TAMPILHA 10

//pilha ou stack

int pilha [TAMPILHA] = {0,0,0,0,0,0,0,0,0,0};
short int topo = 0;

//listar elementos da pilha
void listar () {
	short int i = 0;
	printf("\n===================PILHA ATUAL===========:\n");
	for ( ; i < TAMPILHA ; i++){
		printf ("-");
		printf ("|%d|", pilha [i]);
		printf("-");
	}
	printf ("Topo: %d", topo); //mostra o local do topo da pilha
	
	printf ("\n\n");
	
}

//função para remover elementos da pilha
void pop () {
	//o topo indica onde vai entrar o proximo elemento
	if (topo >=0){
		pilha [topo-1] =0;
		topo = topo -1;
		listar ();	
	}
	else {
		printf ("Pilha vazia...\n");
		}
}

//adiciona elemento na pilha

void push () {
	short int val;
	printf ("informe o valor: ");
	scanf ("%d ", &val);
	if (topo < TAMPILHA){
		pilha [topo] = val;
		topo = topo +1;
		listar ();
	}else{
		printf ("pilha Cheia...\n");
		}
}
//função pra limpar a pilha
void clear () {
	short int i = 0;
	for (; i < TAMPILHA; i++){
		pilha [i] = 0;
	}
	topo = 0;
}


int main (void){
	
	short int opcao = 0;
	
	do{
		printf ("Selecione a opcao: \n\n");
		printf ("[1] - Inserir (PUSH)\n");
		printf ("[2] - Retirar (POP)\n");
		printf ("[3] - Listar:\n");
		printf ("[4] - Limpar a pilha\n");
		printf ("[-1] - SAIR\n");
		scanf ("%d", &opcao);
		switch (opcao){
			case 1:
				push ();
				break;
			case 2:
				pop ();
				break;
			case 3:
				listar ();
				break;
			case 4:
				clear ();
				break;
			case -1:
				break;
			default:
				printf("opcao invalida!!\n\n");	
	}
					
	}while (opcao != -1);
	
	
	
	return 0;
}
