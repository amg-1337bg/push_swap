/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:52:36 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/23 20:06:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_length(*a) < 2)
		return ;
	first = *a;
	second = first->next;
	*a = second;
	first->next = second->next;
	second->next = first;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_length(*b) < 2)
		return ;
	first = *b;
	second = first->next;
	*b = second;
	first->next = second->next;
	second->next = first;
	write(1, "sb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*heada;
	t_stack	*headb;

	if (*b == NULL)
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
	t_stack	*heada;
	t_stack	*headb;

	if (*a == NULL)
		return ;
	heada = *a;
	headb = *b;
	*a = (*a)->next;
	heada->next = headb;
	*b = heada;
	write(1, "pb\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;

	last = last_node(*a);
	last->next = *a;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}
