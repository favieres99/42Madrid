/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:43:44 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/18 11:01:30 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*result;
	t_list		*head;
	t_list		*elem;

	if (!lst || !f)
		return (NULL);
	elem = f(lst);
	result = ft_lstnew(elem->content, elem->content_size));
	if (!result)
		return (NULL);
	lst = lst->next;
	head = result;
	while (lst)
	{
		elem = f(lst);
		result->next = ft_lstnew(elem->content, elem->content_size));
		if (!result->next)
			return (NULL);
		result = result->next;
		lst = lst->next;
	}
	return (head);
}
