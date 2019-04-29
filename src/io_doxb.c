/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_doxb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:04:50 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 10:45:30 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_d(t_conv_spec *cs, va_list arg)
{
	long long		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_int(cs, arg);
	num_size = (cs->precision || d) ? num_len_base(d, 10) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (d < 0 || cs->flags & FLAG_P
			|| cs->flags & FLAG_SP ? 1 : 0);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		put_nchars(cs->field - num_size, ' ');
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		n_zeroes += cs->field - num_size;
	if (cs->precision || d)
		ft_putl_zer_base(d, n_zeroes, cs->flags, 10);
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (max(num_size, cs->field));
}

int			put_u(t_conv_spec *cs, va_list arg)
{
	unsigned long long	d;
	unsigned int		num_size;
	unsigned int		n_zeroes;

	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? num_len_base_u(d, 10) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes;
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		put_nchars(cs->field - num_size, ' ');
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		n_zeroes += cs->field - num_size;
	if (cs->precision || d)
		ft_putl_zer_base_u(d, n_zeroes, 0, 10);
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (max(num_size, cs->field));
}

int			put_x(t_conv_spec *cs, va_list arg)
{
	long long		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? num_len_base_u(d, 16) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (cs->flags & FLAG_SH && d ? 2 : 0);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		put_nchars(cs->field - num_size, ' ');
	if (cs->flags & FLAG_SH && d)
		ft_putstr(cs->type == 'X' ? "0X" : "0x");
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		put_nchars(cs->field - num_size, '0');
	if (cs->precision || d)
		ft_putl_zer_base_u(d, n_zeroes, cs->type == 'X', 16);
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (max(num_size, cs->field));
}

int			put_o(t_conv_spec *cs, va_list arg)
{
	long long		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? num_len_base_u(d, 8) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (cs->flags & FLAG_SH ? 1 : 0);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		put_nchars(cs->field - num_size, ' ');
	if (cs->flags & FLAG_SH)
		ft_putchar('0');
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		put_nchars(cs->field - num_size, '0');
	if (cs->precision || d)
		ft_putl_zer_base_u(d, n_zeroes, 0, 8);
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (max(num_size, cs->field));
}

int			put_b(t_conv_spec *cs, va_list arg)
{
	long long		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? num_len_base_u(d, 2) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + (cs->flags & FLAG_SH && d ? 2 : 0);
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		put_nchars(cs->field - num_size, ' ');
	if (cs->flags & FLAG_SH && d)
		ft_putstr(cs->type == 'B' ? "0B" : "0b");
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		put_nchars(cs->field - num_size, '0');
	ft_putl_zer_base_u(d, n_zeroes, 0, 2);
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (max(num_size, cs->field));
}
