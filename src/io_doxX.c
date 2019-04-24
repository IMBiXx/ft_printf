/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_doxX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:04:50 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 16:05:49 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_d(t_conv_spec *cspec, long long *args)
{
	long long	d;
	int			num_size;
	int			n_zeroes;

	d = cast_long_long(cspec, args[cspec->arg_index]);
	num_size = num_len(d, 10);
	n_zeroes = (cspec->precision - num_size > 0 ? cspec->precision
		- num_size : 0);
	num_size += n_zeroes + (d < 0 || cspec->flags & FLAG_P ? 1 : 0);
	if (!(cspec->flags & FLAG_M))
		put_nchars(cspec->field - num_size, ' ');
	ft_putlong_zeroes(d, n_zeroes, cspec->flags & FLAG_P);
	if (cspec->flags & FLAG_M)
		put_nchars(cspec->field - num_size, ' ');
	return (MAX(num_size, cspec->field));
}

