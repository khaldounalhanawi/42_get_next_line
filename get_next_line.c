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

void    extract(char **full, char **rest);

char	*get_next_line(int fd)
{
    static char    *rest;
    char           *buf;
    char           *full;
    int            read_lines;
    int test=0;

    buf = malloc ((BUFFER_SIZE + 1) * sizeof (char));
    full = ft_strdup ("");
    if (!rest)
        rest = ft_strdup ("");

    if (ft_strchr (rest, '\n'))
    {
        free (full);
        extract(&full, &rest);
        return (full);
    }

    full = ft_strjoin(full, rest);


    read_lines = read (fd, buf, BUFFER_SIZE);
    buf[read_lines] = '\0';
    if (!read_lines)
    {
        if (*rest && ft_strchr (rest, '\n')) 
        {
            free (full);
            extract(&full, &rest);
            return (full);
        }
        if (*rest && !ft_strchr (rest, '\n'))
            return (rest);
        return (NULL);
    }
    full = ft_strjoin(full, buf);
    while (read_lines && !ft_strchr (buf, '\n') && test < 50)
    {
        read_lines = read (fd, buf, BUFFER_SIZE);
        if (!ft_strchr (buf, '\n'))
        {

            full = ft_strjoin(full, buf);
        }
        test++;

    }
    // full = ft_strjoin(full, buf);
    extract(&full, &buf);
    free (rest);
    rest = ft_strdup(buf);
    free (buf);
    return (full);
}

// extract the full and rest 

void    extract(char **line, char **rest)
{
    char    *n_line;
    char    *temp;
    char    *temp2;

    if (!ft_strchr (*line, '\n') || !**line)
        return;
    n_line = *line;
    if (*ft_strchr(n_line, '\n') == n_line[ft_strlen(n_line) - 1])
    {
        n_line[ft_strlen(n_line) - 1] = '\0';
        temp = ft_strdup (n_line);
        free (*line);
        *line = temp;
    }
    else 
    {
        temp2 = ft_strchr(n_line, '\n') + 1;
        free (*rest);
        *rest = ft_strdup (temp2);
        n_line[ft_strchr(n_line, '\n') - n_line] = '\0';
        temp = ft_strdup (*line);
        free (*line);
        *line = temp;
    }
}
/*

    temp = ft_strdup (prest);
    temp[ft_strchr (temp, '\n') - temp] = '\0';
    new = ft_strdup (temp);
    free (temp);

    temp_full = ft_strjoin(*full, new);
    free(*full);
    *full = temp_full;

    temp2 = ft_strdup(ft_strchr (prest, '\n') + 1);
    free (prest);
    *rest = temp2;*/