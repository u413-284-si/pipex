/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:50:10 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 09:59:40 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hash(int count)
{
	ft_putstr_fd("0x", 1);
	count += 2;
	return (count);
}

int	print_hash_up(int count)
{
	ft_putstr_fd("0X", 1);
	count += 2;
	return (count);
}

/*
Reduce optional spaces to be printed by 2 for 0x.
If precision specified and precision value greater than amount of chars to
be printed, reduce spaces to be printed by precision value.
If no precision specified, reduce spaces to be printed by amount of chars to
be printed.
Print spaces if amount to be printed still greater zero after afore mentioned
operations.
*/
int	print_spaces_x(int count, int conv, t_flags *flags)
{
	int	n;

	if (flags->hash == 1)
		flags->width -= 2;
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
Difference to hexadecimal print: optional spaces to be printed are NOT
reduced by preceding 0x as address always includes them.

If precision specified and precision value greater than amount of chars to
be printed, reduce spaces to be printed by precision value.
If no precision specified, reduce spaces to be printed by amount of chars to
be printed.
Print spaces if amount to be printed still greater zero after afore mentioned
operations.
*/
int	print_spaces_p(int count, int conv, t_flags *flags)
{
	int	n;

	flags->width -= 2;
	if (flags->dot == 1)
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

int	print_error_p(int count)
{
	ft_putstr_fd("(nil)", 1);
	count += 5;
	return (count);
}
