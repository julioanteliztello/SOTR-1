#define FALSE	0
#define TRUE	1
#define N	2 			//numero de procesos
#include <stdio.h>
int turn;				//a quien le toca?
int interested[N];			//todos los valores son inicialmente 0

void enter_region(int process){	//proceso 0
	int other;			//numero del otro proceso
	other=1-process;		//lo opuesto del proceso
	interested[process]=TRUE;	//mostrar interes
	turn=process;			//establecer bandera
	while(turn==process&&interested[other]==TRUE);//instruccion nula
}

void leave_region(int process){		//process: quien sale
	interested[process]=FALSE;
}

void abcmin(){
	char abc='a';
	int i;

	for(i=1;i++;i<=26){
		printf("%c", abc);
		abc++;
	}
}

void main(){
	abcmin();
}
