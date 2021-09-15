#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("loren.txt", O_RDONLY);

	if (fd  == -1)
	{
		printf("file opening failed\n");
		exit(0);
	}
	else
	{
		printf("file opening successful\n");
		printf("file descriptor: %d\n", fd);
	}

	printf("%d\n", BUFFER_SIZE);
	return (0);
}
