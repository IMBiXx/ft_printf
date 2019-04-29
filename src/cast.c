/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:23:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 06:16:18 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			get_arg_int(t_conv_spec *cspec, va_list arg)
{
	if (cspec->modifier == MOD_LL)
		return ((long long)va_arg(arg, long long));
	if (cspec->modifier == MOD_L)
		return ((long)va_arg(arg, long));
	if (cspec->modifier == MOD_NONE)
		return ((int)va_arg(arg, int));
	if (cspec->modifier == MOD_H)
		return ((short)va_arg(arg, int));
	if (cspec->modifier == MOD_HH)
		return ((char)va_arg(arg, int));
	return (0);
}

long double			get_arg_float(t_conv_spec *cspec, va_list arg)
{
	if (cspec->modifier == MOD_LLL)
		return ((long double)va_arg(arg, long double));
	if (cspec->modifier == MOD_L || cspec->modifier == MOD_NONE)
		return ((double)va_arg(arg, double));
	return (0);
}

unsigned long long	get_arg_uint(t_conv_spec *cspec, va_list arg)
{
	if (cspec->modifier == MOD_LL)
		return ((unsigned long long)va_arg(arg, unsigned long long));
	if (cspec->modifier == MOD_L)
		return ((unsigned long)va_arg(arg, unsigned long));
	if (cspec->modifier == MOD_NONE)
		return ((unsigned int)va_arg(arg, unsigned int));
	if (cspec->modifier == MOD_H)
		return ((unsigned short)va_arg(arg, unsigned int));
	if (cspec->modifier == MOD_HH)
		return ((unsigned char)va_arg(arg, unsigned int));
	return (0);
}
