/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:31:12 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/27 09:38:33 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			dig_count(int n);
static const char	*set_prec(const char *fmt, t_flags *flags);

/*
********************Uncomment for testing**********************************
*/
// int	ft_atoi(const char *str)
// {
// 	int		i;
// 	long	sign;
// 	long	result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + str[i++] - '0';
// 		if (result * sign > 2147483647)
// 			return (-1);
// 		if (result * sign < -2147483648)
// 			return (0);
// 	}		
// 	return (result * sign);
// }

/*
If respective flag encountered, set struct members value to 1. Retrieve
width value with ft_atoi. Return fmt string at following position.
*/
char	*check_flags(const char *fmt, t_flags *flags)
{
	while (!(*fmt == 'c' || *fmt == 's' || *fmt == 'p' || *fmt == 'd'
			|| *fmt == 'i' || *fmt == 'u' || *fmt == 'x' || *fmt == 'X'
			|| *fmt == '%'))
	{
		if (*fmt == '#')
			flags->hash = 1;
		else if (*fmt == '0')
			flags->zero = 1;
		else if (*fmt == '-')
			flags->minus = 1;
		else if (*fmt == ' ')
			flags->space = 1;
		else if (*fmt == '+')
			flags->sign = 1;
		else if (*fmt == '.')
			fmt = set_prec(fmt, flags);
		else if (*fmt >= '1' && *fmt <= '9')
		{
			flags->width = ft_atoi(fmt);
			fmt += dig_count(flags->width) - 1;
		}
		fmt++;
	}
	return ((char *)fmt);
}

/*
Retrieve precision value with ft_atoi. Return fmt string at last digit
position.
*/
static const char	*set_prec(const char *fmt, t_flags *flags)
{
	flags->dot = 1;
	flags->precision = ft_atoi(fmt + 1);
	if (flags->precision == 0)
		return (fmt);
	fmt += dig_count(flags->precision);
	return (fmt);
}

static int	dig_count(int n)
{
	int	counter;

	counter = 1;
	while (n > 9)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}
