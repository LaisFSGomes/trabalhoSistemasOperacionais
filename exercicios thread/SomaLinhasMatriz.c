#include <stdio.h>
#include <pthread.h>
int i=0;
int matriz[5][5] = {{1, 1, 2, 1, 1},
					{2, 2, 3, 2, 2},
					{3, 3, 4, 3, 3},
					{4, 4, 5, 4, 4},
					{5, 5, 6, 5, 5}};	
//função que retornará para thread e mostrará o valor da soma das linhas da matriz					
void *sumLine(void *arg){
		int som, c;
		i++;
		for(c = 0; c < 5; c++){
			som = som + matriz[i-1][c];
		};
		
		printf("Somatório da Linha %d  = %d\n",i , som);
}

int main(void){
	//vetor de thread
	pthread_t thread[5];				
	int r=0, c=0;
	
	//Mostrar em tela a Matriz		
	for(r = 0; r < 5; r++){
		for(c=0; c < 5; c++){
			printf(" %d ", matriz[r][c]);			
		}
		printf("\n");
	};
	printf("\n");
	//serão criadas 5 threads
	int i;
	for(i = 0; i<5 ;i++){
		pthread_create(&thread[i], NULL, sumLine, NULL);
	};
	pthread_exit(NULL);
	
}
