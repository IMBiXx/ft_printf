/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:06:17 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 16:35:51 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		num_len_base(long long n, int base)
{
	size_t	s;

	s = 1;
	while (n /= base)
		s++;
	return (s);
}

size_t		num_len_base_u(unsigned long long n, int base)
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

/* put a long with a given base padded with zeroes */
/* zer = amount of zeroes */
/* f_sgn = force the sign display */
/* cas = true -> chars must be uppercase */
/* b = base */

void		ft_putl_zer_base(long long n, int zer, char f_sgn, int cas, int b)
{
	unsigned long long	numb;
	const char			digits[] = "0123456789abcdef";

	if (n < 0)
		ft_putchar('-');
	else if (force)
		ft_putchar('+');
	put_nchars(zeroes, '0');
	numb = (n < 0) ? -n : n;
	if (numb > b - 1)
		ft_putlong_zeroes(numb / b, 0, 0, cas, b);
	ft_putchar(b ? to_upper(digits[numb % b]) : digits[numb % b]);
}

/*unsigned version of ft_putl_zer_base*/

void		ft_putl_zer_base_u(unsigned long long n, int zer, char f_sgn,
		int cas, int b)
{
	unsigned long long	numb;
	const char			digits[] = "0123456789abcdef";

	if (n < 0)
		ft_putchar('-');
	else if (force)
		ft_putchar('+');
	put_nchars(zeroes, '0');
	numb = (n < 0) ? -n : n;
	if (numb > b - 1)
		ft_putlong_zeroes(numb / b, 0, 0, cas, b);
	ft_putchar(b ? to_upper(digits[numb % b]) : digits[numb % b]);
}
