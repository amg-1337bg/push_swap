/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:50:42 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/23 10:56:10 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
# include <stdio.h>


typedef struct s_stack
{
    long long num;
	int	index;
	int	position;
    struct s_stack *next;
}	t_stack;

t_stack	*last_node(t_stack *head);
t_stack *before_last(t_stack *head);


int		add_to_list(t_stack **head, long long num);
int		is_valid(char *av, long long num);
void	ft_free_list(t_stack **a);
int		is_dup(t_stack *head, long long num);
int		stack_length(t_stack *head);
void	start_sort(t_stack **a, t_stack **b);
// instructions

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b); // Need TO be modified
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);


# endif