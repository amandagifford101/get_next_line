#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft/libft.h"
# define IS_LEFT(x) (x ? (1) : (0))

#define BUFF_SIZE 16
typedef struct		s_line
{
	int				fd;
	char			*temp;
	char			*lo;
	char			buff[BUFF_SIZE + 1];
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
