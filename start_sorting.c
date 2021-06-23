/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:26:07 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/23 13:22:32 by bamghoug         ###   ########.fr       */
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

	i = 16;
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

int	is_sorted(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	first = *a;
	while (first)
	{
		second = first;
		while (second)
		{
			if (first->num > second->num)
				return (1);
			second = second->next;
		}
		first = first->next;
	}
	return (0);
}

void	sort_three(t_stack **a, int len)
{
	sort_in_arr(*a, len);
	if ((*a)->index == 2 && (*a)->next->next->index == 0)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->index == 2 && (*a)->next->index == 0)
		rra(a);
	else if ((*a)->index == 1 && (*a)->next->index == 0)
		sa(a);
	else if ((*a)->index == 0 && (*a)->next->index == 2)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->index == 1 && (*a)->next->index == 2)
		ra(a);
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
	t_stack *tmp;

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
		rra(a);
		set_position(*a);
		push_index(a, b, index);
	}
	else if (tmp->position > 2)
	{
		ra(a);
		set_position(*a);
		push_index(a, b, index);
	}
}

void	push_two_small(t_stack **a, t_stack **b, int *len)
{
	int		index;

	index = 0;
	while((*len) > 3)
	{
		set_position(*a);
		push_index(a, b, index);
		(*len)--;
		index++;
	}
}
void	sort_under_five(t_stack **a, t_stack **b, int len)
{
	int before;
	t_stack *tmp;

	before = len;
	sort_in_arr(*a, len);
	push_two_small(a, b, &len);
	// tmp = *a;
	// while (tmp)
	// {
	// 	printf("%lld\n", tmp->num);
	// 	tmp = tmp->next;
	// }
	sort_three(a, len);
	if (before == 4)
		pa(a, b);
	else
	{
		pa(a, b);
		pa(a, b);
	}
	tmp = *a;
	while (tmp)
	{
		printf("%lld\n", tmp->num);
		tmp = tmp->next;
	}
}

void	start_sort(t_stack **a, t_stack **b)
{
	int len;
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