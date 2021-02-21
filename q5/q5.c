#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>


#define QTD 4 //quantidade de threads 

int valor = 0;


pthread_mutex_t mutex; //para fazer a exclusão múltua na memória compartilhada pelas duas threads



void *produtor(void *arg){
	 int *x = &valor;
	while (valor == 0){
		pthread_mutex_lock(&mutex);
		*x = (rand()%100);
		printf("Produtor %d: produziu %d\n", ((int)pthread_self()), *x);
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

void *consumidor(void *arg){
	 int *x = &valor;
	while (valor != 0){
		pthread_mutex_lock(&mutex);
		printf("Consumidor %d: consumiu %d\n", ((int)pthread_self()), *x);
		*x = 0;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t pro[QTD], con[QTD];
	pthread_mutex_init(&mutex, NULL);
	int i;
	
	for (i = 0; i < QTD; i++){
		//printf("valor =  %d\n", valor);
		pthread_create(&pro[i], NULL, (void *)produtor, NULL);
		//printf("valor =  %d\n", valor);
		pthread_create(&con[i], NULL, (void *)consumidor, NULL);
		pthread_join(pro[i], NULL);
		pthread_join(con[i], NULL);
	}
//	for (i = 0; i < QTD; i++){
//		pthread_join(pro[i], NULL);
//		pthread_join(con[i], NULL);
//	}
	
	pthread_mutex_destroy(&mutex);

}
