/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 08:33:50 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/04 19:38:59 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int			ft_find(char *all, char **line)
{
	if (ft_strchr(all, '\n'))
	{
		*line = ft_strsub(all, 0, ft_strchr(all, '\n') - all);
		return (1);
	}
	return (0);
}

static int			ft_niekostyl(char **all, char **line)
{
	if (ft_find(*all, line) && ft_strchr(*all, '\n'))
	{
		*all = ft_strchr(*all, '\n') + 1;
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static char		*all;
	char			buff[BUFF_SIZE + 1];
	int				numb;

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	while ((numb = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[numb] = '\0';
		all = (!all) ? ft_strdup(buff) : ft_strjoin(all, buff);
		if (ft_niekostyl(&all, line))
			return (1);
	}
	if (ft_niekostyl(&all, line))
		return (1);
	if (ft_strchr(all, '\0') && *all != '\0')
	{
		*line = ft_strsub(all, 0, ft_strchr(all, '\0') - all);
		*all = '\0';
		return (1);
	}
	return (0);
}
