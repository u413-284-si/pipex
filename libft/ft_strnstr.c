/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:01:57 by sqiu              #+#    #+#             */
/*   Updated: 2022/11/16 11:48:11 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_same(char *big, char *little);

/*
The	strnstr(void) function locates the first occurrence of the null-terminated 
string little in the string big, where not more than len characters are 
searched. Characters that appear after a ‘\0’ character are not searched. 
Since the strnstr() function is a FreeBSD specific API,	it should only be used 
when portability is not a concern.

If little is an empty string, big is returned; if little occurs nowhere in big, 
NULL is returned; otherwise a pointer to the first character of the first 
occurrence of little is returned.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	l;
	int		n;

	i = 0;
	l = ft_strlen(little);
	n = len;
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] && n--)
	{
		if (big[i] == little[0] && (len - i) >= l)
		{
			if (is_same((void *)&big[i], (char *)little))
				return ((void *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

static int	is_same(char *big, char *little)
{
	int	j;
	int	same;

	j = 0;
	same = 1;
	while (little[j] && same == 1)
	{
		if (big[j] != little[j])
			same = 0;
		j++;
	}
	return (same);
}

// int	main(void)
// {
// 	char str1[100] = "SoyaPikachu";
// 	char str2[100] = "ka";
// 	char *ptr;
// 	size_t n;

// 	n = 8;
// 	//ptr = strnstr(str1, str2, n);
// 	ptr = ft_strnstr(str1, str2, n);
// 	if (ptr)
// 	{
// 		/* Ptr points to xth Byte in str1
// 		str1 points to 1st Byte in str1
// 		Position = x - 1 (pointer arithmetics)
// 		*/
// 		int length = ptr - str1;

// 		printf("String: %s\n", str1);
// 		printf("Pattern: %s\n", str2);
// 		printf("Pattern gefunden ab dem %d Zeichen\n", length);
// 	}
// 	else
// 		puts("Suchmuster nicht gefunden");
// 	return (0);
// }
