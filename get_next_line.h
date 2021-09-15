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

#endif
