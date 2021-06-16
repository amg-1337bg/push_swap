/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:52:36 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/16 13:20:14 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack *first;
	t_stack *second;

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
	t_stack *first;
	t_stack *second;

	if (stack_length(*b) < 2)
		return ;
	first = *b;
	second = first->next;
	*b = second;
	first->next = second->next;
	second->next = first;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}