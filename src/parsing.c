/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:28:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 11:57:00 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		init_conv_spec(t_conv_spec *cs)
{
	cs->flags = 0;
	cs->modifier = MOD_NONE;
	cs->field = 0;
	cs->precision = -1;
	cs->precision = cs->type == 'f' ? 6 : cs->precision;
}

void		first_pass(t_conv_spec *cs, char *fmt)
{
	cs->size = 0;
	while (ft_strchr(VALID_CHRS, fmt[cs->size]) && fmt[cs->size])
		cs->size++;
	cs->type = fmt[cs->size];
	if (cs->type)
		cs->size++;
	init_conv_spec(cs);
}

void		parse_conv_spec(t_conv_spec *cs, char *fmt, va_list arg)
{
	size_t	i;

	i = 0;
	first_pass(cs, fmt);
	parse_flags(cs, fmt, &i);
	parse_field(cs, fmt, &i, arg);
	parse_precision(cs, fmt, &i, arg);
	parse_modifiers(cs, fmt, &i);
}

int			parse_print_format(char *format, va_list arg)
{
	t_conv_spec	cspec;
	int			n;

	n = 0;
	while (*format)
	{
		if (*format == '%')
		{
			parse_conv_spec(&cspec, format + 1, arg);
			ft_put_conv_spec(&cspec, arg, &n);
			format += cspec.size + 1;
		}
		else
		{
			ft_putchar(*(format++));
			n++;
		}
	}
	return (n);
}
