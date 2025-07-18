/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:00:00 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/06/11 16:02:57 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*searcher(char **rest, char **temp);
char	*extract(char **rest);

char	*free_all(char **full, char **rest)
{
	if (full && *full)
	{
		free (*full);
		*full = NULL;
	}
	if (rest && *rest)
	{
		free (*rest);
		*rest = NULL;
	}
	return (NULL);
}

int	sticher(char *buf, char **rest)
{
	char	*temp;

	temp = ft_strjoin (*rest, buf);
	if (!temp)
		return (-1);
	free (*rest);
	*rest = NULL;
	*rest = temp;
	return (1);
}

char	*looper(int fd, char **rest)
{
	char	*buf;
	int		letters;

	buf = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (!buf)
		return (free_all(rest, NULL));
	letters = read (fd, buf, BUFFER_SIZE);
	while (letters > 0)
	{
		buf[letters] = '\0';
		if (sticher (buf, rest) == -1)
			return (free_all (rest, &buf));
		if (ft_strchr (buf, '\n'))
			break ;
		letters = read (fd, buf, BUFFER_SIZE);
	}
	if ((letters == 0 && **rest == '\0') || (letters < 0))
		return (free_all(rest, &buf));
	free_all(NULL, &buf);
	return (extract (rest));
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!rest[fd])
	{
		rest[fd] = ft_strdup ("");
		if (!rest[fd])
			return (NULL);
	}
	return (looper(fd, &rest[fd]));
}

char	*extract(char **rest)
{
	char	*temp;

	if (!rest)
		return (NULL);
	if (!ft_strchr(*rest, '\n'))
	{
		temp = ft_strdup (*rest);
		if (!temp)
			return (free_all(rest, NULL));
		free_all(rest, NULL);
		return (temp);
	}
	temp = ft_strdup (ft_strchr(*rest, '\n') + 1);
	if (!temp)
		return (free_all(rest, NULL));
	return (searcher(rest, &temp));
}
