#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h> // for open

int main()
{
    char	*final_line;

    int	fd = open ("tst.txt", O_RDONLY);
    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);  

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line);      

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line); 

    final_line = get_next_line(fd);
    printf(">%s<\n", final_line); 
	return (0);
}

/*int	main()
{
	char *p;
	char *j;

	int ss = 5;

	p = malloc (ss);
	j = malloc (ss);
	while (ss--)
	{
		p[ss] = 'a';
		j[ss] = 'b';
	}
	p [2] = '\n';
	p [3] = 'c';
	p [4] = 'd';


	trim_assign (&p, &j);

	printf("p = >%s<\n", p);
	printf("j = >%s<\n", j);
}*/

// 1- read using buffer, and then apply stringlcat until \n is reached.
// 2- store the left over after \n in a static temp array
// 3- print string out.
// 4- next time it gets called, start with the leftover and then do step 1 + 2