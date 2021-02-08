#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;

typedef struct {
	int inicio;
	int fim;
} args;

int totalPrimos = 0;
int * ptotalP = &totalPrimos;

int eprimo(int n){
	int i, res = 0;
	for(i=2; i<=n; i++){
		if (n%i == 0){
			res++;
		}
	}
	if (res==1){
		return 1;
	}else {
		return 0;
	}
}

void* qtsPrimo(void *argumento){
	args* lim = (args*)argumento;
	int* qts =(int*)malloc(sizeof(int));
	int ini = lim->inicio;
	int final = lim->fim;
	int i=0;
	*qts = 0;
	pthread_mutex_lock(&lock);
	for(i = ini; i <= final; i++){
        *ptotalP += eprimo(i);
		printf("\nqtds primos: %d\n", 	*ptotalP);
	}
	pthread_mutex_unlock(&lock);
	
	pthread_exit(NULL);
	return NULL;
}


int main(){
	int num;
	printf("entre com um valor inteiro maior que zero: ");
	scanf("%d", &num);
	int a = (int)(num/2);
	args args1, args2;
	args1.inicio = 1;
	args1.fim = a;
	args2.inicio = a+1;
	args2.fim = num;
	//---------------threads-------------
	 pthread_mutex_init(&lock, NULL);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, qtsPrimo, (void*)&args1);
	pthread_create(&t2, NULL, qtsPrimo, (void*)&args2);
	
	printf("\n args1: inicio = %d e fim = %d\n", args1.inicio, args1.fim);
	printf("\n args2: inicio = %d e fim = %d\n", args2.inicio, args2.fim);
	
	printf("\n\ntotal primos = %d\n\n", totalPrimos);
	
	pthread_mutex_destroy(&lock);
	
	system("pause");
}
