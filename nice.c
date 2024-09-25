#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	pid_t pid;
	pid = fork();
	if (pid==0)
	{
		printf("\n iam a child process ,id=%d\n",getpid());
		printf("\n priority =%d\n",nice(-7),getpid());
	}
	else 
	{
		printf("\n i am prent process ,id=%d\n",getpid());
		nice(1);
		printf("\n priorty :%d,id =%d\n",nice(15),getpid());
	}
	return 0;
}

