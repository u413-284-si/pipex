/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:39:12 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 10:54:34 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_conv(unsigned int n);
static int	print_u(unsigned int n, int count, int fd);
static int	print_dec_lj(unsigned int n, int count, int conv, t_flags *flags);
static int	print_dec_rj(unsigned int n, int count, int conv, t_flags *flags);

/*
Count chars to be printed. 
If n = 0, dont't print number, only optional preceding spaces.
Differentiate between left or right justification.
*/
int	print_unsigned(unsigned int n, int count, t_flags *flags)
{
	int	conv;

	conv = set_conv(n);
	if (n == 0 && flags->precision == 0 && flags->dot == 1)
	{
		count = print_spaces_u(count, 0, flags);
		return (count);
	}
	if (flags->minus == 1)
		count = print_dec_lj(n, count, conv, flags);
	else
		count = print_dec_rj(n, count, conv, flags);
	return (count);
}

/*
Printing in exactly the following order:
* Print single space if n positive and space flag specified.
* Print plus sign if signature flag specified and n = 0 or positive.
* Print zeroes if zero flag or precision specified.
* Print number.
* Print optional spaces.
*/
static int	print_dec_lj(unsigned int n, int count, int conv, t_flags *flags)
{
	if ((flags->space == 1 && n > 0)
		|| (flags->space == 1 && n > 0 && flags->zero == 1))
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	if (flags->sign == 1 && n > 0)
		count = print_sign(count, 1);
	if (flags->zero == 1 || flags->dot == 1)
		count = print_zeroes_u(count, conv, flags);
	count = print_u(n, count, 1);
	if (flags->zero == 0 || (flags->zero == 1 && flags->dot == 1))
		count = print_spaces_u(count, conv, flags);
	return (count);
}

/*
Printing in exactly the following order:
* Print single space if n positive and space flag specified.
* Print optional spaces.
* Print plus sign if signature flag specified and n = 0 or positive.
* Print zeroes if zero flag or precision specified.
* Print number.
*/
static int	print_dec_rj(unsigned int n, int count, int conv, t_flags *flags)
{
	if ((flags->space == 1 && n > 0)
		|| (flags->space == 1 && n > 0 && flags->zero == 1))
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	if (flags->zero == 0 || (flags->zero == 1 && flags->dot == 1))
		count = print_spaces_u(count, conv, flags);
	if (flags->sign == 1 && n > 0)
		count = print_sign(count, 1);
	if (flags->zero == 1 || flags->dot == 1)
		count = print_zeroes_u(count, conv, flags);
	count = print_u(n, count, 1);
	return (count);
}

static int	print_u(unsigned int n, int count, int fd)
{
	if (n > 9)
	{
		count = print_u(n / 10, count, fd);
		count = print_u(n % 10, count, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		count++;
	}
	return (count);
}

static int	set_conv(unsigned int n)
{
	int	conv;

	conv = 1;
	while (n > 9)
	{
		n /= 10;
		conv++;
	}
	return (conv);
}
