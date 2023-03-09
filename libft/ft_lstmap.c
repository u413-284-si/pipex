/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:38:20 by sqiu              #+#    #+#             */
/*   Updated: 2022/10/10 17:52:56 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
lst: The address of a pointer to a node.
f: The address of the function used to iterate on
the list.
del: The address of the function used to delete
the content of a node if needed.
Return: The new list.
NULL if the allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*rtrn;

	if (!lst || !f || !del)
		return (NULL);
	tmp = ft_lstnew((*f)(lst -> content));
	if (!tmp)
		return (NULL);
	rtrn = tmp;
	while (lst -> next)
	{
		lst = lst -> next;
		tmp = ft_lstnew((*f)(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&rtrn, (*del));
			return (NULL);
		}
		ft_lstadd_back(&rtrn, tmp);
	}
	return (rtrn);
}
