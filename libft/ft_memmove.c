/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:27:53 by obaranni          #+#    #+#             */
/*   Updated: 2016/12/04 19:16:47 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src <= dst)
	{
		i = len;
		while (i != 0)
		{
			i--;
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
			i++;
		}
	}
	return (dst);
}
