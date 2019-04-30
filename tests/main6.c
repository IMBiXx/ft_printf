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


	/*float		nb;*/
	/*nb = 0;*/
	/*ft_printf("null prec : %.0f\n", nb);*/
	/*dprintf(2, "null prec : %.0f\n", nb);*/
	/*printf("\n\n\n");*/
	/*nb = 12.5;*/
	/*ft_printf("null prec : %+.f\n", nb);*/
	/*dprintf(2, "null prec : %+.f\n", nb);*/
	/*printf("\n\n\n");*/
	/*nb = -25632.2541;*/
	/*ft_printf("null prec : %+.0f\n", nb);*/
	/*dprintf(2, "null prec : %+.0f\n", nb);*/
	/*printf("\n\n\n");*/
	/*nb = -1.0123;*/
	/*ft_printf("null prec : %+.0f\n", nb);*/
	/*dprintf(2, "null prec : %+.0f\n", nb);*/
	/*printf("\n\n\n");*/
	/*nb = 12354.569874;*/
	/*ft_printf("null prec : %+.0f\n", nb);*/
	/*dprintf(2, "null prec : %+.0f\n", nb);*/
	/*printf("\n\n\n");*/


	double		nb;
	nb = -12547.58;

	ft_printf("my test basique:\n");
	ft_printf("my space:% f|\n", nb);
	dprintf(2, "cl space:% f|\n", nb);
	ft_printf("my plus:%+f|\n", nb);
	dprintf(2, "cl plus:%+f|\n", nb);
	ft_printf("my hash:%#f|\n", nb);
	dprintf(2, "cl hash:%#f|\n", nb);
	ft_printf("my precision:%.2f|\n", nb);
	dprintf(2, "cl precision:%.2f|\n", nb);
	ft_printf("my big prec:%.14f|\n", nb);
	dprintf(2, "cl big prec:%.14f|\n", nb);
	ft_printf("my precision + hash:%#.0f|\n", nb);
	dprintf(2, "cl precision + hash:%#.0f|\n", nb);
	ft_printf("my space + prec:% .5f|\n", nb);
	dprintf(2, "cl space + prec:% .5f|\n", nb);
	ft_printf("my space + prec + hash:%# .0f|\n", nb);
	dprintf(2, "cl space + prec + hash:%# .0f|\n", nb);
	ft_printf("my space + prec + hash:% #.0f|\n", nb);
	dprintf(2, "cl space + prec + hash:% #.0f|\n", nb);
	ft_printf("my Plus + prec / grande:%+.5f|\n", nb);
	dprintf(2, "cl Plus + prec / grande:%+.5f|\n", nb);
	ft_printf("my Plus + prec / petite:%+.0f|\n", nb);
	dprintf(2, "cl Plus + prec / petite:%+.0f|\n", nb);
	ft_printf("my Plus + prec + hash:%#+.0f|\n", nb);
	dprintf(2, "cl Plus + prec + hash:%#+.0f|\n", nb);
	ft_printf("my Prec + 0:%0.5f|\n", nb);
	dprintf(2, "cl Prec + 0:%0.5f|\n", nb);
	ft_printf("my Prec + minus:%-.5f|\n", nb);
	dprintf(2, "cl Prec + minus:%-.5f|\n", nb);
	ft_printf("my size:%5f|\n", nb);
	dprintf(2, "cl size:%5f|\n", nb);
	ft_printf("my size + space:% 5f|\n", nb);
	dprintf(2, "cl size + space:% 5f|\n", nb);
	ft_printf("my size + plus:%+5f|\n", nb);
	dprintf(2, "cl size + plus:%+5f|\n", nb);
	ft_printf("my size + space:%# 5f|\n", nb);
	dprintf(2, "cl size + space:%# 5f|\n", nb);
	ft_printf("my size + plus:%#+5f|\n", nb);
	dprintf(2, "cl size + plus:%#+5f|\n", nb);
	ft_printf("my size + minus:%-5f|\n", nb);
	dprintf(2, "cl size + minus:%-5f|\n", nb);
	ft_printf("my size + 0:%05f|\n", nb);
	dprintf(2, "cl size + 0:%05f|\n", nb);
	ft_printf("my size + 0 + plus:%+05f|\n", nb);
	dprintf(2, "cl size + 0 + plus:%+05f|\n", nb);
	ft_printf("my size + 0 + plus:%0+5f|\n", nb);
	dprintf(2, "cl size + 0 + plus:%0+5f|\n", nb);
	ft_printf("my size + 0 + prec:%05.3f|\n", nb);
	dprintf(2, "cl size + 0 + prec:%05.3f|\n", nb);
	ft_printf("my size + 0 + prec + hash:%0#5.0f|\n", nb);
	dprintf(2, "cl size + 0 + prec + hash:%0#5.0f|\n", nb);
	ft_printf("my size + minus + prec:%-5.3f|\n", nb);
	dprintf(2, "cl size + minus + prec:%-5.3f|\n", nb);
	ft_printf("my size + minus + prec + hash:%-#5.0f|\n", nb);
	dprintf(2, "cl size + minus + prec + hash:%-#5.0f|\n", nb);
	ft_printf("my size + plus + 0 + prec:%+05.3f|\n", nb);
	dprintf(2, "cl size + plus + 0 + prec:%+05.3f|\n", nb);
	ft_printf("my size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	dprintf(2, "cl size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	ft_printf("my size + espace + zero + prec:%0 5.3f|\n", nb);
	dprintf(2, "cl size + espace + zero + prec:%0 5.3f|\n", nb);
	ft_printf("my size + espace + zero + prec:% 05.3f|\n", nb);
	dprintf(2, "cl size + espace + zero + prec:% 05.3f|\n", nb);
	ft_printf("my size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	dprintf(2, "cl size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	ft_printf("my size + minus + plus + prec:%-+5.3f|\n", nb);
	dprintf(2, "cl size + minus + plus + prec:%-+5.3f|\n", nb);
	ft_printf("my size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	dprintf(2, "cl size + minus + plus + prec + hash:%-#+5.0f|\n", nb);



	/*int		nb;*/
	/*nb = 0;*/
	/*ft_printf("my null prec : %+.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %+.0d|\n", nb);*/
	/*printf("\n\n");*/
	/*nb = 8;*/
	/*ft_printf("my null prec : %+.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %+.0d|\n", nb);*/
	/*printf("\n\n");*/
	/*nb = -1234212;*/
	/*ft_printf("my null prec : %+.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %+.0d|\n", nb);*/
	/*printf("\n\n");*/

	/*nb = 0;*/
	/*ft_printf("my null prec : %.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %.0d|\n", nb);*/
	/*printf("\n\n");*/
	/*nb = 8;*/
	/*ft_printf("my null prec : %.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %.0d|\n", nb);*/
	/*printf("\n\n");*/
	/*nb = -1234212;*/
	/*ft_printf("my null prec : %.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %.0d|\n", nb);*/
	/*printf("\n\n");*/

	/*nb = 0;*/
	/*ft_printf("my null prec : % .0d|\n", nb);*/
	/*dprintf(2, "cl null prec : % .0d|\n", nb);*/
	/*printf("\n\n");*/
	/*ft_printf("my null prec : %+.d|\n", nb);*/
	/*dprintf(2, "cl null prec : %+.d|\n", nb);*/
	/*printf("\n\n");*/
	/*ft_printf("my null prec : %.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %.0d|\n", nb);*/
	/*printf("\n\n");*/
	/*ft_printf("my null prec : %012.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %012.0d|\n", nb);*/
	/*printf("\n\n");*/
	/*ft_printf("my null prec : %-.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %-.0d|\n", nb);*/
	/*printf("\n\n");*/
	/*ft_printf("my null prec : %-12.0d|\n", nb);*/
	/*dprintf(2, "cl null prec : %-12.0d|\n", nb);*/
	/*printf("\n\n");*/
	return (0);
}
