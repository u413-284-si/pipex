/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:34:53 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/04 16:34:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dupl;
	int		k;

	k = 0;
	dupl = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dupl == NULL)
		return (NULL);
	while (src[k])
	{
		dupl[k] = src[k];
		k++;
	}
	dupl[k] = '\0';
	return (dupl);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*output;

// 	str1 = "Ciao bello, come sta";
// 	output = ft_strdup(str1);
// 	printf("%s\n", output);
// 	free(output);
// 	return (0);
// }
