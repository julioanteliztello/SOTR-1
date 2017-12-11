/**adjuntashm.c obtiene una region de memoria que sera compar5tida por mas de un proceso 

**/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int intShmid;
	char *charPt=0;
	char str[32];
	/*if(argc<2){
		printf("Forma de uso: ./%s <identificador>",argv[0]);
		exit(EXIT_FAILURE);
	}*/
	scanf("%d",&intShmid);
//	intShmid=atoi(argv[1]);
	sprintf(str,"ipcs -id %d",intShmid);	
	system(str);
	if((charPt=shmat(intShmid,NULL,0777))<0){
		sprintf(str,"shmat FAILURE, %d\n",intShmid);
		perror(str);
		exit(EXIT_FAILURE);
	}
	sprintf(str,"ipcs -id %d",intShmid);	
	system(str);
	printf("shared memory attached at %p\n", charPt);
	exit(EXIT_SUCCESS);
}
