/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:58:37 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/23 20:11:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stacka(t_stack **a, char **av)
{
	long long	num;
	int			i;
	int			check;

	i = 0;
	while (av[++i] != NULL)
	{
		num = ft_atoi(av[i]);
		check = is_valid(av[i], num);
		if (check == 1)
			return (1);
		check = add_to_list(a, num);
		if (check == 1)
		{
			ft_free_list(a);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		ret;

	stacka = NULL;
	stackb = NULL;
	if (ac < 2)
		return (1);
	ret = fill_stacka(&stacka, av);
	if (ret == 1)
	{
		write(1, "Error\n", 6);
		return (ret);
	}
	start_sort(&stacka, &stackb);
	ft_free_list(&stacka);
	return (0);
}
