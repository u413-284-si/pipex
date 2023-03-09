/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:22:16 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/07 13:43:13 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  memcpy()  function  copies  n bytes from memory area src to memory 
area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
memory areas do overlap.

The memcpy() function returns a pointer to dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;

	if (!dest && !src)
		return (NULL);
	str = (unsigned char *)dest;
	while (n--)
		*str++ = *((unsigned char *) src++);
	return (dest);
}

// int main (void)
// {
//     char str1[] = "Geeks";
//     char str2[] = "Quiz";

//     puts("str1 before memcpy ");
//     puts(str1);

// /* Copies contents of str2 to str1 */
//     ft_memcpy (str1, str2, sizeof(str2));
//     puts("\nstr1 after ft_memcpy ");
//     puts(str1);
//     strcpy(str1,"Geeks");
//     memcpy (str1, str2, sizeof(str2));
//     puts("\nstr1 after memcpy ");
//     puts(str1);
//     return (0);
// }
