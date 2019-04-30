/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:53:35 by valecart          #+#    #+#             */
/*   Updated: 2019/04/30 17:52:36 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

long double		put_f_round(t_conv_spec *cs, long double f)
{
	long double		tmp;
	unsigned int	n;

	n = 0;
	tmp = f;
	while ((int)(n++) < cs->precision)
		tmp = tmp * 10 - (((unsigned long long)tmp / 10) * 10);
	if ((unsigned long long)tmp % 10 >= 5)
	{
		tmp = 1;
		while (n-- > 1)
			tmp /= 10;
		f += tmp;
	}
	return (f);
}

void			put_f_decimal(t_conv_spec *cs, long double f)
{
	unsigned int	n;

	f *= f > 0 ? 1 : -1;
	n = 0;
	if (cs->precision > 0 || (cs->precision == 0 && cs->flags & FLAG_SH))
	{
		f -= (unsigned long long)f;
		f = put_f_round(cs, f);
		ft_putchar('.');
		while ((int)(n++) < cs->precision)
		{
			ft_putchar('0' + (unsigned long long)(f *= 10) % 10);
			f -= (unsigned long long)f;
		}
	}
}

long double		put_f_zero_precision(t_conv_spec *cs, long double f)
{
	if (cs->precision == 0)
		if ((f - (long long)f) * (f > 0 ? 1 : -1) >= 0.5)
			f += f > 0 ? 1 : -1;
	return (f);
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
	f = put_f_zero_precision(cs, f);
	ft_putnbr((long long)f);
	put_f_decimal(cs, f);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - num_size);
	return (max(num_size, cs->field));
}
