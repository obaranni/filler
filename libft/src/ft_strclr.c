/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:05:18 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:32:33 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_strclr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i) != '\0')
	{
		*(s + i) = '\0';
		i++;
	}
}
