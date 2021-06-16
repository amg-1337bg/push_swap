/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:50:37 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/16 15:28:44 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *head)
{
	while (head != NULL)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}

int	add_to_list(t_stack **head, long long num)
{
	t_stack *fill;
	t_stack *tmp;
	int		ret;

	ret = is_dup(*head, num);
	if (ret == 1)
		return (1);
	fill = malloc(sizeof(t_stack));
    fill->num = num;
    fill->next = NULL;
	tmp = last_node(*head);
	if (tmp == NULL)
		*head = fill;
	else
		tmp->next = fill;
	return (0);
}

int	stack_length(t_stack *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_free_list(t_stack **a)
{
	t_stack *tmp;
	t_stack *next;

	tmp = *a;
	while (tmp)
	{
		next = tmp->next;
		free (tmp);
		tmp = next;
	}
	*a = NULL;
}

t_stack *before_last(t_stack *head)
{
	while (head)
	{
		if (head->next != NULL && head->next->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}