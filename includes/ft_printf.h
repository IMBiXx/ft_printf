/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:47:26 by valecart          #+#    #+#             */
/*   Updated: 2019/04/25 18:24:14 by tpotier          ###   ########.fr       */
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
	_FLAG_P
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

# define CONV_CHARS	"cspdiouxX"
# define FLAG_CHARS	"#0-+"
# define MOD_CHARS	"lhL"

typedef struct		s_conv_spec
{
	int				flags;
	int				field;
	int				precision;
	char			modifier;
	char			type;
	int				arg_index;
	int				size;
}					t_conv_spec;

int					ft_printf(const char * restrict format, ...);

t_list				*parse_format(char *format);

size_t				num_len_base(long long n, int base);
size_t				num_len_base_u(unsigned long long n, int base);
void				ft_putl_zer_base(long long n, int zer, char f_sgn, int b);
void				ft_putl_zer_base_u(unsigned long long n, int zer, int cas,
		int b);

long long			get_arg_int(t_conv_spec *cspec, va_list arg);
long double			get_arg_float(t_conv_spec *cspec, va_list arg);
long long			get_arg_uint(t_conv_spec *cspec, va_list arg);

void				ft_put_conv_spec(t_conv_spec *cspec, void *args,
		int *count);
t_conv_spec			*parse_conv_spec(char *format);
int					put_d(t_conv_spec *cspec, va_list arg);
int					put_x(t_conv_spec *cspec, va_list arg);
int					put_o(t_conv_spec *cspec, va_list arg);
int					put_s(t_conv_spec *conv_spec, long long *args);
void				put_nchars(int n, char c);
long long			cast_long_long(t_conv_spec *cspec, long long val);
int					put_c(t_conv_spec *conv_spec, long long *args);

#endif
