#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	int semid;
	int nsems=1;			//cantidad de semafroros a crear
	int flags=0666;
	struct sembuf buf;		//comprotamiento del semaforo
	semid=semget(IPC_PRIVATE,nsems,flags);
	if(semid<0){
		perror("semfet()");
		exit(EXIT_FAILURE);	
	}
	printf("semaforo creado: %d\n", semid);
//configuracion de la estructura
	buf.sem_num=0;			//un solo semaforo
	buf.sem_op=1;			//incrementa el valor del semaforo
	buf.sem_flg=IPC_NOWAIT;	//no lo bloquea
	if((semop(semid,&buf,nsems))<0){
		perror("semop()");
		exit(EXIT_FAILURE);
	}
	system("ipcs -s");
	exit(EXIT_SUCCESS);
}					//end main
