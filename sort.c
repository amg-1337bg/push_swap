/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:53:01 by marvin            #+#    #+#             */
/*   Updated: 2021/06/23 19:53:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, int len)
{
	sort_in_arr(*a, len);
	if ((*a)->index == 2 && (*a)->next->next->index == 0)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->index == 2 && (*a)->next->index == 0)
		ra(a);
	else if ((*a)->index == 1 && (*a)->next->index == 0)
		sa(a);
	else if ((*a)->index == 0 && (*a)->next->index == 2)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->index == 1 && (*a)->next->index == 2)
		rra(a);
}

void	set_position(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a->position = i++;
		a = a->next;
	}
}

void	push_index(t_stack **a, t_stack **b, int index)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index == index)
			break ;
		tmp = tmp->next;
	}
	if (tmp->position == 0)
		pb(b, a);
	else if (tmp->position <= 2)
	{
		ra(a);
		set_position(*a);
		push_index(a, b, index);
	}
	else if (tmp->position > 2)
	{
		rra(a);
		set_position(*a);
		push_index(a, b, index);
	}
}

void	push_two_small(t_stack **a, t_stack **b, int *len)
{
	int		index;

	index = 0;
	while ((*len) > 3)
	{
		set_position(*a);
		push_index(a, b, index);
		(*len)--;
		index++;
	}
}

void	sort_under_five(t_stack **a, t_stack **b, int len)
{
	int	before;

	before = len;
	sort_in_arr(*a, len);
	push_two_small(a, b, &len);
	sort_three(a, len);
	if (before == 4)
		pa(a, b);
	else
	{
		pa(a, b);
		pa(a, b);
	}
}
