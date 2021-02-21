#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>


#define MaxItems 5 //maximo de intens que o produtor pode produzir e o consumidor pode remover
#define BufferSize 1  //tamanhodo buffer

sem_t empty;	//slotes vazios do buffer
sem_t full;		//slotes cheios
int in = 0;		//índice que o produtor usará a seguir
int out = 0;	//índice que o consumidor usará a seguir
int buffer[BufferSize];	//memória compartilhada
pthread_mutex_t mutex; //para fazer a exclusão múltua na memória compartilhada pelas duas threads

void *producer(void *pno){
	int item;
	int i;
	for(i = 0; i < MaxItems; i++){
		item = rand()%100;	//produzir um valor aleatório
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("Produtor %d: inceriu o item %d na posicao %d do buffer\n", ((int)pthread_self()), buffer[in], in);
		in= (in+1)%BufferSize;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
	pthread_exit(NULL);
}

void *consumer(void *cno){
	int i;
	for (i = 0; i < MaxItems; i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[out];
		printf("Consumidor %d: Removeu o item %d de %d\n", ((int)pthread_self()), item, out);
		out = (out+1)%BufferSize;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t pro, con;
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty,0, BufferSize);
	sem_init(&full, 0, 0);
	int i;
	
	
	pthread_create(&pro, NULL, (void *)producer, NULL);
	pthread_create(&con, NULL, (void *)consumer, NULL);
	pthread_join(pro, NULL);
	pthread_join(con, NULL);
	
	
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
}
