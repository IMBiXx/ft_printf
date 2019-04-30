/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:49:29 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/30 19:56:49 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_p(t_conv_spec *cs, va_list arg)
{
	long long		d;
	unsigned int	num_size;
	unsigned int	n_zeroes;

	cs->modifier = MOD_L;
	d = get_arg_uint(cs, arg);
	num_size = (cs->precision || d) ? ft_num_len_base_u(d, 16) : 0;
	n_zeroes = cs->precision > (int)num_size ? cs->precision - num_size : 0;
	num_size += n_zeroes + 2;
	if (!(cs->flags & FLAG_M) && !(cs->flags & FLAG_0 && cs->precision < 0))
		ft_putnchar(' ', cs->field - num_size);
	ft_putstr(cs->type == 'X' ? "0X" : "0x");
	if (!(cs->flags & FLAG_M) && cs->flags & FLAG_0 && cs->precision < 0)
		ft_putnchar('0', cs->field - num_size);
	if (cs->precision || d)
		ft_putl_zer_base_u(d, n_zeroes, cs->type == 'X', 16);
	if (cs->flags & FLAG_M)
		ft_putnchar(' ', cs->field - num_size);
	return (max(num_size, cs->field));
}
