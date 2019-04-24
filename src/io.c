/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:34:02 by tpotier           #+#    #+#             */
/*   Updated: 2019/04/24 16:24:38 by valecart         ###   ########.fr       */
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
}
