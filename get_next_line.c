#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*file;
	static int	pos;
	int	i;

	pos = 0;
	// first call: allocate buffer
	if (!file)
	{
		file = malloc(sizeof(char) * BUFFER_SIZE + 1);
	}
	if (pos)
	{

	}
	else
	{
		read(fd, file, BUFFER_SIZE);
	}

	// try to find a new line "\n"
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (file[i] == '\n')
		{
			file[i + 1] = '\0';
			pos = i + i;
			break ;
		}
		i++;
	}

	return (file);
}


