/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:31:51 by obaranni          #+#    #+#             */
/*   Updated: 2016/12/04 17:23:03 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int nb, size_t len)
{
	size_t	i;
	char	*tm;

	tm = str;
	i = 0;
	while (i != len)
	{
		tm[i] = nb;
		i++;
	}
	return (str);
}
