/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:06:17 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 16:06:31 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
