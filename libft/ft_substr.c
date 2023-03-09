/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:08:34 by sqiu              #+#    #+#             */
/*   Updated: 2022/11/16 21:34:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
Return value: The substring.
NULL if the allocation fails.
*/

//**********************Uncomment for testing***************************
/* void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;

	if (!dest && !src)
		return (NULL);
	str = (unsigned char *)dest;
	while (n--)
		*str++ = *((unsigned char *) src++);
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
} */
//************************************************************************

static char	*str_ex(char const *s, unsigned int start, size_t len, size_t rlen);

/*
Retrieve total length of s. If start index is bigger than last
index of s (total length - 1) or s is empty, then to be copied amount
len = 0. Calculate the max. possibly to be copied length (rlen).

If rlen is larger than len (possible copy more than asked for),
then only malloc amount asked for (= len).
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtrn;
	size_t	rlen;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l == 0 || start > (l - 1))
		len = 0;
	if (l > start)
		rlen = l - start;
	else
		rlen = 0;
	rtrn = str_ex(s, start, len, rlen);
	return (rtrn);
}

static char	*str_ex(char const *s, unsigned int start, size_t len, size_t rlen)
{
	char	*str;
	size_t	sz;

	if (rlen > len)
		sz = len;
	else
		sz = rlen;
	str = (char *) malloc (sizeof(char) * (sz + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, sz);
	str[sz] = '\0';
	return (str);
}

/* int	main(void)
{
	//const char	s[] = "01234567";
	//printf("%s\n", ft_substr(s, 25, 40));
	printf("%s\n", ft_substr("", 1, 1));
	return (0);
} */
