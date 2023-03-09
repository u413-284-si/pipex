/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:58:54 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/08 14:18:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
Return value: The string representing the integer.
NULL if the allocation fails.
*/

static int	dig_count(long int n);
static char	*ft_putnbr(long int nb, char *str);

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = dig_count((long int)n);
	if (n < 0)
		size += 1;
	str = malloc (size + 1);
	if (!str)
		return (NULL);
	str = ft_putnbr((long int)n, str);
	*str = '\0';
	return (str - size);
}

static char	*ft_putnbr(long int nb, char *str)
{
	if (nb < 0)
	{
		*str++ = '-';
		str = ft_putnbr(-nb, str);
	}
	else if (nb > 9)
	{
		str = ft_putnbr(nb / 10, str);
		str = ft_putnbr(nb % 10, str);
	}
	else
	{
		*str = nb + '0';
		str++;
	}
	return (str);
}

static int	dig_count(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

// int main(void)
// {
//     int i;

//     i = 0; //-2147483648
//     printf("%s\n", ft_itoa(i));
//     return (0);
// }
