/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:15:59 by sqiu              #+#    #+#             */
/*   Updated: 2022/11/17 09:14:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The	strchr(void)  function  returns  a  pointer  to the first occurrence of the 
character c in the string s.
Here "character" means "byte"; these functions do not work with wide or 
multibyte characters.
The	strchr(void) and strrchr() functions return a pointer to the matched 
character or NULL if the character is not found. The terminating null byte is 
considered part of the string, so that if c is specified as '\0', these 
functions return a pointer to the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if (c > 255)
		c -= 256 * (c / 256);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((void *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((void *)&s[i]);
	return (NULL);
}

/* int	main(void)
{
	char	*s;
	//char	c;

	s = "Sambadijaneiro";
	//c = 1024;
	printf("%s\n", strchr(s, 1024));
	printf("%s\n", ft_strchr(s, 1024));
	return (0);
} */
