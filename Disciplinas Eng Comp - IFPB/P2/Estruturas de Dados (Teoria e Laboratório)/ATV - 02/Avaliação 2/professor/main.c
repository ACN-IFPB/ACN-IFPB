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

//###########################################################
//Linhas de codigos com devidas modificacoes


#include "listadupenc.h"
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include <stddef.h>

int main(void) {
    TListaDupEnc lista_1,lista_2;
    TListaDupEnc *lista_3;
    
	int retirado = 0;
    
	//Iniciando a lista
    criarLista(&lista_1);
    criarLista(&lista_2);

/**********************

//MENU PARA ESCOLHER AS FUNCOES DE CADA LISTA

int op1, op2;

	do {
		op1=menu1();
		opcao(TListaDupEnc, op1);
	}while(opt);

***********************/
   
   
   
    if( listaVazia( lista_1 ) ){
		printf ( "Lista Iniciada vazia!\n" );
	}
	
	//Criando Lista 1
    printf("*****************************\n");
    //Adicionando No Inicio da lista_1
    printf( "\n%s", insereInicio( &lista_1,12));
    printf( "\n%s", insereInicio( &lista_1,10) );
    printf( "\n%s", insereInicio( &lista_1,29));
    //Adicionando itens no final da lista_1 No Final
    printf( "\n%s", insereFinal( &lista_1,35) );
    printf( "\n%s", insereFinal( &lista_1,27) );
    printf( "\n%s", insereFinal( &lista_1,44)  );
    

    //Criando lista 2 
    printf("############################\n");
    //Adicionando No Inicio
    printf( "\n%s", insereInicio( &lista_2,88) );
    printf( "\n%s", insereInicio( &lista_2,666 ));
    printf( "\n%s", insereInicio( &lista_2,200) );
                 
    //Adicionando No Final
    printf( "\n%s", insereFinal( &lista_2,33) );
    printf( "\n%s", insereFinal( &lista_2,24) );
    printf( "\n%s", insereFinal( &lista_2,99) );
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    
	//Imprimindo Conteudo da lista
    printf("Lista 1: \n");
    imprimir(lista_1);
    printf("*****************************\n");
    
	//Imprimindo Conteudo da lista
    printf("Lista 2: \n");
    imprimir(lista_2);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    //Fazendo merge das duas listas
    lista_3 = merge(&lista_1,&lista_2);
    printf("Lista 1 e 2 Concatenadas: \n");
    //Verificando Quantidade de elementos
    printf( "\nQtd elementos na Lista Merge: %d\n", tamanhoLista( *lista_3 ) );
    imprimir(*lista_3); 
    printf("___________________________\n");
   

    
    //Buscando Quantidade de ocorrencia do numero 2  
    NumeroDeOcorrencia(*lista_3,2);
    printf("#############################\n");
    //Buscando Quantidade de ocorrencia do numero 7  
    NumeroDeOcorrencia(*lista_3,7);
    printf("++++++++++++++++++++++++++++++\n");  

    //Removendo do Inicio
    removerInicio( lista_3, &retirado );
    printf( "\n%d é o primeiro elemento da lista e foi removido !", retirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( *lista_3 ) );
    imprimir( *lista_3 );

    printf("===========================\n");

    //Removendo do Final 
	removerFinal( lista_3, &retirado );
    printf( "\n%d é o ultimo elemento da lista e foi removido !", retirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( *lista_3 ) );

    //Imprimindo a lista
    imprimir(*lista_3);

    free(lista_3);
   
  return 0;
}

//Fim das modificacoes
//############################################################


	
