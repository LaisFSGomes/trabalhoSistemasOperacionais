#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
O algoritmo de escalonamento SJF da prioridade aos processos que demorarão menos, afim de diminuir o tempo de espera
*/

typedef struct{
	int id;
	int tempo;
} processo;

//função que ordena de acordo com o tempo de execução de cada processo. O algoritmo é o insertion sort
void ordena(processo *v, int N){
	int i, j;
	processo aux;
	for (i = 1; i < N; i++){
		aux = v[i];
		for (j=i; (j>0) && (aux.tempo < v[j-1].tempo); j--)
			v[j] = v[j-1];
		v[j] = aux;
	}
}

int main(){
	int qtd; //quantidade de processos na fila de execução
	printf("quantos processos estao na fila: ");
	scanf("%d", &qtd);
	
	processo filap[qtd]; //fila de processos
	
	//input dos processos
	printf("diga, na ordem de chegada, as informacoes de cada processo:\n");
	int i, j;
	for (i=0; i<qtd; i++){
		printf("\n------------------PROCESSO %d------------------\n", (i+1));
		printf("tempo de execucao (em segundos): ");
		scanf("%d", &filap[i].tempo);
		filap[i].id = i+1;
	}
	
	//ordenando de acordo com o tempo de execução
	ordena(filap, qtd);

	//escalonamento
	system("cls");
	for (i=0; i<qtd; i++){
		printf("\n------------------PROCESSO %d------------------\n", (i+1));
		printf("id = %d \nTempo de execucao em segundos: %d\n", filap[i].id, filap[i].tempo);
		Sleep(filap[i].tempo*1000);
	}
	
}
