/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:28:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 08:21:17 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		init_conv_spec(t_conv_spec *cs)
{
	cs->flags = 0;
	cs->modifier = MOD_NONE;
	cs->field = 0;
	cs->precision = 0;
	cs->precision = cs->type == 'f' ? 6 : cs->precision;
	cs->precision = cs->type == 's' ? -1 : cs->precision;
}

void		first_pass(t_conv_spec *cs, char *fmt)
{
	cs->size = 0;
	while (!ft_strchr(CONV_CHARS, fmt[cs->size]))
		cs->size++;
	cs->type = fmt[cs->size++];
	init_conv_spec(cs);
}

void		parse_flags(t_conv_spec *cs, char *fmt, size_t *i)
{
	while (ft_strchr(FLAG_CHARS, fmt[*i]))
	{
		cs->flags |= fmt[*i] == '#' ? FLAG_SH : 0;
		cs->flags |= fmt[*i] == '0' ? FLAG_0 : 0;
		cs->flags |= fmt[*i] == '-' ? FLAG_M : 0;
		cs->flags |= fmt[*i] == '+' ? FLAG_P : 0;
		cs->flags |= fmt[*i] == ' ' ? FLAG_SP : 0;
		(*i)++;
	}
}

void		parse_field(t_conv_spec *cs, char *fmt, size_t *i, va_list arg)
{
	if (fmt[*i] == '*')
	{
		cs->field = va_arg(arg, int);
		(*i)++;
	}
	if (ft_isdigit(fmt[*i]))
		cs->field = ft_atoi_len(fmt, i);
}

void		parse_precision(t_conv_spec *cs, char *fmt, size_t *i, va_list arg)
{
	if (fmt[*i] == '.')
	{
		(*i)++;
		if (fmt[*i] == '*')
		{
			cs->precision = va_arg(arg, int);
			(*i)++;
		}
		else
			cs->precision = ft_atoi_len(fmt, i);
	}
}

void		parse_modifiers(t_conv_spec *cs, char *fmt, size_t *i)
{
	if (ft_strchr(MOD_CHARS, fmt[*i]))
	{
		if (fmt[*i] == 'l')
			cs->modifier = fmt[*i + 1] == 'l' ? MOD_LL : MOD_L;
		if (fmt[*i] == 'h')
			cs->modifier = fmt[*i + 1] == 'h' ? MOD_HH : MOD_H;
		cs->modifier = fmt[*i] == 'L' ? MOD_LLL : cs->modifier;
		if (cs->modifier == MOD_HH || cs->modifier == MOD_LL)
			(*i)++;
	}
	(*i)++;
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
