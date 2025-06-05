#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include <stdlib.h>
#include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
// void     trim_assign(char **full, char **rest);
size_t  ft_strlen(const char *str);


#endif