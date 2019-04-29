/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:47:26 by valecart          #+#    #+#             */
/*   Updated: 2019/04/29 08:21:52 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <string.h>
# include <stdarg.h>

enum				e_flags
{
	_FLAG_SH = 0,
	_FLAG_0,
	_FLAG_M,
	_FLAG_P,
	_FLAG_SP
};

typedef enum		e_mods
{
	MOD_HH = 0,
	MOD_H,
	MOD_NONE,
	MOD_L,
	MOD_LL,
	MOD_LLL
}					t_mods;

# define MAX(a, b)	((a) > (b) ? (a) : (b))

# define FLAG_SH	(1 << _FLAG_SH)
# define FLAG_0		(1 << _FLAG_0)
# define FLAG_M		(1 << _FLAG_M)
# define FLAG_P		(1 << _FLAG_P)
# define FLAG_SP		(1 << _FLAG_SP)

# define CONV_CHARS	"cspdiouxXf%kKbB"
# define FLAG_CHARS	"#0-+ "
# define MOD_CHARS	"lhL"

# define K_COL_MSK	0xffffffUL

# define K_M_BOLD	(1UL << 48)
# define K_M_NBOLD	(1UL << 49)
# define K_M_ITAL	(1UL << 50)
# define K_M_NITAL	(1UL << 51)
# define K_M_UNDER	(1UL << 52)
# define K_M_NUNDER	(1UL << 53)

# define K_BLACK	0x000000UL
# define K_RED		0xff0000UL
# define K_GREEN	0x00ff00UL
# define K_YELLOW	0xffff00UL
# define K_BLUE		0x0000ffUL
# define K_PURPLE	0xff00ffUL
# define K_CYAN		0x00ffffUL
# define K_WHITE	0xffffffUL

# define K_BG_SHIFT	24

typedef long		t_style;

typedef struct		s_conv_spec
{
	int				flags;
	unsigned int	field;
	unsigned int	precision;
	char			modifier;
	char			type;
	int				size;
}					t_conv_spec;

int					ft_printf(const char *restrict format, ...);

int					parse_print_format(char *format, va_list arg);

size_t				num_len_base(long long n, int base);
size_t				num_len_base_u(unsigned long long n, int base);
void				ft_putl_zer_base(long long n, int zer, char f_sgn, int b);
void				ft_putl_zer_base_u(unsigned long long n, int zer, int cas,
		int b);

long long			get_arg_int(t_conv_spec *cspec, va_list arg);
long double			get_arg_float(t_conv_spec *cspec, va_list arg);
unsigned long long	get_arg_uint(t_conv_spec *cspec, va_list arg);

void				ft_put_conv_spec(t_conv_spec *cspec, va_list arg, int *c);

int					put_d(t_conv_spec *cs, va_list arg);
int					put_x(t_conv_spec *cs, va_list arg);
int					put_o(t_conv_spec *cs, va_list arg);
int					put_c(t_conv_spec *cs, va_list arg);
int					put_s(t_conv_spec *cs, va_list arg);
int					put_f(t_conv_spec *cs, va_list arg);
int					put_k(t_conv_spec *cs, va_list arg);
int					put_b(t_conv_spec *cs, va_list arg);

void				put_nchars(int n, char c);
long long			cast_long_long(t_conv_spec *cspec, long long val);

#endif
