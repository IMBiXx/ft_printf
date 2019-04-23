#include <stdio.h>

int	main(void)
{
	printf("void *: %lu\n", sizeof(void *));
	printf("long long: %lu\n", sizeof(long long));
	printf("long: %lu\n", sizeof(long));
	printf("int: %lu\n", sizeof(int));
	printf("short: %lu\n", sizeof(short));
	printf("char: %lu\n", sizeof(char));
	return (0);
}
