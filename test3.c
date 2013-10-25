#include <stdio.h>
#include <unisted.h>
#include <sys/wait.h>

int main()
{
    if(IGCreate(0) == 0)
		printf("Failed to create a group.\n");
	IGSubscriber(0);
	IGSubscribe(0); //empty buffer, error message
}