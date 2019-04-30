/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:48:09 by valecart          #+#    #+#             */
/*   Updated: 2019/04/30 21:25:25 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	double		nb;



	nb = -12547.58;
	printf("\n\n\n\ntest : %f|\n", nb);

	ft_printf("MON F EST FAIT:%.50f|\n", nb);
	printf("MON F EST FAIT:%.50f|\n", nb);
	ft_printf("my test basique:\n");
	ft_printf("my space:% f|\n", nb);
	printf("cl space:% f|\n", nb);
	ft_printf("my plus:%+f|\n", nb);
	printf("cl plus:%+f|\n", nb);
	ft_printf("my hash:%#f|\n", nb);
	printf("cl hash:%#f|\n", nb);
	ft_printf("my precision:%.2f|\n", nb);
	printf("cl precision:%.2f|\n", nb);
	ft_printf("my big prec:%.14f|\n", nb);
	printf("cl big prec:%.14f|\n", nb);
	ft_printf("my precision + hash:%#.0f|\n", nb);
	printf("cl precision + hash:%#.0f|\n", nb);
	ft_printf("my space + prec:% .5f|\n", nb);
	printf("cl space + prec:% .5f|\n", nb);
	ft_printf("my space + prec + hash:%# .0f|\n", nb);
	printf("cl space + prec + hash:%# .0f|\n", nb);
	ft_printf("my space + prec + hash:% #.0f|\n", nb);
	printf("cl space + prec + hash:% #.0f|\n", nb);
	ft_printf("my Plus + prec / grande:%+.5f|\n", nb);
	printf("cl Plus + prec / grande:%+.5f|\n", nb);
	ft_printf("my Plus + prec / petite:%+.0f|\n", nb);
	printf("cl Plus + prec / petite:%+.0f|\n", nb);
	ft_printf("my Plus + prec + hash:%#+.0f|\n", nb);
	printf("cl Plus + prec + hash:%#+.0f|\n", nb);
	ft_printf("my Prec + 0:%0.5f|\n", nb);
	printf("cl Prec + 0:%0.5f|\n", nb);
	ft_printf("my Prec + minus:%-.5f|\n", nb);
	printf("cl Prec + minus:%-.5f|\n", nb);
	ft_printf("my size:%5f|\n", nb);
	printf("cl size:%5f|\n", nb);
	ft_printf("my size + space:% 5f|\n", nb);
	printf("cl size + space:% 5f|\n", nb);
	ft_printf("my size + plus:%+5f|\n", nb);
	printf("cl size + plus:%+5f|\n", nb);
	ft_printf("my size + space:%# 5f|\n", nb);
	printf("cl size + space:%# 5f|\n", nb);
	ft_printf("my size + plus:%#+5f|\n", nb);
	printf("cl size + plus:%#+5f|\n", nb);
	ft_printf("my size + minus:%-5f|\n", nb);
	printf("cl size + minus:%-5f|\n", nb);
	ft_printf("my size + 0:%05f|\n", nb);
	printf("cl size + 0:%05f|\n", nb);
	ft_printf("my size + 0 + plus:%+05f|\n", nb);
	printf("cl size + 0 + plus:%+05f|\n", nb);
	ft_printf("my size + 0 + plus:%0+5f|\n", nb);
	printf("cl size + 0 + plus:%0+5f|\n", nb);
	ft_printf("my size + 0 + prec:%05.3f|\n", nb);
	printf("cl size + 0 + prec:%05.3f|\n", nb);
	ft_printf("my size + 0 + prec + hash:%0#5.0f|\n", nb);
	printf("cl size + 0 + prec + hash:%0#5.0f|\n", nb);
	ft_printf("my size + minus + prec:%-5.3f|\n", nb);
	printf("cl size + minus + prec:%-5.3f|\n", nb);
	ft_printf("my size + minus + prec + hash:%-#5.0f|\n", nb);
	printf("cl size + minus + prec + hash:%-#5.0f|\n", nb);
	ft_printf("my size + plus + 0 + prec:%+05.3f|\n", nb);
	printf("cl size + plus + 0 + prec:%+05.3f|\n", nb);
	ft_printf("my size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	printf("cl size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	ft_printf("my size + espace + zero + prec:%0 5.3f|\n", nb);
	printf("cl size + espace + zero + prec:%0 5.3f|\n", nb);
	ft_printf("my size + espace + zero + prec:% 05.3f|\n", nb);
	printf("cl size + espace + zero + prec:% 05.3f|\n", nb);
	ft_printf("my size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	printf("cl size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	ft_printf("my size + minus + plus + prec:%-+5.3f|\n", nb);
	printf("cl size + minus + plus + prec:%-+5.3f|\n", nb);
	ft_printf("my size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	printf("cl size + minus + plus + prec + hash:%-#+5.0f|\n", nb);

	/*nb = 0;*/
	nb = 0;
	printf("\n\n\n\ntest : %f|\n", nb);

	ft_printf("my test basique:\n");
    ft_printf("my space:% f|\n", nb);
	printf("cl space:% f|\n", nb);
    ft_printf("my plus:%+f|\n", nb);
	printf("cl plus:%+f|\n", nb);
    ft_printf("my hash:%#f|\n", nb);
	printf("cl hash:%#f|\n", nb);
    ft_printf("my precision:%.2f|\n", nb);
	printf("cl precision:%.2f|\n", nb);
    ft_printf("my big prec:%.14f|\n", nb);
	printf("cl big prec:%.14f|\n", nb);
    ft_printf("my precision + hash:%#.0f|\n", nb);
	printf("cl precision + hash:%#.0f|\n", nb);
    ft_printf("my space + prec:% .5f|\n", nb);
	printf("cl space + prec:% .5f|\n", nb);
    ft_printf("my space + prec + hash:%# .0f|\n", nb);
	printf("cl space + prec + hash:%# .0f|\n", nb);
    ft_printf("my space + prec + hash:% #.0f|\n", nb);
	printf("cl space + prec + hash:% #.0f|\n", nb);
    ft_printf("my Plus + prec / grande:%+.5f|\n", nb);
	printf("cl Plus + prec / grande:%+.5f|\n", nb);
    ft_printf("my Plus + prec / petite:%+.0f|\n", nb);
	printf("cl Plus + prec / petite:%+.0f|\n", nb);
    ft_printf("my Plus + prec + hash:%#+.0f|\n", nb);
	printf("cl Plus + prec + hash:%#+.0f|\n", nb);
    ft_printf("my Prec + 0:%0.5f|\n", nb);
	printf("cl Prec + 0:%0.5f|\n", nb);
    ft_printf("my Prec + minus:%-.5f|\n", nb);
	printf("cl Prec + minus:%-.5f|\n", nb);
    ft_printf("my size:%5f|\n", nb);
	printf("cl size:%5f|\n", nb);
    ft_printf("my size + space:% 5f|\n", nb);
	printf("cl size + space:% 5f|\n", nb);
    ft_printf("my size + plus:%+5f|\n", nb);
	printf("cl size + plus:%+5f|\n", nb);
    ft_printf("my size + space:%# 5f|\n", nb);
	printf("cl size + space:%# 5f|\n", nb);
    ft_printf("my size + plus:%#+5f|\n", nb);
	printf("cl size + plus:%#+5f|\n", nb);
    ft_printf("my size + minus:%-5f|\n", nb);
	printf("cl size + minus:%-5f|\n", nb);
    ft_printf("my size + 0:%05f|\n", nb);
	printf("cl size + 0:%05f|\n", nb);
    ft_printf("my size + 0 + plus:%+05f|\n", nb);
	printf("cl size + 0 + plus:%+05f|\n", nb);
    ft_printf("my size + 0 + plus:%0+5f|\n", nb);
	printf("cl size + 0 + plus:%0+5f|\n", nb);
    ft_printf("my size + 0 + prec:%05.3f|\n", nb);
	printf("cl size + 0 + prec:%05.3f|\n", nb);
    ft_printf("my size + 0 + prec + hash:%0#5.0f|\n", nb);
	printf("cl size + 0 + prec + hash:%0#5.0f|\n", nb);
    ft_printf("my size + minus + prec:%-5.3f|\n", nb);
	printf("cl size + minus + prec:%-5.3f|\n", nb);
    ft_printf("my size + minus + prec + hash:%-#5.0f|\n", nb);
	printf("cl size + minus + prec + hash:%-#5.0f|\n", nb);
    ft_printf("my size + plus + 0 + prec:%+05.3f|\n", nb);
	printf("cl size + plus + 0 + prec:%+05.3f|\n", nb);
    ft_printf("my size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	printf("cl size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
    ft_printf("my size + espace + zero + prec:%0 5.3f|\n", nb);
	printf("cl size + espace + zero + prec:%0 5.3f|\n", nb);
    ft_printf("my size + espace + zero + prec:% 05.3f|\n", nb);
	printf("cl size + espace + zero + prec:% 05.3f|\n", nb);
    ft_printf("my size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	printf("cl size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
    ft_printf("my size + minus + plus + prec:%-+5.3f|\n", nb);
	printf("cl size + minus + plus + prec:%-+5.3f|\n", nb);
    ft_printf("my size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	printf("cl size + minus + plus + prec + hash:%-#+5.0f|\n", nb);

    /*nb = 45.123456789;*/
    nb = 45.123456789;
	printf("\n\n\n\ntest : %f|\n", nb);

	ft_printf("my test basique:");
	ft_printf("my space:% f|\n", nb);
	printf("cl space:% f|\n", nb);
	ft_printf("my plus:%+f|\n", nb);
	printf("cl plus:%+f|\n", nb);
	ft_printf("my hash:%#f|\n", nb);
	printf("cl hash:%#f|\n", nb);
	ft_printf("my precision:%.2f|\n", nb);
	printf("cl precision:%.2f|\n", nb);
	ft_printf("my big prec:%.14f|\n", nb);
	printf("cl big prec:%.14f|\n", nb);
	ft_printf("my precision + hash:%#.0f|\n", nb);
	printf("cl precision + hash:%#.0f|\n", nb);
	ft_printf("my space + prec:% .5f|\n", nb);
	printf("cl space + prec:% .5f|\n", nb);
	ft_printf("my space + prec + hash:%# .0f|\n", nb);
	printf("cl space + prec + hash:%# .0f|\n", nb);
	ft_printf("my space + prec + hash:% #.0f|\n", nb);
	printf("cl space + prec + hash:% #.0f|\n", nb);
	ft_printf("my Plus + prec / grande:%+.5f|\n", nb);
	printf("cl Plus + prec / grande:%+.5f|\n", nb);
	ft_printf("my Plus + prec / petite:%+.0f|\n", nb);
	printf("cl Plus + prec / petite:%+.0f|\n", nb);
	ft_printf("my Plus + prec + hash:%#+.0f|\n", nb);
	printf("cl Plus + prec + hash:%#+.0f|\n", nb);
	ft_printf("my Prec + 0:%0.5f|\n", nb);
	printf("cl Prec + 0:%0.5f|\n", nb);
	ft_printf("my Prec + minus:%-.5f|\n", nb);
	printf("cl Prec + minus:%-.5f|\n", nb);
	ft_printf("my size:%5f|\n", nb);
	printf("cl size:%5f|\n", nb);
	ft_printf("my size + space:% 5f|\n", nb);
	printf("cl size + space:% 5f|\n", nb);
	ft_printf("my size + plus:%+5f|\n", nb);
	printf("cl size + plus:%+5f|\n", nb);
	ft_printf("my size + space:%# 5f|\n", nb);
	printf("cl size + space:%# 5f|\n", nb);
	ft_printf("my size + plus:%#+5f|\n", nb);
	printf("cl size + plus:%#+5f|\n", nb);
	ft_printf("my size + minus:%-5f|\n", nb);
	printf("cl size + minus:%-5f|\n", nb);
	ft_printf("my size + 0:%05f|\n", nb);
	printf("cl size + 0:%05f|\n", nb);
	ft_printf("my size + 0 + plus:%+05f|\n", nb);
	printf("cl size + 0 + plus:%+05f|\n", nb);
	ft_printf("my size + 0 + plus:%0+5f|\n", nb);
	printf("cl size + 0 + plus:%0+5f|\n", nb);
	ft_printf("my size + 0 + prec:%05.3f|\n", nb);
	printf("cl size + 0 + prec:%05.3f|\n", nb);
	ft_printf("my size + 0 + prec + hash:%0#5.0f|\n", nb);
	printf("cl size + 0 + prec + hash:%0#5.0f|\n", nb);
	ft_printf("my size + minus + prec:%-5.3f|\n", nb);
	printf("cl size + minus + prec:%-5.3f|\n", nb);
	ft_printf("my size + minus + prec + hash:%-#5.0f|\n", nb);
	printf("cl size + minus + prec + hash:%-#5.0f|\n", nb);
	ft_printf("my size + plus + 0 + prec:%+05.3f|\n", nb);
	printf("cl size + plus + 0 + prec:%+05.3f|\n", nb);
	ft_printf("my size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	printf("cl size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	ft_printf("my size + espace + zero + prec:%0 5.3f|\n", nb);
	printf("cl size + espace + zero + prec:%0 5.3f|\n", nb);
	ft_printf("my size + espace + zero + prec:% 05.3f|\n", nb);
	printf("cl size + espace + zero + prec:% 05.3f|\n", nb);
	ft_printf("my size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	printf("cl size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	ft_printf("my size + minus + plus + prec:%-+5.3f|\n", nb);
	printf("cl size + minus + plus + prec:%-+5.3f|\n", nb);
	ft_printf("my size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	printf("cl size + minus + plus + prec + hash:%-#+5.0f|\n", nb);

    /*nb = 12389123798;*/
    nb = 12389123798;
	printf("\n\n\n\ntest : %f|\n", nb);

	ft_printf("my test basique:");
	ft_printf("my space:% f|\n", nb);
	printf("cl space:% f|\n", nb);
	ft_printf("my plus:%+f|\n", nb);
	printf("cl plus:%+f|\n", nb);
	ft_printf("my hash:%#f|\n", nb);
	printf("cl hash:%#f|\n", nb);
	ft_printf("my precision:%.2f|\n", nb);
	printf("cl precision:%.2f|\n", nb);
	//    ft_printf("my big prec:%.14f|\n", nb);
	//    ft_printf("my big prec:%.14f|\n", nb);
	ft_printf("my precision + hash:%#.0f|\n", nb);
	printf("cl precision + hash:%#.0f|\n", nb);
	ft_printf("my space + prec:% .5f|\n", nb);
	printf("cl space + prec:% .5f|\n", nb);
	ft_printf("my space + prec + hash:%# .0f|\n", nb);
	printf("cl space + prec + hash:%# .0f|\n", nb);
	ft_printf("my space + prec + hash:% #.0f|\n", nb);
	printf("cl space + prec + hash:% #.0f|\n", nb);
	ft_printf("my Plus + prec / grande:%+.5f|\n", nb);
	printf("cl Plus + prec / grande:%+.5f|\n", nb);
	ft_printf("my Plus + prec / petite:%+.0f|\n", nb);
	printf("cl Plus + prec / petite:%+.0f|\n", nb);
	ft_printf("my Plus + prec + hash:%#+.0f|\n", nb);
	printf("cl Plus + prec + hash:%#+.0f|\n", nb);
	ft_printf("my Prec + 0:%0.5f|\n", nb);
	printf("cl Prec + 0:%0.5f|\n", nb);
	ft_printf("my Prec + minus:%-.5f|\n", nb);
	printf("cl Prec + minus:%-.5f|\n", nb);
	ft_printf("my size:%5f|\n", nb);
	printf("cl size:%5f|\n", nb);
	ft_printf("my size + space:% 5f|\n", nb);
	printf("cl size + space:% 5f|\n", nb);
	ft_printf("my size + plus:%+5f|\n", nb);
	printf("cl size + plus:%+5f|\n", nb);
	ft_printf("my size + space:%# 5f|\n", nb);
	printf("cl size + space:%# 5f|\n", nb);
	ft_printf("my size + plus:%#+5f|\n", nb);
	printf("cl size + plus:%#+5f|\n", nb);
	ft_printf("my size + minus:%-5f|\n", nb);
	printf("cl size + minus:%-5f|\n", nb);
	ft_printf("my size + 0:%05f|\n", nb);
	printf("cl size + 0:%05f|\n", nb);
	ft_printf("my size + 0 + plus:%+05f|\n", nb);
	printf("cl size + 0 + plus:%+05f|\n", nb);
	ft_printf("my size + 0 + plus:%0+5f|\n", nb);
	printf("cl size + 0 + plus:%0+5f|\n", nb);
	ft_printf("my size + 0 + prec:%05.3f|\n", nb);
	printf("cl size + 0 + prec:%05.3f|\n", nb);
	ft_printf("my size + 0 + prec + hash:%0#5.0f|\n", nb);
	printf("cl size + 0 + prec + hash:%0#5.0f|\n", nb);
	ft_printf("my size + minus + prec:%-5.3f|\n", nb);
	printf("cl size + minus + prec:%-5.3f|\n", nb);
	ft_printf("my size + minus + prec + hash:%-#5.0f|\n", nb);
	printf("cl size + minus + prec + hash:%-#5.0f|\n", nb);
	ft_printf("my size + plus + 0 + prec:%+05.3f|\n", nb);
	printf("cl size + plus + 0 + prec:%+05.3f|\n", nb);
	ft_printf("my size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	printf("cl size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	ft_printf("my size + espace + zero + prec:%0 5.3f|\n", nb);
	printf("cl size + espace + zero + prec:%0 5.3f|\n", nb);
	ft_printf("my size + espace + zero + prec:% 05.3f|\n", nb);
	printf("cl size + espace + zero + prec:% 05.3f|\n", nb);
	ft_printf("my size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	printf("cl size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	ft_printf("my size + minus + plus + prec:%-+5.3f|\n", nb);
	printf("cl size + minus + plus + prec:%-+5.3f|\n", nb);
	ft_printf("my size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	printf("cl size + minus + plus + prec + hash:%-#+5.0f|\n", nb);




    /*nb = -8965421.12356432156;*/
    nb = -8965421.12356432156;
	printf("\n\n\n\ntest : %f|\n", nb);

	ft_printf("my test basique:\n");
	ft_printf("my space:% f|\n", nb);
	printf("cl space:% f|\n", nb);
	ft_printf("my plus:%+f|\n", nb);
	printf("cl plus:%+f|\n", nb);
	ft_printf("my hash:%#f|\n", nb);
	printf("cl hash:%#f|\n", nb);
	ft_printf("my precision:%.2f|\n", nb);
	printf("cl precision:%.2f|\n", nb);
	//    ft_printf("my big prec:%.14f|\n", nb);
	//    ft_printf("my big prec:%.14f|\n", nb);
	ft_printf("my precision + hash:%#.0f|\n", nb);
	printf("cl precision + hash:%#.0f|\n", nb);
	ft_printf("my space + prec:% .5f|\n", nb);
	printf("cl space + prec:% .5f|\n", nb);
	ft_printf("my space + prec + hash:%# .0f|\n", nb);
	printf("cl space + prec + hash:%# .0f|\n", nb);
	ft_printf("my space + prec + hash:% #.0f|\n", nb);
	printf("cl space + prec + hash:% #.0f|\n", nb);
	ft_printf("my Plus + prec / grande:%+.5f|\n", nb);
	printf("cl Plus + prec / grande:%+.5f|\n", nb);
	ft_printf("my Plus + prec / petite:%+.0f|\n", nb);
	printf("cl Plus + prec / petite:%+.0f|\n", nb);
	ft_printf("my Plus + prec + hash:%#+.0f|\n", nb);
	printf("cl Plus + prec + hash:%#+.0f|\n", nb);
	ft_printf("my Prec + 0:%0.5f|\n", nb);
	printf("cl Prec + 0:%0.5f|\n", nb);
	ft_printf("my Prec + minus:%-.5f|\n", nb);
	printf("cl Prec + minus:%-.5f|\n", nb);
	ft_printf("my size:%5f|\n", nb);
	printf("cl size:%5f|\n", nb);
	ft_printf("my size + space:% 5f|\n", nb);
	printf("cl size + space:% 5f|\n", nb);
	ft_printf("my size + plus:%+5f|\n", nb);
	printf("cl size + plus:%+5f|\n", nb);
	ft_printf("my size + space:%# 5f|\n", nb);
	printf("cl size + space:%# 5f|\n", nb);
	ft_printf("my size + plus:%#+5f|\n", nb);
	printf("cl size + plus:%#+5f|\n", nb);
	ft_printf("my size + minus:%-5f|\n", nb);
	printf("cl size + minus:%-5f|\n", nb);
	ft_printf("my size + 0:%05f|\n", nb);
	printf("cl size + 0:%05f|\n", nb);
	ft_printf("my size + 0 + plus:%+05f|\n", nb);
	printf("cl size + 0 + plus:%+05f|\n", nb);
	ft_printf("my size + 0 + plus:%0+5f|\n", nb);
	printf("cl size + 0 + plus:%0+5f|\n", nb);
	ft_printf("my size + 0 + prec:%05.3f|\n", nb);
	printf("cl size + 0 + prec:%05.3f|\n", nb);
	ft_printf("my size + 0 + prec + hash:%0#5.0f|\n", nb);
	printf("cl size + 0 + prec + hash:%0#5.0f|\n", nb);
	ft_printf("my size + minus + prec:%-5.3f|\n", nb);
	printf("cl size + minus + prec:%-5.3f|\n", nb);
	ft_printf("my size + minus + prec + hash:%-#5.0f|\n", nb);
	printf("cl size + minus + prec + hash:%-#5.0f|\n", nb);
	ft_printf("my size + plus + 0 + prec:%+05.3f|\n", nb);
	printf("cl size + plus + 0 + prec:%+05.3f|\n", nb);
	ft_printf("my size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	printf("cl size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	ft_printf("my size + espace + zero + prec:%0 5.3f|\n", nb);
	printf("cl size + espace + zero + prec:%0 5.3f|\n", nb);
	ft_printf("my size + espace + zero + prec:% 05.3f|\n", nb);
	printf("cl size + espace + zero + prec:% 05.3f|\n", nb);
	ft_printf("my size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	printf("cl size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	ft_printf("my size + minus + plus + prec:%-+5.3f|\n", nb);
	printf("cl size + minus + plus + prec:%-+5.3f|\n", nb);
	ft_printf("my size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	printf("cl size + minus + plus + prec + hash:%-#+5.0f|\n", nb);




    /*nb = 1.0/0.0;*/
    nb = 1.0/0.0;
	printf("\n\n\n\ntest : %f|\n", nb);
	ft_printf("my %f|\n", nb);
	printf("cl %f|\n", nb);
	ft_printf("my %12f|\n", nb);
	printf("cl %12f|\n", nb);
	ft_printf("my %-12f|\n", nb);
	printf("cl %-12f|\n", nb);
	ft_printf("my %5.9f|\n", nb);
	printf("cl %5.9f|\n", nb);

    nb = -1.0/0.0;
	ft_printf("my %f|\n", nb);
	printf("cl %f|\n", nb);
	ft_printf("my %12f|\n", nb);
	printf("cl %12f|\n", nb);
	ft_printf("my %-12f|\n", nb);
	printf("cl %-12f|\n", nb);
	ft_printf("my %5.9f|\n", nb);
	printf("cl %5.9f|\n", nb);

	nb = 0.0/0.0;
	ft_printf("my %f|\n", nb);
	printf("cl %f|\n", nb);
	ft_printf("my %12f|\n", nb);
	printf("cl %12f|\n", nb);
	ft_printf("my %-12f|\n", nb);
	printf("cl %-12f|\n", nb);
	ft_printf("my %5.9f|\n", nb);
	printf("cl %5.9f|\n", nb);



	/*nb = -0.000;*/
	nb = -0.000;
	printf("\n\n\n\ntest : %f|\n", nb);

	ft_printf("my test basique:\n");
	ft_printf("my space:% f|\n", nb);
	printf("cl space:% f|\n", nb);
	ft_printf("my plus:%+f|\n", nb);
	printf("cl plus:%+f|\n", nb);
	ft_printf("my hash:%#f|\n", nb);
	printf("cl hash:%#f|\n", nb);
	ft_printf("my precision:%.2f|\n", nb);
	printf("cl precision:%.2f|\n", nb);
	ft_printf("my big prec:%.14f|\n", nb);
	printf("cl big prec:%.14f|\n", nb);
	ft_printf("my precision + hash:%#.0f|\n", nb);
	printf("cl precision + hash:%#.0f|\n", nb);
	ft_printf("my space + prec:% .5f|\n", nb);
	printf("cl space + prec:% .5f|\n", nb);
	ft_printf("my space + prec + hash:%# .0f|\n", nb);
	printf("cl space + prec + hash:%# .0f|\n", nb);
	ft_printf("my space + prec + hash:% #.0f|\n", nb);
	printf("cl space + prec + hash:% #.0f|\n", nb);
	ft_printf("my Plus + prec / grande:%+.5f|\n", nb);
	printf("cl Plus + prec / grande:%+.5f|\n", nb);
	ft_printf("my Plus + prec / petite:%+.0f|\n", nb);
	printf("cl Plus + prec / petite:%+.0f|\n", nb);
	ft_printf("my Plus + prec + hash:%#+.0f|\n", nb);
	printf("cl Plus + prec + hash:%#+.0f|\n", nb);
	ft_printf("my Prec + 0:%0.5f|\n", nb);
	printf("cl Prec + 0:%0.5f|\n", nb);
	ft_printf("my Prec + minus:%-.5f|\n", nb);
	printf("cl Prec + minus:%-.5f|\n", nb);
	ft_printf("my size:%5f|\n", nb);
	printf("cl size:%5f|\n", nb);
	ft_printf("my size + space:% 5f|\n", nb);
	printf("cl size + space:% 5f|\n", nb);
	ft_printf("my size + plus:%+5f|\n", nb);
	printf("cl size + plus:%+5f|\n", nb);
	ft_printf("my size + space:%# 5f|\n", nb);
	printf("cl size + space:%# 5f|\n", nb);
	ft_printf("my size + plus:%#+5f|\n", nb);
	printf("cl size + plus:%#+5f|\n", nb);
	ft_printf("my size + minus:%-5f|\n", nb);
	printf("cl size + minus:%-5f|\n", nb);
	ft_printf("my size + 0:%05f|\n", nb);
	printf("cl size + 0:%05f|\n", nb);
	ft_printf("my size + 0 + plus:%+05f|\n", nb);
	printf("cl size + 0 + plus:%+05f|\n", nb);
	ft_printf("my size + 0 + plus:%0+5f|\n", nb);
	printf("cl size + 0 + plus:%0+5f|\n", nb);
	ft_printf("my size + 0 + prec:%05.3f|\n", nb);
	printf("cl size + 0 + prec:%05.3f|\n", nb);
	ft_printf("my size + 0 + prec + hash:%0#5.0f|\n", nb);
	printf("cl size + 0 + prec + hash:%0#5.0f|\n", nb);
	ft_printf("my size + minus + prec:%-5.3f|\n", nb);
	printf("cl size + minus + prec:%-5.3f|\n", nb);
	ft_printf("my size + minus + prec + hash:%-#5.0f|\n", nb);
	printf("cl size + minus + prec + hash:%-#5.0f|\n", nb);
	ft_printf("my size + plus + 0 + prec:%+05.3f|\n", nb);
	printf("cl size + plus + 0 + prec:%+05.3f|\n", nb);
	ft_printf("my size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	printf("cl size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	ft_printf("my size + espace + zero + prec:%0 5.3f|\n", nb);
	printf("cl size + espace + zero + prec:%0 5.3f|\n", nb);
	ft_printf("my size + espace + zero + prec:% 05.3f|\n", nb);
	printf("cl size + espace + zero + prec:% 05.3f|\n", nb);
	ft_printf("my size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	printf("cl size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	ft_printf("my size + minus + plus + prec:%-+5.3f|\n", nb);
	printf("cl size + minus + plus + prec:%-+5.3f|\n", nb);
	ft_printf("my size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	printf("cl size + minus + plus + prec + hash:%-#+5.0f|\n", nb);

	return 0;
}
