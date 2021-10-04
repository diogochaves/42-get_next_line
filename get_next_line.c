#include "get_next_line.h"

char	*get_line(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;

	return (get_line(fd, buffer));
}

char	*get_line(int fd, char *buffer)
{
	char	*file;
	char	*line;
	size_t	i;
	size_t	digits;

	i = 0;
	if (buffer)
	{
		digits = ft_strlen(buffer);
		while (i < digits)
		{
			if (buffer[i] == '\n')
				break ;
			i++;
		}
		if (i < digits - 1)
		{
			line = malloc(i + 2);
			ft_memmove(line, buffer, i + 1);
			line[i + 1] = '\0';

			if (i < digits - 1)
			{
				ft_memmove(buffer, buffer + i + 1, digits - i);
				buffer[digits - i + 1] = '\0';
			}

			return (line);
		}
	}
	i = 0;
	file = malloc(BUFFER_SIZE);
	digits = read(fd, file, BUFFER_SIZE);
	if (!digits)
		return (NULL);
	while (i < BUFFER_SIZE && i < digits)
	{
		if (file[i] == '\n')
			break ;
		i++;
	}
	if (buffer)
	{
		if (i == digits)
		{
			buffer = malloc(i + 1);
			ft_memmove(buffer, file, i);
			buffer[i] = '\0';
			//call getnetline again
		}
		else
		{
			line = malloc(i + ft_strlen(buffer) + 2);
			ft_memmove(line, buffer, ft_strlen(buffer));
			ft_memmove(line + ft_strlen(buffer), file, i + 1);
			line[i + ft_strlen(buffer) + 1] = '\0';
		}
	}
	else
	{
		if (i == digits)
		{
			buffer = malloc(i + 1);
			ft_memmove(buffer, file, i);
			buffer[i] = '\0';
			//call getnetline again
		}
		else
		{
			line = malloc(i + 2);
			ft_memmove(line, file, i + 1);
			line[i + 1] = '\0';
		}
	}


	if (i < digits - 1)
	{
		buffer = malloc(digits - i + 1);
		ft_memmove(buffer, file + i + 1, digits - i);
		buffer[digits - i + 1] = '\0';
	}

	free(file);
	return (line);
}
