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
	pid_t pid, pid2,pid3,pid4;
	pid = fork();
    if(pid != 0){
    	pid2 = fork();
    	if(pid2!=0){
    		pid3 = fork();
    		if(pid3!=0){
    			pid4=fork();
    			if(pid4==0){
					printf("Hello I'm process 1\n");
    			}
    		}else{
					printf("Hello I'm process 2\n");
    		}
    	}
    		else{
					printf("Hello I'm process 3\n");
    		}
    }else{
		printf("Hello I'm process 4\n");
}
	sleep(10);
}