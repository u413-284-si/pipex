/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:08:05 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/03 18:59:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
A void pointer is a special pointer that can point to object of any type. A 
void pointer is typeless pointer also known as generic pointer. While 
dereferencing a void pointer, the C compiler does not have any clue about type 
of value pointed by the void pointer. Hence, dereferencing a void pointer is 
illegal in C. To dereference a void pointer you must typecast it to a valid 
pointer type.
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n--)
		*str++ = '\0';
}

// int	main (void)
// {
//    char str[50];
//    int count;

// 	count = 0;
//    strcpy(str,"This is string.h library function");
//    puts(str);
//    ft_bzero(str, 7);
//    while (count < 15)
//    {
// 	printf("%d", str[count++]);
//    }
//    printf("\n");
//    strcpy(str,"This is string.h library function");
//    bzero(str, 7);
//    count = 0;
//    while (count < 15)
//    {
// 	printf("%d", str[count++]);
//    }
//    printf("\n");
//    return (0);
// }
