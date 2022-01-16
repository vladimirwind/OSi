#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <signal.h>



int seconds = 1000000;

void 	set_led(int condition)
{
	if (condition == 0)
		printf("0\n");
	else
		printf("1\n");
}





int flag = 0;


int	main(int argc, char **argv)
{	if (argc!=1)
		seconds = atoi(argv[1])*1000000;
	int	condition = 0;
	
	
	
	while (1)
	{
		set_led(condition);
		condition = (condition + 1)%2;
		usleep(seconds);
	}
		
	return (0);
}
