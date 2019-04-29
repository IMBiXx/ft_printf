/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:53:35 by valecart          #+#    #+#             */
/*   Updated: 2019/04/29 15:34:34 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			put_f(t_conv_spec *cs, va_list arg)
{
	long double		f;
	long double		tmp;
	size_t			num_size;
	unsigned int	n;

	f = get_arg_float(cs, arg);
	num_size = num_len_base((int)f, 10) + cs->precision
		+ (cs->precision > 0 ? 1 : 0);
	num_size += (f < 0 || cs->flags & FLAG_P ? 1 : 0);
	if (!(cs->flags & FLAG_M))
		put_nchars(cs->field - num_size, cs->flags & FLAG_0 ? '0' : ' ');
	if (cs->flags & (FLAG_SP | FLAG_P))
		ft_putchar(cs->flags & FLAG_P ? '+' : ' ');
	ft_putnbr((int)f);
	f *= f > 0 ? 1 : -1;
	n = 0;
	if (cs->precision > 0)
	{
		f -= (unsigned long long)f;
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
		n = 0;
		ft_putchar('.');
		while ((int)(n++) < cs->precision)
		{
			ft_putchar('0' + (unsigned long long)(f *= 10) % 10);
			f -= (unsigned long long)f;
		}
	}
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (max(num_size, cs->field));
}
