/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:14:31 by dchaves-          #+#    #+#             */
/*   Updated: 2021/10/17 15:19:47 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/**
 * @brief Get the next line object
 *
 * @param fd File descriptor to read from
 * @return Read line: correct behavior || NULL: nothing else to read or an
 * error occurred
 */
char	*get_next_line(int fd);

/**
 * @brief Calculates the length of the string pointed to by S, excluding the
 * terminating null byte ('\0').
 *
 * @param s The string to count.
 * @return The lenght of the string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Locate the first occurrence of character in string.
 *
 * @param s The string to search.
 * @param c The char to find.
 * @return A pointer to the matched character or NULL if the character is not
 * found.
 */
char	*ft_strchr(const char *s, int c);

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
 * @brief Duplicates the string S.
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string. It returns NULL if insufficient
 * memory was available.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Appends the NUL-terminated string SRC to the end of DST. It will
 * append at most (SIZE - strlen(DST) - 1 byte), NUL-terminating the result.
 *
 * @param dst The pointer to the memory area DST.
 * @param src The pointer to the memory area SCR.
 * @param size The quantity of bytes to append.
 * @return The total length of the string it tried to create (the initial
 * length of DST plus the length of SRC).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Allocates and returns a new string, which is the result of the
 * concatenation of S1 and S2.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

#endif
