/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:50:42 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/23 20:24:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	long long		num;
	int				index;
	int				position;
	struct s_stack	*next;
}	t_stack;

t_stack	*last_node(t_stack *head);
t_stack	*before_last(t_stack *head);
int		add_to_list(t_stack **head, long long num);
int		is_valid(char *av, long long num);
void	ft_free_list(t_stack **a);
int		is_sorted(t_stack **a);
int		is_dup(t_stack *head, long long num);
int		stack_length(t_stack *head);
void	start_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a, int len);
void	sort_two(t_stack **a);
void	set_position(t_stack *a);
void	push_index(t_stack **a, t_stack **b, int index);
void	push_two_small(t_stack **a, t_stack **b, int *len);
void	sort_under_five(t_stack **a, t_stack **b, int len);
void	sort_in_arr(t_stack *a, int len);
int		looping(int len);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif