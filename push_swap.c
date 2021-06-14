/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:58:37 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/14 12:19:03 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int fill_stacka(t_stack **a, char **av)
{
    int num;
    int i;
    t_stack *tmp;

    i = -1;
    while (av[++i] != NULL)
    {
        num = ft_atoi(av[i]);
        tmp = malloc(sizeof(t_stack));
        tmp->num = num;
        tmp->next = NULL;
    }
    
}

int main(int ac, char *av[])
{
    t_stack *stacka;
    t_stack *stackb;

    if (ac < 2)
        return (1);
    else
    {

    }

    return (0);
}