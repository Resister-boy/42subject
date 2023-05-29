/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:23:54 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/29 08:42:22 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tmp	*get_lasttmp(t_pipe *pipe)
{
	t_tmp	*temp;

	temp = pipe->temp;
	if (!temp)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	parse_cmd(t_pipe_manager *p_man, char *prompt, size_t idx)
{
	t_pipe	*node;
	size_t	start;
	char	*str;

	start = idx;
	node = get_lastnode(p_man);
	while (prompt[idx] && !ft_isspace(prompt[idx]))
		idx++;
	str = ft_substr(prompt, start, idx - start);
	if (check_dollar(str))
		handle_expand(str, node);
	else
		get_temp(str, node);
	return (idx);
}

void	get_temp(char *str, t_pipe *node)
{
	t_tmp	*tmp;
	t_tmp	*last;

	tmp = (t_tmp *)malloc(sizeof(t_tmp));
	tmp->args = ft_strdup(str);
	tmp->next = NULL;
	last = get_lasttmp(node);
	if (!last)
		node->temp = tmp;
	else
		last->next = tmp;
}

size_t	get_tmpsize(t_pipe *node)
{
	size_t	len;
	t_tmp	*cur;

	len = 0;
	cur = node->temp;
	if (!cur)
		return (0);
	while (cur)
	{
		cur = cur->next;
		len++;
	}
	return (len);
}

char	**change_cmds(t_pipe *node, char **envp)
{
	size_t	i;
	size_t	len;
	t_tmp	*tmp;
	char	**cmds;

	i = 1;
	tmp = node->temp;
	len = get_tmpsize(node) + 1;
	cmds = (char **)malloc(sizeof(char *) * (len + 1));
	cmds[len] = NULL;
	cmds[0] = get_env_path(envp, tmp->args);
	while (tmp)
	{
		cmds[i] = ft_strdup(tmp->args);
		tmp = tmp->next;
		i++;
	}
	return (cmds);
}
