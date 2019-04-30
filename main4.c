#include <stdio.h>

int main(void)
{
	printf("%d\n", -0.0 < -1e-308);
	printf("%d\n", 0.0 == -0.0);
	printf("%d\n", 0.0 == -0.0);
	return (0);
}
