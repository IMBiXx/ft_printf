#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	foo(int type, int count, ...)
{
	va_list ap;
	int d;
	char c, *s;

	va_start(ap, count);
	while (count--)
		switch (type) {
			case 0:
				s = va_arg(ap, char *);
				printf("chaîne %s\n", s);
				break;
			case 1:
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 2:
				c = (char)va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	va_end(ap);
}

void	print_memory(const void *addr, size_t size);

void	bar(int count, ...)
{
	va_list	ap;
	va_list	*aps;
	int		i;

	i = 0;
	aps = malloc(count * sizeof(va_list));
	va_start(ap, count);
	while (i < count)
	{
		va_copy(aps[i++], ap);
		va_arg(ap, int);
	}
	va_end(ap);
	va_copy(ap, aps[count - 2]);
	printf("%lld\n", va_arg(ap, long long));
	va_end(ap);
	va_copy(ap, aps[count - 1]);
	printf("%Lf\n", va_arg(ap, long double));
	va_end(ap);
	va_copy(ap, aps[count - 1]);
	printf("%s\n", va_arg(ap, char *));
	va_end(ap);
	i = 0;
	while (i < count)
	{
		va_end(aps[i++]);
	}
}
int	main(void)
{
	long long k = 123;
	long double l = 456;
	char *hel = "hello";

	bar(4, 1, 2, 3, hel);
	printf("%Lf\n", (long double)(long long)hel);
	return (0);
}
