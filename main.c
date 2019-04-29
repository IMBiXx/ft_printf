#include <stdio.h>
#include "ft_printf.h"

int	main(int ac, char **av)
{
	/*int	k;*/

	/*if (ac != 2)*/
		/*return (-1);*/
	/*ft_putstr("Mine: |");*/
	/*k = ft_printf(av[1], 'A', 45.123456789, 42, 42.98765432101111, 42.12349L, "hello world", 4242424242424242);*/
	/*ft_putstr("| (");*/
	/*ft_putnbr(k);*/
	/*ft_putstr(")\nOrig: |");*/
	/*k = printf(av[1], 'A', 45.123456789, 42, 42.98765432101111, 42.12349L, "hello world", 4242424242424242);*/
	/*printf("| (%d)\n", k);*/
	double		nb;
	nb = -12547.58;

	ft_printf("test basique:");
    ft_printf("space:% f\n", nb);
    ft_printf("plus:%+f\n", nb);
    ft_printf("hash:%#f\n", nb);
    ft_printf("precision:%.2f\n", nb);
    ft_printf("big prec:%.14f\n", nb);
    printf("big prec:%.14f\n", nb);
    printf("big prec:%f\n", nb);
    ft_printf("precision + hash:%#.0f\n", nb);
    ft_printf("space + prec:% .5f\n", nb);
    ft_printf("space + prec + hash:%# .0f\n", nb);
    ft_printf("space + prec + hash:% #.0f\n", nb);
    ft_printf("Plus + prec / grande:%+.5f\n", nb);
    ft_printf("Plus + prec / petite:%+.0f\n", nb);
    ft_printf("Plus + prec + hash:%#+.0f\n", nb);
    ft_printf("Prec + 0:%0.5f\n", nb);
    ft_printf("Prec + minus:%-.5f\n", nb);
    ft_printf("size:%5f\n", nb);
    ft_printf("size + space:% 5f\n", nb);
    ft_printf("size + plus:%+5f\n", nb);
    ft_printf("size + space:%# 5f\n", nb);
    ft_printf("size + plus:%#+5f\n", nb);
    ft_printf("size + minus:%-5f\n", nb);
    ft_printf("size + 0:%05f\n", nb);
    ft_printf("size + 0 + plus:%+05f\n", nb);
    ft_printf("size + 0 + plus:%0+5f\n", nb);
    ft_printf("size + 0 + prec:%05.3f\n", nb);
    ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
    ft_printf("size + minus + prec:%-5.3f\n", nb);
    ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
    ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
    ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
    ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
    ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
    ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);
	return (0);
}
