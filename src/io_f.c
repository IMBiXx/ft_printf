/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:53:35 by valecart          #+#    #+#             */
/*   Updated: 2019/04/30 20:09:06 by valecart         ###   ########.fr       */
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
	//printf("[f: %Lf]\n", f);
	while (n++ < cs->precision)
		tmp = 10 * (tmp - (long long)tmp);
	tmp -= (long long)tmp;
	//printf("[tmp1: %Lf]\n", tmp);
	if (tmp >= 0.5)
	{
		tmp = 1;
		while (n-- > 1)
			tmp /= 10;
		//printf("[tmp: %Lf]\n", tmp);
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
		f -= (long long)f;
	}
}

int				put_f(t_conv_spec *cs, va_list arg)
{
	long double		f;
	size_t			num_size;
	int				n_zeroes;

	if (cs->type == 'F')
		cs->modifier = MOD_L;
	f = get_arg_float(cs, arg);
	num_size = ft_num_len_base((long long)f, 10) + cs->precision
		+ (cs->precision > 0 ? 1 : 0);
	num_size += (f <= -0.0 || cs->flags & FLAG_P
			|| cs->flags & FLAG_SP ? 1 : 0);
	n_zeroes = cs->field - num_size - (cs->precision > 0
				|| (cs->precision == 0 && cs->flags & FLAG_SH) ? 1 : 0);
	num_size += n_zeroes;
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0))
		ft_putnchar(' ', n_zeroes);
	f = put_f_round(cs, f);
	ft_putf_zer_base((long long)f,
			cs->flags & FLAG_M ? 0 : n_zeroes, cs->flags, 10);
	if (cs->precision > 0 || (cs->precision == 0 && cs->flags & FLAG_SH))
		put_f_decimal(cs, f);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', n_zeroes);
	return (max(num_size, cs->field));
}
