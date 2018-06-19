#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
// 	int fd;
// 	char *line;
// //	int i = 0;

	if (ac != 2)
		printf("put in one file damnitt");
	
// 	if ((fd = open(av[1], O_RDONLY)) == -1)
// 		return (-1);
// 	printf("memory of line is {%p}\n", &line);
// 	while(get_next_line(fd, &line) > 0)
// 	{
// //		printf("line %d: {%s}\n", i++, line);
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);



	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);

	return (0);
}
