#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_conv_spec s;
	long long args[10];
	int k;

	k = 0;
	args[0] = 42;
	s.flags = 0;
	s.field = 0;
	s.precision = 0;
	s.modifier = MOD_NONE;
	s.type = 'd';
	s.arg_index = 0;
	s.size = 0;
	ft_put_conv_spec(&s, &args, &k);
	ft_putchar('\n');
	ft_putlong(k);
	ft_putchar('\n');
	return (0);
}
