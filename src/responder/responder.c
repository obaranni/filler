/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:46:59 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 14:47:08 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"

int				responder(t_filler *f)
{
	ft_putnbr(f->game.step_cord.y);
	ft_putchar(32);
	ft_putnbr(f->game.step_cord.x);
	ft_putchar(10);
	return (1);
}
