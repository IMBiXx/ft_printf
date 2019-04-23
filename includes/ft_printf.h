/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:47:26 by valecart          #+#    #+#             */
/*   Updated: 2019/04/23 20:24:10 by tpotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>

enum			e_flags
{
	_FLAG_SH = 0,
	_FLAG_0,
	_FLAG_M,
	_FLAG_P
};

typedef enum	e_modifiers
{
	MOD_NONE = 0,
	MOD_HH,
	MOD_H,
	MOD_L,
	MOD_LL,
	MOD_GL
}				t_modifiers;

# define MAX(a, b)	((a) > (b) ? (a) : (b))

# define FLAG_SH	(1 << _FLAG_SH)
# define FLAG_0		(1 << _FLAG_0)
# define FLAG_M		(1 << _FLAG_M)
# define FLAG_P		(1 << _FLAG_P)

# define CONV_CHARS	"cspdiouxX"

typedef struct	s_conv_spec
{
	int			flags;
	int			field;
	int			precision;
	t_modifiers	modifier;
	char		type;
	int			arg_index;
	int			size;
}				t_conv_spec;



size_t	num_len(long long n, int base);
void	ft_put_conv_spec(t_conv_spec *cspec, void *args, int *count);
void	ft_putlong(long long n);

#endif
