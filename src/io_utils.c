/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:06:17 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 17:07:14 by tpotier          ###   ########.fr       */
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

void		ft_putl_zer_base(long long n, int zer, char f_sgn, int b)
{
	unsigned long long	numb;
	const char			digits[] = "0123456789";

	if (n < 0)
		ft_putchar('-');
	else if (f_sgn)
		ft_putchar('+');
	put_nchars(zer, '0');
	numb = (n < 0) ? -n : n;
	if (numb > (unsigned int)(b - 1))
		ft_putl_zer_base(numb / b, 0, 0, b);
	ft_putchar(digits[numb % b]);
}

/*unsigned version of ft_putl_zer_base*/

void		ft_putl_zer_base_u(unsigned long long n, int zer, int cas, int b)
{
	const char			digits[] = "0123456789abcdef";

	put_nchars(zer, '0');
	if (n > (unsigned int)(b - 1))
		ft_putl_zer_base_u(n / b, 0, cas, b);
	ft_putchar(cas ? ft_toupper(digits[n % b]) : digits[n % b]);
}
