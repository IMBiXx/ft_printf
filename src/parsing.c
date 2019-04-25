/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:28:39 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/25 18:18:07 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_conv_spec	*parse_conv_spec(char *fmt)
{
	t_conv_spec		*cspec;
	unsigned int	i;
	long			tmp;
	char			precision;

	precision = 0;
	tmp = 0;
	i = 0;
	if (!(cspec = (t_conv_spec*)malloc(sizeof(t_conv_spec))))
		return (NULL);
	cspec->type = 0;
	cspec->precision = 1;
	cspec->field = 0;
	cspec->arg_index = 0;
	cspec->modifier = MOD_NONE;
	while (!ft_strchr(CONV_CHARS, fmt[i])) // == CONV_CHARS ?
	{
		cspec->size = i;
		if (ft_isdigit(fmt[i]))
			tmp = ft_atoi_len(fmt, &i);
		if (fmt[i] == '$')
		{
			if (tmp == 0)
				return (cspec);
			cspec->arg_index = tmp - 1;
			tmp = 0;
		}
		if (fmt[i] == '.')
		{
			cspec->field = tmp;
			precision = 1;
			tmp = 1;
		}
		if (ft_strchr(FLAG_CHARS, fmt[i]))
		{
			cspec->flags |= fmt[i] == '#' ? FLAG_SH : 0;
			cspec->flags |= fmt[i] == '0' ? FLAG_0 : 0;
			cspec->flags |= fmt[i] == '-' ? FLAG_M : 0;
			cspec->flags |= fmt[i] == '+' ? FLAG_P : 0;
		}
		if (ft_strchr(MOD_CHARS, fmt[i]))
		{
			if (fmt[i] == 'l')
				cspec->modifier = fmt[i + 1] == 'l' ? MOD_LL : MOD_L;
			if (fmt[i] == 'h')
				cspec->modifier = fmt[i + 1] == 'h' ? MOD_HH : MOD_H;
			cspec->modifier = fmt[i] == 'L' ? MOD_LLL : cspec->modifier;
			if (cspec->modifier == MOD_HH || cspec->modifier == MOD_LL)
				i++;
		}
		i++;
	}
	if (precision == 0)
		cspec->field = tmp;
	else
		cspec->precision = tmp;
	cspec->type = fmt[i];
	return (cspec);
}

int			lst_push_ordered(t_list **lst, t_conv_spec *spec)
{
	t_list	*elem;
	t_list	*new;

	if (!lst)
		return (0);
	elem = *lst;
	while (elem && elem->next && ((t_conv_spec *)elem->content)->arg_index <= spec->arg_index)
		elem = elem->next;
	if (!(new = ft_lstnew(spec, sizeof(t_conv_spec))))
		return (0);
	if (*lst)
		elem->next = new;
	else
		*lst = new;
	return (1);
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
			if (!(lst_push_ordered(&lst, cspec)))
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

