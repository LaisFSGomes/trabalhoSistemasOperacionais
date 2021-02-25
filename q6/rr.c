#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

typedef struct{
	int id;
	int tempo;
	int ciclos;
	double cada;
} processo;

int main(){
	int qtd; //quantidade de processos na fila de execu��o
	int i, j, m = 0;	//vari�veis auxiliares
	int quantum = 2; //eu quero q o quantum dure 2 segundos
	int fim = 0; //indica quando todos forem executados
	double help;
	printf("quantos processos estao na fila: ");
	scanf("%d", &qtd);
	
	processo filap[qtd]; //fila de processos
	
	//input dos processos
	printf("diga, na ordem de chegada, as informacoes de cada processo:\n");
	
	for (i=0; i<qtd; i++){
		printf("\n------------------PROCESSO %d------------------\n", (i+1));
		printf("tempo de execucao (em segundos): ");
		scanf("%d", &filap[i].tempo);
		filap[i].id = i+1;
	}
	
	
	/*
	for(i=0; i<qtd; i++){
		help = filap[i].tempo;
		filap[i].ciclos = ceil(help/quantum);
		printf("%d e %f\n", filap[i].ciclos, (help/quantum));
	}
	
	
	//agora vou descobrir qual o maior ciclo
 	for(i=0; i<qtd; i++){
 		if(filap[i].ciclos > m) m = filap[i].ciclos;
	 }
	//agora m mostra o maior ciclo
	
	int ftemporeal = qtd;	//tamanho da fila em tempo real
	int posicao = 0;
	iteracao = 0;
	*/
	
	int ftemporeal=qtd;            //tamnho da fila em tempo real
    i = 0;                 //Primeira posição da fila
    while(ftemporeal !=0){		//enquanto houver processos na fila
        while(filap[i].tempo <= 0){ //Caso o tempo total do processo tiver acabado, descartá-lo 
            i++;
            if(i>= qtd) //Faz a rotação
                i=0;
        }
        printf("\n\nO processo %d está entrando em execucao com %d segundos restantes", i , filap[i].tempo);
        //printf("\nPaga ate %d contas", quantum);
        filap[i].tempo = filap[i].tempo - quantum;        //calculando quantos segundos vai faltar
        if( filap[i].tempo<=0){
            printf("\nE sai da fila de processos.\n");
            ftemporeal--;
        }
        else{
            printf("\nE vai pro final da fila de processos com %d segundos restantes.\n", filap[i].tempo);
        }
        i++;                               //Atualiza primeira posi��o
            if(i>qtd)    //Faz a rota��o
                i=0;
        system("PAUSE");
    }
	
	
}
