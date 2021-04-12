#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#define FORK_ERROR -1

/*

	Le serveur va changer le comportement par defaut des signauxs SIGUSR1 et SIGUSR2 et SIGIINT et aussi le serveur va etre tourner sans arret sauf si il a reçu un signal d'arrêt comme SIGKILL
	ou SIGINT.
	
	Ce programme est fait seulment pour tester comment la gestion et  la reception des signaux marche.

*/


int cp=0; // Compteur qui va compter le nombre de fois une fonction handler a été declancher



/*
	Declaration et definition des fonctions qui vont etre executer quand un des ces signauxs est declanché SIGUSR1,SIGUSR2,SIGUSR3

*/

void sigUsr1Handler(int num)
{
	printf("SIGUSR1 SIGNAL RECEIVED Server pid : %d\tcp=%d\n",getpid(),++cp);
}


void sigUsr2Handler(int num)
{
	printf("SIGUSR2 SIGNAL RECEIVED Server pid : %d\tcp=%d\n",getpid(),++cp);
}


void sigIntHandler(int num)
{
	printf("Arret du serveur ! \n");
	exit(0);
}

int main(int argc,char *argv[])
{
	printf("Server process id = %d\n",getpid());	
	
	
	// Changer le comportement par defaut des signaux avec la foncton signal(int signum,handler)
	signal(SIGUSR1,sigUsr1Handler);	
	signal(SIGUSR2,sigUsr2Handler);	
	signal(SIGINT,sigIntHandler);
	
	//tourner le serveur à l'infini
	while(true);
		
	return 0;
}
