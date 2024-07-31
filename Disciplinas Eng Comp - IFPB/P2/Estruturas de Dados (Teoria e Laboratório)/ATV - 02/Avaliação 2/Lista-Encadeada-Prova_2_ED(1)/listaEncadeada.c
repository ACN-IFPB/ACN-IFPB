#include "listaEncadeada.h"

listaEncadeada aloca();

void criaLista( listaEncadeada *lista ){ *lista = NULL; }

int listaVazia( listaEncadeada lista ){ return lista == NULL; }

int tamanhoLista( listaEncadeada lista ){
	short int count = 0;
    while( lista != NULL ) {
    	lista = lista->prox;
        count++;
    }
    return count;
}
void Qtd_Ocorrencias( listaEncadeada lista, int elemento ){
    short int ocorrencias = 0;

    while ( lista != NULL ) {
   		if ( elemento == lista->dado ) {
         ocorrencias++;
       }
	    
    	lista = lista->prox;
    }

    if(ocorrencias == 0){
      printf("Zero Ocorrencias do elemento %d na lista !\n",elemento);
    }else{
      printf("%d Ocorrencias do Elemento %d na lista !\n",ocorrencias,elemento);
    }
}
int insereInicio( listaEncadeada* lista, int elemento ){
    listaEncadeada novo = NULL;
    int tam = tamanhoLista(*lista);
    if( listaVazia( *lista ) ) {
		// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = elemento;
        novo->prox = NULL;
        novo->ant = NULL;
        *lista = novo;
        return 1;
    }
   
    	// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = elemento;
        novo->prox = *lista; // faz novo nÃ³ "conectar-se" ao primeiro
        novo->ant = NULL;
        (*lista)->ant = novo;
        *lista = novo;
        return 1;
    
}
int insereFinal( listaEncadeada* lista, int elemento ){
	listaEncadeada novo = NULL, aux = NULL;
  int tam = tamanhoLista(*lista);
    int contador = 1;
    
    if( tam == 0 ){
        insereInicio(lista,elemento);
        return 1;
   	}

    
    aux = *lista;
    while( ( contador < tam ) && ( aux != NULL ) ) {
    	aux = aux->prox;
      contador++;
    }

    if( aux == NULL ) return 0;
    if( ( novo = aloca() ) == NULL ) return 0;
    novo->dado = elemento;
    novo->prox = aux->prox;
    novo->ant = aux;

    aux->prox = novo;
    return 1;
}
int removerInicio( listaEncadeada* lista, int *dado ){
	  
    listaEncadeada aux = NULL;
    if ( listaVazia( *lista ) ) return 0;
    aux = *lista;

    if ( aux == NULL ) return 0;
    *dado = aux->dado;
    *lista = aux->prox;
    if( aux->prox != NULL )	aux->prox->ant = NULL;
    
    free(aux);

    return 1;
}
int removerFim( listaEncadeada* lista, int *dado ){
	  listaEncadeada aux = NULL;
    
    int tam = tamanhoLista(*lista);
    int contador = 1;

    if ( listaVazia( *lista ) ) return 0;
    aux = *lista;

    while( ( contador <= tam -1 ) && ( aux != NULL ) ){
        aux = aux->prox;
        contador++;
    } 
    if ( aux == NULL ) return 0;
    *dado = aux->dado;
    if( tam == 1 ){
    	*lista = aux->prox;
        if( aux->prox != NULL )	aux->prox->ant = NULL;
    } else {
        if( aux->prox != NULL ) aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
    }
    free(aux);

    return 1;
}

listaEncadeada* merge(listaEncadeada* lista1, listaEncadeada* lista2){
  listaEncadeada *lista3 = malloc (sizeof (listaEncadeada)*tamanhoLista(*lista1));
  listaEncadeada aux1 = NULL,aux2 = NULL;
  int indice = 1;
  if( tamanhoLista(*lista1) != tamanhoLista(*lista2))return 0;
  aux1 = *lista1;
  aux2 = *lista2;
 
  while (indice <= tamanhoLista(*lista1)){
    insereFinal(lista3,aux1->dado);
    insereFinal(lista3,aux2->dado);
    aux1 = aux1 -> prox;
    aux2 = aux2 -> prox;
    indice++;
  }
  return lista3;
  free(lista3);
}
void exibe_lista ( listaEncadeada lista ){
	printf( "\nLista: ( ");

	for( ;!listaVazia( lista ); lista = lista->prox )
	    printf("%d ", lista->dado );

	printf( ")\n" );
}

listaEncadeada aloca(){ return (no*) malloc( sizeof( no ) ); }