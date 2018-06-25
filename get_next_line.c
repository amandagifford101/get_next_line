/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static t_line	*init_line(int fd)
{
	t_line	*bam;

	bam = ft_memalloc(sizeof(t_line));
	bam->fd = fd;
	bam->ret = BUFF_SIZE;
	bam->lo = ft_memalloc(0);
	bam->temp = ft_memalloc(0);
	bam->done = 0;
	return (bam);
}

static int		check_leftovers(t_line *bam, char **line)
{
	int		i;

	i = 0;

	while (bam && bam->lo && bam->lo[i] != '\0')
	{
		if (bam->lo[i] == '\n')
		{	
			*line = ft_strndup(bam->lo, i);
			bam->temp = bam->lo;					//not freeing temp for some reason
			bam->lo = ft_strndup(bam->lo + i + 1,   //need to free bam->lo on last time through... 
				ft_strlen(bam->lo) + 1 - i);
			free(bam->temp);
			return (1);
		}
		i++;
	}
	if (bam->ret == 0)
	{
		*line = bam->lo[i] == '\n' ? ft_strndup(bam->lo, i - 1) : ft_strndup(bam->lo, i);
		free(bam->lo);
		bam->lo = ft_memalloc(1);			//fix bam->done shit.
		bam->done = 1;
		return (1);
	}
	return (0);
}

static t_line	*check_list(t_list *head, const int fd)
{
	t_list			*bam;
	t_line			*GNL;

	bam = head;
	while (bam && (GNL = (t_line*)bam->content) && GNL->fd != fd)
		bam = bam->next;
	if (!bam && (bam = ft_lstnew(NULL, sizeof(t_line))))
	{
		bam->content = init_line(fd);
		ft_lstadd(&head, bam);
	}
	GNL = (t_line*)bam->content;
	return (GNL);
}
	
int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_line			*GNL;

	if (fd < 0 || line == NULL) 	//closed file descriptor	
		return (-1);
	if (!head)
	{
		head = ft_lstnew(NULL, sizeof(t_line));
		head->content = init_line(fd);
	}
	GNL = check_list(head, fd);
	if (GNL->ret == 0 && GNL->done)
		return (0);
	if (GNL && !(check_leftovers(GNL, line)))
	{
		while ((GNL->ret = read(fd, GNL->buff, BUFF_SIZE)) > 0)
		{
			if (GNL->ret < BUFF_SIZE)
				GNL->ret = 0;
			GNL->temp = GNL->lo;
			GNL->lo = ft_strjoin(GNL->lo, GNL->buff);		//strjoin that frees
			ft_bzero(GNL->buff, BUFF_SIZE + 1);
			free(GNL->temp);
			if (GNL && check_leftovers(GNL, line))
				break;
		}
	}
	return (1);
}
