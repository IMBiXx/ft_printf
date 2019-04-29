#include <stdio.h>
#include "ft_printf.h"

int	main(int ac, char **av)
{
	int	k;

	if (ac != 2)
		return (-1);
	ft_putstr("Mine: |");
	k = ft_printf(av[1], 'A', 0, 42, 42.98765432101111, 42.0123456L, "hel\blo wo\xFFrld\n", 4242424242424242);
	ft_putstr("| (");
	ft_putnbr(k);
	ft_putstr(")\nOrig: |");
	k = printf(av[1], 'A', 0, 42, 42.98765432101111, 42.0123456L, "hello world", 4242424242424242);
	printf("| (%d)\n", k);
	return (0);
}
