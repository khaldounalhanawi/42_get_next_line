#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*record;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	p = malloc((len + 1) * (size_t) sizeof(char));
	if (!p)
		return (NULL);
	record = p;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (record);
}

void zero_buf(char *buf)
{
    int     i;

    i = 0;
    while (i < BUFFER_SIZE)
    {
        buf[i] = 0;
        i++;
    }
}

char	*get_next_line(int fd)
{
    char           *buf;
    static char    *rest;
    char           *full;
    char           *change;
    int            read_lines;

    buf = malloc (BUFFER_SIZE * sizeof (char));
    full = "";
    if (!rest)
        rest = "";
    full = ft_strjoin(full, rest);
    read_lines = 1;
    while (read_lines)
    {
        read_lines = read (fd, buf, BUFFER_SIZE);
        if (!read_lines && *full)
        {
            rest = NULL;
            break;

        }
        if (!read_lines) // in case end of file was reached
        {
            free (buf);
            return (NULL);
        }
        full = ft_strjoin (full, buf);
        if (read_lines < BUFFER_SIZE) // 1- in case end of file was inside buffer
        {
            full[ft_strlen(full) - (BUFFER_SIZE - read_lines)]= '\0';
            break;
        }
        if (read_lines && ft_strchr (buf, '\n'))
        {
            rest = ft_strdup(ft_strchr (full, '\n'));
            rest++;
            //printf ("%ld", (ft_strchr (full, '\n') - full));
            full [(ft_strchr (full, '\n') - full)] = '\0';
            break;
        }
         zero_buf (buf);
    }


       
    
    free (buf);
    return (full);

}

void trim_assign(char **full, char **rest)
{
    
}
