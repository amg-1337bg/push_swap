/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:26:07 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/23 20:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b, int time)
{
	int	i;
	int	stack_len;

	i = 0;
	while (time >= 0)
	{
		stack_len = stack_length(*a);
		while (stack_len > 0)
		{
			if (((*a)->index & (1 << i)))
				ra(a);
			else
				pb(b, a);
			stack_len--;
		}
		while (*b)
			pa(a, b);
		time--;
		i++;
	}
}

void	start_sort(t_stack **a, t_stack **b)
{
	int	len;
	int	time_to_loop;

	len = stack_length(*a);
	if (is_sorted(a) == 0)
		return ;
	if (len < 2)
		return ;
	else if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a, len);
	else if (len <= 5)
		sort_under_five(a, b, len);
	else
	{
		sort_in_arr(*a, len);
		time_to_loop = looping(len);
		sort_stack(a, b, time_to_loop);
		*b = NULL;
	}
}
