/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:53:35 by valecart          #+#    #+#             */
/*   Updated: 2019/04/29 06:12:17 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			display_pre_float(float f, int *count)
{
	if (f < 10)
	{
		ft_putchar(f + '0');
	}
	else
	{
		display_pre_float(f / 10, count);
		ft_putchar(((int)f % 10) + '0');
		(*count)++;
	}
}

void			display_post_float(int n, int *count)
{
	char	*ret;

	ret = ft_itoa(n);
	ft_putstr(&ret[*count]);
	free(ret);
}

int		mainnnnn(void)
{
	float	f = -420.1234;
	long	i = 0;
	long	precision = 6;
	float	tmp = f;
	int		count = 1;

	if (f < 0)
	{
		ft_putchar('-');
		count++;
		f = -f;
	}
	display_pre_float(f, &count);
	ft_putchar('.');
	while (i < precision)
	{
		tmp = tmp * 10;
		i++;
	}
	display_post_float((int)tmp, &count);
	return (0);
}

int			put_f(t_conv_spec *cs, va_list arg)
{
	long double		f;
	size_t			num_size;
	unsigned int	n;

	f = get_arg_float(cs, arg);
	num_size = num_len_base((int)f, 10) + cs->precision
		+ (cs->precision > 0 ? 1 : 0);
	num_size += (f < 0 || cs->flags & FLAG_P ? 1 : 0);
	if (!(cs->flags & FLAG_M))
		put_nchars(cs->field - num_size, ' ');
	ft_putnbr((int)f);
	n = 0;
	if (cs->precision > 0)
	{
		f -= (int)f;
		ft_putchar('.');
		while (n++ < cs->precision)
			ft_putchar('0' + (int)(f *= 10) % 10);
	}
	if (cs->flags & FLAG_M)
		put_nchars(cs->field - num_size, ' ');
	return (MAX(num_size, cs->field));
}
