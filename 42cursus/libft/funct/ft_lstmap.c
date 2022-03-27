/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:15:15 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/27 20:10:17 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
Creates a new list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed. */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	while (lst)
	{
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		tmp = ft_lstnew(f(lst->content));
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
