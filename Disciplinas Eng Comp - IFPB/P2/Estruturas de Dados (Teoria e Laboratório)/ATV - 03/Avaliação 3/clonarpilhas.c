#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct no {
    int qnt;
    int dados[];
} no;

no* cria() {
    int qnt=0;
    int dados=0;
    no *L = (no *) malloc(sizeof(no));
    if (L != NULL) {
        L->qnt = 0;
    }
    return L;
}

struct clone {
            int qnt;
            int dados[];
}clone;

struct Pilha {

    int qnt;
    float *dados;

};

struct PilhaClone {

    int qnt;
    float *dados;

}PilhaClone;

void criarpilha( struct Pilha *p){

    p->qnt = 0;
    p->dados = (float*) malloc (sizeof(float));

}



void criarpilhaclone( struct PilhaClone *p){

    p->qnt = 0;
    p->dados = (float*) malloc (sizeof(float));

}

void insere(no *L, int valor) {

    L->dados[L->qnt] = valor;
    L->qnt++;

}

void exibe(no *L) {
	short int i;
    for ( i = 0; i < L->qnt; i++)
        printf("%3d\n", L->dados[i]);
}

void exibeClone(no *L) {
    for (clone.qnt= 0; clone.qnt < L->qnt; clone.qnt++)
        printf("%i\n", clone.dados[clone.qnt]);
}

no* inverteLista(struct no *L) {
    no *outra = cria();
    while (L->qnt > 0) {
        outra->dados[outra->qnt] = L->dados[L->qnt - 1];
        L->qnt--;
        outra->qnt++;
    }
    return outra;
}

void clonaValorLista(struct no *L) {
        for (clone.qnt=0; clone.qnt<L->qnt; clone.qnt++){
            clone.dados[clone.qnt] = L->dados[clone.qnt];
            printf("%i\n",clone.dados[clone.qnt]);
        }
}

void push ( struct Pilha *p, float v){

    p->qnt++;
    p->dados[p->qnt] = v;

}


void pushclone ( struct PilhaClone *p, float v){

    p->qnt++;
    p->dados[p->qnt] = v;

}

void imprimePilhaPrincipal (struct Pilha *p){

    int aux = p->qnt;
       printf("teste %i\n",p->qnt);

}

float retornaqnt ( struct Pilha *p ){
    return p->dados [p->qnt];
}

void clonaValorPilha(struct no **Pilha){
    int PilhaClone;
    int valorPilha;
    int x;
    (**Pilha).qnt=0;
    /*for (x; x<Pilha.qnt; x++){
        valorPilha = retornaqnt(&Pilha);
        printf ( "%.1i\n", valorPilha );

    }*/
    /*for (PilhaClone.qnt=0; PilhaClone.qnt<Pilha->qnt; PilhaClone.qnt++){
        //valorPilha = retornaqnt(&Pilha);
        //PilhaClone.dados[PilhaClone.qnt] = Pilha->dados[PilhaClone.qnt];
        //printf("%i\n",PilhaClone.dados[PilhaClone.qnt]);
    }*/

   /*
    int x=0;
    for (x=0; x < Pilha->qnt; x++){
        PilhaClone.dados[x] = Pilha.dados[x];
        printf("%i\n",PilhaClone.dados[x]);
    }
    */
}


int desempilhar ( struct Pilha *p ){

    int aux = p->dados [p->qnt];
    p->qnt--;
    return aux;

}




int main() {
    setlocale(LC_ALL, "Portuguese");
    int valor,op,valorPilha;
    bool listaClonada = false;
    no *L = cria();
    no *clone = cria();
    struct Pilha minhapilha;
    struct PilhaClone minhapilhaclone;
    criarpilha (&minhapilha);
    criarpilhaclone(&minhapilhaclone);

    while( 1 ){
        printf("\n1- Informar Valores Da Lista Principal \n");
        printf("2- Função clonaValorLista (Clona lista Principal)\n");
        printf("3- Exibe lista clonada\n");
        printf("4- Exibe lista principal \n");
        printf("5- Função inverteLista (Inverte a lista Original)\n");
        printf("6- Inserir Valor No Topo Da Pilha Principal\n");
        printf("7- Imprimir Pilha Principal\n");
        printf("8- Função clonaValorPilha\n");
        printf("10- sair\n");

        printf("\nSelecione A Opção: ");
        scanf("%i", &op);
        fflush(stdin);


        switch (op){

            case 1:
                printf("Informe o valor:");
                scanf("%i", &valor);
                insere(L, valor);
                break;

                case 2:
                    printf("Lista Clonada\n");
                    clonaValorLista(L);
                    listaClonada = true;

                break;

                case 3:
                if (listaClonada == false){
                    printf("\nLista ainda não clonada\n");
                }
                else {
                    printf("\nValores Clonados\n");
                    exibeClone(L);
                }
                break;

            case 4:
                printf("\nValores\n");
                exibe(L);
                break;

            case 5:
                printf("\nValores Originais:\n");
                exibe(L);
                L = inverteLista(L);
                printf("\nValores Invertidos:\n");
                exibe(L);
                break;

            case 6:
                printf("\nInsira o valor para adicionar ao qnt da pilha princpal: ");
                scanf("%i",&valorPilha);
                push (&minhapilha, valorPilha);
                break;

			case 7:
                if( minhapilha.qnt == 0 ){
                    printf("\nA pilha principal ainda está vazia\n");
                }
                else{
                    printf("\nPilha Principal\n");
                    int aux=minhapilha.qnt;
                    for (minhapilha.qnt; minhapilha.qnt>0; minhapilha.qnt--){
                        valorPilha = retornaqnt(&minhapilha);
                        printf ( "%.1i\n", valorPilha );
                    }
                    minhapilha.qnt=aux;
                }
                break;
            case 8:
                //clonaValorPilha(&minhapilha);
                if( minhapilha.qnt == 0 ){
                    printf("\nA pilha principal ainda está vazia\n");
                }
                else{
                    printf("\nPilha Clonada\n");
                    int aux=minhapilha.qnt;
                    int x= minhapilha.qnt;
                    for (x; x>0; x--){
                        valorPilha = minhapilha.dados[x];
                        pushclone(&minhapilhaclone,valorPilha);
                        printf ( "%.1i\n", valorPilha );
                    }
                    minhapilhaclone.qnt=aux;
                }
                break;

            case 10:
                exit(0);
        }

    }

}
