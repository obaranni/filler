/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:19:08 by obaranni          #+#    #+#             */
/*   Updated: 2016/12/05 17:37:13 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		io;
	int		j;

	io = 0;
	if (little[0] == '\0')
		return ((char*)&big[0]);
	while (big[io] != '\0')
	{
		j = 0;
		i = io;
		while (big[i] == little[j] && little[j] != '\0' && big[i] != '\0')
		{
			j++;
			i++;
		}
		if (little[j] == '\0')
			return ((char*)&big[io]);
		io++;
	}
	return (NULL);
}
