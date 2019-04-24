#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_conv_spec s;
	long long args[10];
	int k;

	k = 0;
	args[0] = 372036854775807;
	s.flags = FLAG_P | FLAG_M;
	s.field = 20;
	s.precision = 18;
	s.modifier = 2;
	s.type = 'd';
	s.arg_index = 0;
	s.size = 0;
	ft_put_conv_spec(&s, &args, &k);
	ft_putendl("|");
	ft_putnbr(k);
	ft_putchar('\n');
	printf("%d\n", printf("%+-20.18lld", args[0]), printf("|\n"));
	s.modifier = -2;
	k = 0;
	ft_put_conv_spec(&s, &args, &k);
	ft_putendl("|");
	ft_putnbr(k);
	ft_putchar('\n');
	printf("%d\n", printf("%+-20.18hhd", args[0]), printf("|\n"));
	s.flags = FLAG_M;
	s.modifier = 2;
	k = 0;
	ft_put_conv_spec(&s, &args, &k);
	ft_putendl("|");
	ft_putnbr(k);
	ft_putchar('\n');
	printf("%d\n", printf("%-20.18lld", args[0]), printf("|\n"));
	s.modifier = -2;
	k = 0;
	ft_put_conv_spec(&s, &args, &k);
	ft_putendl("|");
	ft_putnbr(k);
	ft_putchar('\n');
	printf("%d\n", printf("%-20.18hhd", args[0]), printf("|\n"));
	return (0);
}
