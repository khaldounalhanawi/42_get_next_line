#include "get_next_line.h"


#include <stdio.h>
#include <fcntl.h> // for open

int main()
{
    char	*final_line;

    int	fd = open ("giant_line.txt", O_RDONLY);
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


// int    sticher(char *buf, char **rest);
// int main ()
// {
// 	char *a;
// 	char *b;

// 	a = ft_strdup("123456");
//     a[4] = '\n';
//     b = ft_strdup("");
// 	sticher(b, &a);
// 	printf("return: >%s<\n", a);

// }


// ******* extract test
// char *extract(char **rest);

// int main ()
// {
// 	char *a;
// 	char *b;

// 	a = ft_strdup("  ab");
// 	a [0] = '\n';
//     a [1] = '\n';
	
// 	printf("return: >%s<\n", extract(&a));
// 	printf("rest:   >%s<\n", a);
// }