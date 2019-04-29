/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:36:18 by valecart          #+#    #+#             */
/*   Updated: 2019/04/29 03:58:55 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = parse_print_format((char *)format, arg);
	va_end(arg);
	return (ret);
}
