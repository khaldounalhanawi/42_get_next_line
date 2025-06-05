#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h> // for open

int main()
{
    char	*final_line;

    int	fd = open ("tst.txt", O_RDONLY);
    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);  

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line);      

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line); 

    final_line = get_next_line(fd);
    printf(">%s<\n\n", final_line); 
	return (0);
}


/* char	*ft_strdup(const char *s1)
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
int	main()
{
	char *p;
	char *j;
    char *temp;

	int ss = 20;

	//p = malloc (ss);
	j = malloc (ss);

    temp = "abcdefghijlmn";
    p = ft_strdup(temp);
    p[0] = '\n';
    p[1] = '\n';
    //j = "ff";


	trim_assign (&p, &j);
    
	printf("p = >%s<\n\n", p);
	printf("j = >%s<\n\n", j);
    
    trim_assign (&j, &p);

    printf("p = >%s<\n\n", j);
	printf("j = >%s<\n\n", p);
} */
/*
char	*ft_strdup2(const char *s1)
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

void    extract2(char **line, char **rest)
{
    char    *n_line;
    char    *temp;
    char 	*temp2;

    if (!ft_strchr (*line, '\n') || !**line)
        return;
    n_line = *line;
    if (*ft_strchr(n_line, '\n') == n_line[ft_strlen(n_line) - 1])
    {
        printf("correct\n");
        *rest = NULL;
        n_line[ft_strlen(n_line) - 1] = '\0';
        temp = ft_strdup2 (n_line);
        free (*line);
        *line = temp;
    }
    else 
    {
        temp2 = ft_strchr(n_line, '\n') + 1;
        free (*rest);
        *rest = ft_strdup2 (temp2);
        n_line[ft_strchr(n_line, '\n') - n_line] = '\0';
        temp = ft_strdup2 (*line);
        free (*line);
        *line = temp;
    }
}

int main ()
{
	char *a;
	char *b;

	a = ft_strdup2 ("abcd");
	a [3] = '\n';
	b = ft_strdup2("1234");

	extract2 (&a, &b);
	printf("a: %s\n", a);
	printf("b: %s\n", b);




}*/