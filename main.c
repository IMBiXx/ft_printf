#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
	printf("%ld\n", num_len(-42, 10));
	printf("%ld\n", num_len(255, 10));
	printf("%ld\n", num_len(255, 16));
	printf("%ld\n", num_len(-200000, 10));
	printf("%ld\n", num_len(0, 10));
	return (0);
}
