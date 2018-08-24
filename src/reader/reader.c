/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:02:47 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 15:04:59 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"

void				last_lines(t_filler *f, int *i,
		int len, int filedesc)
{
	int				to_end;
	char			*buf;

	to_end = FIGF_Y;
	while (to_end > 0)
	{
		get_next_line(filedesc, &buf);
		len = (int)ft_strlen(buf);
		f->input[*i] = (char*)malloc(sizeof(char) * len + 1);
		ft_strcpy(f->input[*i], buf);
		to_end--;
		ft_strdel(&buf);
		(*i)++;
	}
}

int					loop(t_filler *f, int *i, int filedesc)
{
	char			*buf;
	int				len;

	while (get_next_line(filedesc, &buf) > 0)
	{
		len = (int)ft_strlen(buf);
		f->input[*i] = (char*)malloc(sizeof(char) * len + 1);
		ft_strcpy(f->input[*i], buf);
		if (ft_strncmp(buf, "Piece", 5) == 0)
		{
			ft_strdel(&buf);
			validate_figure_part(f, i);
			(*i)++;
			last_lines(f, i, len, filedesc);
			return (1);
		}
		ft_strdel(&buf);
		(*i)++;
	}
	return (0);
}

int					reader(t_filler *f, int fd)
{
	int				i;
	int				res;

	i = 0;
	f->input = 0;
	MAP_F = 0;
	f->input = (char **)malloc(sizeof(char*) * 4096);
	res = loop(f, &i, fd);
	f->input[i] = 0;
	return (res);
}
