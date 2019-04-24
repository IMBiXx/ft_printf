/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:46:29 by valecart          #+#    #+#             */
/*   Updated: 2019/04/24 15:08:47 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atoi_len(const char *str, unsigned int *i)
{
	long	ret;

	ret = 0;
	while (ft_isdigit(str[*i]) == 1 && str[*i])
	{
		ret = (ret * 10) + str[*i] - 48;
		(*i)++;
	}
	(*i)--;
	return (ret);
}
