/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_doxX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:04:50 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 07:54:06 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_d(t_conv_spec *cs, va_list arg)
{
	long long		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_int(cs, arg);
	num_size = num_len_base(d, 10);
	n_zeroes = cs->precision > num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (d < 0 || cs->flags & FLAG_P ? 1 : 0);
	if (!(cs->flags & FLAG_M))
		put_nchars(cs->field - num_size, ' ');
	ft_putl_zer_base(d, n_zeroes, cs->flags & FLAG_P, 10);
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (MAX(num_size, cs->field));
}

int			put_x(t_conv_spec *cs, va_list arg)
{
	long long		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_uint(cs, arg);
	num_size = num_len_base_u(d, 16);
	n_zeroes = cs->precision > num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (cs->flags & FLAG_SH ? 2 : 0);
	if (!(cs->flags & FLAG_M))
		put_nchars(cs->field - num_size, ' ');
	if (cs->flags & FLAG_SH)
		ft_putstr(cs->type == 'X' ? "0X" : "0x");
	ft_putl_zer_base_u(d, n_zeroes, cs->type == 'X', 16);
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (MAX(num_size, cs->field));
}

int			put_o(t_conv_spec *cs, va_list arg)
{
	long long		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_uint(cs, arg);
	num_size = num_len_base_u(d, 8);
	n_zeroes = cs->precision > num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (cs->flags & FLAG_SH ? 1 : 0);
	if (!(cs->flags & FLAG_M))
		put_nchars(cs->field - num_size, ' ');
	if (cs->flags & FLAG_SH)
		ft_putchar('0');
	ft_putl_zer_base_u(d, n_zeroes, 0, 8);
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (MAX(num_size, cs->field));
}
