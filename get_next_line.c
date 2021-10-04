#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*file;
	char		*line;
	size_t			i;
	size_t			digits;

	i = 0;
	if (buffer)
	{
		while (i < ft_strlen(buffer))
		{
			if (buffer[i] == '\n')
				break ;
			i++;
		}
		if (i < ft_strlen(buffer) - 1)
		{
			line = malloc(i + 2);
			ft_memcpy(line, buffer, i + 1);
			line[i + 1] = '\0';

			if (i < ft_strlen(buffer) - 1)
			{
				buffer = malloc(ft_strlen(buffer) - i + 1);
				ft_memcpy(buffer, file + i + 1, digits - i);
				buffer[digits - i + 1] = '\0';
			}

			return (line);
		}
	}

	file = malloc(BUFFER_SIZE);
	digits = read(fd, file, BUFFER_SIZE);
	buffer = 0;
	if (!digits)
		return (NULL);
	while (i < BUFFER_SIZE && i < digits)
	{
		if (file[i] == '\n')
			break ;
		i++;
	}
	line = malloc(i + 2);
	ft_memcpy(line, file, i + 1);
	line[i + 1] = '\0';

	if (i < digits - 1)
	{
		buffer = malloc(digits - i + 1);
		ft_memcpy(buffer, file + i + 1, digits - i);
		buffer[digits - i + 1] = '\0';
	}

	free(file);
	return (line);
}

char	*get_next_line_old(int fd)
{
	static char	*buffer;
	char		*file;
	char		*line;
	int			b_size;
	int			i;
	int			count;

	file = 0;
	line = 0;
	b_size = 0;

	if (buffer)
	{
		/*
--- Iterate BUFFER, search for a new line '\n'
--- [newline?]
----- MALLOC var LINE(sizeof BUFFER until "\n"): copy content from BUFFER to
      LINE
----- Copy content from BUFFER (position (newline + 1) to sizeof(BUFFER)) to a
      new var (TEMP)
----- copy temp to new buffer
----- return LINE
--- [no newline?]
----- MALLOC var FILE(BUFFER_SIZE + len(BUFFER) (+ 1 [for the '\0'] ??))
----- Copy from BUFFER to FILE.
*/
	}
	else
	{
		file = malloc(sizeof(char) * BUFFER_SIZE);
		b_size = 0;
	}

	count = read(fd, file, BUFFER_SIZE);

	i = 0;
	while (i < BUFFER_SIZE && i < count)
	{
		if (file[i] == '\n' || file[i] == '\0')
			break;
		i++;
	}
	if (file[i] == '\n')
	{
		line = malloc(sizeof(char) * (i + 2));
		ft_memcpy(line, file, i + 1);
		line[i + 1] = '\0';
		/*
--- MALLOC var LINE(sizeof FILE until "\n"): copy content from FILE to LINE
--- Copy content from FILE (position (newline + 1) to sizeof(FILE)) to BUFFER
--- return LINE
*/
	}
	else if (file[i] == '\0')
	{
		line = malloc(sizeof(char) * (i + 2));
		ft_memcpy(line, file, i + 1);
		line[i + 1] = '\0';
/*
--- MALLOC var LINE(sizeof FILE until "EOF"): copy content from FILE to LINE
--- return LINE
*/
	}
	else
	{
/*
--- copy content from FILE to BUFFER ( BUFFER += file)
--- start again
*/
	}

	return (line);
}


