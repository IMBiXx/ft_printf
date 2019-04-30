/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:53:35 by valecart          #+#    #+#             */
/*   Updated: 2019/04/30 18:08:19 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

long double		put_f_round(t_conv_spec *cs, long double f)
{
	long double		tmp;
	int	n;

	n = 0;
	tmp = f * (f >= 0 ? 1 : -1);
	while (n++ < cs->precision)
		tmp = 10 * (tmp - (long long)tmp);
	if (tmp >= 0.5)
	{
		tmp = 1;
		while (n-- > 1)
			tmp /= 10;
		f += tmp * (f >= 0 ? 1 : -1);
	}
	return (f);
}

void			put_f_decimal(t_conv_spec *cs, long double f)
{
	int	n;

	f *= f >= 0 ? 1 : -1;
	n = 0;
	ft_putchar('.');
	while (n++ < cs->precision)
	{
		ft_putchar('0' + (long long)(f *= 10) % 10);
		f -= (unsigned long long)f;
	}
}

int				put_f(t_conv_spec *cs, va_list arg)
{
	long double		f;
	size_t			num_size;

	if (cs->type == 'F')
		cs->modifier = MOD_L;
	f = get_arg_float(cs, arg);
	num_size = num_len_base((int)f, 10) + cs->precision
		+ (cs->precision > 0 ? 1 : 0);
	num_size += (f < 0 || cs->flags & FLAG_P ? 1 : 0);
	if (!(cs->flags & FLAG_M))
		ft_putnchar(cs->flags & FLAG_0 ? '0' : ' ', cs->field - num_size);
	if (cs->flags & (FLAG_SP | FLAG_P))
		if (f >= 0)
			ft_putchar(cs->flags & FLAG_P ? '+' : ' ');
	//f = put_f_zero_precision(cs, f);
	f = put_f_round(cs, f);
	ft_putnbr((long long)f);
	if (cs->precision > 0 || (cs->precision == 0 && cs->flags & FLAG_SH))
		put_f_decimal(cs, f);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - num_size);
	return (max(num_size, cs->field));
}
