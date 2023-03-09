/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:58:40 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 09:34:48 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int printf(const char *restrict format, ...);
The functions in the printf() family produce output according to
a format as described below.  The functions printf() and
vprintf() write output to stdout, the standard output stream;

The format string is a character string, beginning and ending in
its initial shift state, if any.  The format string is composed
of zero or more directives: ordinary characters (not %), which
are copied unchanged to the output stream; and conversion
specifications, each of which results in fetching zero or more
subsequent arguments.  Each conversion specification is
introduced by the character %, and ends with a conversion
specifier.  In between there may be (in this order) zero or more
flags, an optional minimum field width, an optional precision and
an optional length modifier.

The overall syntax of a conversion specification is:

    %[$][flags][width][.precision][length modifier]conversion

Upon successful return, these functions return the number of
characters printed (excluding the null byte used to end output to
strings). If an output error is encountered, a negative value is returned.
*/

/*
********************Uncomment for testing**********************************
*/
// void	ft_putchar_fd(char c, int fd)
// {
// 	write (fd, &c, 1);
// }

static void	set_flags(t_flags *flags);
static int	print_percent(int count);
static int	type_check(int count, va_list ap, t_flags *flags, const char *fmt);

/*
Initialise all flags, run through formatter string fmt. If encounters specifier
%, check following flags. Then check specified print type and print to stdout
according to flags. If specifier not encountered, print char.
*/
int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	t_flags	flags;

	va_start(ap, fmt);
	count = 0;
	set_flags(&flags);
	while (*fmt)
	{
		if (*fmt == '%')
		{	
			fmt++;
			fmt = check_flags(fmt, &flags);
			count = type_check(count, ap, &flags, fmt);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
		}
		fmt++;
	}
	va_end(ap);
	return (count);
}

/*
Check specified printing type and call according print function. After print
reset all flags. Returns amount of chars printed.
*/
static int	type_check(int count, va_list ap, t_flags *flags, const char *fmt)
{
	if (*fmt == 'c')
		count = print_char(va_arg(ap, int), count, flags);
	else if (*fmt == 's')
		count = print_string(va_arg(ap, const char *), count, flags);
	else if (*fmt == 'p')
		count = print_adress(va_arg(ap, unsigned long), count, flags);
	else if (*fmt == 'd' || *fmt == 'i')
		count = print_decimal(va_arg(ap, int), count, flags);
	else if (*fmt == 'u')
		count = print_unsigned(va_arg(ap, unsigned int), count, flags);
	else if (*fmt == 'x')
		count = print_hex(va_arg(ap, int), count, flags);
	else if (*fmt == 'X')
		count = print_hex_up(va_arg(ap, int), count, flags);
	else if (*fmt == '%')
		count = print_percent(count);
	set_flags(flags);
	return (count);
}

/*
Prints percentage sign.
*/
static int	print_percent(int count)
{
	ft_putchar_fd('%', 1);
	count++;
	return (count);
}

/*
Resets all flags to 0.
*/
static void	set_flags(t_flags *flags)
{
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->space = 0;
	flags->sign = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->width = 0;
}

/*
********************Uncomment for testing**********************************
also: ft_putchar_fd; check_flags.c/ft_atoi
*/

// int	main(void)
// {
// 	int				rtrn_orig;
// 	int				rtrn_my;
// 	char			*str;
// 	//int				i;
// 	//unsigned int	u;
// 	//int				x;

// 	//str = " you printable?";
// 	//x = 325565;
// 	//i = -2147483648;
// 	//u = 4294967295; //4294967295
// 	//void	*p;
// 	//p = &x;	
// 	// Test c
// 	// rtrn_orig = printf("orig: %-3c\n", 'u');
// 	// rtrn_my = ft_printf("my:   %-3c\n", 'u');
// 	// printf("return value orig: %d\n", rtrn_orig);
// 	// printf("return value my: %d\n", rtrn_my);
// 	// Test s
// 	// rtrn_orig = printf("orig: % 1s\n", "");
// 	// rtrn_my = ft_printf("my:   % 1s\n", "");
// 	// printf("return value orig: %d\n", rtrn_orig);
// 	// printf("return value my: %d\n", rtrn_my);
// 	// Test p
// 	// rtrn_orig = printf("orig: %p\n", ptr);
// 	// rtrn_my = ft_printf("my:   %p\n", ptr);
// 	// printf("return value orig: %d\n", rtrn_orig);
// 	// printf("return value my: %d\n", rtrn_my);
// 	// Test d
// 	// rtrn_orig = printf("orig: %.0d\n", i);
// 	// rtrn_my = ft_printf("my:   %.0d\n", i);
// 	// printf("return value orig: %d\n", rtrn_orig);
// 	// printf("return value my: %d\n", rtrn_my);
// 	// Test u
// 	// rtrn_orig = printf("orig: %-20.15uaaa\n", u);
// 	// rtrn_my = ft_printf("my:   %-20.15uaaa\n", u);
// 	// printf("return value orig: %d\n", rtrn_orig);
// 	// printf("return value my: %d\n", rtrn_my);
// 	// Test x
// 	// rtrn_orig = printf("orig: %xaaa\n", x);
// 	// rtrn_my = ft_printf("my:   %xaaa\n", x);
// 	// printf("return value orig: %d\n", rtrn_orig);
// 	// printf("return value my: %d\n", rtrn_my);
// 	//Test X
// 	// rtrn_orig = printf("orig: %-#30.20Xaaa\n", x);
// 	// rtrn_my = ft_printf("my:   %-#30.20Xaaa\n", x);
// 	// printf("return value orig: %d\n", rtrn_orig);
// 	// printf("return value my: %d\n", rtrn_my);
// 	// Text p
// 	// rtrn_orig = printf("orig: %-20paaa\n", p);
// 	// rtrn_my = ft_printf("my:   %-20paaa\n", p);
// 	// printf("return value orig: %d\n", rtrn_orig);
// 	// printf("return value my: %d\n", rtrn_my);
// 	// Test %
// 	rtrn_orig = printf("orig: %%\n");
// 	rtrn_my = ft_printf("my:   %%\n");
// 	printf("return value orig: %d\n", rtrn_orig);
// 	printf("return value my: %d\n", rtrn_my);
// 	return (0);
// }
