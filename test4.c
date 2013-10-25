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
//the amount of the group cannot greater than 20.
    for(int i =0;i<18;i++){
    	if(IGCreate(i+3) == 0)
    	printf("Failed to create a group at creating group %d ,\n",i+3);
    }
	
	//test IGPublisher
	pid_t pid, pid2,pid3,pid4;
	pid = fork();
    if(pid != 0){
    	pid2 = fork();
    	if(pid2!=0){
    		pid3 = fork();
    		if(pid3!=0){
    			pid4=fork();
    			if(pid4==0){
    				//test IGSubscriber
    				if(IGSubscriber(0) == 0)
    					printf("Failed to declare as a publisher.\n");
    				if(IGSubscriber(1) == 0)
    					printf("Failed to declare as a publisher.\n");
    			}
    		}else{
    			if(IGSubscriber(0) == 0)
    			    printf("Failed to declare as a publisher.\n");
    			if(IGSubscriber(1) == 0)
    			    printf("Failed to declare as a publisher.\n");
    		}
    	}
    		else{
    			if(IGPublisher(0) == 0)
    				printf("Failed to declare as a publisher.\n");
    			if(IGPublisher(1) == 0)
    				printf("Failed to declare as a publisher.\n");
    		}
    }else{
		if(IGPublisher(0) == 0)
			printf("Failed to declare as a publisher.\n");
		IGPublish(0, "How are you?");
		
	}
	
	//test IGPublish
	
	
	//test IGRetrive
	
}
