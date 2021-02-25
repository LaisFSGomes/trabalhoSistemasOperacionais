#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
Faça um programa que leia um número “n” informado pelo usuário e diga quantos números primos há entre 0 e “n”. Esse seu 
programa deve rodar em 2 threads, de forma que o esforço computacional seja uniformemente dividido entre os threads.
*/


pthread_mutex_t lock;	//criando a variável mutex, usada para a exclusão múltua

typedef struct {
	int inicio;
	int fim;
} args;

int totalPrimos = 0;

/* Foi usado um ponteiro pq qd se incrementa uma variável global dentro de uma função, o valor é incrementado apenas dentro da função */
int * ptotalP = &totalPrimos;

/* a função eprimo calcula quantos divisores um número tem e se ele for divisível apenas por 1 e por ele mesmo (nesse caso, ele conta de 2
 a n e vê se o resto da divisão é igual a zero apenas uma vez, que é quando é divisível por ele meso) e retorna 1 se isso ocorrer e 0 se não */
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

/* essa função recebe como argumento um intervalo (de inicio e fim) e retorna quantos números primos há nesse intervalo */
void* qtsPrimo(void *argumento){
	args* lim = (args*)argumento;
	int* qts =(int*)malloc(sizeof(int));
	int ini = lim->inicio;
	int final = lim->fim;
	int i=0;
	*qts = 0;
	
	pthread_mutex_lock(&lock);
	//aqui entra na região crítica, pois é onde a variável global é incrementada
	for(i = ini; i <= final; i++){
        *ptotalP += eprimo(i);
		//printf("\nqtds primos: %d\n", 	*ptotalP);
	}
	//aqui termina a região crítica
	pthread_mutex_unlock(&lock);
	//finalizando a thread
	pthread_exit(NULL);
	return NULL;
}


int main(){
	int num;
	printf("entre com um valor inteiro maior que zero: ");
	scanf("%d", &num);
	
	//dividindo os dois intervalos para cada thread
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
	
	printf("\nNa thread1: inicio = %d e fim = %d\n", args1.inicio, args1.fim);
	
	//não necessariamente precisa de um join, pois as threads estão bem divididas, mas está sendo colocado por precaução
	//e também pq a lei de murphy não costuma decepcionar rs
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	
	printf("\nNa thread2: inicio = %d e fim = %d\n", args2.inicio, args2.fim);
	printf("\n\ntotal primos = %d\n\n", totalPrimos);
	
	pthread_mutex_destroy(&lock);	//destruindo a variável mutex
	
	system("pause");
}
