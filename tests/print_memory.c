#include <unistd.h>
#include <string.h>

void	print_line_b(unsigned char *addr, size_t size)
{
	char	*alph;
	char	buff[8];
	size_t	s;
	int		i;
	unsigned char	tmp;

	s = 0;
	alph = "0123456789abcdef";
	while (s < 8)
	{
		if (s < size)
		{
			i = 0;
			tmp = addr[s];
			while (i < 8)
			{
				buff[i] = alph[tmp % 2];
				tmp /= 2;
				i++;
			}
			write(1, buff, 8);
		}
		else
			write(1, "        ", 8);
		write(1, " ", 1);
		s++;
	}
}

void	print_line_c(unsigned char *addr, size_t size)
{
	size_t			s;
	unsigned char	c;

	s = 0;
	while (s < size)
	{
		if ((c = addr[s++]) >= ' ' && c <= '~')
			write(1, &c, 1);
		else
			write(1, ".", 1);
	}
}

void	print_line_h(unsigned char *addr, size_t size)
{
	char	*alph;
	char	buff[2];
	size_t	s;

	s = 0;
	alph = "0123456789abcdef";
	while (s < 8)
	{
		if (s < size)
		{
			buff[0] = alph[addr[s] / 16];
			buff[1] = alph[addr[s] % 16];
			write(1, buff, 2);
		}
		else
			write(1, "  ", 2);
		if (s && s % 2)
			write(1, " ", 1);
		s++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t	s;

	s = 0;
	while (s < size)
	{
		print_line_h(((unsigned char *)addr) + s, size - s >= 8 ? 8 : size - s);
		print_line_b(((unsigned char *)addr) + s, size - s >= 8 ? 8 : size - s);
		print_line_c(((unsigned char *)addr) + s, size - s >= 8 ? 8 : size - s);
		write(1, "\n", 1);
		s += 8;
	}
}
