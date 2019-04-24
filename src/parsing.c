/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:28:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 17:24:46 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_conv_spec	*parse_conv_spec(char *format)
{
	t_conv_spec		*conv_spec;
	unsigned int	i;
	long			tmp;
	char			precision;

	precision = 0;
	tmp = 0;
	i = 0;
	if (!(conv_spec = (t_conv_spec*)malloc(sizeof(t_conv_spec))))
		return (NULL);
	conv_spec->type = 0;
	conv_spec->precision = 1;
	conv_spec->field = 0;
	conv_spec->arg_index = 0;
	conv_spec->modifier = 0;
	while (!ft_strchr(CONV_CHARS, format[i])) // == CONV_CHARS ?
	{
		conv_spec->size = i;
		if (ft_isdigit(format[i]))
			tmp = ft_atoi_len(format, &i);
		if (format[i] == '$')
		{
			if (tmp == 0)
				return (conv_spec);
			conv_spec->arg_index = tmp - 1;
			tmp = 0;
		}
		if (format[i] == '.')
		{
			conv_spec->field = tmp;
			precision = 1;
			tmp = 1;
		}
		if (ft_strchr(FLAG_CHARS, format[i]))
		{
			conv_spec->flags |= format[i] == '#' ? FLAG_SH : 0;
			conv_spec->flags |= format[i] == '0' ? FLAG_0 : 0;
			conv_spec->flags |= format[i] == '-' ? FLAG_M : 0;
			conv_spec->flags |= format[i] == '+' ? FLAG_P : 0;
		}
		if (format[i] == 'l' || format[i] == 'h')
			conv_spec->modifier += format[i] == 'l' ? 1 : -1;
		i++;
	}
	if (precision == 0)
		conv_spec->field = tmp;
	else
		conv_spec->precision = tmp;
	conv_spec->type = format[i];
	return (conv_spec);
}

t_list		*parse_format(char *format)
{
	t_list		*lst;
	t_conv_spec	*cspec;

	lst = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			cspec = parse_conv_spec(format + 1);
			if (!(ft_lstpushback(&lst, cspec, sizeof(t_conv_spec))))
			{
				free(cspec);
				return (NULL);
			}
			format += cspec->size;
			free(cspec);
		}
		else
			format++;
	}
	return (lst);
}

