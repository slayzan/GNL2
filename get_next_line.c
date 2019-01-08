/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:29:50 by humarque          #+#    #+#             */
/*   Updated: 2019/01/08 13:31:49 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_struct	*ft_lstcreate(const int fd, t_struct **list)
{
	t_struct *new;
	
	if(!(new = ft_memalloc(sizeof(t_struct))))
	{
		free(new);
		return (NULL);
	}
	new->fd = fd;
	if(!(new->str = ft_strnew(0)))
	{
		free(new->str);
		free(new);
		return (NULL);
	}
	new->next = *list;
	return (new);
}

t_struct *ft_findfd(t_struct **list, const int fd)
{
	t_struct *new;
	
	new = *list;
	while (new)
	{
		if (new->fd == fd)
			return (new);
		new = new->next;
	}
	if(!(new = ft_lstcreate(fd, list)))
		return (NULL);
	return (new);
}


int		get_next_line(const int fd, char **line)
{
	static t_struct *list = NULL;
	
	list = ft_findfd(&list, fd);
	return (1);
}


int main(int argc, char **argv)
{
	int fd;
	int fd2;
	int res;
	char *line;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if ( fd == -1)
	{
		close(fd);
		return (-1);
	}
	res = get_next_line(fd, &line);
	printf("%d\n", res);
	res = get_next_line(fd2,&line);
	printf("%d\n", res);
}
