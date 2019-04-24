#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_conv_spec *s;
	long long args[10];
	int k;

	k = 0;
	args[0] = "bonjour les amis";
	args[1] = "salut les potes";
	/*s = parse_conv_spec("2$+20.10lls");*/
	/*args[0] = 'V';*/
	/*args[1] = 'T';*/
	s = parse_conv_spec("1$#-20.3lls");
	ft_put_conv_spec(s, &args, &k);
	ft_putendl("|");
	ft_putnbr(k);
	ft_putchar('\n');
	printf("%d\n", printf("%1$#-20.3lls", args[0], args[1]), printf("|\n"));
	return (0);
}
