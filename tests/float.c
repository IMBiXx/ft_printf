#include "ft_printf.h"

int	main(void)
{
	float f = 420.10003;
	ft_putnbr((int)f);
	f -= (int)f;
	ft_putchar('.');
	ft_putnbr((int)(f * 1000));
	return (0);
}
