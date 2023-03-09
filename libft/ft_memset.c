/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:14:47 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/03 17:38:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n--)
		*str++ = (unsigned char)c;
	return (s);
}

// int	main(void)
// {
// 	char	str[50];

// 	strcpy(str, "This is string.h library function");
// 	puts(str);
// 	ft_memset(str, '$', 7);
// 	puts(str);
// 	return (0);
// }
