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
 
// 1- read using buffer, and then apply stringlcat until \n\n is reached.
// 2- store the left over after \n\n in a static temp array
// 3- print string out.
// 4- next time it gets called, start with the leftover and then do step 1 + 2