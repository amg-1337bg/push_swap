/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:16:45 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/16 13:09:46 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	zero_val(char *av)
{
	int i;

	i = 0;
	if (av[0] == '-' || av[0] == '+' || av[0] == '0')
	{
		while (av[++i] != '\0')
		{
			if (av[i] != '0')
				return (1);
		}
	}
	else if (av[0] != '-' || av[0] != '+' || av[0] != '0')
		return (1);
	return (0);
}

int	all_num(char *av)
{
	int	i;

	if (av[0] == '-' || av[0] == '+')
		i = 0;
	else
		i = -1;
	while (av[++i] != '\0')
	{
		if (ft_isdigit(av[i]) != 1)
			return (1);
	}
	return (0);
}

int	check_max_min(long long num)
{
	if (num < -2147483648 || num > 2147483647)
		return (1);
	return(0);
}

int	is_valid(char *av, long long num)
{
	int	check;

	if (num == 0)
		check = zero_val(av);
	else
		check = all_num(av);
	if (check == 1)
		return (1);
	else
		check = check_max_min(num);
	return (check);
}

int	is_dup(t_stack *head, long long num)
{
	while (head != NULL)
	{
		if (head->num == num)
			return (1);
		head = head->next;
	}
	return (0);
}
