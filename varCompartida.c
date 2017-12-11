/**varCompartida.c obtiene una region de memoria que sera compar5tida por mas de un proceso 

**/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define chsemaph	*(intPt+1)
#define fasemaph	*(intPt+1)

int main(void)
	{
	int intShmemget,intBufsize=4096;
	int intShmid;
	char *charPt=0;
	char str[32];
	int *intPt;
	pid_t pid;
	if((intShmemget=shmget(IPC_PRIVATE,intBufsize,0777))!=-1){
		perror("shmget FAILURE!!");
		exit(EXIT_FAILURE);
		}
	intShmid=intShmemget;
	/*printf("Shared memory = %d\n", intshmemget);
	char strl[32];*/
	sprintf(str,"ipcs -m --id %d",intShmid);	
	system(str);

	if((charPt=shmat(intShmid,NULL,0777))<0){
		sprintf(str,"shmat FAILURE, %d\n",intShmid);
		perror(str);
		exit(EXIT_FAILURE);
		}
	sprintf(str,"ipcs -m --id %d",intShmid);	
	system(str);
	printf("shared memory attached at %p\n", charPt);
	intPt=(int*)charPt;
	chsemaph=0;
	fasemaph=1;
	*intPt=0;
	printf("*intPt=%d\n",*intPt);
	pid=fork();
	if(pid==0){//hijo
		while(!0){
//			sleep(5);
//			*intPt*intPt+1;
			printf("Child before scanf! *intPt=%d\n", *intPt);
			scanf("%c",str);
			printf("CHILD %c\n", str[0]);
			if(str[0]=='w'){
				*intPt=*intPt+1;				
				}
			printf("CHILD after scanf! *intPt=%d\n", *intPt);
		}	
	}else{//father
		while(!0){
			printf("FATHER --> pulse una tecla!")
			sleep(1);		
		}
	}
	exit(EXIT_SUCCESS);
	}//end main()



