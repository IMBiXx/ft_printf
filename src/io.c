/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:34:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 16:07:24 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"


void		ft_put_conv_spec(t_conv_spec *cspec, void *args, int *count)
{
	if (cspec->type == 'd')
		*count += put_d(cspec, args);
}
