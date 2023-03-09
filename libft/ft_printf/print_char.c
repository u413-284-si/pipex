/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:55:20 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/20 08:45:46 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, int count, t_flags *flags)
{	
	int	conv;

	conv = 1;
	if (flags->minus == 1)
	{
		ft_putchar_fd(c, 1);
		count++;
		count = print_spaces(1, count, conv, flags);
	}
	else
	{
		count = print_spaces(1, count, conv, flags);
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}
