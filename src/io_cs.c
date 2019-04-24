/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:59:02 by valecart          #+#    #+#             */
/*   Updated: 2019/04/24 16:18:31 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_s(t_conv_spec *conv_spec, long long *args)
{
	long long	str_size;
	char		*s;

	s = (char*)(args[conv_spec->arg_index]);
	str_size = ft_strlen(s);
	ft_putstr(s);
	return (MAX(str_size, conv_spec->field));
}

// MAX(str_size, conv_spec->field)
