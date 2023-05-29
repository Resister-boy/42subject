/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:20:43 by seonghle          #+#    #+#             */
/*   Updated: 2023/05/29 07:30:20 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*make_node(char *key, char *value)
{
	t_env	*new;

	if (!key)
		return (NULL);
	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

int	free_node(t_env **node)
{
	free((*node)->key);
	if ((*node)->value)
		free((*node)->value);
	free(*node);
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
