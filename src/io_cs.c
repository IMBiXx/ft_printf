/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:59:02 by valecart          #+#    #+#             */
/*   Updated: 2019/04/24 17:26:27 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> // remove stp

int		put_c(t_conv_spec *conv_spec, long long *args)
{
	char			c;

	c = (char)(args[conv_spec->arg_index]);
	if (!(conv_spec->flags & FLAG_M))
		put_nchars(conv_spec->field - 1, ' ');
	ft_putchar(c);
	if (conv_spec->flags & FLAG_M)
		put_nchars(conv_spec->field - 1, ' ');
	return (MAX(1, conv_spec->field));
}

int		put_s(t_conv_spec *conv_spec, long long *args)
{
	size_t			str_size;
	char			*s;
	unsigned int	n_print;

	n_print = 0;
	s = (char*)(args[conv_spec->arg_index]);
	str_size = ft_strlen(s);
	if (conv_spec->precision < (int)str_size)
		n_print = conv_spec->precision;
	else
		n_print = str_size;
	if (!(conv_spec->flags & FLAG_M))
		put_nchars(conv_spec->field - n_print, ' ');
	printf("conv_spec->precision: %d\n", conv_spec->precision);
	if (conv_spec->precision > 0)
		ft_putnstr(s, n_print);
	if (conv_spec->flags & FLAG_M)
		put_nchars(conv_spec->field - n_print, ' ');
	return (MAX((int)n_print, conv_spec->field));
}
