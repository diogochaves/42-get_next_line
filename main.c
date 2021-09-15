#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <fcntl.h> // OPEN FILES

int	main(void)
{
	int	fd;
	char *line_content;

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
	printf("buffer size: %d\n", BUFFER_SIZE);

	printf("\n[START]\n");
	line_content = get_next_line(fd);
	printf("%s", line_content);
	line_content = get_next_line(fd);
	printf("%s", line_content);

	printf("\n[END]\n");
	return (0);
}
