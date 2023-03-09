/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:51:54 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 09:43:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_x(unsigned long nb, int count, char *radix);
static int	set_conv(unsigned long n, int conv, char *radix);
static int	print_hex_lj(unsigned long n, int count, int conv, t_flags *flags);
static int	print_hex_rj(unsigned long n, int count, int conv, t_flags *flags);

/*
Recieve address value as unsigned long. If address pointer is NULL, print
error message (including optional preceding spaces specified by width option).
Count the chars to be printed. Differentiate between left or right justifi-
cation.
*/
int	print_adress(unsigned long ptr, int count, t_flags *flags)
{
	int	conv;

	conv = 3;
	if (!ptr)
	{
		count = print_spaces_p(count, conv, flags);
		count = print_error_p(count);
		return (count);
	}
	conv = 0;
	conv = set_conv(ptr, conv, "0123456789abcdef");
	if (flags->minus == 1)
		count = print_hex_lj(ptr, count, conv, flags);
	else
		count = print_hex_rj(ptr, count, conv, flags);
	return (count);
}

/*
Always print 0x-preceding chars. Use putnbr_x to translate into hexa-
decimal and print. Optional spaces follow.
*/
static int	print_hex_lj(unsigned long n, int count, int conv, t_flags *flags)
{
	count = print_hash(count);
	count = ft_putnbr_x((unsigned long) n, count, "0123456789abcdef");
	count = print_spaces_p(count, conv, flags);
	return (count);
}

/*
Optional spaces precede.
Always print 0x-preceding chars. Use putnbr_x to translate into hexa-
decimal and print.
*/
static int	print_hex_rj(unsigned long n, int count, int conv, t_flags *flags)
{
	count = print_spaces_p(count, conv, flags);
	count = print_hash(count);
	count = ft_putnbr_x((unsigned long) n, count, "0123456789abcdef");
	return (count);
}

static int	ft_putnbr_x(unsigned long nb, int count, char *radix)
{
	if (nb >= 16)
	{
		count = ft_putnbr_x(nb / 16, count, radix);
		count = ft_putnbr_x(nb % 16, count, radix);
	}
	else
	{
		ft_putchar_fd(radix[nb], 1);
		count ++;
	}
	return (count);
}

/*
Convert into hexadecimal and count chars to be printed.
*/
static int	set_conv(unsigned long n, int conv, char *radix)
{
	if (n >= 16)
	{
		conv = set_conv(n / 16, conv, radix);
		conv = set_conv(n % 16, conv, radix);
	}
	else
		conv++;
	return (conv);
}
