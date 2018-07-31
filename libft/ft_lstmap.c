/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:15:05 by obaranni          #+#    #+#             */
/*   Updated: 2016/12/30 17:04:24 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*prev;
	t_list		*begin;

	if (!f || !lst)
		return (NULL);
	begin = f(lst);
	prev = begin;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new = f(lst);
		prev->next = new;
		prev = new;
	}
	return (begin);
}
