/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:48:43 by valecart          #+#    #+#             */
/*   Updated: 2019/04/23 13:40:23 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int			d = 42;
	long int	lu = 4294967295;
	int			pouet = 0x4242;
	float		f = 42.123;
	char		c = 'V';
	char		*s = "bonjour les amis";

	printf("%d\n", d);
	printf("%lu\n", lu);
	printf("%f\n", f);
	printf("%c\n", c);
	printf("%s\n", s);

	printf("\n##### %%5d #####\n");

	printf("%5d\n", d);
	printf("%5lu\n", lu);
	printf("%5f\n", f);
	printf("%5c\n", c);
	printf("%5s\n", s);

	printf("\n##### %%.5d #####\n");

	printf("%.5d\n", d);
	printf("%.5lu\n", lu);
	printf("%.5f\n", f);
//	printf("%.5c\n", c);
	printf("%.5s\n", s);

	printf("\n##### %%#d #####\n");

	printf("%hh#x\n", pouet);
	printf("%#hhx\n", pouet);
	/*printf("%#f\n", f);*/
	/*printf("%#c\n", c);*/
	/*printf("%#s\n", s);*/

	printf("SPECIAL CASES\n");
	/*printf("%5[ ]onj\n");*/
	return (0);
}
