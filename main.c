#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
    if (ac != 4)
    {
        printf("put in 3 different files please! :), love you!");
        return (1);
    }
    int fd1 = open(av[1], O_RDONLY);
    int fd2 = open(av[2], O_RDONLY);
    int fd3 = open(av[3], O_RDONLY);

    char **line1 = NULL;
    char **line2 = NULL;
    char **line3 = NULL;

    int i = 0;

    while (i < 100)
    {
        if (i % 6 == 0)
        {
            (get_next_line(fd1, line1));
            printf("fd1, line1: {%s}\n", *line1);
            free(line1);
        }
        if (i % 6 == 1)
        {
            (get_next_line(fd2, line2));
            printf("fd2, line2: {%s}\n", *line2);
            free(line2);
        }
        if (i % 6 == 2)
        {
            (get_next_line(fd3, line3));
            printf("fd3, line3: {%s}\n", *line3);
            free(line3);
        }
        if (i % 6 == 3)
        {
            (get_next_line(fd1, line3));
            printf("fd1, line3: {%s}\n", *line3);
            free(line3);
        }
        if (i % 6 == 4)
        {
            (get_next_line(fd2, line1));
            printf("fd2, line1: {%s}\n", *line1);
            free(line1);
        }
        if (i % 6 == 5)
        {
            (get_next_line(fd3, line2));
            printf("fd3, line2: {%s}\n", *line2);
            free(line2);
        }
    }

    return 0;
}
