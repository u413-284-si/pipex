/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:42:08 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/10 11:07:53 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

/*
The	calloc(void)  function allocates memory for an array of nmemb elements
of size bytes each and returns a pointer to the allocated memory.   The
memory  is  set  to zero.  If nmemb is 0, then calloc() returns NULL. If size
is 0, calloc returns a unique pointer value that can later be successfully
passed to free(void).  If the multiplication of nmemb and size would result
in integer overflow, then calloc() returns an error.  By  contrast,  an
integer  overflow  would  not be detected in the following call to mal‐
loc(), with the result that an incorrectly sized block of memory  would
be allocated: malloc(nmemb * size);
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb > INT_MAX || size > INT_MAX)
		return (NULL);
	if (nmemb <= 0 || size <= 0)
		arr = (void *)malloc(1);
	else
		arr = (void *)malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

// int	main(void)
// {
// 	int i, n;
// 	int *a;

// 	printf("Number of elements to be entered:");
// 	scanf("%d", &n);

// 	a = (int *)ft_calloc(n, sizeof(int));
// 	//a = (int *)calloc(n, sizeof(int));
// 	printf("Enter %d numbers:\n", n);
// 	for (i = 0; i < n; i++)
// 	{
// 		scanf("%d", &a[i]);
// 	}

// 	printf("The numbers entered are: ");
// 	for (i = 0; i < n; i++)
// 	{
// 		printf("%d ", a[i]);
// 	}
// 	free(a);

// 	return (0);
// }