/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:21:38 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/04 11:31:16 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length + size);
	dst_length = ft_strlen(dst);
	if (size <= dst_length)
		return (src_length + size);
	while (src[i] && dst_length + i + 1 < size)
	{	
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}

// int	main(void)
// {
// 	size_t	n = 13; //size of dest string including \0 Byte
// 	size_t	r;
// 	char	str1[13] = "42dfgdl33r ";
// 	char	str2[] = "l33r";

// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	r = ft_strlcat(str1, str2, n);
// 	printf("%s\nTotal ft_strlen: %zu\n", str1, r);
// 	/* If total ft_strlen of string is bigger or equal buffer size, it means 
// 	that at least the last char was cut off as NULL takes the last place. */
// 	if (r > n)
// 		puts("String truncated");
// 	else
// 	{
//     		puts("String was fully copied");
// 	}
// 	return (0);
// }
