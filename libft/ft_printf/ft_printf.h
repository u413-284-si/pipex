/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:21:31 by sqiu              #+#    #+#             */
/*   Updated: 2022/11/17 13:09:31 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	hash;
	int	zero;
	int	minus;
	int	space;
	int	sign;
	int	dot;
	int	precision;
	int	width;
}	t_flags;

int		ft_printf(const char *fmt, ...);
char	*check_flags(const char	*fmt, t_flags *flags);
int		print_char(int c, int count, t_flags *flags);
int		print_spaces(int nb, int count, int conv, t_flags *flags);
int		print_zeroes(int nb, int count, int conv, t_flags *flags);
int		print_string(const char *s, int count, t_flags *flags);
int		print_adress(unsigned long ptr, int count, t_flags *flags);
int		print_decimal(int n, int count, t_flags *flags);
int		print_sign(int count, int sign);
int		print_unsigned(unsigned int n, int count, t_flags *flags);
int		print_spaces_u(int count, int conv, t_flags *flags);
int		print_hex(unsigned int n, int count, t_flags *flags);
int		print_zeroes_u(int count, int conv, t_flags *flags);
int		print_hash(int count);
int		print_spaces_x(int count, int conv, t_flags *flags);
int		print_hex_up(unsigned int n, int count, t_flags *flags);
int		print_hash_up(int count);
int		print_spaces_p(int count, int conv, t_flags *flags);
int		print_error_p(int count);
int		print_spaces_d(int nb, int count, int conv, t_flags *flags);
#endif