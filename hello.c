#include <sys/param.h>
#include <sys/types.h>
#include <signal.h>
#include <err.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	pid_t pid, pid2;
    int state, state2;
	pid = fork();
	//pid2 = fork();
    if(pid == 0){
		printf("Hello I'm process 1\n");
		sleep(5);
		printf("Hello I'm process 1 again\n");

	}
	
	pid2 = fork();
	if(pid2 == 0){
		printf("Hello I'm process 2\n");
		sleep(2);
		printf("Hello I'm process 2 again\n");
		
	}
	sleep(20);
	
}
