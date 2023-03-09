/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:01:27 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/04 15:03:05 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	diff = 0;
	while ((s1[i] || s2[i]) && diff == 0 && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (diff);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*equal;
// 	char	*greater;
// 	char	*lesser;
// 	int		i;
// 	size_t	n;

// 	str1 = "chulu";
// 	equal = "chulu";
// 	greater = "cfuly";
// 	lesser = "chulxfobo";
// 	n = 5;
// 	i = strncmp(str1, equal, n);
// 	printf("Equal: %d\n", i);
// 	i = strncmp(str1, greater, n);
// 	printf("Greater: %d\n", i);
// 	i = strncmp(str1, lesser, n);
// 	printf("Lesser: %d\n", i);
// 	i = ft_strncmp(str1, equal, n);
// 	printf("Equal: %d\n", i);
// 	i = ft_strncmp(str1, greater, n);
// 	printf("Greater: %d\n", i);
// 	i = ft_strncmp(str1, lesser, n);
// 	printf("Lesser: %d\n", i);
// 	return (0);
// }
