#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>


char    *extract(char **rest);

// char *free_all(char **full, char **rest)
// {
//     if (*full)
//     {
//         free (*full);
//         *full = NULL;
//     }
//     if (*rest)
//     {
//         free (*rest);
//         *rest = NULL;
//     }
//     return (NULL);
// }

char *free_all(char **full, char **rest)
{
    return (NULL);
}

int    sticher(char *buf, char **rest)
{
    char   *temp;

    temp = ft_strjoin (*rest, buf);
    if (!temp)
        return (-1);
    free (*rest);
    *rest = NULL;
    *rest = temp;  
    return (1);
}

char    *looper(int fd, char **rest)
{
    char    *buf;
    int     letters;

    buf = malloc ((BUFFER_SIZE + 1)* sizeof (char));
    if (!buf)
        return (free_all(rest, NULL));
    while ((letters = read (fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[letters] = '\0';
        if (sticher (buf, rest) == -1)
        {
            free_all (rest, &buf);
            return (NULL);
        }
        if (ft_strchr (buf, '\n'))
            break;
    }
    if ((letters == 0 && **rest == '\0') || (letters < 0))
        return (free_all(rest, &buf));
    free_all(NULL,&buf);
    return (extract (rest));
}


char	*get_next_line(int fd)
{
    static char    *rest;

    if (fd < 0 || fd > 10024)
        return (NULL);
    if (!rest)
    {
        rest = ft_strdup ("");
        if (!rest)
            return (NULL);
    }
    return (looper(fd ,&rest));
}

char *extract(char **rest)
{
    char    *clean;
    char    *income;
    char    *record;
    char    *temp;
    int     new_len;

    if (!rest)
        return (NULL);
    if (!ft_strchr(*rest, '\n'))
    {
        temp = ft_strdup (*rest);
        if (!temp)
            return (free_all(rest)); // free rest as well
        free (*rest);
        rest = NULL;
        return (temp);
    }
    temp = ft_strdup (ft_strchr(*rest, '\n') + 1);
    if (!temp)
        return (free_all(rest));
    income = *rest;
    new_len = ft_strchr(income, '\n') - income + 1;
    clean = malloc ((new_len + 1) * sizeof (char));
    record = clean;
    while (*income != '\n')
        *clean ++ = *income++;
    *clean ++ = *income++;
    free (*rest);
    *rest = NULL;
    *rest = temp;
    return (record);
}
