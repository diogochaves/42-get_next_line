#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*file;
	char		*line;
	int			b_size;
	int			i;
	int			read;

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

	read = read(fd, (file + b_size), BUFFER_SIZE);

	i = 0;
	while (i < BUFFER_SIZE && i < read)
	{
		if (file[i] == '\n' || file[i] == '\0')
			break;
		i++;
	}
	if (file[i] == '\n')
	{
		line = malloc(sizeof(char) * (i + 2));

		/*
--- MALLOC var LINE(sizeof FILE until "\n"): copy content from FILE to LINE
--- Copy content from FILE (position (newline + 1) to sizeof(FILE)) to BUFFER
--- return LINE
*/
	}
	else if (file[i] == '\0')
	{
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


