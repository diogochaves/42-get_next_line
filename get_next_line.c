#include "get_next_line.h"

char	*get_line(int fd, char **buffer);
char	*set_buffer(char **buffer, char *file, int digits);
char	*get_buffer_line(char **buffer, char *eol);

char	*get_next_line(int fd)
{
	static char	**buffer;
	char		*line;

	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (NULL);
		*buffer = malloc(sizeof(char));
		if (!*buffer)
			return (NULL);
	}
	line = get_line(fd, buffer);
	if (!line)
		free(buffer);
	return (line);
}

char	*get_line(int fd, char **buffer)
{
	char	*eol;
	char	*file;
	char	*line;
	int		digits;

	file = malloc(BUFFER_SIZE);
	eol = ft_strchr(*buffer, '\n');
	while (!eol)
	{
		digits = read(fd, file, BUFFER_SIZE);
		if (!digits)
			return (NULL); // EOF - ToDo: FREE ptr - WRONG
		*buffer = set_buffer(buffer, file, digits);
		eol = ft_strchr(*buffer, '\n');
	}
	line = get_buffer_line(buffer, eol);
	return (line);
}

char	*set_buffer(char **buffer, char *file, int digits)
{
	char	*new_buffer;
	int		buffer_len;

	buffer_len = ft_strlen(*buffer);
	new_buffer = malloc(buffer_len + digits + 1);
	ft_memcpy(new_buffer, *buffer, buffer_len);
	ft_memcpy((new_buffer + buffer_len), file, digits);
	new_buffer[buffer_len + digits] = '\0';
	free(*buffer);
	return (new_buffer);
}

char	*get_buffer_line(char **buffer, char *eol)
{
	char	*temp;
	char	*new_buffer;
	int		new_buffer_len;

	temp = *buffer;
	new_buffer_len = ft_strlen(*buffer) - (eol - *buffer);
	new_buffer = malloc(new_buffer_len + 1);
	// copy from buffer to new
	new_buffer = ft_memcpy(new_buffer, eol + 1, new_buffer_len);
	new_buffer[new_buffer_len] = '\0';
	*(eol + 1) = '\0';
	*buffer = new_buffer;
	return (temp);
}
