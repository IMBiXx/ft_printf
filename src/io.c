/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:34:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 15:45:30 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t		num_len(long long n, int base)
{
	size_t	s;

	s = 1;
	while (n /= base)
		s++;
	return (s);
}

void		put_nchars(int n, char c)
{
	while (n-- > 0)
		ft_putchar(c);
}

void		ft_putlong_zeroes(long long n, int zeroes, char force)
{
	unsigned long long	numb;

	if (n < 0)
		ft_putchar('-');
	else if (force)
		ft_putchar('+');
	put_nchars(zeroes, '0');
	numb = (n < 0) ? -n : n;
	if (numb > 9)
		ft_putlong_zeroes(numb / 10, 0, 0);
	ft_putchar(numb % 10 + '0');
}

long long	cast_long_long(t_conv_spec *cspec, long long val)
{
	val = cspec->modifier >= 2 ? (long long)val : val;
	val = cspec->modifier == 1 ? (long)val : val;
	val = cspec->modifier == 0 ? (int)val : val;
	val = cspec->modifier == -1 ? (short)val : val;
	val = cspec->modifier <= -2 ? (char)val : val;
	return (val);
}

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

void		ft_put_conv_spec(t_conv_spec *cspec, void *args, int *count)
{
	(void)cspec;
	(void)args;
	if (cspec->type == 'd')
		*count += put_d(cspec, args);
}
