/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:38:49 by humarque          #+#    #+#             */
/*   Updated: 2019/01/11 18:43:29 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main(int argc, char **argv)
{
	int fd;
	int fd2;
	int res;
	char *line;

	argc = 0;
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
