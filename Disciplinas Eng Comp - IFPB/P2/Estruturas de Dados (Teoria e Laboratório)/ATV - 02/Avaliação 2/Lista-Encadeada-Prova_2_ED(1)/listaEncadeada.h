#include <stdio.h>
#include <stdlib.h>


typedef struct nolista {
	int dado;  			   // valor
    struct nolista *prox;  // Aponta para o proximo
    struct nolista *ant;   // Aponta para o anterior 
}no;


typedef no* listaEncadeada; 

void criaLista( listaEncadeada *lista );

int listaVazia( listaEncadeada lista );

int tamanhoLista( listaEncadeada lista );

void Qtd_Ocorrencias( listaEncadeada lista, int dado );

int insereInicio( listaEncadeada* lista, int elemento );
int insereFinal( listaEncadeada* lista, int elemento );

int removerInicio( listaEncadeada* lista, int *dado );
int removerFim( listaEncadeada* lista, int *dado );

listaEncadeada* merge(listaEncadeada* lista1, listaEncadeada* lista2);

void exibe_lista ( listaEncadeada lista ); 