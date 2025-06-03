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
    int     loop;
    int             letters_read;
    char            *buf;
    char            *full;
    static char     *rest;

    if (fd < 0)
    	return (NULL);

    // prepare for full and rest joining from earlier calls for LEFTOVERs
    full = "";
    if (!rest)
        rest = "";
    full = ft_strjoin(full, rest);

    // new BUFFER
    buf = malloc ((BUFFER_SIZE + 1) * sizeof (char));
    if (!buf)
    	return (NULL);

    // read the file into BUF
    loop = 0;
    // printf ("kaka");
    while (!loop)
    {
        letters_read = read (fd, buf, BUFFER_SIZE);         // read into BUF 

        if (letters_read && ft_strchr (buf, '\n'))          // 1- BUF is 5 and has \n 
        {
            full = ft_strjoin (full, buf);
            trim_assign(&full, &rest);
            break;
        }
        else if (letters_read)
        {
            full = ft_strjoin (full, buf);                      // NORMAL = joing full to buf
        }
        else if (*full && !letters_read)         // 2- BUF = 0 but FULL has "ab"
        {
            rest = NULL;
            free (rest);
            return (full);
        }
        else                           // 3- BUF = 0 >>> return NULL
        {    
            rest = NULL;
            free (rest);
            free (full);
            free (buf);
            return (NULL);
        }    
    }
    free (buf);
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






