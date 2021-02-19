#include <stdio.h>
#include <pthread.h>

void *funcInc(void *ard){
	int *num = (int *) ard;
	int a = *num;
	int i;
	
	for(i=0; i<=a ;i++){
		printf("valor crescente: %d\n",i);
	}
	
}

void *funcDec(void *ard){
	int *num = (int *) ard;
	int a = *num;
	int i;
	
	for(i=a; i>=0 ;i--){
		printf("valor decrescente: %d\n",i);
	}
	
}

int main (){
    pthread_t thread1, thread2;
    int valor1 = 500;	
	
	pthread_create(&thread1, NULL, funcInc, &valor1);	
	pthread_create(&thread2, NULL, funcDec, &valor1);
	
	pthread_exit(NULL);

    
    //pthread_exit(NULL);

   

 
    
    

	return 0;
}
