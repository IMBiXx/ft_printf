#include <stdio.h>

int	main(void)
{
	printf("void *: %lu\n", sizeof(void *));
	printf("long double: %lu\n", sizeof(long double));
	printf("double: %lu\n", sizeof(double));
	printf("float: %lu\n", sizeof(float));
	printf("long long: %lu\n", sizeof(long long));
	printf("long: %lu\n", sizeof(long));
	printf("int: %lu\n", sizeof(int));
	printf("short: %lu\n", sizeof(short));
	printf("char: %lu\n", sizeof(char));
	return (0);
}
