#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
Fa�a um programa que leia um n�mero �n� informado pelo usu�rio e diga quantos n�meros primos h� entre 0 e �n�. Esse seu 
programa deve rodar em 2 threads, de forma que o esfor�o computacional seja uniformemente dividido entre os threads.
*/


pthread_mutex_t lock;	//criando a vari�vel mutex, usada para a exclus�o m�ltua

typedef struct {
	int inicio;
	int fim;
} args;

int totalPrimos = 0;

/* Foi usado um ponteiro pq qd se incrementa uma vari�vel global dentro de uma fun��o, o valor � incrementado apenas dentro da fun��o */
int * ptotalP = &totalPrimos;

/* a fun��o eprimo calcula quantos divisores um n�mero tem e se ele for divis�vel apenas por 1 e por ele mesmo (nesse caso, ele conta de 2
 a n e v� se o resto da divis�o � igual a zero apenas uma vez, que � quando � divis�vel por ele meso) e retorna 1 se isso ocorrer e 0 se n�o */
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

/* essa fun��o recebe como argumento um intervalo (de inicio e fim) e retorna quantos n�meros primos h� nesse intervalo */
void* qtsPrimo(void *argumento){
	args* lim = (args*)argumento;
	int* qts =(int*)malloc(sizeof(int));
	int ini = lim->inicio;
	int final = lim->fim;
	int i=0;
	*qts = 0;
	
	pthread_mutex_lock(&lock);
	//aqui entra na regi�o cr�tica, pois � onde a vari�vel global � incrementada
	for(i = ini; i <= final; i++){
        *ptotalP += eprimo(i);
		//printf("\nqtds primos: %d\n", 	*ptotalP);
	}
	//aqui termina a regi�o cr�tica
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
	
	//n�o necessariamente precisa de um join, pois as threads est�o bem divididas, mas est� sendo colocado por precau��o
	//e tamb�m pq a lei de murphy n�o costuma decepcionar rs
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	
	printf("\nNa thread2: inicio = %d e fim = %d\n", args2.inicio, args2.fim);
	printf("\n\ntotal primos = %d\n\n", totalPrimos);
	
	pthread_mutex_destroy(&lock);	//destruindo a vari�vel mutex
	
	system("pause");
}
