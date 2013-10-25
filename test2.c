#include <stdio.h>
#include <unisted.h>
#include <sys/wait.h>

int main()
{
    if(IGCreate(0) == 0)
		printf("Failed to create a group.\n");
	IGPublisher(0);
	IGPublish(0, "message12");
	IGPublish(0, "message12");
	IGPublish(0, "message12");
	IGPublish(0, "message12");
	IGPublish(0, "message12");
	IGPublish(0, "message12"); //buffer is full, error message
}