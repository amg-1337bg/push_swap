/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:54:09 by marvin            #+#    #+#             */
/*   Updated: 2021/06/23 19:54:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	set_index(t_stack *a, int *arr, int len)
{
	int		i;
	t_stack	*tmp;

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
	int		*arr;
	int		i;
	int		j;
	t_stack	*head;

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
