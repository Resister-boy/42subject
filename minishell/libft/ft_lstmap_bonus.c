/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyolee <kiyolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:03:37 by kiyolee           #+#    #+#             */
/*   Updated: 2022/11/28 12:19:42 by seonghle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_first_node;
	t_list	*temp;

	if (!lst)
		return (0);
	new_first_node = ft_lstnew(f(lst->content));
	if (!new_first_node)
		return (0);
	lst = lst->next;
	temp = new_first_node;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (!(temp->next))
		{
			ft_lstclear(&new_first_node, del);
			return (0);
		}
		lst = lst->next;
		temp = temp->next;
	}
	return (new_first_node);
}
