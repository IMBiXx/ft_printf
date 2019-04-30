/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len_base_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:54:41 by valecart          #+#    #+#             */
/*   Updated: 2019/04/30 19:54:50 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_num_len_base_u(unsigned long long n, int base)
{
	size_t	s;

	s = 1;
	while (n /= base)
		s++;
	return (s);
}
