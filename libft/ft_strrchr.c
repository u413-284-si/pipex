/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:49:36 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/06 14:46:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The	strrchr(void)  function  returns  a  pointer  to the last occurrence of the 
character c in the string s.
Here "character" means "byte"; these functions do not work with wide or 
multibyte characters.
The	strchr(void) and strrchr() functions return a pointer to the matched 
character or NULL if the character is not found. The terminating null byte is 
considered part of the string, so that if c is specified as '\0', these 
functions return a pointer to the terminator.
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((void *)&s[i]);
	while (i + 1)
	{
		if (s[i] == (char)c)
			return ((void *)&s[i]);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*s;
// 	char	c;

// 	s = "Sambadijaneiro";
// 	c = 'j';
// 	printf("%s\n", strrchr(s, c));
// 	printf("%s\n", ft_strrchr(s, c));
// 	return (0);
// }
