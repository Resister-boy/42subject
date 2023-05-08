/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:33:02 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 16:59:24 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				num;
	unsigned int	index;
	unsigned int	rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

typedef struct s_command
{
	int				count;
	int				flag;
}	t_command;

// push_swap.c
void		push_swap(char **args);
void		ft_sort_stack(t_stack **stack_a, t_stack **stack_b);

// utils/arg_utils.c
char		**ft_check_args(int argc, char **argv);
int			ft_check_double(int current, size_t current_idx, char **args);
int			ft_check_only_num(char *str);
int			ft_get_double_len(char **argv);
void		ft_allocate_arg(int argc, char **argv, char **args);

// utils/stack_utils.c
void		ft_init_stack(t_stack **stack, char **argv);
void		ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
void		ft_free_stack(t_stack **stack);
void		ft_free_str(char ***str);
void		ft_argc_small(char **argv, char ***args);

// utils/sort_utils_1.c
int			ft_check_is_sorted(t_stack **stack);
t_node		*ft_get_available_node(t_stack **stack_a, size_t pivot);
void		ft_sort_type_a(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_type_b(t_stack **stack_a, t_stack **stack_b);
void		ft_check_args_kit(char **args);
// utils/sort_utils_2.c
void		ft_send_node_top(t_stack **stack_a, t_node *min_node);
void		ft_execute_cmd(t_stack **stack_a, t_stack **stack_b, \
t_command *cmd);
void		ft_return_node(t_stack **stack_a, t_stack **stack_b);
size_t		ft_get_total_cmd(t_command *cmd);
void		ft_select_collect(t_node **current, t_node **collect);

// utils/sort_utils_3.c
void		ft_sort_case_min_top(t_stack **stack);
void		ft_sort_case_min_mid(t_stack **stack, t_node *head, t_node *min);
void		ft_sort_case_min_bot(t_stack **stack, t_node *head, t_node *min);
void		ft_get_op_cmd(t_stack **stack_a, t_stack **stack_b, \
t_command *cmd);
int			ft_find_short_cmd(t_command *cmd);

// utils/sort_utils_4.c
t_node		*ft_find_min_node(t_stack **stack);
t_node		*ft_find_max_node(t_stack **stack);
int			ft_get_escape_count(t_stack **stack, t_node *node);
int			ft_abs(int count);
int			ft_count_total_len(int argc, char **argv);

// utils/sort_utils_5.c
t_node		*ft_find_min_next_node(t_stack **stack, t_node *bottom);
t_node		*ft_find_max_prev_node(t_stack **stack, t_node *top);
t_command	ft_find_node_from(t_stack **stack_b, t_node *node);
t_command	ft_find_node_to(t_stack **stack_a, t_node *node);
t_node		*ft_get_collect_node(t_stack **stack_a, t_node *node);

// utils/sort_utils_6.c
void		ft_sort_stack_len_3(t_stack **stack);
void		ft_sort_stack_len_4(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_stack_len_5(t_stack **stack_a, t_stack **stack_b);
void		ft_init_rank(t_stack **stack);

// utils/sort_utils_7.c
int			ft_exe_dup_cmd(t_stack **stack_a, t_stack **stack_b, \
t_command *cmd);

// utils/command_utils.c
int			ft_push(t_stack **stack_to, t_stack **stack_from);
int			ft_swap(t_stack **stack);
int			ft_rotate(t_stack **stack);
int			ft_reverse_rotate(t_stack **stack);

// utils/etc_utils.c
void		ft_del_stack(t_stack **stack);
void		ft_rebalance_index(t_stack **stack);

// utils/push_utils.c
void		ft_case_over_one(t_node **temp, t_node **head_from, \
t_stack	**stack_from);
void		ft_case_under_one(t_node **temp, t_stack **stack_from);
void		ft_case_stack_null(t_stack **stack_to, t_node **head_from);
void		ft_case_stack_full(t_node **head_from, t_node **head_to);

// utils/print_utils.c
void		ft_print_result(char *result);
void		ft_print_command(char *command);
void		ft_error(char *error);
int			ft_compare_command(int count1, int count2);

// utils/swap_utils.c
void		ft_case_stack_over(t_node **head, t_node **head_next, \
t_node **temp);
void		ft_case_stack_two(t_stack **stack, t_node **head, \
t_node **head_next);

// lib
size_t		ft_strlen(char *str);
long long	ft_atoi(char *str);
char		**ft_split(char *s, char c);
size_t		count_total_string(char *s, char c);
void		ft_lstadd_back(t_stack **stack, t_node *new_node);
t_node		*ft_lstlast(t_node *node);
t_node		*ft_lstnew(int word, int idx);
size_t		ft_lstsize(t_stack **stack);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
char		*ft_strdup(char *str);

// command/ft_push.c
int			ft_pa(t_stack **stack_a, t_stack **stack_b);
int			ft_pb(t_stack **stack_a, t_stack **stack_b);

// command/ft_swap.c
int			ft_sa(t_stack **stack_a);
int			ft_sb(t_stack **stack_b);
int			ft_ss(t_stack **stack_a, t_stack **stack_b);

// command/ft_lotate.c
int			ft_ra(t_stack **stack_a);
int			ft_rb(t_stack **stack_b);
int			ft_rr(t_stack **stack_a, t_stack **stack_b);

// command/ft_reverse_locate.c
int			ft_rra(t_stack **stack_a);
int			ft_rrb(t_stack **stack_b);
int			ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif