/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:14:07 by dchaves-          #+#    #+#             */
/*   Updated: 2021/10/17 15:59:54 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **buffer);
char	*set_buffer(char *buffer, char *file);
char	*read_buffer(char **buffer, char *eol, int size);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	line = read_line(fd, &buffer);
	return (line);
}

char	*read_line(int fd, char **buffer)
{
	char	*file;
	char	*line;
	int		size;

	file = malloc(BUFFER_SIZE + 1);
	size = 1;
	while (!ft_strchr(*buffer, '\n') && size > 0)
	{
		size = read(fd, file, BUFFER_SIZE);
		if (size > 0)
		{
			file[size] = '\0';
			*buffer = set_buffer(*buffer, file);
		}
	}
	line = read_buffer(buffer, ft_strchr(*buffer, '\n'), size);
	free(file);
	return (line);
}

char	*set_buffer(char *buffer, char *file)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(buffer, file);
	free(buffer);
	buffer = NULL;
	return (new_buffer);
}

char	*read_buffer(char **buffer, char *eol, int size)
{
	char	*line;

	line = *buffer;
	if (size > 0)
	{
		*buffer = ft_strdup(eol + 1);
		*(eol + 1) = '\0';
	}
	else
	{
		if (ft_strlen(*buffer) == 0)
		{
			free(*buffer);
			line = NULL;
		}
		*buffer = NULL;
	}
	return (line);
}
