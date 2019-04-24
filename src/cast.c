/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:23:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 16:34:48 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			cast_long_long(t_conv_spec *cspec, long long val)
{
	val = cspec->modifier >= 2 ? (long long)val : val;
	val = cspec->modifier == 1 ? (long)val : val;
	val = cspec->modifier == 0 ? (int)val : val;
	val = cspec->modifier == -1 ? (short)val : val;
	val = cspec->modifier <= -2 ? (char)val : val;
	return (val);
}

unsigned long long	cast_long_long_u(t_conv_spec *cspec, unsigned long long val)
{
	val = cspec->modifier >= 2 ? (unsigned long long)val : val;
	val = cspec->modifier == 1 ? (unsigned long)val : val;
	val = cspec->modifier == 0 ? (unsigned int)val : val;
	val = cspec->modifier == -1 ? (unsigned short)val : val;
	val = cspec->modifier <= -2 ? (unsigned char)val : val;
	return (val);
}
