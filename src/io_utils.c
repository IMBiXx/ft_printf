/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:06:17 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 11:15:17 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr_r(char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (s[i] && i < size)
	{
		if (ft_isprint(s[i]) == 1)
			ft_putchar(s[i]);
		else
		{
			ft_putstr("\\x");
			ft_putchar("0123456789abcdef"[(unsigned char)(s[i]) / 16]);
			ft_putchar("0123456789abcdef"[(unsigned char)(s[i]) % 16]);
		}
		i++;
	}
}

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

void		ft_putl_zer_base(long long n, int zer, char f_sgn, int b)
{
	unsigned long long	numb;
	const char			digits[] = "0123456789";

	if (n < 0)
		ft_putchar('-');
	else if (f_sgn & (FLAG_P | FLAG_SP))
		ft_putchar(f_sgn & FLAG_P ? '+' : ' ');
	put_nchars(zer, '0');
	numb = (n < 0) ? -n : n;
	if (numb > (unsigned int)(b - 1))
		ft_putl_zer_base(numb / b, 0, 0, b);
	ft_putchar(digits[numb % b]);
}

void		ft_putl_zer_base_u(unsigned long long n, int zer, int cas, int b)
{
	const char			digits[] = "0123456789abcdef";

	put_nchars(zer, '0');
	if (n > (unsigned int)(b - 1))
		ft_putl_zer_base_u(n / b, 0, cas, b);
	ft_putchar(cas ? ft_toupper(digits[n % b]) : digits[n % b]);
}
