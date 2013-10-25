#include <stdio.h>
#include <unisted.h>
#include <sys/wait.h>

int main()
{
    if(IGCreate(1) == 0)
		printf("Failed to create a group.\n");
	IGPublisher(1);
	IGPublish(1, "message12");
	IGPublish(1, "message12");
	IGPublish(1, "message12");
	IGPublish(1, "message12");
	IGPublish(1, "message12");
	IGPublish(1, "message12"); //buffer is full, error message
}