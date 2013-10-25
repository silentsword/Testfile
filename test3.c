#include <stdio.h>
#include <unisted.h>
#include <sys/wait.h>

int main()
{
    if(IGCreate(1) == 0)
		printf("Failed to create a group.\n");
	IGSubscriber(1);
	IGSubscribe(1); //empty buffer, error message
}