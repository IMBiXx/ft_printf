/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:56:12 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/25 16:58:03 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_fill(char *ret, long int n, int *i)
{
	if (n < 0)
	{
		ret[0] = '-';
		*i = 1;
		n = -n;
	}
	if (n < 10)
	{
		ret[*i] = n + '0';
		(*i)++;
	}
	else
	{
		ft_itoa_fill(ret, n / 10, i);
		ret[*i] = (n % 10) + '0';
		(*i)++;
	}
	ret[*i] = '\0';
}

static int		ft_intcount(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = -1;
		i++;
	}
	while ((n = n / 10) > 0)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char		*ret;
	long int	nb;
	int			i;

	i = 0;
	nb = n;
	if (!(ret = (char*)malloc(sizeof(char) * (ft_intcount(n) + 1))))
		return (NULL);
	ft_itoa_fill(ret, nb, &i);
	return (ret);
}
