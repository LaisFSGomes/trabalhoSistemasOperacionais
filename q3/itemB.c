#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int n; //número de termos
int *v; //ponteiro para alocar os termos digitados 
int i; // variável para controle do laço

pid_t pid; // identificador de processos, cada processo tem um valor diferente de pid

//função que vai colocar os números nos processos criados pelo fork();
//A função mostra numeros no processo pai e no processo filho
void numeros(){
	pid = fork();

	for (i = 0; i < (n/2)+2; ++i){
		//se o pid for < 0 há algum erro e ele não execulta o processo
		if (pid < 0){
      			perror("fork");
     			exit(1);
    		
		if (pid == 0){
      			//O código aqui dentro será executado no processo filho
			//imprime metade dos valores
      			printf("Filho: ");
      			printf("%d \n", v[i+1]);
      			i++;
			
    		}else{
      			//O código neste trecho será executado no processo pai
			//imprime metade dos valores
      			printf("Pai: ");
      			printf("%d \n", v[i]);
    		}		
	 }
	 exit(0);
}

int main() {
	printf("Digite a quantidade de termos: ");
    	scanf("%d", &n);
    	v = (int *)malloc(n * sizeof(int)); //alocar a memória par ao ponteiro
	//laço para ler o números inseridos pelo usuário
    	for (i = 0; i < n; ++i) {
        	scanf("%d", &v[i]);
    	}
    	/*for (i = 0; i < n; ++i) {
        	printf("%d ", v[i]);
    	}*/
    	numeros();//função para imprimir os números
    	printf("\n");
    	free(v);//liberar as posições de memória do ponteiro
    	return 0;
}
