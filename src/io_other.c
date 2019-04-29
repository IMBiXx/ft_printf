/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:04:52 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 09:13:03 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			max(int a, int b)
{
	return (a > b ? a : b);
}

int			put_perc(t_conv_spec *cs)
{
	if (!(cs->flags & FLAG_M))
		put_nchars(cs->field - 1, ' ');
	ft_putchar('%');
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - 1, ' ');
	return (max(1, cs->field));
}
