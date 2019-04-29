#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%+ f\n", 42.5);
	ft_printf("% f\n", 42.5);
	ft_printf("%f\n", -42.5);
	ft_printf("%+ d\n", 42);
	ft_printf("% d\n", 42);
	ft_printf("%d\n", -42);
	return (0);
}
