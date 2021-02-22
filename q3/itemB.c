#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int n;
int *v;
int i;

pid_t pid;

void numeros(){
	pid = fork();
	for (i = 0; i < (n/2)+2; ++i){
		if (pid < 0){
      perror("fork");
      exit(1);
    }
    if (pid == 0){
      //O código aqui dentro será executado no processo filho
      printf("Filho: ");
      printf("%d \n", v[i+1]);
      i++;
			
    }else{
      //O código neste trecho será executado no processo pai
      printf("Pai: ");
      printf("%d \n", v[i]);
    }		
	 }
	
	 exit(0);
}

int main() {

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    /*for (i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }*/
    numeros();

    printf("\n");
    free(v);
    return 0;
}
