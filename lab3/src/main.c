#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <signal.h>

int	flag;

void	empty_func(int arg)
{
}



void	help(void)
{
	printf("This prog outputs to the console 0 and 1 with period n seconds\n");
}


int	main(int argc, char **argv)
{
	signal(SIGUSR1, empty_func);
	int	seconds=1;
	
	if (argc == 2 && !strncmp("help", argv[1], 4))
	{
		help();
		return (0);
	}
	
	if (argc!=1)
		seconds = atoi(argv[1]);
	char open[20] = "./sub ";
	char buffer[10];
	sprintf(buffer, "%d", seconds);
	strcat(open, buffer);
	strcat(open, "\n");
	FILE *pBLINKER = popen(open, "w");
	
	int n;
	while (1)
	{
		scanf("%d", &seconds);
		if (seconds <= 0)
			break;
		fprintf(pBLINKER, "%d\n", seconds);
		fflush(pBLINKER);
		kill(0, SIGUSR1);
	}
	
	pclose(pBLINKER);
	
	
	return (0);
}
