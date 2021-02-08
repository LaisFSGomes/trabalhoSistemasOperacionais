#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

int termos, x;
double resultado, resultado1;

unsigned long long fatorial( int n ) {
    unsigned long long f = 1;
    for( ; n > 0; f *= n-- );
    //printf("Fatorial: %d",  f);
    return f;
}

void *somas(void *arg){
	int i;
   	resultado = 0;
	int *n = (int *)arg;
	x = *n;
	for(i = 0; i < termos; i++){
      	if(i%2 == 0){
			resultado += pow(x, 2*i + 1) / fatorial(2*i + 1);
			printf("...\n");
   		}
   		
	}
   	printf("somas: %d\n",  resultado);

}
	

void *subtracoes(void *arg){	
	int i;
   	resultado1 = 0;
	int *n = (int *)arg;
	x = *n;	
	
	for(i = 0; i < termos;i++){
		if(i%2 == 1){
      		resultado1 += pow(x, 2*i + 1) / fatorial(2*i + 1);
      		printf(".......\n");
   		}
   		
	}
	printf("subs: %d\n",  resultado1);	
	printf("\n\nO resultado e: %f\n\n", resultado - resultado1);
   	
}


int main(){
	
	pthread_t thread1, thread2;
	
	printf("Digite o numero de termos da sequencia: " );
   	scanf("%d", &termos);
   	printf("\nDigite o valor de x para o calculo do sen(x), x = ");
   	scanf("%lf", &x);
	
	
	pthread_create(&thread1, NULL, somas,(void*) &x);
	pthread_create(&thread2, NULL, subtracoes, (void*) &x);
	
	
	
	pthread_exit(NULL);
	
	
	return 0;	

}

