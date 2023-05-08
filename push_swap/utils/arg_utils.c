/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:04:15 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 16:57:38 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_allocate_arg(int argc, char **argv, char **args)
{
	int		i;
	size_t	j;
	char	**temp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		temp = ft_split(argv[i], ' ');
		while (temp[j])
		{
			(*args) = ft_strdup(temp[j]);
			(args)++;
			j++;
		}
		i++;
		ft_free_str(&temp);
	}
}

int	ft_check_only_num(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && '9' >= str[i]) || \
		(str[i] == '-' || str[i] == ' '))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_double(int current, size_t current_idx, char **args)
{
	size_t	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (i != current_idx && current == ft_atoi(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_double_len(char **argv)
{
	size_t	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

char	**ft_check_args(int argc, char **argv)
{
	size_t		size;
	char		**args;

	if (argc == 2)
		ft_argc_small(argv, &args);
	else
	{
		size = ft_count_total_len(argc, argv) + 1;
		args = (char **)malloc(sizeof(char *) * size);
		args[size - 1] = NULL;
		ft_allocate_arg(argc, argv, args);
	}
	ft_check_args_kit(args);
	return (args);
}
