/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:20:43 by seonghle          #+#    #+#             */
/*   Updated: 2023/07/07 16:12:23 by seonghle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*make_node(char *key, char *value)
{
	t_env	*new;

	if (!key)
		return (NULL);
	new = (t_env *)malloc(sizeof(t_env));
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

int	free_node(t_env **node)
{
	ft_free((void **)&(*node)->key);
	ft_free((void **)&(*node)->value);
	ft_free((void **)node);
	return (1);
}

t_env	*get_last_node(t_env *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
