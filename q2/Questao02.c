#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>


int termos;
double resultado, resultado1;
double x = 0;


//Função para calculo do fatorial
unsigned long long fatorial( int n ) {
    unsigned long long f = 1;
    for( ; n > 0; f *= n-- );
    //printf("Fatorial: %d",  f);
    return f;
}
//função para calcula a soma dos termos positivos da series de McLaurin
void *somas(void *arg){
	int i;
   	resultado = 0;
	
	
	for(i = 0; i < termos; i++){
      	if(i%2 == 0){
			resultado = resultado + pow(x, 2*i + 1) / fatorial(2*i + 1);
			//printf("...\n");
			//printf("somas: %f\n",  resultado);
   		}
   		
	}
	
}
	
//função para calcula a soma dos termos negativos da series de McLaurin
void *subtracoes(void *arg){	
	int i;
   	resultado1 = 0;
	

	for(i = 0; i < termos;i++){
		if(i%2 == 1){
      		resultado1 = resultado1 + pow(x, 2*i + 1) / fatorial(2*i + 1);
      		//printf(".......\n");
      		//printf("subs: %f\n",  resultado1);	
   		}
   		
	}
	printf("\n\nO resultado : %f\n", resultado - resultado1);
   	
}


int main(){
	
	pthread_t thread1, thread2;
	
	printf("Digite o numero de termos da sequencia: " );
   	scanf("%d", &termos);
   	printf("\nDigite o valor de x para o calculo do sen(x), x = ");
   	scanf("%lf", &x);
	
	// criação das threads
	pthread_create(&thread1, NULL, somas,(void*) &x);
	pthread_create(&thread2, NULL, subtracoes, (void*) &x);
	
	
	pthread_exit(NULL);
	
	return 0;	

}
