#include "listaEncadeada.h"



int main(void) {
    listaEncadeada lista_1,lista_2;
    listaEncadeada *lista_3;
    int tirado = 0;
    //Iniciando a lista
    criaLista(&lista_1);
    criaLista(&lista_2);
   
    if( listaVazia( lista_1 ) ) printf( "Lista Iniciada vazia!\n" );

    //Criando Lista 1
    printf("_____________________________\n");
    //Adicionando No Inicio
    printf( "\n%s", insereInicio( &lista_1,5) ? 
                  "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", insereInicio( &lista_1,3) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", insereInicio( &lista_1,1) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    //Adicionando No Final
    printf( "\n%s", insereFinal( &lista_1,7) ?
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", insereFinal( &lista_1,9) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", insereFinal( &lista_1,11) ? 
	                "Sucesso na Inserção\n" : "Erro na Inserçao!\n" );
    

    //Criando lista 2 
    printf("_____________________________\n");
    //Adicionando No Inicio
    printf( "\n%s", insereInicio( &lista_2,6) ? 
                  "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", insereInicio( &lista_2,4) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", insereInicio( &lista_2,2) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
                 
    //Adicionando No Final
    printf( "\n%s", insereFinal( &lista_2,8) ?
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", insereFinal( &lista_2,10) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", insereFinal( &lista_2,12) ? 
	                "Sucesso na Inserção\n" : "Erro na Inserçao!\n" );
    printf("_____________________________\n");
    //Imprimindo Conteudo da lista
    printf("Lista 2: \n");
    exibe_lista(lista_1);
    printf("_____________________________\n");
    //Imprimindo Conteudo da lista
    printf("Lista 2: \n");
    exibe_lista(lista_2);


    printf("_____________________________\n");
    //Fazendo merge das duas listas
    lista_3 = merge(&lista_1,&lista_2);
    printf("Lista 1 e 2 Concatenadas: \n");
    //Verificando Quantidade de elementos
    printf( "\nQtd elementos na Lista Merge: %d\n", tamanhoLista( *lista_3 ) );
    exibe_lista(*lista_3); 
     printf("_____________________________\n");
   

    
    //Buscando Quantidade de ocorrencia do numero 2  
    Qtd_Ocorrencias(*lista_3,2);
    printf("_____________________________\n");
    //Buscando Quantidade de ocorrencia do numero 7  
    Qtd_Ocorrencias(*lista_3,7);
    printf("_____________________________\n");  

    //Removendo do Inicio
    removerInicio( lista_3, &tirado );
    printf( "\n%d é o primeiro elemento da lista e foi removido !", tirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( *lista_3 ) );
    exibe_lista( *lista_3 );

    printf("_____________________________");

    //Removendo do Final 
	removerFim( lista_3, &tirado );
    printf( "\n%d é o ultimo elemento da lista e foi removido !", tirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( *lista_3 ) );

    //Imprimindo a lista
    exibe_lista(*lista_3);

    free(lista_3);
   
  return 0;
}