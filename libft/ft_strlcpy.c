/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:52:31 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/04 11:20:58 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	/* Only 4 chars can be written into str1 because last element is taken 
// 	by \0 */
// 	char	str1[5] = "abcd"; 
// 	char	str2[8];
// 	size_t		n;
// 	size_t		l;

// 	n = 4;
// 	l = ft_strlcpy(str2, "buenodfsg", n);
// 	printf("String 1: %s\nString 2: %s\nSource length: %zu\n\n", str1, str2, l);
// 	l = ft_strlcpy(str2, str1, n);
// 	printf("String 1: %s\nString 2: %s\nSource length: %zu\n\n", str1, str2, l);
// 	return (0);
// }
