/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:36:18 by valecart          #+#    #+#             */
/*   Updated: 2019/04/25 17:04:31 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char * restrict format, ...)
{
	t_list	*lst;
	int		n;
	long long args[] = {18, 0x18, 2, 3, 4, 5, 6, 7, 8, 9};

	n = 0;
	lst = parse_format((char *)format);
	while (lst)
	{
		ft_put_conv_spec(lst->content, args, &n);
		ft_putchar('\n');
		lst = lst->next;
	}
	return (0);
}
