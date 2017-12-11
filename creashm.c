/**sharedmem.c obtiene una region de memoria que sera compar5tida por mas de un proceso 

**/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {
int intShmemget,intBufsize=4096;
if((intShmemget=shmget(IPC_PRIVATE,intBufsize,0777))==-1){
	perror("shmget FAILURE!!!");
	exit(EXIT_FAILURE);
}
//printf("Shared memory = %d\n",intShmemget);
printf("%d",intShmemget);
/*char str[32];
sprintf(str,"ipcs -m --id %d\n",intShmemget);
system(str);*/
exit(EXIT_SUCCESS);
return 0;
}

