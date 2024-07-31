/*****************************************************************************
 * Instituto Federal de Educacao Ciência e Tecnologia da Paraíba			 
 * Campus Campina Grande													 
 * Curso Superior em Engenharia da Computacao								 
 * Professor: Cesar Vasconcelos												 
 * 																			 
 * Copyright - Cesar Vasconcelos											 
 * Este marerial foi elaborado apenas para ser utilizado pelos alunos da 	 
 * disciplina Estruturas de Dados, do curso de Eng. da Computacao do IFPB.	 
 * 																			 
 * Nenhuma parte deste material pode ser reproduzida ou transmitida			 
 * de qualquer modo ou por qualquer meio sem prévia autorizacao do 			 
 * autor e sem lhe ser dado o devido crédito.								 
 * **************************************************************************/
/*##############################################################


			Aluno: Adriel Cassimiro do Nascimento
			Avaliacao II

######################################################################### */

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include <stddef.h>

//*************** Implementacao da área de dados do TAD ***************//

// definicao da estrutura lista duplamente encadeada
typedef struct nolista {
	int dado;  			   // campo que guarda a informacao
    struct nolista *prox;  // guarda o endereco para prox noh
    struct nolista *ant;   // guarda o endereco para noh anterior
}no;

typedef no* TListaDupEnc;

//************ A interface de uso do TAD Lista Dup. Encadeada *********//

/* Procedimento para criar uma lista vazia */
void criarLista( TListaDupEnc *lista );

/* Funcao para verificar se a lista está vazia ou noh */
int listaVazia( TListaDupEnc lista );

/* Funcao para verificar a quantidade de elementos na lista */
int tamanhoLista( TListaDupEnc lista );

/* Funcao para buscar um elemento mediante sua posicao dentro da lista */
int elementoNaPosicao( TListaDupEnc lista, int posicao, int* dado );

/* Funcao para buscar a posicao de um elemento na lista */
int posicaoDoElemento( TListaDupEnc lista, int dado );

/* Funcao para inserir um elemento na lista mediante sua posicao */
int inserirElemento( TListaDupEnc* lista, int posicao, int dado );

/* Funcao para remover um elemento da lista mediante sua posicao */
int removerElemento( TListaDupEnc* lista, int posicao, int *dado );

/* Procedimento para exibir todos os elementos da lista */
void imprimir ( TListaDupEnc lista );


//###########################################################
//Linhas de códigos com devidas modificacoes

void NumeroDeOcorrencia( TListaDupEnc lista, int dado );

int insereInicio( TListaDupEnc* lista, int dado );
int insereFinal( TListaDupEnc* lista, int dado );

int removerInicio( TListaDupEnc* lista, int *dado );
int removerFinal( TListaDupEnc* lista, int *dado );


//Fim das modificacoes
//############################################################



//**********************************

//----------------------------------------------------------------------

// funcoes auxiliares que apenas fatoram código comum as sub-rotinas...
TListaDupEnc aloca();

//----------------------------------------------------------------------

//*************** Implementacao do TAD Lista Dup. Encadeada ***********//


/* Criar uma lista duplamente encadeada vazia
 * Parâmetros: o ponteiro que representa "a cabeça" da lista 
 * (por referência)
 */
void criarLista( TListaDupEnc *lista ){ *lista = NULL; }


/* Verificar se a lista está (ou não) vazia
 * Parâmetros: o ponteiro que representa "a cabeça" da lista (por valor)
 */
int listaVazia( TListaDupEnc lista ){ return lista == NULL; }


/* Verificar a quantidade de elementos na lista
 * Parâmetros: o ponteiro que representa a cabeça da lista (por valor)
 */
int tamanhoLista( TListaDupEnc lista ){
	int tamanho = 0;
	while( lista != NULL ) {
    	lista = lista->prox;
        tamanho++;
    }
    return tamanho;
}

/*  Buscar um elemento mediante sua posicao na lista
 *  Parâmetros: lista = a lista dup. encadeada
 *              posicao = posicao na qual se deseja buscar o elemento
 *              dado = passagem por referência "retornando" o elem. desejado
 *  Retorno: 1 em caso de sucesso ou 0, no caso de posicao inválida
 */
int elementoNaPosicao( TListaDupEnc lista, int posicao, int* dado ){
	int posicaoAtual = 1;
	
    // se lista está vazia ou posicao inválida
    if ( listaVazia( lista ) || posicao <= 0 
              || posicao > tamanhoLista( lista ) ) return 0;
    
    while ( ( lista != NULL ) && ( posicaoAtual < posicao ) ){
    	lista = lista->prox;
        posicaoAtual++;
    }
    *dado = lista->dado;
    return 1;
}

/* Obter a posicao de um elemento na lista dup. encadeada
 * Parâmetros: lista = a lista dup. encadeada
 *             elemento = o dado a ser pesquisado na lista
 * Retorno: a posicao do elemento em caso de sucesso ou 0 caso contrário
 */
int posicaoDoElemento( TListaDupEnc lista, int dado ){
    int posicao = 1;

    while ( lista != NULL ) {
    	// testar se o dado � igual ao campo de informacao do noh...
    	if ( dado == lista->dado )	return posicao;
    	
    	lista = lista->prox;
    	posicao++;
    }
    return 0;
}

/* Inserir um elemento na lista mediante uma posicao
 * Parâmetros: lista = a lista dup. encadeada
 *             elemento = o dado a ser inserido
 *             posicao = posicao na qual se deseja inserir o elemento
 * Retorno: 1 em caso de sucesso ou 0, caso contrário
 */
int inserirElemento( TListaDupEnc* lista, int posicao, int dado ){
	TListaDupEnc novo = NULL, aux = NULL;
    int contador = 1;
    
    // insercao em uma lista que está vazia
    if( listaVazia( *lista ) ) {
    	// se a lista está vazia, só é possível inserir na posicao 1
        if( posicao != 1 ) return 0;
		// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = dado;
        novo->prox = NULL;
        novo->ant = NULL;
        *lista = novo;
        return 1;
    }

	// insercao na primeira posicao em uma lista não vazia
    if( posicao == 1 ){
    	// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = dado;
        novo->prox = *lista; // faz novo noh "conectar-se" ao primeiro
        novo->ant = NULL;
        (*lista)->ant = novo;
        *lista = novo;
        return 1;
    }

    // insercao após a primeira posicao e em uma lista não vazia
    aux = *lista;

	// uma estratégia é fazer aux parar uma posicao "antes" da real posicao
	while( ( contador < posicao -1 ) && ( aux != NULL ) ) {
    	aux = aux->prox;
        contador++;
    }

    // só por garantia, vou testar se posicao 
	// foi maior que o esperado (é inválida)
    if( aux == NULL ) return 0;

    // alocar o novo noh
    if( ( novo = aloca() ) == NULL ) return 0;

    novo->dado = dado;
    novo->prox = aux->prox;
    novo->ant = aux;

    // cenário de insercao entre dois elementos existentes
    if( aux->prox != NULL ) aux->prox->ant = novo;

    aux->prox = novo;
    return 1;
}

/* Remover um elemento da lista mediante sua posicao
 * Parâmetros: lista = a lista dup. encadeada
 * 			   dado = passagem por referência "retornando" o elem. removido
 *             posicao = posicao na qual se deseja remover o elemento
 * Retorno: 1 em caso de sucesso ou 0, caso contrário
 */
int removerElemento( TListaDupEnc* lista, int posicao, int *dado ){
	TListaDupEnc aux = NULL;
    int contador = 1;

    if ( listaVazia( *lista ) ) return 0;

    // faz aux apontar para o primeiro elemento
    aux = *lista;

    // aux deve "parar" sobre o noh a ser removido
    while( ( contador < posicao ) && ( aux != NULL ) ){
    	aux = aux->prox;
        contador++;
    }
    // se a posicao foi maior que o esperado
    if ( aux == NULL ) return 0;

 	// guardar o dado antes de "apagar" o noh da memoria
    *dado = aux->dado;

    // primeiro noh da lista?
    if( posicao == 1 ){
    	*lista = aux->prox;
        // deve-se testar se há mais de um elemento na lista
        if( aux->prox != NULL )	aux->prox->ant = NULL;
    } else {
    	// se não é o último noh...
        if( aux->prox != NULL ) aux->prox->ant = aux->ant;

        aux->ant->prox = aux->prox;
    }
    // remover, aqui, implica em desalocar memoria
    free( aux );
    return 1;
}

//##########################################################
//INICIO DAS MODIFICACOES ADRIEL CASSIMIRO

void NumeroDeOcorrencia( TListaDupEnc lista, int elemento ){
    int ocorrencias = 0;

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
int insereInicio( TListaDupEnc* lista, int dado ){
    TListaDupEnc novo = NULL;
    int tam = tamanhoLista(*lista);
    if( listaVazia( *lista ) ) {
		// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = dado;
        novo->prox = NULL;
        novo->ant = NULL;
        *lista = novo;
        return 1;
    }
   
    	// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = dado;
        novo->prox = *lista; // faz novo nÃ³ "conectar-se" ao primeiro
        novo->ant = NULL;
        (*lista)->ant = novo;
        *lista = novo;
        return 1;
    
}
int insereFinal( TListaDupEnc* lista, int dado ){
	TListaDupEnc novo = NULL, aux = NULL;
  int tam = tamanhoLista(*lista);
    int contador = 1;
    
    if( tam == 0 ){
        insereInicio(lista,dado);
        return 1;
   	}

    
    aux = *lista;
    while( ( contador < tam ) && ( aux != NULL ) ) {
    	aux = aux->prox;
      contador++;
    }

    if( aux == NULL ) return 0;
    if( ( novo = aloca() ) == NULL ) return 0;
    novo->dado = dado;
    novo->prox = aux->prox;
    novo->ant = aux;

    aux->prox = novo;
    return 1;
}
int removerInicio( TListaDupEnc* lista, int *dado ){
	  
    TListaDupEnc aux = NULL;
    if ( listaVazia( *lista ) ) return 0;
    aux = *lista;

    if ( aux == NULL ) return 0;
    *dado = aux->dado;
    *lista = aux->prox;
    if( aux->prox != NULL )	aux->prox->ant = NULL;
    
    free(aux);

    return 1;
}
int removerFinal( TListaDupEnc* lista, int *dado ){
	  TListaDupEnc aux = NULL;
    
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

TListaDupEnc* merge(TListaDupEnc* lista1, TListaDupEnc* lista2){
  TListaDupEnc *lista3 = malloc (sizeof (TListaDupEnc)*tamanhoLista(*lista1));
  TListaDupEnc aux1 = NULL,aux2 = NULL;
  int posicao = 1;
  if( tamanhoLista(*lista1) != tamanhoLista(*lista2))return 0;
  aux1 = *lista1;
  aux2 = *lista2;
 
  while (posicao <= tamanhoLista(*lista1)){
    insereFinal(lista3,aux1->dado);
    insereFinal(lista3,aux2->dado);
    aux1 = aux1 -> prox;
    aux2 = aux2 -> prox;
    posicao++;
  }
  return lista3;
  free(lista3);
}

//adicionando menus para melhor visualizacao
/*

void sair (no *TListaDupEnc){
	if(!vazia(TListaDupEnc)){
		no *proxNo, *atual;
		atual = TListaDupEnc->prox;
		while(atual != NULL){
			proxNo = atual->prox;
			free(atual);
			atual = proxNo;
		}
	}
}

void opcao (no *TListaDupEnc, short int op){
	switch(op){
		case 0:
			sair (TListaDupEnc);
			break;
		case 1:
			imprimir (TListaDupEnc);
			break;
		case 2:
			insereInicio (TListaDupEnc);
			break;
		case 3:
			insereFinal (TListaDupEnc);
			break;
		case 4:
			inicia(TListaDupEnc);
			break;
		case 5:
			removerInicio(TListaDupEnc);
			break;
		case 6:
			removerFinal(TListaDupEnc);
			break;
		default:
			printf("Comando invalido\n\n");

	}
}

int menu(void){
	short int opt;

	printf("Escolha a opcao: \n");
	printf("[0] - Sair: \n");
	printf("[1] - Exibir: \n");
	printf("[2] - Adicionar noh no inicio: \n");
	printf("[3] - Adicionar noh no fim: \n");
	printf("[4] - Remove noh no inicio da lista: \n");
	printf("[5] - Remove noh no final da lista: \n");
	printf("[6] - Zerar lista: \n");
	
	printf("Opcao: ");
	scanf("%d", &opt);

	return opt;
}
*/


//FINAL DAS MODIFICACOES ADRIEL CASSIMIRO
//########################################




/* Exibir todos os elementos da lista
 * Parâmetros: lista = a lista encadeada
 */
void imprimir ( TListaDupEnc lista ){
	printf( "\nLista: ( ");

	for( ;!listaVazia( lista ); lista = lista->prox )
	    printf("%d ", lista->dado );

	printf( ")" );
}


// alocar um novo noh na memoria do computador
// funcao utilitária usada para fatorar código comum
TListaDupEnc aloca(){ return (no*) malloc( sizeof( no ) ); }

//**********************************
