#include <stdio.h>
#include <unisted.h>
#include <sys/wait.h>

int main()
{
    //test IGLookup
    //test IGCreate
    if(IGCreate(1) == 0)
		printf("Failed to create a group.\n");
    if(IGCreate(1) == 0)
		printf("Failed to create a group.\n");    
    if(IGCreate(2) == 0)
		printf("Failed to create a group.\n");
    if(IGCreate(3) == 0)
		printf("Failed to create a group.\n");
	//the amount of the group cannot be greater than 20
    for(int i =0;i<18;i++){
    	if(IGCreate(i+4) == 0)
    	printf("Failed to create a group at creating group %d ,\n",i+3);
    }
	
	//fork processes
	pid_t pid, pid2,pid3,pid4;
	pid = fork();
    if (pid == -1)
	{
		fprintf(stderr, "can't fork, error %d\n", errno);
		exit(EXIT_FAILURE);
	}
    if(pid != 0){
    	pid2 = fork();
    	if (pid2 == -1){
    		  fprintf(stderr, "can't fork, error %d\n", errno);
    	      exit(EXIT_FAILURE);
    	}
    	if(pid2!=0){
    		pid3 = fork();
    		if (pid3 == -1){
    			fprintf(stderr, "can't fork, error %d\n", errno);
    			exit(EXIT_FAILURE);
    		}
    		if(pid3!=0){
    			pid4=fork();
    			if (pid4 == -1){
    			    fprintf(stderr, "can't fork, error %d\n", errno);
    			    exit(EXIT_FAILURE);
    			}
    			if(pid4==0){ //test IGSubscriber
    				if(IGSubscriber(1) == 0)
    					printf("Failed to declare as a publisher.\n");
    				if(IGSubscriber(2) == 0)
    					printf("Failed to declare as a publisher.\n");
					IGRetrive(1);
					IGRetrive(2);
    			}
    		}else{ //test IGSubscriber
    			if(IGSubscriber(1) == 0)
    			    printf("Failed to declare as a publisher.\n");
				//test IGRetrive
				IGRetrive(1);
				IGRetrive(2); //error message will occur
    		}
    	}
    		else{ //test IGPublisher
    			if(IGPublisher(1) == 0)
    				printf("Failed to declare as a publisher.\n");
    			if(IGPublisher(2) == 0)
    				printf("Failed to declare as a publisher.\n");
				//test IGPublish
				IGPublish(1, "message11");
				IGPublish(2, "message12");
    		}
    }else{ //test IGPublisher
		if(IGPublisher(1) == 0)
			printf("Failed to declare as a publisher.\n");
		//test IGPublish
		IGPublish(1, "message21");
		IGPublish(2, "message22"); //error message will occur
		
	}
	
	sleep(20);
}
