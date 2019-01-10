/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:29:50 by humarque          #+#    #+#             */
/*   Updated: 2019/01/10 18:34:46 by humarque         ###   ########.fr       */
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

int	ft_dup(char **line, char *lst)
{
	int i;

	i = 0;
//	printf("oui");
	while(lst[i] != '\n')
		i++;
	*line = ft_strnew(i + 1);
	*line = ft_strncpy(*line, lst, i);
	return (i);
}

t_struct	*ft_delstr(int ret, t_struct *lst)
{

	if (ret < ft_strlen(lst->str))
	{
		lst->str = ft_strdup(lst->str + ret + 1);
	}
	else
		ft_strclr(lst->str);
	return(lst);
}



int		get_next_line(const int fd, char **line)
{
	static t_struct *list = NULL;
	char buf[BUFF_SIZE + 1];
	char *tofree;
	int ret;
	t_struct *lst;
	
	if(!(lst = ft_findfd(&list, fd)))
		return(-1);
	while ((ret = read(lst->fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tofree = lst->str;
		lst->str = ft_strjoin(lst->str, (char const *)buf);
		free(tofree);
		if (ft_strchr(buf, '\n'))
			break;
	}
	//printf("la");
	if((ret < BUFF_SIZE) && (ft_strlen(lst->str) == 0))
		return (0);
	ret = ft_dup(line,lst->str);
	lst = ft_delstr(ret, lst);
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
	while((res = get_next_line(fd, &line) == 1))	
	{
		printf("%s", line);
		printf("\n");
	}
}
