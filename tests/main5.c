#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%#.o\n", 0);
	ft_printf("%#.o\n", 0);
	printf("%#.0o\n", 0);
	ft_printf("%#.0o\n", 0);
	printf("%3.o\n", 0);
	ft_printf("%3.o\n", 0);
	printf("%#o\n", 0);
	ft_printf("%#o\n", 0);
	printf("%#o\n", 0);
	ft_printf("%#o\n", 0);
	printf("%#3o\n", 0);
	ft_printf("%#3o\n", 0);
	printf("%#o\n", 1);
	ft_printf("%#o\n", 1);
	printf("%#3o\n", 1);
	ft_printf("%#3o\n", 1);
	printf("%#.3o\n", 1);
	ft_printf("%#.3o\n", 1);
}
