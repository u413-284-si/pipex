/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:51:01 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 10:52:43 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Print spaces for chars and strings:

Reduce amount of spaces to be printed by
* optional signature sign by 1
* optional negative number by 1 (if no signature flag)
* if precision specified, optional preceding single space
*/
int	print_spaces(int nb, int count, int conv, t_flags *flags)
{
	int	n;
	int	neg;

	neg = 0;
	if (nb < 0 && flags->sign == 0)
		neg = 1;
	if (flags->dot == 1)
		n = flags->width - flags->sign - neg - flags->space
			- conv;
	else
		n = flags->width - flags->sign - neg - conv;
	while (n-- > 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

/*
Reduce amount of spaces to be printed by
* if precision specified, precision value, otherwise amount of digits
to be printed

No negative numbers with unsigned int.
*/
int	print_spaces_u(int count, int conv, t_flags *flags)
{
	int	n;

	if (flags->dot == 1 && flags->precision > conv)
		n = flags->width - flags->precision;
	else
		n = flags->width - conv;
	while (n-- > 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

/*
Print zeroes for ints:

Reduce amount of zeroes to be printed by
* if precision specified, precision value minus amount of digits to
be printed
* if no precision specified, width value minus
	* optional signature sign by 1
	* optional negative number by 1 (if no signature flag)
	* optional single space by 1
	* amount of digits to be printed
*/
int	print_zeroes(int nb, int count, int conv, t_flags *flags)
{
	int	n;
	int	neg;

	neg = 0;
	if (nb < 0 && flags->sign == 0 && flags->dot == 0)
		neg = 1;
	if (flags->dot == 1)
		n = flags->precision - neg - conv;
	else
		n = flags->width - flags->sign - neg - flags->space - conv;
	while (n-- > 0)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	return (count);
}

/*
Print zeroes for unsigned:

Reduce amount of zeroes to be printed by
* if precision specified, precision value minus amount of digits to
be printed
* if no precision specified, width value minus amount of digits to 
be printed
*/
int	print_zeroes_u(int count, int conv, t_flags *flags)
{
	int	n;

	if (flags->dot == 1)
		n = flags->precision - conv;
	else
		n = flags->width - conv;
	while (n-- > 0)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	return (count);
}

int	print_sign(int count, int sign)
{
	if (sign == 1)
		ft_putchar_fd('+', 1);
	else
		ft_putchar_fd('-', 1);
	count++;
	return (count);
}
