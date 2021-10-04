#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Get the next line object
 *
 * @param fd File descriptor to read from
 * @return Read line: correct behavior || NULL: nothing else to read or an
 * error occurred
 */
char	*get_next_line(int fd);

/**
 * @brief Copies N bytes from memory area SRC to memory area DEST. The memory
 * areas must not overlap.
 *
 * @param dest The pointer to the memory area DEST.
 * @param src The pointer to the memory area SCR.
 * @param n The quantity of bytes to copy.
 * @return A pointer to the memory area DEST.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Calculates the length of the string pointed to by S, excluding the
 * terminating null byte ('\0').
 *
 * @param s The string to count.
 * @return The lenght of the string.
 */
size_t	ft_strlen(const char *s);

#endif
