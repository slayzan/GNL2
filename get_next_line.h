/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:30:05 by humarque          #+#    #+#             */
/*   Updated: 2019/01/16 16:33:17 by humarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 6
# include <unistd.h>
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "libft/libft.h"

typedef    struct            s_struct
{
	unsigned int fd;
	char *str;
	struct s_struct *next;
}                        t_struct;

int        get_next_line(int fd, char **line);

#endif
