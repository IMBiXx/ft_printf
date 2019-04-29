/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 08:44:44 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 09:11:58 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
