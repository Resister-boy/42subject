/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehulee <jaehulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:56:41 by jaehulee          #+#    #+#             */
/*   Updated: 2023/04/12 12:36:15 by jaehulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

void	checker(char **args);
void	ft_proof_is_sorted(t_stack **stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_proof_command(t_stack **stack_a, t_stack **stack_b, char *command);
void	ft_proof_push(t_stack **stack_a, t_stack **stack_b, char *command);
void	ft_proof_swap(t_stack **stack, t_stack **stack_b, char *command);
void	ft_proof_rotate(t_stack **stack_a, t_stack **stack_b, char *command);
void	ft_proof_reverse_rotate(t_stack **stack_a, t_stack **stack_b, \
char *command);

#endif