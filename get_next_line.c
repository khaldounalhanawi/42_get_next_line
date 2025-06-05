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

void    extract(char **full, char **rest);

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
    char           *full;
    static char    *rest;
    char           *buf;
    int            read_lines;
    char           *temp;
    int loop;

    full = ft_strdup ("");
    if (!rest)
        rest = ft_strdup ("");
    
    temp = ft_strjoin(full, rest);
    free (full);
    zero_buf (rest);
    full = temp;

    if (ft_strchr (full, '\n'))
    {
        extract(&full, &rest);
        return (full);
    }

    else if (*full == '\n')
    {
        // free rest??
        return ("");
    }

    buf = malloc ((BUFFER_SIZE + 1) * sizeof (char));
    if (!buf)
        return (NULL);
    loop = 1;
    while (loop)
    {    
        read_lines = read (fd, buf, BUFFER_SIZE);
        buf[read_lines] = '\0';
        
        if (!read_lines)
        {
            free (rest);
            rest = NULL;
            free (buf);
            if (!*full)
            return (NULL);
            if (*full != '\0')
            return (full);
        }
        
        if (read_lines < BUFFER_SIZE)
        {
            temp = ft_strjoin(full, buf);
            free (full);
            full = temp;
            if (!ft_strchr (buf, '\n'))
                return (full);
             else
            {
                extract(&full, &rest);
                rest = ft_strdup("\n");
                return (full);
            }
        }
        
        if (ft_strchr (buf, '\n'))
        {
            temp = ft_strjoin(full, buf);
            free (full);
            full = temp;
            break ;
        }

        temp = ft_strjoin(full, buf);
        free (full);
        full = temp;
        zero_buf (buf);
    }

    extract (&full, &rest);
    free (buf);
    return (full);
}

void    extract(char **line, char **rest)
{
    char    *n_line;
    char    *temp;
    char    *temp2;

    if (!ft_strchr (*line, '\n') || !**line)
    return ;

    n_line = *line;
    temp2 = ft_strchr(n_line, '\n') + 1;
    free (*rest);
    *rest = ft_strdup (temp2);
    n_line[ft_strchr(n_line, '\n') - n_line] = '\0';
    temp = ft_strdup (*line);
    free (*line);
    *line = temp;
}

/* void    extract(char **line, char **rest)
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
} */
