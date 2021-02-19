#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>

//funçao sen^2(x)
void *firstFunc(void *arg){
	float *num = (float *) arg;
	//alocando um espaço de memória do tamanho de um float e atribuindo a variável f1 
	float *f1 = (float *)malloc(sizeof(float));
	*f1 = pow(sin(*num), 3);	
	float b = *((float *) f1);
	printf("f1: sin^3(x): %f", b);
	
	//retornando endereço apontado por f1
	pthread_exit(f1);
}
//função (srqt(cos(x))
void *secondFunc(void *ard){
	float *num = (float *) ard;
	//alocando um espaço de memória do tamanho de um float e atribuindo a variável f2
	float *f2 = (float *)malloc(sizeof(float));
	*f2 = sqrt(cos(*num));
	//Verificando o valor de cos(x) é negativo
	if(cos(*num) < 0){
		printf("\n Error, the result of cos(%f) is negative", *num);
		exit;
	}else{		
		float b = *((float *) f2);
		printf("\nf1: sin^3(x): %f", b);
		
		//retornando endereço apontado por f2
		pthread_exit(f2);
	}
}

int main (){
	float f1, f2, sum, x;
	//referenciando duas threads
    pthread_t thread1, thread2;
    //ponteiro void para poder armazenar os endereços que estão vindo no join
    void* res1;
    void* res2;
    //Inserindo o valor que vai ser atribuito ao x das threads
    printf("Insira um valor para X \n X = ");		
	scanf("%f", &x);
	
	//criando as threads e passando o dado digitado
	pthread_create(&thread1, NULL, firstFunc, &x);	
	pthread_create(&thread2, NULL, secondFunc, &x);
	
	//finalizando as threads e recebendo o endereço que elas estão retornando
	pthread_join(thread1, &res1);
	pthread_join(thread2, &res2);
	
	//Convertendo de void para float e em seguida recebe o valor que está sendo apontado.
	f1 = *((float *)res1);
	f2 = *((float *)res2);

	sum = f1 + f2;
	
	printf("\nresultado da soma: %f", sum);
		
	//liberando as posições
	free(res2);
	free(res1);
	pthread_exit(NULL);

}
