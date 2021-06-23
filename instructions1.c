/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:21:52 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/23 12:40:11 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack *heada;
	t_stack *headb;

	if(*b == NULL)
		return ;
	heada = *a;
	headb = *b;
	*b = (*b)->next;
	headb->next = heada;
	*a = headb;
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack *heada;
	t_stack *headb;

	if(*a == NULL)
		return ;
	heada = *a;
	headb = *b;
	*a = (*a)->next;
	heada->next = headb;
	*b = heada;
	write(1, "pb\n", 3);
}

void	rra(t_stack **a)
{
	t_stack *last;
	t_stack *tmp;

	last = last_node(*a);
	last->next = *a;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack *last;
	t_stack *tmp;

	last = last_node(*b);
	last->next = *b;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rr(t_stack **a, t_stack **b)
{
	rb(b);
	ra(a);
	write(1, "rr\n", 3);
}

void	ra(t_stack **a)
{
	t_stack *last;
	t_stack *b_last;

	if (stack_length(*a) < 2)
		return ;
	b_last = before_last(*a);
	last = last_node(*a);
	b_last->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack *last;
	t_stack *b_last;

	if (stack_length(*b) < 2)
		return ;
	b_last = before_last(*b);
	last = last_node(*b);
	b_last->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rb\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}