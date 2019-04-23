/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:34:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/23 19:12:08 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	num_len(long long n, int base)
{
	size_t	s;

	s = n > 0 ? 1 : 2;
	while (n)
	{
		n /= base;
		s++;
	}
	return (s);
}

int		ft_put_conv_spec(t_conv_spec *cspec, void *args, int count)
{
	(void)cspec;
	(void)args;
	(void)count;
	if (cspec->type == 'd')
		return (0);
	return (0);
}
