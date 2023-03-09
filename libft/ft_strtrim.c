/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:43:36 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/07 14:55:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
Return value: The trimmed string. NULL if the allocation fails.
*/

static int	trim_start(char const *s1, char const *set);
static int	trim_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		diff;

	if (!s1 || !set)
		return (NULL);
	start = trim_start(s1, set);
	end = trim_end(s1, set);
	diff = end - start + 1;
	if (start > end)
		diff = 0;
	str = (char *) malloc (diff + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, &s1[start], diff);
	str[diff] = '\0';
	return (&str[0]);
}

static int	trim_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[i])
	{
		if (s1[j] == set[i])
		{
			j++;
			i = -1;
		}
		i++;
	}
	return (j);
}

static int	trim_end(char const *s1, char const *set)
{
	int		i;
	size_t	l;

	i = 0;
	l = ft_strlen(s1) - 1;
	while (set[i])
	{
		if (s1[l] == set[i])
		{
			l--;
			i = -1;
		}
		i++;
	}
	return (l);
}

// int	main(void)
// {
// 	char	str[] = "   xxxtripouille   xxx";
// 	char	set[] = " x";

// 	printf("%s\n", ft_strtrim(str, set));
// 	return (0);
// }