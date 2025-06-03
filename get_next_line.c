#include "get_next_line.h"

#include <stdio.h>
#include <unistd.h>

void trim_assign(char **full, char **rest);

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char	*get_next_line(int fd)
{
    int             letters_read;
    char            *buf;
    char            *full;
    static char     *rest;

    if (fd < 0)
    	return (NULL);

    // prep for full and rest joining from earlier calls for LEFTOVERs
    full = "";
    if (!rest)
        rest = "";
    full = ft_strjoin(full, rest);

    // new BUFFER
    buf = malloc ((BUFFER_SIZE + 1) * sizeof (char));
    if (!buf)
    	return (NULL);

    // Loop through, and look for \n
    while (!ft_strchr (buf, '\n'))
    {
        letters_read = read (fd, buf, BUFFER_SIZE);
        if (letters_read > 0)
        {
            if (letters_read < BUFFER_SIZE)
            {
                buf[letters_read] = '\0';
                full = ft_strjoin(full, buf);
                break;
            }
        	full = ft_strjoin(full, buf);
        }
        else
            return (NULL); 
    }

    // after \n is found, 1- TRIM it and 2- send to REST as leftover
    trim_assign(&full, &rest);

    // return full
	return (full);
}

void trim_assign(char **full, char **rest)
{
    int i;
    int b;
    char    *right;
    char    *left;

    // checks if pointers are caput, left[0] = '\0' or rest = '\0' or left has no \n
    if (!full || !rest || !(*full) || !(*rest) || !ft_strchr (*full, '\n'))  
        return ;

    left = *full;
    i = 0;

    // length of left until \n
    while (left[i] != '\0' && left[i] != '\n')
        i++;

    // puts an end to left instead of \n
    left[i] = '\0';

    // move one to start new B line
    i++;

    // get length for B line
    b = ft_strlen(&left[i]);

    // malloc space for B line
    right = malloc (b * sizeof(char));
    if (!right)
        return;

    // copy left from i point on left to right
    b = 0;
    while (left[i])
    { 
        right[b] = left[i];
        i++;
        b++;
    }
    right[b] = '\0';

    // set pointer to right
    *rest = right;
}






