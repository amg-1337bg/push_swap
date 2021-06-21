/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:26:07 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/21 13:35:58 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	set_index(t_stack *a, int *arr, int len)
{
	int i;
	t_stack *tmp;

	i = -1;
	while (++i < len)
	{
		tmp = a;
		while (tmp)
		{
			if (tmp->num == arr[i])
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

void	sort_in_arr(t_stack *a, int len)
{
	int *arr;
	int i;
	int j;
	t_stack *head;

	i = -1;
	head = a;
	arr = malloc(len * sizeof(int));
	while (++i < len)
	{
		arr[i] = a->num;
		a = a->next;
	}
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
	set_index(head, arr, len);
}

int	looping(int len)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if ((len & (1 << i)))
			break;
		i--;
	}
	return (i);
}

void	sort_stack(t_stack **a, t_stack **b, int time)
{
	int i;
	int stack_len;

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

void	sort_two(t_stack **a)
{
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

// void	sort_under_five(t_stack **a, t_stack **b)
// {

// }

void	start_sort(t_stack **a, t_stack **b)
{
	int len;
	// t_stack *tmp;
	int	time_to_loop;

	len = stack_length(*a);
	if (len < 2)
		return ;
	else if (len == 2)
		sort_two(a);
	// else if (len <= 5)
	// 	sort_under_five(a, b);
	else
	{
		sort_in_arr(*a, len);
		time_to_loop = looping(len);
		sort_stack(a, b, time_to_loop);
		*b = NULL;
	}
}