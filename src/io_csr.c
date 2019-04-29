/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_csr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:59:02 by valecart          #+#    #+#             */
/*   Updated: 2019/04/29 10:43:13 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_c(t_conv_spec *conv_spec, va_list arg)
{
	char			c;

	c = (char)va_arg(arg, int);
	if (!(conv_spec->flags & FLAG_M))
		put_nchars(conv_spec->field - 1, ' ');
	ft_putchar(c);
	if (conv_spec->flags & FLAG_M)
		put_nchars(conv_spec->field - 1, ' ');
	return (max(1, conv_spec->field));
}

int		put_s(t_conv_spec *conv_spec, va_list arg)
{
	size_t			str_size;
	char			*s;
	unsigned int	n_print;

	n_print = 0;
	s = va_arg(arg, char *);
	str_size = s ? ft_strlen(s) : 6;
	if (conv_spec->precision >= 0 && conv_spec->precision < (int)str_size)
		n_print = conv_spec->precision;
	else
		n_print = str_size;
	if (!(conv_spec->flags & FLAG_M))
		put_nchars(conv_spec->field - n_print, ' ');
	if (conv_spec->precision != 0)
		ft_putnstr(s ? s : "(null)", n_print);
	if (conv_spec->flags & FLAG_M)
		put_nchars(conv_spec->field - n_print, ' ');
	return (max(n_print, conv_spec->field));
}
