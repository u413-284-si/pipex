/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:54:23 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/04 11:54:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
If  c is an uppercase letter, tolower() returns its lowercase equivalent, if a 
lowercase representation exists in the current locale.  Otherwise, it returns c.
The value returned is that of the converted letter, or c if the conversion 
was not possible.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'B';
// 	printf("%c\n", tolower(c));
// 	printf("%c\n", ft_tolower(c));
// 	return (0);
// }
