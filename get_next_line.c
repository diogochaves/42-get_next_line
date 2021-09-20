#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*file;
	static int	pos;
	int	i;


/*
+ static *buffer;

- [BUFFER?]
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
- Read from FD into FILE (pass *(FILE + len(BUFFER)) as pointer location)
- Iterate FILE, search for a new line '\n'
- [newline]
--- MALLOC var LINE(sizeof FILE until "\n"): copy content from FILE to LINE
--- Copy content from FILE (position (newline + 1) to sizeof(FILE)) to BUFFER
--- return LINE
- [no newline?]
--- copy content from FILE to BUFFER ( BUFFER += file)
--- start again
- [EOF?]
--- MALLOC var LINE(sizeof FILE until "EOF"): copy content from FILE to LINE
--- return LINE
*/


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


