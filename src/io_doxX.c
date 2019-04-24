/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_doxX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:04:50 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 17:06:51 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_d(t_conv_spec *cspec, long long *args)
{
	long long	d;
	int			num_size;
	int			n_zeroes;

	d = cast_long_long(cspec, args[cspec->arg_index]);
	num_size = num_len_base(d, 10);
	n_zeroes = (cspec->precision - num_size > 0 ? cspec->precision
		- num_size : 0);
	num_size += n_zeroes + (d < 0 || cspec->flags & FLAG_P ? 1 : 0);
	if (!(cspec->flags & FLAG_M))
		put_nchars(cspec->field - num_size, ' ');
	ft_putl_zer_base(d, n_zeroes, cspec->flags & FLAG_P, 10);
	if (cspec->flags & FLAG_M)
		put_nchars(cspec->field - num_size, ' ');
	return (MAX(num_size, cspec->field));
}

int			put_x(t_conv_spec *cspec, long long *args, int cas)
{
	long long	d;
	int			num_size;
	int			n_zeroes;

	d = cast_long_long_u(cspec, args[cspec->arg_index]);
	num_size = num_len_base_u(d, 16);
	n_zeroes = (cspec->precision - num_size > 0 ? cspec->precision
		- num_size : 0);
	num_size += n_zeroes + cspec->flags & FLAG_SH ? 2 : 0;
	if (!(cspec->flags & FLAG_M))
		put_nchars(cspec->field - num_size, ' ');
	if (cspec->flags & FLAG_SH)
		ft_putstr(cas ? "0X" : "0x");
	ft_putl_zer_base_u(d, n_zeroes, cas, 16);
	if (cspec->flags & FLAG_M)
		put_nchars(cspec->field - num_size, ' ');
	return (MAX(num_size, cspec->field));
}

