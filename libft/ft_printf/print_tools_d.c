/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:03:02 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 10:16:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Reduce amount of spaces to be printed by
* optional signature sign by 1
* optional negative number by 1 (if no signature flag)
* optional preceding single space
* if precision specified, precision value (= amount of digits to be printed
plus preceding zeroes), otherwise amount of digits to be printed
*/
int	print_spaces_d(int nb, int count, int conv, t_flags *flags)
{
	int	n;
	int	neg;

	neg = 0;
	if (nb < 0 && flags->sign == 0)
		neg = 1;
	if (flags->dot == 1 && flags->precision > conv)
		n = flags->width - flags->sign - neg - flags->space
			- flags->precision;
	else
		n = flags->width - flags->sign - neg - flags->space - conv;
	while (n-- > 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}
