#include <stdio.h>
#include <unisted.h>

int main()
{
	//test IGLookup
	
	
    //test IGCreate
    if(IGCreate(0) == 0)
		printf("Failed to create a group.\n");
    if(IGCreate(0) == 0)
		printf("Failed to create a group.\n");    
    if(IGCreate(1) == 0)
		printf("Failed to create a group.\n");
    if(IGCreate(2) == 0)
		printf("Failed to create a group.\n");

	
	//test IGPublisher
	pid_t pid, pid2;
    int state, state2;
	pid = fork();
    if(pid != 0){
		//waitpid(pid, &state, 0);
    }else{
		if(IGPublisher(0) == 0)
			printf("Failed to declare as a publisher.\n");
		IGPublish(0, "How are you?");
		
	}
	
	pid2 = fork();
	if(pid2 == 0&&pid!=0){
		if(IGPublisher(0) == 0)
				printf("Failed to declare as a publisher.\n");
		if(IGPublisher(1) == 0)
				printf("Failed to declare as a publisher.\n");
    }
	/*
    if(IGPublisher(0) == 0)
	printf("Failed to declare as a publisher.\n");
    if(IGPublisher(0) == 0)
	printf("Failed to declare as a publisher.\n");
    if(IGPublisher(0) == 0)
	printf("Failed to declare as a publisher.\n");
	*/
	
	//test IGSubscriber
	pid_t pid3, pid4;
    int state3, state4;
	pid3 = fork();
    if(pid!= 0&&pid2!=0&&pid3==0){
    	if(IGSubscriber(0) == 0)
    			printf("Failed to declare as a publisher.\n");
    	if(IGSubscriber(1) == 0)
    			printf("Failed to declare as a publisher.\n");
    }
	
	pid4 = fork();
	if(pid!= 0&&pid2!=0&&pid3!=0&&pid4==0){
		if(IGSubscriber(0) == 0)
			printf("Failed to declare as a publisher.\n");
		if(IGSubscriber(1) == 0)
			printf("Failed to declare as a publisher.\n");
    }
	
	//test IGPublish
	
	
	//test IGRetrive
	
	
	
}
