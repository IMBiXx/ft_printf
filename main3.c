#include "ft_printf.h"

int	main(void)
{
	t_style mystyle;

	mystyle = K_PURPLE | K_M_BOLD | K_M_UNDER | (K_YELLOW << K_BG_SHIFT);
	ft_printf("%d\n", ft_printf("%k%lld%K\n", mystyle, 424242424242424242L));
	return (0);
}
