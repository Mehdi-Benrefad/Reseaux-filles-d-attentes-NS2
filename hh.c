#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
int i , x,f,status;
x=1;
printf("pid %d ppid %d  value %d\n",getpid(),getppid(),x);

for(i=0;i<3;i++){
f=fork();
if(f==0){

x=x*2;
printf("pid %d ppid %d  value %d\n",getpid(),getppid(),x); 
}
}
wait(&status);
return 0;
}

