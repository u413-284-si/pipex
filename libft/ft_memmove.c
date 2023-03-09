/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:57:05 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/06 12:06:14 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 The memmove() function copies n bytes from memory area src to memory area dest.
The memory areas may overlap: copying takes place as though the bytes in src 
are first copied into a  temporary  array that does not overlap src or dest, 
and the bytes are then copied from the temporary array to dest.
The	memmove(void) function returns a pointer to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (src < dest)
			d[n - i - 1] = s[n - i - 1];
		else
			d[i] = s[i];
		i++;
	}
	return (d);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*tmp;
// 	size_t			i;

// 	if (!dest && !src)
// 		return (NULL);
// 	tmp = (unsigned char *)malloc(n);
// 	if (!tmp)
// 		return (dest);
// 	i = 0;
// 	while (i < n)
// 		tmp[i++] = *((unsigned char *)src++);
// 	i = 0;
// 	while (i < n)
// 		*((unsigned char *)dest++) = tmp[i++];
// 	free(tmp);
// 	return (dest - i);
// }

// int	main(void)
// {
// 	char str[] = "memmove can be very useful......";

// 	ft_memmove(str + 20, str + 15, 11);
// 	puts(str);
// 	return (0);
// }
