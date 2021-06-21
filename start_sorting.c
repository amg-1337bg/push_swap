/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:26:07 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/21 11:49:05 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_in_arr(t_stack *a, int len)
{
	int *arr;
	int i;

	i = -1;
	arr = malloc(len * sizeof(int));
	while (++i < len)
	{
		if (a->next != NULL && a->num < a->next->num)
			arr[i] = a->num;
		else if (a->next != NULL)
			arr[i] = a->next->num;
		else
			arr[i] = a->num;
		a = a->next;
	}
	i = 0;
	while (i < len)
		printf("%d\n", arr[i++]);
}

void	start_sort(t_stack **a, t_stack **b)
{
	int len;

	len = stack_length(*a);
	sort_in_arr(*a, len);
	*b = NULL;
}