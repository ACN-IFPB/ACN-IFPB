/*****************************************************************************
 * Instituto Federal de Educação Ciência e Tecnologia da Paraíba			 
 * Campus Campina Grande													 
 * Curso Superior em Engenharia da Computação								 
 * Professor: Cesar Vasconcelos												 
 * 																			 
 * Copyright - Cesar Vasconcelos											 
 * Este marerial foi elaborado apenas para ser utilizado pelos alunos da 	 
 * disciplina Estruturas de Dados, do curso de Eng. da Computação do IFPB.	 
 * 																			 
 * Nenhuma parte deste material pode ser reproduzida ou transmitida			 
 * de qualquer modo ou por qualquer meio sem prévia autorização do 			 
 * autor e sem lhe ser dado o devido crédito.								 
 * **************************************************************************/
/*##############################################################


			Aluno: Adriel Cassimiro do Nascimento
			Avaliacao III

######################################################################### */


#include "pilhaenc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stddef.h>

/* Criar uma pilha vazia */
void criarPilha( TPilhaEnc *pilha )
{
	*pilha = NULL;
}

/* Verificar se a pilha está vazia ou não */
int pilhaVazia( TPilhaEnc pilha )
{
	return pilha == NULL;
}

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha )
{
	int tamanho = 0;
	while( pilha != NULL ) {
		pilha = pilha->prox;
		tamanho++;
	}
	return tamanho;
}

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, int dado )
{
	TPilhaEnc novo;

	// aloca o no e testa pra ver se o SO alocou mesmo
	if( (novo = (no*) malloc(sizeof(no))) == NULL ) return 0;

	novo->dado = dado;
	novo->prox = *pilha;
	*pilha = novo;
	return 1;
}

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, int *dado )
{
	// se pilha está vazia
   	if ( pilhaVazia( *pilha ) ) return 0;

	TPilhaEnc aux;

	aux = *pilha;
	*dado = aux->dado;
	*pilha = (*pilha)->prox;
	
	// libera memória do nó desempilhado
	free( aux );

    return 1;
}


/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, int *dado )
{
	if( pilhaVazia( pilha ) ) return 0;

	*dado = pilha->dado; // já que topo é igual ao primeiro no
	return 1;
}

/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha )
{
	// se pilha está vazia
   	if ( pilhaVazia( pilha ) ) return 0;

    printf("\n Pilha=[ ");

	// varrendo todos os elementos
	while( !pilhaVazia(pilha) ){
		printf("%d ", pilha->dado);
		pilha = pilha->prox;
	}

    printf("]");
     return 1;
}
//FUNCAO DA AVALIACAO 3

int clonar (TPilhaEnc *origem, TPilhaEnc *destino){
	TPilhaEnc tmp;
	tmp = *origem;
	
	// aloca o no e testa pra ver se o SO alocou mesmo
	if( (destino = (no*) malloc(sizeof(no))) == NULL ) return 0;

	// se pilha destino esta vazia
   	if ( pilhaVazia( *destino ) ) return 0;

	if (tmp == NULL) 
		return 0;
	while (tmp != NULL){
		if (origem != NULL){
			empilhar (destino, tmp->dado);
		} //tecnicamente nem precisava dessas {} mas vai que d� erro ...
	}

			/* ESSA PARTE N�O FUNCIONOU, DESCONSIDERAR
			    printf("\n Pilha destino= ");
			
				// preenchendo todos os elementos
				while( !pilhaVazia(pilha) ){
					pilha = pilha->prox;
					destino->dado = dado;
					destino->prox = *pilha;
					*pilha = destino;
				}
			*/
	return 1;
	free (tmp);
}

//================================================================
//===  ADRIEL'S NOTES
//=== "May God have mercy on this nation." - Eduardo Cunha
//================================================================

int main(){
	
	TPilhaEnc origem, destino;
	
	//criar as duas pilhas
	criarPilha (&origem);
	criarPilha (&destino);
	
	//garantir que a segunda pilha vai ser limpa
	
	if (pilhaVazia (destino)){
		printf ("Pilha destino vazia!\n");
	}
	//inserir dados na pilha origem

	
	empilhar( TPilhaEnc *origem, 5 );
	empilhar( TPilhaEnc *origem, 4 );
	empilhar( TPilhaEnc *origem, 3 );
	empilhar( TPilhaEnc *origem, 2 );
	empilhar( TPilhaEnc *origem, 1 );
	
	//imprimir pilha origem
	
	imprimir ( TPilhaEnc *origem);
	
	//clonar pilha origem em pilha destino
	
	clonar (TPilhaEnc *origem, TPilhaEnc *destino);
	
	//imprimir pilha destino
	
	imprimir (TPilhaEnc *destino);
	
	return 0;
}

					/* DESCONSIDERAR
					//	int TPilhaEnc [5] = {0,0,0,0,0};
					//	int *pilha = NULL;
						int opt = 0;
						criarPilha(  );
						
						do{
							printf("Selecione a op��o: \n\n");
							printf("[1] - Inserir (push):\n");
							printf("[2] - Remover (pop):\n");
							printf("[3] - Listar: \n");
							printf("[4] - Limpar a pilha: \n");
							printf("[-1] - Sair.\n");
							printf("Op��o: ");
							scanf("%d", &opt);
					
							switch(opt){	
								case 1:
									empilhar(TPilhaEnc *pilha );
									break;
								case 2:
									desempilhar(TPilhaEnc *pilha );
									break;
								case 3:
									imprimir(TPilhaEnc *pilha );
									break;
								case 4:
									clear();
									break; 
								case -1:
									break;
								default:
									printf("Op��o inv�lida.");
							}
					
						}while(opcao != -1);
					*/

