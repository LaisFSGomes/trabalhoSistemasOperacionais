#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int i; 
    pid_t pid; // identificador de processos, cada processo tem um valor diferente de pid
    
    //dentro do processo filho, o pid tem valor 0
    //dentro do processo pai, o pid tem o valor do processo filho
    //a fork() retorna um valor negativo, caso tenha ocorrido algum erro.
    if((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }
    //caso pid = 0 el cria o processo filho
    if (pid == 0){
        //O código aqui dentro será executado no processo filho
        printf("pid do Filho: %d\n", getpid());

    }else{
        //O código neste trecho será executado no processo pai
        printf("pid do Pai: %d\n", getpid());
    }
    //    F0       Haverá um processo filho criado pelo primeiro fork() 
    //  /     \
    //F1      F1   Haverão 2 processos filhos criados pelo segundo fork()
    fork();
    if(pid == 0){
      printf("pid do Filho 1: %d\n", getpid());
    }else{
	    exit(0);
    }
    printf("Esta regiao sera executada por todos processos\n\n");
    exit(0);
}
