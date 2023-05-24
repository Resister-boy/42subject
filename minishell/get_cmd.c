/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:23:54 by jaehulee          #+#    #+#             */
/*   Updated: 2023/05/24 18:58:20 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	check_dollar(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	parse_cmd(t_pipe_manager *p_man, char *prompt, size_t idx)
{
	t_pipe	*node;
	t_tmp	*new;
	size_t	start;
	char	*str;
	char	**buf;

	start = idx;
	node = get_lastnode(p_man);
	while (prompt[idx] && check_space(prompt[idx]))
		idx++;
	str = ft_substr(prompt, start, idx);
	new = (t_tmp *)malloc(sizeof(t_tmp));
	if (check_dollar(str))
	{
		buf = ft_split(str, '$');
		(new->args) = expand_env(buf);
	}
	else
		(new->args) = str;
	(new->next) = NULL;
	if (!get_lasttmp(node))
		node->temp = new;
	else
		get_lasttmp(node)->next = new;
	return (idx);
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

t_cmd	*change_cmds(t_pipe *node)
{
	size_t	i;
	size_t	len;
	t_tmp	*tmp;
	t_cmd	*cmd;
	char	**cmds;

	i = 0;
	tmp = node->temp;
	len = get_tmpsize(node);
	printf("len: %zu\n", len);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmds = (char **)malloc(sizeof(char *) * (len + 1));
	cmds[len] = NULL;
	while (tmp)
	{
		cmds[i] = ft_strdup(tmp->args);
		tmp = tmp->next;
		i++;
	}
	(cmd->args) = cmds;
	(cmd->path) = NULL;
	free_tmps(node);
	return (cmd);
}
