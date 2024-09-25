#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int pid=fork();
	if (pid>0){
		printf("I AKM PRENT PROCESS\n");
		printf("ID:%d\n\n",getpid());
	}
	else if (pid==0){
		printf("i am child process\n");
		printf("ID:%d\n",getpid());
	}
	else{
		printf("fe9ild to cearte a child process@s");
	}
	return 0;
}
