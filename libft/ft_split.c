/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:08:57 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/08 20:19:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
Return value: The array of new strings resulting from the split.
NULL if the allocation fails.
*/
static int	str_occ(char const *s, char c);
static char	*get_str(char const *s, char c);
static char	**fill_arr(char **arr, char const *s, char c, int str_count);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		str_count;

	if (!s)
		return (NULL);
	str_count = str_occ(s, c);
	arr = malloc (sizeof(char *) * (str_count + 1));
	if (!arr)
		return (NULL);
	arr = fill_arr(arr, s, c, str_count);
	return (arr);
}

static char	**fill_arr(char **arr, char const *s, char c, int str_count)
{
	char	*tmp;
	int		i;
	size_t	j;

	i = -1;
	while (++i < str_count)
	{
		tmp = get_str(s, c);
		arr[i] = (char *) malloc (sizeof(char) * (ft_strlen(tmp) + 1));
		if (!arr[i])
			return (NULL);
		j = -1;
		while (++j < ft_strlen(tmp))
			arr[i][j] = tmp[j];
		arr[i][j] = '\0';
		if (!(i == str_count - 1))
		{
			while (*s == c)
				s++;
			s += ft_strlen(tmp) + 1;
		}
		free(tmp);
	}
	arr[i] = NULL;
	return (arr);
}

static int	str_occ(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] != c && s[j + 1] != '\0')
			i++;
		if (s[j] != c && i == 0)
			i++;
		j++;
	}
	return (i);
}

static char	*get_str(char const *s, char c)
{
	char	*tmp;
	char	*str;
	int		len;
	int		i;

	while (*s == c)
		s++;
	tmp = ft_strchr(s, c);
	if (!tmp)
		len = ft_strlen(s);
	else
		len = tmp - s;
	str = (char *) malloc (sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = *s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	s[] = "   ";
// 	char	c = ' ';
// 	char	**arr;
// 	int		i;

// 	arr = ft_split(s, c);
// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("%s\n", arr[i]);
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }
