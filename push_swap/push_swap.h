#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_node
{
	int				    num;
  unsigned int  index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

// push_swap.c
void  push_swap(int argc, char **args);
void  ft_sort_stack(t_stack **stack_a, t_stack **stack_b);

// utils/arg_utils.c
char  **ft_check_args(int argc, char **argv);
int  ft_check_double(int current, size_t current_idx, char **args);
int	ft_check_only_num(char *str);

// utils/stack_utils.c
void	ft_free_stack(t_stack	**stack);
void ft_init_stack(int argc, t_stack  **stack, char **argv);
void  ft_direct_command_a(t_stack **stack_a, t_node *min_node);
void  ft_direct_command_b(t_stack **stack_b, t_node *max_node);

// utils/sort_utils.c
int ft_check_is_sorted(t_stack **stack);
void  ft_sort_type_a(t_stack **stack_a, t_stack **stack_b);
void  ft_sort_type_b(t_stack **stack_a, t_stack **stack_b);
t_node  *ft_get_next_node(t_stack **stack_a, t_node *half_node);

// utils/command_utils.c
int ft_push(t_stack **stack_to, t_stack **stack_from);
int ft_swap(t_stack **stack);
int ft_rotate(t_stack **stack);
int ft_reverse_rotate(t_stack **stack);

// utils/sort_type_a_utils.c
void  ft_sort_stack_len_3(t_stack **stack);

// utils/sort_type_b_utils.c
void  ft_sort_upper(t_stack **stack_a, t_stack **stack_b);
void  ft_sort_lower(t_stack **stack_b, t_stack **stack_a);
t_node  *ft_find_min_node(t_stack **stack);
t_node  *ft_find_max_node(t_stack **stack);
t_node  *ft_find_half_node(t_stack **stack);
t_node  *ft_find_next_node(t_stack **stack, t_node *bottom);
t_node  *ft_find_prev_node(t_stack **stack, t_node *top);
void  ft_return_node(t_stack **stack_a, t_stack **stack_b, int count);

// utils/etc_utils.c
void  ft_free(char **str);
void  ft_free_node(t_node *node);
void  ft_del_stack(t_stack **stack);
void	ft_rebalance_index(t_stack **stack);

// utils/push_utils.c
void  ft_case_over_one(t_node **temp, t_node **head_from, t_stack **stack_from);
void  ft_case_under_one(t_node **temp, t_stack **stack_from);
void  ft_case_stack_null(t_stack **stack_to, t_node **head_from);
void  ft_case_stack_full(t_node **head_from, t_node **head_to);

// utils/print_utils.c
void  ft_print_command(char *command);
void  ft_error(char *error);

// lib
size_t  ft_strlen(const char *str);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_stack **stack, t_node *new_node);
t_node	*ft_lstlast(t_node *node);
t_node	*ft_lstnew(int word, int idx);
size_t ft_lstsize(t_stack **stack);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// command/ft_push.c
int ft_pa(t_stack **stack_a, t_stack **stack_b);
int ft_pb(t_stack **stack_a, t_stack **stack_b);

// command/ft_swap.c
int ft_sa(t_stack **stack_a);
int ft_sb(t_stack **stack_b);
int ft_ss(t_stack **stack_a, t_stack **stack_b);

// command/ft_lotate.c
int ft_ra(t_stack **stack_a);
int ft_rb(t_stack **stack_b);
int ft_rr(t_stack **stack_a, t_stack **stack_b);

// command/ft_reverse_locate.c
int ft_rra(t_stack **stack_a);
int ft_rrb(t_stack **stack_b);
int ft_rrr(t_stack **stack_a, t_stack **stack_b);

void print_stack(t_stack *stack);

#endif