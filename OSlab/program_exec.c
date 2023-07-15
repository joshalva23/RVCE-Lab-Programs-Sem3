#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(int argc, char *argv[])
{
	printf("Inside main\n");
	int res=1;
	pid_t pid = fork();

	if(pid<0)
		printf("Error Generated\n");

	if(pid==0){
		printf("Inside child process, PID=%d\n",getpid());
		execl("./RSA","RSA",NULL,NULL);
	}
	else{
		printf("Inside parent process, PID=%d\n",getpid());
		wait(&res);
		if(WIFEXITED( res )==1)
			printf("\nterminates normally\n");
		else{
			printf("Abnormal Termination\n");
			exit(0);
		}	 
	}
}
