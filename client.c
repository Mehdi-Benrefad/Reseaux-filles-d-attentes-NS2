#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

#include <errno.h> // Pour la variable errno qui stock un entier  qui indique une erreur spécifique quand un appel system renvoi une erreur  
#include <string.h> // Pour la fonction strerror(int errno)  car errno ce n'est qu'un entier et cette fonction va expliquer le probleme  en chaine de caractère

	
	/*
	
		Programme client qui sert à envoyer des signaux à un processus
		Syntax : ./prog <pid>
	*/


int main(int argc,char *argv[])
{
	/*Tester si l'utilisateur à bien saisie les arguments*/
	if(argc != 2)
	{
		fprintf(stdout,"Syntax : %s <p_id>\n",argv[0]);
		return EXIT_FAILURE;
	}

	// Parser la chaine de caractère
	pid_t server_pid=atoi(argv[1]);
	
	printf("Sending SIGUSR1 signal to %d\n",server_pid);
	
	
	/* Tester si la fonction a bien fonctionner et envoyer le signal au processus server_pid*/
	
	if(kill(server_pid,SIGUSR1)<0)
	{
		fprintf(stdout,"kill():%s\n",strerror(errno));
		return EXIT_FAILURE;//exit du programme
	}
	printf("SIGUSR1 signal sent ! \n");
	sleep(5);
	printf("Sending SIGUSR2 signal to %d\n",server_pid);
	kill(server_pid,SIGUSR2);
	printf("SIGUSR2 signal sent ! \n");
	sleep(5);
	
	/*Arreter le serveur avec l'envoi d'un SIGINT*/
	printf("Sending SIGINT to the server for shutdown\n");
	kill(server_pid,SIGINT);
	printf("SIGINT signal sent !\n");
	
	return 0;
}
