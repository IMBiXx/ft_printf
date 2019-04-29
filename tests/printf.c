#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		printf(av[1], 'a', 42, 42.0f, "hello");
	return (0);
}
