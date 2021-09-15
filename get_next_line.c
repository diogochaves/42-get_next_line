#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static void	*file;
	static char	*line;

	if (!line)
	{
		file = malloc(sizeof(char) * BUFFER_SIZE);
	}
	read(fd, file, BUFFER_SIZE);
	line = file;

	return (line);
}
