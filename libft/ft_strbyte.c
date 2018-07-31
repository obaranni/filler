/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbyte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:12:12 by obaranni          #+#    #+#             */
/*   Updated: 2016/12/18 18:46:35 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strbyte(unsigned char b)
{
	char			*byte;
	unsigned char	a;
	int				i;

	byte = (char*)malloc(sizeof(char) * 9);
	a = 128;
	i = 0;
	while (i != 8)
	{
		if (b >= a)
		{
			b = b - a;
			byte[i] = '1';
		}
		else
			byte[i] = '0';
		a = a / 2;
		i++;
	}
	byte[i] = '\0';
	return (byte);
}
