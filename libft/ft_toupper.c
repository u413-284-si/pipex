/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:31:52 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/04 11:43:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
If  c is a lowercase letter, toupper() returns its uppercase equivalent, if an
uppercase representation exists in the current locale.  Otherwise, it returns c.
The value returned is that of the converted letter, or c if the conversion 
was not possible.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'b';
// 	printf("%c\n", toupper(c));
// 	printf("%c\n", ft_toupper(c));
// 	return (0);
// }