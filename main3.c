#include "ft_printf.h"

int	main(void)
{
	t_style mystyle;

	mystyle = K_GREEN | K_M_BOLD | K_M_UNDER | (K_WHITE << K_BG_SHIFT);
	ft_printf("%d\n", ft_printf("%k%*d%K\n", mystyle, 5, 42));
	return (0);
}
