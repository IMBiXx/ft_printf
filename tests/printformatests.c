/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:48:43 by valecart          #+#    #+#             */
/*   Updated: 2019/04/23 16:13:05 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int			d = 42;
	long int	lu = 4294967295;
	int			pouet = 123456789;
	float		f = 42.123;
	char		c = 'V';
	char		*s = "bonjour les amis";

	printf("##### %%d #####\n");
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
	printf("%.5c\n", c);
	printf("%.5s\n", s);

	printf("\n##### %%-5d #####\n");

	printf("%-5d|\n", d);
	printf("%-5lu|\n", lu);
	printf("%-5f|\n", f);
	printf("%-5c|\n", c);
	printf("%-5s|\n", s);

	printf("\n##### %%#h[d.o.u.x.X] #####\n");

	printf("%h#d\n", pouet);
	printf("%#hd\n", pouet);
	printf("%h#o\n", pouet);
	printf("%#ho\n", pouet);
	printf("%h#u\n", pouet);
	printf("%#hu\n", pouet);
	printf("%h#x\n", pouet);
	printf("%#hx\n", pouet);
	printf("%h#X\n", pouet);
	printf("%#hX\n", pouet);

	printf("\n##### %%#hh[d.o.u.x.X] #####\n");

	printf("%hh#d\n", pouet);
	printf("%#hhd\n", pouet);
	printf("%hh#o\n", pouet);
	printf("%#hho\n", pouet);
	printf("%hh#u\n", pouet);
	printf("%#hhu\n", pouet);
	printf("%hh#x\n", pouet);
	printf("%#hhx\n", pouet);
	printf("%hh#X\n", pouet);
	printf("%#hhX\n", pouet);

	printf("\n##### %%#l[d.o.u.x.X] #####\n");

	printf("%l#d\n", pouet);
	printf("%#ld\n", pouet);
	printf("%l#o\n", pouet);
	printf("%#lo\n", pouet);
	printf("%l#u\n", pouet);
	printf("%#lu\n", pouet);
	printf("%l#x\n", pouet);
	printf("%#lx\n", pouet);
	printf("%l#X\n", pouet);
	printf("%#lX\n", pouet);

	printf("\n##### %%#ll[d.o.u.x.X] #####\n");

	printf("%ll#d\n", pouet);
	printf("%#lld\n", pouet);
	printf("%ll#o\n", pouet);
	printf("%#llo\n", pouet);
	printf("%ll#u\n", pouet);
	printf("%#llu\n", pouet);
	printf("%ll#x\n", pouet);
	printf("%#llx\n", pouet);
	printf("%ll#X\n", pouet);
	printf("%#llX\n", pouet);

	printf("\n##### SPECIAL CASES #####\n");
	printf("%5[bonj\n");
	printf("%1$d %1$x %3$d %d\n", d, 2, 3, 4);
	return (0);
}
