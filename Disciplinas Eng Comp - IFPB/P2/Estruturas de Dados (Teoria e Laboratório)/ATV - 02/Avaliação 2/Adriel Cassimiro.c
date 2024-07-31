#include <stdio.h>
#include <stdlib.h>

// Lista Encadeada


//struct nó. Um nó é o nome de cada elemento da list
struct st_no{
	int valor;
	struct st_no *prox;
};

typedef struct st_no no;


//Verifica se a lista está vazia
int vazia(no *le){
	if(le->prox == NULL){
		return 1;
	}else{
		return 0;
	}
}

//inicia a lista
void inicia(no *le){
	le->prox = NULL;
}

void libera(no *le){
	if(!vazia(le)){
		no *proxNo, *atual;
		atual = le->prox;
		while(atual != NULL){
			proxNo = atual->prox;
			free(atual);
			atual = proxNo;
		}
	}
}

//imprime a lista
void exibe(no *le){
	if(vazia(le)){
		printf("Lista esta vazia!\n\n");
		return;
	}
	no *tmp;
	tmp = le->prox;

	while(tmp != NULL){
		printf("%d ", tmp->valor);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

//insere nó no inicio
void insereInicio(no *le){
	no *novo = (no*)malloc(sizeof(no));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Informe o valor: ");
	scanf("%d", &novo->valor);

	no *oldHead = le->prox;

	le->prox = novo;
	novo->prox = oldHead;
}

//insere nó no final
void insereFim(no *le){
	no *novo = (no*)malloc(sizeof(no));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Informe o valor: ");
	scanf("%d", &novo->valor);
	novo->prox = NULL;

	if(vazia(le)){
		le->prox = novo;
	}else{
		no *tmp = le->prox;

		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}
}

void opcao(no *le, int op){
	switch(op){
		case 0:
			libera(le);
			break;
		case 1:
			exibe(le);
			break;
		case 2:
			insereInicio(le);
			break;
		case 3:
			insereFim(le);
			break;
		case 4:
			inicia(le);
			break;
		case 5:
			removeInicio(le);
			break;
		case 6:
			removeFinal(le);
			break;
		default:
			printf("Comando invalido\n\n");

	}
}

int menu(){
	int opt;

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

///***************************
int removeInicio( no *le ){
	  
    le aux = NULL;
    if ( listaVazia( *lista) ) return 0;
    
	aux = *lista;

    if (aux == NULL) return 0;
    *dado = aux->dado;
    *lista = aux->prox;
    
	if( aux->prox != NULL )	aux->prox->ant = NULL;
    
    free(aux);

    return 1;
}
int removeFinal ( le* lista, int *dado ){
	le aux = NULL;
    
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


///****************************



int main(){
	no *le = (no*)malloc(sizeof(no));

	if(!le){
		printf("Sem memoria disponivel: ");
		exit(1);
	}
	inicia(le);
	int opt;

	do{
		opt=menu();
		opcao(le, opt);
	}while(opt);
	free(le);
	return 0;
}
