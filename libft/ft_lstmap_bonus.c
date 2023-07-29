/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:31:41 by jaehulee          #+#    #+#             */
/*   Updated: 2022/12/04 17:41:24 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_new_node( void *content, void *(*f)(void *), \
		void (*del)(void *))
{
	t_list	*new_node;
	void	*new_content;

	if (content == NULL || f == NULL)
		return (NULL);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_content = f(content);
	if (!new_content)
	{
		del(new_content);
		free(new_node);
		return (NULL);
	}
	new_node->content = new_content;
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_node;
	t_list	*new_node;

	if (lst == NULL || f == NULL)
		return (NULL);
	head_node = get_new_node(lst->content, f, del);
	if (!head_node)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_node = get_new_node(lst->content, f, del);
		if (!new_node)
		{
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		ft_lstadd_back(&head_node, new_node);
		lst = lst->next;
	}
	return (head_node);
}
