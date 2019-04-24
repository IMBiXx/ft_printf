/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:34:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 17:07:05 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h> // remove pls
void		ft_put_conv_spec(t_conv_spec *cspec, void *args, int *count)
{
	if (cspec->type == 'd')
		*count += put_d(cspec, args);
	if (cspec->type == 's')
		*count += put_s(cspec, args);
	if (cspec->type == 'c')
		*count += put_c(cspec, args);
	if (cspec->type == 'x' || cspec->type == 'X')
		*count += put_x(cspec, args, cspec->type == 'x' ? 0 : 1);
}
