/********************************************************************
			INSTITUTO FEDERAL DA PARAÍBA
			CAMPUS DE CAMPINA GRANDE
			ENGENHARIA DA COMPUTAÇÃO
			PROFESSOR: CESAR ROCHA VASCONCELOS
			ALUNO: ADRIEL CASSIMIRO DO NASCIMENTO
			MATRÍCULA: 202021250005
********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h> // PARA USAR AS FUNÇÕES RAIZ QUADRADA E POTENCIA


// STRUCT PARA ARMAZENAMENTO DAS COORDENADAS X E Y DO PONTO, QUE TAMBÉM VAI SER USADO NO CENTRO
typedef struct {
    float x;   
    float y;    
} Ponto;

//STRUCT PARA ARMAZENAR OS VALORES DO CIRCULO
typedef struct {
    char *nome;   
    Ponto Centro; //struct Ponto RECEBE OS DADOS X E Y DO Centro
    float raio; //     
} Circulo;


Circulo *criaCirculo(char *nome,float x,float y, float Centro ){
 
    Circulo  *circulo  = (Circulo*) malloc(sizeof(Circulo));;
	circulo->nome = nome;
	circulo->Centro.x = x;
	circulo->Centro.y = y;
	circulo->raio = Centro;
	  
	return circulo;
}

int contem(Circulo *c1, Circulo *c2){
    float d = sqrt( pow(c2->Centro.x - c1->Centro.x,2) + pow(c2->Centro.y - c1->Centro.y,2)  );
  
    if( d + c2->raio <= c1->raio){
        return 1;
  } 
  
  return 0;
}

// FUNÇÃO DO EXERCÍCIO
int main(void) {
    Circulo *c1,*c2,*c3;
  
    c1 = criaCirculo("Circulo01",3.0,4.0,2.0);
    c2 = criaCirculo("Circulo02",3,3,1);
    c3 = criaCirculo("Circulo03",1,5,1);

    printf("%d\n", contem( c1,  c2));
    printf("%d\n", contem(c1, c3));
  
    free(c1);
    free(c2);
    free(c3);

    return 0;
}
