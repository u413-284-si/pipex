/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:09:57 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/04 15:18:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The	memchr(void) function scans the initial n bytes of the memory area pointed 
to by s for the first instance of c. Both c and the bytes of the memory area 
pointed to by s are interpreted as unsigned char.
The	memchr(void) and memrchr() functions return a pointer to the matching byte 
or NULL if the character does not occur in the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *s;
// 	char	c;

// 	size_t	n;
// 	s = "01";
// 	c = '2';
// 	n = 4;
// 	//printf("%s\n", (char *) memchr(s, c, n));
// 	//printf("%s\n", (char *) ft_memchr(s, c, n));
// 	printf("%p\n", ft_memchr(s, c, n));
// 	return (0);
// }
