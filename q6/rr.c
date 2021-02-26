#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define quantum 2	//duração do quantum em segundos

typedef struct{
	int id;
	int tempo;
} processo;

int main(){
	int qtd; //quantidade de processos na fila de execucao
	int i, j;	//variaveis auxiliares
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
	O algoritmo de escalonamento do tipo RR funciona como uma fila circular que executa cada processo por um quantum (aqui, 2s) e 
	quando um processo tem seu tempo de execuçãp total finalizado, ele sai da fila e os proximos continuam até que se findem e
	a fila fica fazia.
	
	Esse algoritmo roda enquanto a fila estiver maior que zero e faz as verificações necessarias que o escalonador RR precisa.
	*/
	
	
	int ciclo = 1; 		//para contar quantos ciclos irá durar o escalonamento
	int ftemporeal=qtd; 	//tamnho da fila em tempo real
    i = 0;                 //Primeira posicao da fila de processos

	system("cls");    
	printf("\CICLO %d ---------------------------------------\n", ciclo);
    while(ftemporeal !=0){		//enquanto houver processos na fila
        while(filap[i].tempo <= 0){ //Caso o tempo total do processo tiver acabado, descartÃ¡-lo 
			i = (i+1)%qtd;	//atualiza a posicao
        }
    	
    	printf("PROCESSO %d\n", (i+1));
    	printf("id = %d \nTempo de execucao (em segundos): %d\n", filap[i].id, filap[i].tempo);
        Sleep(2000);	//espera
        
        //vendo se o processo ja terminou o tempo de execucao ou se ele ja finalizou e exibindo na tela a resposta
        filap[i].tempo = filap[i].tempo - quantum;        
        if( filap[i].tempo<=0){
            printf("Processo sai da fila de processos\n\n", filap[i].id);
            ftemporeal--;
        }
        else{
            printf("\nProcesso vai pro final da fila de processos com %d segundos restantes.\n\n", filap[i].id, filap[i].tempo);
        }

		i = (i+1)%qtd; //atualiza a posicao
		
		if(i==0 && ftemporeal != 0){
			ciclo++;
			printf("\nCICLO %d ---------------------------------------\n", ciclo);
		}
    }
}
