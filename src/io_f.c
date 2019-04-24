/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:53:35 by valecart          #+#    #+#             */
/*   Updated: 2019/04/24 23:56:26 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			display_pre_float(float f, int *count)
{
	if (f < 10)
	{
		ft_putchar(f + '0');
	}
	else
	{
		display_pre_float(f / 10, count);
		ft_putchar(((int)f % 10) + '0');
		(*count)++;
	}
}

void			display_post_float(int n, int *count)
{
	if (*count < 0)
	{
	//	ft_putchar(n + '0');
	}
	else
	{
		printf("count: %d, n: %d\n", *count, n);
		(*count)--;
		display_post_float(n / 10, count);
		/*ft_putchar(((int)f % 10) + '0');*/
	}
}

int		main(void)
{
	float	f = 420.1234;
	long	i = 0;
	long	precision = 6;
	float	tmp = f;
	int		n;
	int		count = 1;

	display_pre_float(f, &count);
	ft_putchar('.');
	printf("[%d]\n", count);
	while (i < precision)
	{
		tmp = tmp * 10;
		i++;
	}
	printf("tmp: [%f]\n", tmp);
	n = (int)tmp;
	printf("n: [%d]\n", n);
	display_post_float(n, &count);
}

/*int			put_f(t_conv_spec *cspec, long long *args)*/
/*{*/
/*long long	f;*/
/*int			num_size;*/
/*int			n_zeroes;*/

/*d = cast_long_long(cspec, args[cspec->arg_index]);*/
/*num_size = num_len_base(d, 10);*/
/*n_zeroes = (cspec->precision - num_size > 0 ? cspec->precision*/
/*- num_size : 0);*/
/*num_size += n_zeroes + (d < 0 || cspec->flags & FLAG_P ? 1 : 0);*/
/*if (!(cspec->flags & FLAG_M))*/
/*put_nchars(cspec->field - num_size, ' ');*/
/*ft_putl_zer_base(d, n_zeroes, cspec->flags & FLAG_P, 10);*/
/*if (cspec->flags & FLAG_M)*/
/*put_nchars(cspec->field - num_size, ' ');*/
/*return (MAX(num_size, cspec->field));*/
/*}*/
