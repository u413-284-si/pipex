/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:14:52 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 09:53:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_conv(int n);
static int	print_d(int n, int count, int fd);
static int	print_decimal_lj(int n, int count, int conv, t_flags *flags);
static int	print_decimal_rj(int n, int count, int conv, t_flags *flags);

/*
Count chars to be printed. 
If n = 0, dont't print number, only optional preceding spaces.
Differentiate between left or right justification.
*/
int	print_decimal(int n, int count, t_flags *flags)
{
	int	conv;

	conv = set_conv(n);
	if (n == 0 && flags->precision == 0 && flags->dot == 1)
	{
		count = print_spaces(n, count, 0, flags);
		return (count);
	}
	if (flags->minus == 1)
		count = print_decimal_lj(n, count, conv, flags);
	else
		count = print_decimal_rj(n, count, conv, flags);
	return (count);
}

/*
Printing in exactly the following order:
* Print single space if n positive and space flag specified.
* Print plus sign if signature flag specified and n = 0 or positive.
* Print minus sign if signature flag specified and n negative, or
if n simply negative.
* Print zeroes if zero flag or precision specified.
* Print number.
* Print optional spaces.
*/
static int	print_decimal_lj(int n, int count, int conv, t_flags *flags)
{
	if ((flags->space == 1 && n >= 0)
		|| (flags->space == 1 && n >= 0 && flags->zero == 1))
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	if (flags->sign == 1 && n >= 0)
		count = print_sign(count, 1);
	if ((flags->sign == 1 && n < 0) || n < 0)
		count = print_sign(count, 0);
	if (flags->zero == 1 || flags->dot == 1)
		count = print_zeroes(n, count, conv, flags);
	count = print_d(n, count, 1);
	if (flags->zero == 0)
		count = print_spaces_d(n, count, conv, flags);
	return (count);
}

/*
Printing in exactly the following order:
* Print single space if n positive and space flag specified.
* Print optional spaces.
* Print plus sign if signature flag specified and n = 0 or positive.
* Print minus sign if signature flag specified and n negative, or
if n simply negative.
* Print zeroes if zero flag or precision specified.
* Print number.
*/
static int	print_decimal_rj(int n, int count, int conv, t_flags *flags)
{
	if ((flags->space == 1 && n >= 0)
		|| (flags->space == 1 && n >= 0 && flags->zero == 1))
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	if (flags->zero == 0 || (flags->zero == 1 && flags->dot == 1))
		count = print_spaces_d(n, count, conv, flags);
	if (flags->sign == 1 && n >= 0)
		count = print_sign(count, 1);
	if ((flags->sign == 1 && n < 0) || n < 0)
		count = print_sign(count, 0);
	if (flags->zero == 1 || flags->dot == 1)
		count = print_zeroes(n, count, conv, flags);
	count = print_d(n, count, 1);
	return (count);
}

/*
Print digits recursively starting from first digit (from the left).
Return number of digits printed.
*/
static int	print_d(int n, int count, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("2147483648", fd);
			return (count += 10);
		}
		count = print_d(-n, count, fd);
	}
	else if (n > 9)
	{
		count = print_d(n / 10, count, fd);
		count = print_d(n % 10, count, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		count++;
	}
	return (count);
}

/*
Count digits and return count value.
*/
static int	set_conv(int n)
{
	int	conv;

	conv = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (conv = 10);
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		conv++;
	}
	return (conv);
}
