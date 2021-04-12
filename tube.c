#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	int p_f[2],f_p[2];
	pipe(p_f);
	pipe(f_p);
	int pid;
	pid=fork();
	if(pid==0)
	{
		close(f_p[0]);
		char P[40]="gestionnaire du projet";
		char P1[40]="gestionnaire du projet et admin bdd";
		write(f_p[1],&P,40*sizeof(char));
		printf("fils : %s\n",P);
		sleep(1);
		write(f_p[1],&P1,40*sizeof(char));
                printf("fils : %s\n",P1);
		//sleep(1);
	
	}
	else
	{
		close(p_f[0]);
		char T[40]="quelle profession tu admires";
		char T1[40]="tu es informaticien";
		
			write(p_f[1],&T,40*sizeof(char));
			printf("pere : %s\n",T);
			sleep(1);		
			write(p_f[1],&T1,40*sizeof(char));
                        printf("pere : %s\n",T1);
                        sleep(1);

	}
}

