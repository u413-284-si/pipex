/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:52:54 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 10:12:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	set_conv(const char *s, t_flags *flags);
static int		print_s(const char *s, int count, t_flags *flags);
static int		print_error(int count, t_flags *flags);

/*
If given string pointer is NULL, print error message (null). When width is
specified, print spaces minus 6 (= amount of chars in error message).
Count chars to be printed.
Differentiate between left or right justification.
*/
int	print_string(const char *s, int count, t_flags *flags)
{
	size_t	conv;

	conv = 6;
	if (!s)
	{
		count = print_spaces(1, count, (int)conv, flags);
		count = print_error(count, flags);
		return (count);
	}
	conv = set_conv(s, flags);
	if (flags->minus == 1)
	{
		count = print_s(s, count, flags);
		count = print_spaces(1, count, (int)conv, flags);
	}
	else
	{
		count = print_spaces(1, count, (int)conv, flags);
		count = print_s(s, count, flags);
	}
	return (count);
}

/*
Print string, if precision is specified, only print chars until 
precision value is reached.
*/
static int	print_s(const char *s, int count, t_flags *flags)
{
	if (flags->dot == 0)
	{
		while (*s)
		{
			ft_putchar_fd(*s, 1);
			s++;
			count++;
		}
	}
	else
	{
		while (*s && flags->precision-- > 0)
		{
			ft_putchar_fd(*s, 1);
			s++;
			count++;
		}
	}
	return (count);
}

/*
If no precision is given or width less than precision (?), chars to be
printed = string length.
If precision is given, chars to be
printed = precision value.
*/
static size_t	set_conv(const char *s, t_flags *flags)
{
	size_t	conv;

	if (flags->dot == 0 || flags->width < flags->precision)
		conv = ft_strlen(s);
	else
		conv = flags->precision;
	return (conv);
}

static int	print_error(int count, t_flags *flags)
{
	if (!(flags->dot == 1 && flags->precision < 6))
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
	}	
	return (count);
}
