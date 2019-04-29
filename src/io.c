/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:34:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/29 11:48:53 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		ft_put_conv_spec(t_conv_spec *cspec, va_list arg, int *c)
{
	if (cspec->type == 'd' || cspec->type == 'i')
		*c += put_d(cspec, arg);
	if (cspec->type == 'u' || cspec->type == 'U')
		*c += put_u(cspec, arg);
	if (cspec->type == 'p')
		*c += put_p(cspec, arg);
	if (cspec->type == 's')
		*c += put_s(cspec, arg);
	if (cspec->type == 'f')
		*c += put_f(cspec, arg);
	if (cspec->type == 'o')
		*c += put_o(cspec, arg);
	if (cspec->type == 'c')
		*c += put_c(cspec, arg);
	if (cspec->type == 'x' || cspec->type == 'X')
		*c += put_x(cspec, arg);
	if (cspec->type == 'k' || cspec->type == 'K')
		*c += put_k(cspec, arg);
	if (cspec->type == 'b' || cspec->type == 'B')
		*c += put_b(cspec, arg);
	if (cspec->type == '%')
		*c += put_perc(cspec);
	if (cspec->type == 'r')
		*c += put_r(cspec, arg);
}
